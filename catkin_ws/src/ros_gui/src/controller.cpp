/**
 * @file /src/qnode.cpp
 *
 * @brief Controller central!
 *
 * @date March 2015
 **/

/*****************************************************************************
** Includes
*****************************************************************************/
#include <QtCore>
#include <ros/ros.h>
#include <ros/network.h>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/ros_gui/controller.hpp"
#include <geometry_msgs/PoseArray.h>
#include <apriltags_ros/AprilTagDetection.h>
#include <apriltags_ros/AprilTagDetectionArray.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <tf/transform_datatypes.h>


/*****************************************************************************
** Namespaces
*****************************************************************************/
namespace ros_gui {

/*****************************************************************************
** Implementation
*****************************************************************************/

//Para matrizes de ponderação: Q 100*I e R = I
const float Controller::Kdlqr[3][6] = {
    { 0.0000,   -7.3404,    0.1982,    0.0000,   -5.0455,    0.3356},
    { 6.3570,    3.6702,    0.1982,    4.3695,    2.5227,    0.3356},
    {-6.3570,    3.6702,    0.1982,   -4.3695,    2.5227,    0.3356}
                           };
//

//N = Nu = 50
//[0.0003704, -9.1677, 0.41744, 8.8779e-05, -4.9514, 0.333]
//[7.9264, 4.5844, 0.043546, 4.285, 2.4758, 0.12537]
//[-7.9262, 4.583, 0.29373, -4.285, 2.4755, 0.26446]


/*Referentes ao preditor Otimo*/
const float Controller::Ag[6][6] = {
    {0.8218,         0,         0,         0,         0,         0},
    {     0,    0.8218,         0,         0,         0,         0},
    {     0,         0,    0.5888,         0,         0,         0},
    {0.8218,         0,         0,    1.0000,         0,         0},
    {     0,    0.8218,         0,         0,    1.0000,         0},
    {     0,         0,    0.5888,         0,         0,    1.0000}
                        };

const float Controller::Bg[6][3] = {
    {      0,    0.0400,   -0.0400},
    {-0.0461,    0.0231,    0.0231},
    { 0.9868,    0.9868,    0.9868},
    {      0,    0.0400,   -0.0400},
    {-0.0461,    0.0231,    0.0231},
    { 0.9868,    0.9868,    0.9868}
                        };

/*Referentes ao preditor de Smith*/
const float Controller::Ad[3][3] = {
    {0.8218,         0,         0},
    {     0,    0.8218,         0},
    {     0,         0,    0.5888}
                        };

const float Controller::Bd[3][3] = {
    {        0,    0.0400,   -0.0400},
    {    -0.0461,    0.0231,    0.0231},
    {    0.9868,    0.9868,    0.9868}
                        };

const float Controller::Cd[3][3] = {
                         {1, 0, 0},
                         {0, 1, 0},
                         {0, 0, 1}
                        };

 Mat AA;
 Mat BB;
 Mat CC;

 Mat Q;
 Mat R;

 Mat W;

 double TrajX[100];             //vetor contendo a trajetória em X
 double TrajY[100];             //vetor contendo a trajetória em Y
 double TrajTheta[100];
 int Index;
 int TrajPoints;
 int TrajOK;

 double xr,yr,theta;
 double xr_odom,yr_odom,theta_odom;
 double xv1,yv1,thetav1,idv1,xv2,yv2,thetav2,idv2;
 double Vref[3]; //Ainda é utilizado devido ao log
 double dU[3], U[3];
 double vel[3], old_vel[3];
 double velrad[3];
 double x[3], old_x[3];
 double xFiltrado[3];
 double velm[3], new_velm[3];
 double difvel[3];

 char PWM[4];


// Variaveis do Apriltag
 Mat pose;
 bool newAprilTag;
 /*------------------------------------Constantes-----------------------------------*/
 /*  Para evitar repetições, duplicidades e uma boa inicialização, é definida uma
     função para iniciar as constantes globais.                                     */
 // Variáveis declaradas como global para poder acessar em outras funções
 Mat sigma = Mat::zeros(3, 3, CV_64F);		 // Desvio do estado filtro de Kalman
 Mat mi = Mat::zeros(3, 1, CV_64F);          // Média do estado do filtro de Kalman
 bool flagI = true;                          // Flag qque indica primeira iteração

 /*---------------------------------------------------------------------------------*/

 //***********************

Controller::Controller(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

Controller::~Controller() {
	if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
	}
	wait();
}

//void chatterCallback(const geometry_msgs::PoseArray& msg)
void chatterCallback(const apriltags_ros::AprilTagDetectionArray& msg)
{
        pose.release();
        pose.create(0,0,CV_32F);
        if(!msg.detections.empty()){
             for(int i=0;i<msg.detections.size();i++){
                Mat apriltag;

                tf::Quaternion q(msg.detections[i].pose.pose.orientation.x,
                                 msg.detections[i].pose.pose.orientation.y,
                                 msg.detections[i].pose.pose.orientation.z,
                                 msg.detections[i].pose.pose.orientation.w);
                tf::Matrix3x3 m(q);

                apriltag = (Mat_<double>(4,4) << m[0][0], m[0][1], m[0][2],msg.detections[i].pose.pose.position.x,
                                                 m[1][0], m[1][1], m[1][2],msg.detections[i].pose.pose.position.y,
                                                 m[2][0], m[2][1], m[2][2],msg.detections[i].pose.pose.position.z,
                                                    1,        1,      1,            msg.detections[i].id)        ;
                pose.push_back(apriltag);
             }
             newAprilTag = true;
         }
}


bool Controller::init(SerialPort* device) {
	ros::init(init_argc,init_argv,"ros_gui_controller");
	if ( ! ros::master::check() ) {
		return false;
	}

	ros::start(); // explicitly needed since our nodehandle is going out of scope.
//    n.subscribe("tag_detections_pose", 1000, chatterCallback);

    dataReceived = false;
    enable = false;

    /*-----------------init matrices----------------*/

    // Matrizes Aumentadas
    cv::Mat Aa = (cv::Mat_<float>(6,6) << 0.8218, 0, 0, 0, 0, 0,
                                          0, 0.8218, 0, 0, 0, 0,
                                          0, 0, 0.5888, 0, 0, 0,
                                          0.8218, 0, 0, 1, 0, 0,
                                          0, 0.8218, 0, 0, 1, 0,
                                          0, 0, 0.5888, 0, 0, 1);

    cv::Mat Ba = (cv::Mat_<float>(6,3) <<   0,    0.0400,   -0.0400,
                                            -0.0461,    0.0231,    0.0231,
                                            0.9868,    0.9868,    0.9868,
                                            0,    0.0400,   -0.0400,
                                            -0.0461,    0.0231,    0.0231,
                                            0.9868,    0.9868,    0.9868);

    //Produzindo as Matrizes Caligraficas
    AA.create(0,0,CV_32F);// = Aa;//Mat::zeros(6*HP, 6, CV_32F);
    BB.create(0,0,CV_32F);//Mat::zeros(6*HP, 3*HC, CV_32F);
    CC = Mat::eye(3*HP, 6*HP, CV_32F);

    Q = Mat::eye(3*HP, 3*HP, CV_32F)*25;
    R = Mat::eye(3*HC, 3*HC, CV_32F);

    Mat aux_Ba;// = Ba;
    Mat aux_Aa;// = Aa;

    aux_Ba.create(0,0,CV_32F);
    aux_Aa.create(0,0,CV_32F);

    aux_Ba.push_back(Ba);
    aux_Aa.push_back(Aa);

    Mat aux_BB1 = Ba;
    AA.push_back(Aa);

    for(int i = 1; i < HP; i++){

        aux_Ba = aux_Aa*Ba;
        aux_Aa = aux_Aa*Aa;

        AA.push_back(aux_Aa);
        aux_BB1.push_back(aux_Ba);

    }

//    Mat aux_BB2;// = aux_BB1.t();
//    aux_BB2.create(0,0,CV_32F);

////    aux_BB2.push_back(aux_BB1.t());

////    //std::cout << aux_BB2 << "\n";
////    cout <<" \n";
////    print(aux_BB2,4);

    for(int i = 1; i < HC; i++){
        aux_Ba = Mat::zeros(Ba.rows*i,Ba.cols,CV_32F);
        aux_Ba.push_back(aux_BB1.colRange(0,Ba.cols).rowRange(0,Ba.rows*(HP-i)));

/*        cout <<"1 \n";
        print(aux_Ba,4)*/;

        //aux_BB2.push_back(aux_Ba);

        hconcat(aux_BB1,aux_Ba,aux_BB1);

//        cout <<"2 \n";
//        print(aux_BB1.t(),4);

    }

    BB.push_back(aux_BB1);

//    cout <<" !!!\n";
//    print(BB,4);

    aux_Aa.release();
    aux_Ba.release();
    aux_BB1.release();
    //aux_BB2.release();

//    //cout <<" \n";
//    //print(AA,1);
//    //cout <<" \n";
//    //print(BB,1);
//    //cout <<" \n";

    /*-----------------init vectors-----------------*/

    vel[0] = vel[1] = vel[2] = 0;

    xFiltrado[0] = xFiltrado[1] = xFiltrado[2] = 0;

    velm[0] = velm[1] = velm[2] = 0;
	
	x[0] = x[1] = x[2] = 0;
	
	dU[0] = dU[1] = dU[2] = 0;
    U[0] = U[1] = U[2] = 0;
	
    PWM[0] = PWM[1] = PWM[2] = PWM[3] = 0;

    /*-----------------init trajectory-----------------*/

    TrajOK = 0;
    Index = 0;
    TrajPoints = 72;
    Circulo:
        TrajX[0] = 0.0000;
        TrajY[0] = 0.0000;
        TrajTheta[0] = 0;//
        TrajX[1] = 0.0371/2;
        TrajY[1] = 0.2698/2;
        TrajTheta[1] = 0;//
        TrajX[2] = 0.1456/2;
        TrajY[2] = 0.5196/2;
        TrajTheta[2] = 0;//
        TrajX[3] = 0.3174/2;
        TrajY[3] = 0.7308/2;
        TrajTheta[3] = 0;//
        TrajX[4] = 0.5399/2;
        TrajY[4] = 0.8879/2;
        TrajTheta[4] = 0;//
        TrajX[5] = 0.7965/2;
        TrajY[5] = 0.9791/2;
        TrajTheta[5] = 0;//
        TrajX[6] = 1.0682/2;
        TrajY[6] = 0.9977/2;
        TrajTheta[6] = 0;//
        TrajX[7] = 1.3349/2;
        TrajY[7] = 0.9423/2;
        TrajTheta[7] = 0;//
        TrajX[8] = 1.5767/2;
        TrajY[8] = 0.8170/2;
        TrajTheta[8] = 0;//
        TrajX[9] = 1.7757/2;
        TrajY[9] = 0.6311/2;
        TrajTheta[9] = 0;//
        TrajX[10] = 1.9172/2;
        TrajY[10] = 0.3984/2;
        TrajTheta[10] = 0;//
        TrajX[11] = 1.9907/2;
        TrajY[11] =  0.1362/2;
        TrajTheta[11] = 0;//
        TrajX[12] = 1.9907/2;
        TrajY[12] = -0.1362/2;
        TrajTheta[12] = 0;//
        TrajX[13] = 1.9172/2;
        TrajY[13] = -0.3984/2;
        TrajTheta[13] = 0;//
        TrajX[14] = 1.7757/2;
        TrajY[14] = -0.6311/2;
        TrajTheta[14] = 0;//
        TrajX[15] = 1.5767/2;
        TrajY[15] = -0.8170/2;
        TrajTheta[15] = 0;//
        TrajX[16] = 1.3349/2;
        TrajY[16] = -0.9423/2;
        TrajTheta[16] = 0;//
        TrajX[17] = 1.0682/2;
        TrajY[17] = -0.9977/2;
        TrajTheta[17] = 0;//
        TrajX[18] = 0.7965/2;
        TrajY[18] = -0.9791/2;
        TrajTheta[18] = 0;//
        TrajX[19] = 0.5399/2;
        TrajY[19] = -0.8879/2;
        TrajTheta[19] = 0;//
        TrajX[20] = 0.3174/2;
        TrajY[20] = -0.7308/2;
        TrajTheta[20] = 0;//
        TrajX[21] = 0.1456/2;
        TrajY[21] = -0.5196/2;
        TrajTheta[21] = 0;//
        TrajX[22] = 0.0371/2;
        TrajY[22] =  -0.2698/2;
        TrajTheta[22] = 0;//
        TrajX[23] = 0.0000;
        TrajY[23] = 0.0000;
        TrajTheta[23] = 0;//
        TrajX[24] = 0.0000;
        TrajY[24] = 0.0000;
        TrajTheta[24] = 0;//
        TrajX[25] = 0.0371/2;
        TrajY[25] = 0.2698/2;
        TrajTheta[25] = 0;//
        TrajX[26] = 0.1456/2;
        TrajY[26] = 0.5196/2;
        TrajTheta[26] = 0;//
        TrajX[27] = 0.3174/2;
        TrajY[27] = 0.7308/2;
        TrajTheta[27] = 0;//
        TrajX[28] = 0.5399/2;
        TrajY[28] = 0.8879/2;
        TrajTheta[28] = 0;//
        TrajX[29] = 0.7965/2;
        TrajY[29] = 0.9791/2;
        TrajTheta[29] = 0;//
        TrajX[30] = 1.0682/2;
        TrajY[30] = 0.9977/2;
        TrajTheta[30] = 0;//
        TrajX[31] = 1.3349/2;
        TrajY[31] = 0.9423/2;
        TrajTheta[31] = 0;//
        TrajX[32] = 1.5767/2;
        TrajY[32] = 0.8170/2;
        TrajTheta[32] = 0;//
        TrajX[33] = 1.7757/2;
        TrajY[33] = 0.6311/2;
        TrajTheta[33] = 0;//
        TrajX[34] = 1.9172/2;
        TrajY[34] = 0.3984/2;
        TrajTheta[34] = 0;//
        TrajX[35] = 1.9907/2;
        TrajY[35] =  0.1362/2;
        TrajTheta[35] = 0;//
        TrajX[36] = 1.9907/2;
        TrajY[36] = -0.1362/2;
        TrajTheta[36] = 0;//
        TrajX[37] = 1.9172/2;
        TrajY[37] = -0.3984/2;
        TrajTheta[37] = 0;//
        TrajX[38] = 1.7757/2;
        TrajY[38] = -0.6311/2;
        TrajTheta[38] = 0;//
        TrajX[39] = 1.5767/2;
        TrajY[39] = -0.8170/2;
        TrajTheta[39] = 0;//
        TrajX[40] = 1.3349/2;
        TrajY[40] = -0.9423/2;
        TrajTheta[40] = 0;//
        TrajX[41] = 1.0682/2;
        TrajY[41] = -0.9977/2;
        TrajTheta[41] = 0;//
        TrajX[42] = 0.7965/2;
        TrajY[42] = -0.9791/2;
        TrajTheta[42] = 0;//
        TrajX[43] = 0.5399/2;
        TrajY[43] = -0.8879/2;
        TrajTheta[43] = 0;//
        TrajX[44] = 0.3174/2;
        TrajY[44] = -0.7308/2;
        TrajTheta[44] = 0;//
        TrajX[45] = 0.1456/2;
        TrajY[45] = -0.5196/2;
        TrajTheta[45] = 0;//
        TrajX[46] = 0.0371/2;
        TrajY[46] =  -0.2698/2;
        TrajTheta[46] = 0;//
        TrajX[47] = 0.0000;
        TrajY[47] = 0.0000;
        TrajTheta[47] = 0;//
        TrajX[48] = 0.0000;
        TrajY[48] = 0.0000;
        TrajTheta[48] = 0;//
        TrajX[49] = 0.0371/2;
        TrajY[49] = 0.2698/2;
        TrajTheta[49] = 0;//
        TrajX[50] = 0.1456/2;
        TrajY[50] = 0.5196/2;
        TrajTheta[50] = 0;//
        TrajX[51] = 0.3174/2;
        TrajY[51] = 0.7308/2;
        TrajTheta[51] = 0;//
        TrajX[52] = 0.5399/2;
        TrajY[52] = 0.8879/2;
        TrajTheta[52] = 0;//
        TrajX[53] = 0.7965/2;
        TrajY[53] = 0.9791/2;
        TrajTheta[53] = 0;//
        TrajX[54] = 1.0682/2;
        TrajY[54] = 0.9977/2;
        TrajTheta[54] = 0;//
        TrajX[55] = 1.3349/2;
        TrajY[55] = 0.9423/2;
        TrajTheta[55] = 0;//
        TrajX[56] = 1.5767/2;
        TrajY[56] = 0.8170/2;
        TrajTheta[56] = 0;//
        TrajX[57] = 1.7757/2;
        TrajY[57] = 0.6311/2;
        TrajTheta[57] = 0;//
        TrajX[58] = 1.9172/2;
        TrajY[58] = 0.3984/2;
        TrajTheta[58] = 0;//
        TrajX[59] = 1.9907/2;
        TrajY[59] =  0.1362/2;
        TrajTheta[59] = 0;//
        TrajX[60] = 1.9907/2;
        TrajY[60] = -0.1362/2;
        TrajTheta[60] = 0;//
        TrajX[61] = 1.9172/2;
        TrajY[61] = -0.3984/2;
        TrajTheta[61] = 0;//
        TrajX[62] = 1.7757/2;
        TrajY[62] = -0.6311/2;
        TrajTheta[62] = 0;//
        TrajX[63] = 1.5767/2;
        TrajY[63] = -0.8170/2;
        TrajTheta[63] = 0;//
        TrajX[64] = 1.3349/2;
        TrajY[64] = -0.9423/2;
        TrajTheta[64] = 0;//
        TrajX[65] = 1.0682/2;
        TrajY[65] = -0.9977/2;
        TrajTheta[65] = 0;//
        TrajX[66] = 0.7965/2;
        TrajY[66] = -0.9791/2;
        TrajTheta[66] = 0;//
        TrajX[67] = 0.5399/2;
        TrajY[67] = -0.8879/2;
        TrajTheta[67] = 0;//
        TrajX[68] = 0.3174/2;
        TrajY[68] = -0.7308/2;
        TrajTheta[68] = 0;//
        TrajX[69] = 0.1456/2;
        TrajY[69] = -0.5196/2;
        TrajTheta[69] = 0;//
        TrajX[70] = 0.0371/2;
        TrajY[70] =  -0.2698/2;
        TrajTheta[70] = 0;//
        TrajX[71] = 0.0000;
        TrajY[71] = 0.0000;
        TrajTheta[71] = 0;//


//    TrajPoints = 11;
////    Reta para Frente:
//        TrajX[0] = 0;
//        TrajY[0] = 0.0000;
//        TrajTheta[0] = 0;//
//        TrajX[1] = 0.1;
//        TrajY[1] = 0;
//        TrajTheta[1] = 0;//
//        TrajX[2] = 0.2;
//        TrajY[2] = 0;
//        TrajTheta[2] = 0;//
//        TrajX[3] = 0.3;
//        TrajY[3] = 0;
//        TrajTheta[3] = 0;//
//        TrajX[4] = 0.4;
//        TrajY[4] = 0;
//        TrajTheta[4] = 0;//
//        TrajX[5] = 0.5;
//        TrajY[5] = 0;
//        TrajTheta[5] = 0;//
//        TrajX[6] = 0.6;
//        TrajY[6] = 0;
//        TrajTheta[6] = 0;//
//        TrajX[7] = 0.7;
//        TrajY[7] = 0;
//        TrajTheta[7] = 0;//
//        TrajX[8] = 0.8;
//        TrajY[8] = 0;
//        TrajTheta[8] = 0;//
//        TrajX[9] = 0.9;
//        TrajY[9] = 0;
//        TrajTheta[9] = 0;//
//        TrajX[10] = 1;
//        TrajY[10] = 0;
//        TrajTheta[10] = 0;//

    /*------------------------------------------------*/

    xr = yr = theta = 0;
    xr_odom = yr_odom = theta_odom = 0;

    Vref[0] = Vref[1] = Vref[2] = 0;

    // Add your ros communications here.
    start();

	port = device;
	std::cout << "Controller started\n";
	
	return true;
}

void Controller::run()
{
    /*--------------------------------*/
	float aux;

    ros::NodeHandle n;
//    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Subscriber sub = n.subscribe("person_tag", 1000, chatterCallback);
//      ros::Subscriber sub = n.subscribe("tag_detections_pose", 1000, chatterCallback);

    ros::Rate loop_rate(16.667);

    QTime t1,t2;
    t1.start();
    t2.start();

	while ( ros::ok() )
	{
//        std_msgs::String msg;

//               std::stringstream ss;
//               ss << "hello world";
//          msg.data = ss.str();

//        chatter_pub.publish(msg);
//        ROS_INFO("%s", msg.data.c_str());

        if(!enable)
        {
            port->clearSerialData(0);
            t1.restart();
            t2.restart();
        }
        else {
            //Aqui chamar função para leitura serial
            if(readSerial()) {
                publisher(t1.restart());
            }
            //else {
                //port->clearSerialData(0);
            //}

            //t.restart();

               //if( Vref[0] <= 0.5)
                    //Vref[1] = 0.5;
                old_vel[0] = vel[0];
                old_vel[1] = vel[1];
                old_vel[2] = vel[2];
                //O robô envia RPM *10 --> dividindo por 10 e dividindo por 60 para converter em voltas por seg
                //Depois multiplica por 2*PI para achar em rad/s
                //Velocidade escalar das rodas
                velrad[0] = (pkg_data.m1_velocity)*0.01047197;
                velrad[1] = (pkg_data.m2_velocity)*0.01047197;
                velrad[2] = (pkg_data.m3_velocity)*0.01047197;

                //Aqui converter para o sistema de coordenadas do robô
                //vel[0] = 0*vel[0] + 0.5774*vel[1] - 0.5774*vel[2];
                //vel[1] = -0.6667*vel[0] + 0.3333*vel[1] + 0.3333*vel[2];
                //vel[2] = 3.3333*vel[0] + 3.3333*vel[1] + 3.3333*vel[2];
                //Multiplica a matriz acima comentada por 0,0505
                //para obter a vel linear a partir de velrad
                vel[0] = 0*velrad[0] + 0.0292*velrad[1] - 0.0292*velrad[2];
                vel[1] = -0.0337*velrad[0] + 0.0168*velrad[1] + 0.0168*velrad[2];
                vel[2] = 0.1683*velrad[0] + 0.1683*velrad[1] + 0.1683*velrad[2];

                //Controlador Remoto
                if(true) {

                    trajetoria(t2.restart());

//                    optmum_predictor();
                    smith_predictor();

                    U[0] = dU[0] + U[0];
                    U[1] = dU[1] + U[1];//1.5;
                    U[2] = dU[2] + U[2];//-1.5;
                    //Convertendo para PWM
                    PWM[3] = 0;

                   //Aqui eh preciso converter de tensão para PWM
                   aux = 255-(255/6)*(6-U[0]);
                    if(aux<0) {
                        aux = aux*(-1);
                        PWM[3] += 1;
                    }
                    PWM[0] = (unsigned char) aux;

                    aux = 255-(255/6)*(6-U[1]);
                    if(aux<0) {
                        aux = aux*(-1);
                        PWM[3] += 2;
                    }
                    PWM[1] = (unsigned char) aux;

                    aux = 255-(255/6)*(6-U[2]);
                    if(aux<0) {
                        aux = aux*(-1);
                        PWM[3] += 4;
                    }
                    PWM[2] = (unsigned char) aux;

                    //publisher(t1.restart());
                    sC.serialSend("13A20040B09872", 2, PWM, 4, port->getFd());

                }
                //Controlador Embarcado
                else {

                    trajetoria(t2.restart());

                    char a[7], b;
                    int v,vn,w;
                    b = 0;

                    v = (trunc(100*Vref[0]));
                    vn = (trunc(100*Vref[1]));
                    w = (trunc(100*Vref[2]));

                    if(v<0) {
                        v = -1*v;
                        b +=1;
                    }

                    if(vn<0) {
                        vn = -1*vn;
                        b +=2;
                    }

                    if(w<0) {
                        w = -1*w;
                        b +=4;
                    }

                    a[0] = (char) ((0xff00 & v) >> 8);
                    a[1] = (char) (0xff & v);

                    a[2] = (char) ((0xff00 & vn) >> 8);
                    a[3] = (char) (0xff & vn);

                    a[4] = (char) ((0xff00 & w) >> 8);
                    a[5] = (char) (0xff & w);

                    a[6] = b;
                    sC.serialSend("13A20040B09872", 5, a, 7, port->getFd());
                }

                //std::cout << t.restart() << std::endl;

		}

		ros::spinOnce();
		loop_rate.sleep();
	}

	std::cout << "Ros shutdown, proceeding to close the controller." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

bool Controller::readSerial(){

    std_msgs::String msg;
    std::stringstream ss;
    memset(rx_buffer, 0, sizeof rx_buffer);

    bool error = false;
    fd_set readfs;
    struct timeval Timeout;

    FD_ZERO(&readfs);
    FD_SET(port->getFd(), &readfs);


    /* set timeout value within input loop */
    Timeout.tv_usec = 150000;  /* microseconds */
    Timeout.tv_sec  = 0;  /* seconds */
    //std::cout << "2" << std::endl;

    int ret = select(port->getFd()+1, &readfs, NULL, NULL, &Timeout);
    //std::cout << "asfsdf " << ret << " fsdfsdsfd" << std::endl;

    if(ret) {

        //std::cout << "3" << std::endl;

        int nr = read(port->getFd(), &rx_buffer , sizeof rx_buffer);

        //std::cout << "4" << std::endl;

        if(nr > -1)  {

           if(nr!=RX_BUFFER_SIZE) {
               ss << "ERROR - Buffer Size" << std::endl;
               error = true;
           }
           else if(rx_buffer[0]!=0x7E){ //Testa Delimitador de Inicio de Mensagem
               ss << "ERROR - Starter Delimiter" << std::endl;
               error = true;
           }
           else if(rx_buffer[2]!=(RX_BUFFER_SIZE-4)) { //Testa Tamanho da msg maior que 14 (tamanho do cabeçalho)
               ss << "ERROR - Msg Size" << std::endl;
               error = true;
           }
           else if(rx_buffer[15]!=1){ //Testa Comando igual a 1
               ss << "ERROR - Command" << std::endl;
               error = true;
           }
           else if(((char) SerialCommunication::checkSum(&rx_buffer[3],(int) rx_buffer[2]))!=rx_buffer[RX_BUFFER_SIZE-1]){ //Verifica Checksum
               ss << "ERROR - Buffer Size" << std::endl;
               error = true;
           }
           else {

               //Clear para limpa buffer
               //port->clearSerialData(0);
               //Tudo ocorreu bem na leitura
               return true;

           }

           if(error) {
               error = false;
               msg.data = ss.str();
               log(Error,msg.data);
           }

       }

       else {
           ss << "Error reading: " << nr << " " << errno << " " << strerror(errno) << std::endl;
           msg.data = ss.str();
           log(Error,msg.data);
       }
    }
    else
    {
        ss << "Error: Timeout" << std::endl;
        msg.data = ss.str();
        log(Error,msg.data);
    }

    //std::cout << "5" << std::endl;

    //Clear para limpa buffer
    //port->clearSerialData(0);

    return false;
}

void Controller::publisher(int dt)
{
		
	int16_t m_velocity = (((int) (unsigned char) rx_buffer[16])*256 + ((int) (unsigned char) rx_buffer[17]));
	pkg_data.m1_velocity = (0x01 & ((int) rx_buffer[36]))?m_velocity:(-1*m_velocity);
	m_velocity = (((int) (unsigned char) rx_buffer[18])*256 + ((int) (unsigned char) rx_buffer[19]));
	pkg_data.m2_velocity = (0x02 & ((int) rx_buffer[36]))?m_velocity:(-1*m_velocity);
	m_velocity = (((int) (unsigned char) rx_buffer[20])*256 + ((int) (unsigned char) rx_buffer[21]));
	pkg_data.m3_velocity = (0x04 & ((int) rx_buffer[36]))?m_velocity:(-1*m_velocity);
	pkg_data.m1_current = ((int) (unsigned char) rx_buffer[22])*256 + ((int) (unsigned char) rx_buffer[23]);
	pkg_data.m2_current = ((int) (unsigned char) rx_buffer[24])*256 + ((int) (unsigned char) rx_buffer[25]);
	pkg_data.m3_current = ((int) (unsigned char) rx_buffer[26])*256 + ((int) (unsigned char) rx_buffer[27]);
    pkg_data.x_acelleration = ((int) (unsigned char) rx_buffer[28])*256 + ((int) (unsigned char) rx_buffer[29]);
	pkg_data.y_acelleration = ((int) (unsigned char) rx_buffer[30])*256 + ((int) (unsigned char) rx_buffer[31]);
	pkg_data.angular_velocity = ((int) (unsigned char) rx_buffer[32])*256 + ((int) (unsigned char) rx_buffer[33]);
	pkg_data.compass = ((int) (unsigned char) rx_buffer[34])*256 + ((int) (unsigned char) rx_buffer[35]);
	pkg_data.m1_dutycycle = (int) (unsigned char) rx_buffer[37];
	pkg_data.m2_dutycycle = (int) (unsigned char) rx_buffer[38];
	pkg_data.m3_dutycycle = (int) (unsigned char) rx_buffer[39];
	int16_t m_setpoint = (((int) (unsigned char) rx_buffer[40])*256 + ((int) (unsigned char) rx_buffer[41]));
	pkg_data.m1_setpoint = (0x01 & ((int) rx_buffer[46]))?m_setpoint:(-1*m_setpoint);
	m_setpoint = (((int) (unsigned char) rx_buffer[42])*256 + ((int) (unsigned char) rx_buffer[43]));
	pkg_data.m2_setpoint = (0x02 & ((int) rx_buffer[46]))?m_setpoint:(-1*m_setpoint);
	m_setpoint = (((int) (unsigned char) rx_buffer[44])*256 + ((int) (unsigned char) rx_buffer[45]));
	pkg_data.m3_setpoint = (0x04 & ((int) rx_buffer[46]))?m_setpoint:(-1*m_setpoint);
	pkg_data.m1_inc_control_signal = dU[0];
	pkg_data.m2_inc_control_signal = dU[1];
	pkg_data.m3_inc_control_signal = dU[2];
	pkg_data.m1_control_signal = U[0];
	pkg_data.m2_control_signal = U[1];
	pkg_data.m3_control_signal = U[2];
	pkg_data.V = vel[0];
    pkg_data.Vn = vel[1];
    pkg_data.W = vel[2];
	pkg_data.delta_time = dt;
    pkg_data.X_robot = xr;
    pkg_data.Y_robot = yr;
    pkg_data.Theta_robot = theta;
    pkg_data.Vref = Vref[0];
    pkg_data.Vnref = Vref[1];
    pkg_data.Wref = Vref[2];
    pkg_data.X_robot_Odom = xr_odom;
    pkg_data.Y_robot_Odom = yr_odom;
    pkg_data.Theta_robot_Odom = theta_odom;
    pkg_data.X_v1 = xv1;
    pkg_data.Y_v1= yv1;
    pkg_data.Theta_v1= thetav1;
    pkg_data.id_v1= idv1;
    pkg_data.X_v2 = xv2;
    pkg_data.Y_v2= yv2;
    pkg_data.id_v2= idv2;
	
	Q_EMIT updateList();

}

void Controller::smith_predictor()
{

    Mat QSI;

	old_x[0] = x[0];
	old_x[1] = x[1];
	old_x[2] = x[2];

	//Encontrando o erro entre os valores lidos e os valores do modelo
	difvel[0] = vel[0] - velm[0];
	difvel[1] = vel[1] - velm[1];
	difvel[2] = vel[2] - velm[2];		
	
	//Calculando Novas Velocidades do modelo
	new_velm[0] = Ad[0][0]*velm[0] + Ad[0][1]*velm[1] + Ad[0][2]*velm[2];
	new_velm[0] += Bd[0][0]*U[0] + Bd[0][1]*U[1] + Bd[0][2]*U[2];
    //new_velm[0] += velm<0?-Kd[0]:Kd[0];
    //new_velm[0] += velm<0?-(Gd[0]*exp(-abs(velm[0]))):(Gd[0]*exp(-abs(velm[0])));
	
	new_velm[1] = Ad[1][0]*velm[0] + Ad[1][1]*velm[1] + Ad[1][2]*velm[2];
	new_velm[1] += Bd[1][0]*U[0] + Bd[1][1]*U[1] + Bd[1][2]*U[2];
    //new_velm[1] += velm<0?-Kd[1]:Kd[1];
    //new_velm[1] += velm<0?-(Gd[1]*exp(-abs(velm[1]))):(Gd[1]*exp(-abs(velm[1])));

	new_velm[2] = Ad[2][0]*velm[0] + Ad[2][1]*velm[1] + Ad[2][2]*velm[2];
	new_velm[2] += Bd[2][0]*U[0] + Bd[2][1]*U[1] + Bd[2][2]*U[2];
    //new_velm[2] += velm<0?-Kd[2]:Kd[2];
    //new_velm[2] += velm<0?-(Gd[2]*exp(-abs(velm[2]))):(Gd[2]*exp(-abs(velm[2])));
	
	velm[0] = new_velm[0];
	velm[1] = new_velm[1];
	velm[2] = new_velm[2];
	
	//Filtro
    xFiltrado[0] = difvel[0]*(1-alpha) +alpha*xFiltrado[0];
    xFiltrado[1] = difvel[1]*(1-alpha) +alpha*xFiltrado[1];
    xFiltrado[2] = difvel[2]*(1-alpha) +alpha*xFiltrado[2];
	
	//Encontrando o vetor de estados após filtragem
	x[0] = velm[0] + xFiltrado[0];
	x[1] = velm[1] + xFiltrado[1];
	x[2] = velm[2] + xFiltrado[2];

    QSI = (cv::Mat_<float>(6,1) << 0, 0, 0, 0, 0, 0);

    QSI.at<float>(0,0)= x[0]-old_x[0];
    QSI.at<float>(1,0)= x[1]-old_x[1];
    QSI.at<float>(2,0)= x[2]-old_x[2];
    QSI.at<float>(3,0)= x[0];
    QSI.at<float>(4,0)= x[1];
    QSI.at<float>(5,0)= x[2];
	

    //print(QSI,1);
    //cout <<"\n";
    //print(W,1);
    //cout <<"Ref = \n"<<Vref[0]<<" "<<Vref[1]<<" "<<Vref[2]<<"\n\n";

    //Calculando a ação de controle preditivo sem restrições
    Mat K = ((BB.t()*CC.t()*Q.t()*CC*BB+R).inv())*(BB.t()*CC.t()*Q.t());
    //K = K.inv()*BB.t()*CC.t()*Q.t()*(W-CC*AA*QSI);

    //cout << K.cols << " " << K.rows << " " << AA.cols << " " << AA.rows << "\n";

    //print(K*CC*AA,5);

    K = K*(W-CC*AA*QSI);

    //cout << K.cols << " " << K.rows << "\n";

    dU[0] = K.at<float>(0,0);
    dU[1] = K.at<float>(1,0);
    dU[2] = K.at<float>(2,0);

    //Calculando a ação de controle através do uso do LQR
    //dU[0] = -Kdlqr[0][0]*(x[0]-old_x[0]) - Kdlqr[0][1]*(x[1]- old_x[1]) - Kdlqr[0][2]*(x[2]-old_x[2]);
    //dU[0] += Kdlqr[0][3]*(Vref[0] - x[0]) + Kdlqr[0][4]*(Vref[1] - x[1]) + Kdlqr[0][5]*(Vref[2] - x[2]);

    //dU[1] = -Kdlqr[1][0]*(x[0]-old_x[0]) - Kdlqr[1][1]*(x[1]- old_x[1]) - Kdlqr[1][2]*(x[2]-old_x[2]);
    //dU[1] += Kdlqr[1][3]*(Vref[0] - x[0]) + Kdlqr[1][4]*(Vref[1] - x[1]) + Kdlqr[1][5]*(Vref[2] - x[2]);

    //dU[2] = -Kdlqr[2][0]*(x[0]-old_x[0]) - Kdlqr[2][1]*(x[1]- old_x[1]) - Kdlqr[2][2]*(x[2]-old_x[2]);
    //dU[2] += Kdlqr[2][3]*(Vref[0] - x[0]) + Kdlqr[2][4]*(Vref[1] - x[1]) + Kdlqr[2][5]*(Vref[2] - x[2]);

    QSI.release();
    K.release();

}

void Controller::optmum_predictor()
{

    Mat QSI;

    //Encontrando o vetor de estados x'(k+1|k)
    x[0] = Ag[0][0]*(vel[0]-old_vel[0]) + Ag[0][1]*(vel[1]- old_vel[1]) + Ag[0][2]*(vel[2]-old_vel[2]);
    x[0] += Ag[0][3]*(vel[0]) + Ag[0][4]*(vel[1]) + Ag[0][5]*(vel[2]);
    x[0] += Bg[0][0]*dU[0] + Bg[0][1]*dU[1] + Bg[0][2]*dU[2];

    x[1] = Ag[1][0]*(vel[0]-old_vel[0]) + Ag[1][1]*(vel[1]- old_vel[1]) + Ag[1][2]*(vel[2]-old_vel[2]);
    x[1] += Ag[1][3]*(vel[0]) + Ag[1][4]*(vel[1]) + Ag[1][5]*(vel[2]);
    x[1] += Bg[1][0]*dU[0] + Bg[1][1]*dU[1] + Bg[1][2]*dU[2];

    x[2] = Ag[2][0]*(vel[0]-old_vel[0]) + Ag[2][1]*(vel[1]- old_vel[1]) + Ag[2][2]*(vel[2]-old_vel[2]);
    x[2] += Ag[2][3]*(vel[0]) + Ag[2][4]*(vel[1]) + Ag[2][5]*(vel[2]);
    x[2] += Bg[2][0]*dU[0] + Bg[2][1]*dU[1] + Bg[2][2]*dU[2];

    x[3] = Ag[3][0]*(vel[0]-old_vel[0]) + Ag[3][1]*(vel[1]- old_vel[1]) + Ag[3][2]*(vel[2]-old_vel[2]);
    x[3] += Ag[3][3]*(vel[0]) + Ag[3][4]*(vel[1]) + Ag[3][5]*(vel[2]);
    x[3] += Bg[3][0]*dU[0] + Bg[3][1]*dU[1] + Bg[3][2]*dU[2];

    x[4] = Ag[4][0]*(vel[0]-old_vel[0]) + Ag[4][1]*(vel[1]- old_vel[1]) + Ag[4][2]*(vel[2]-old_vel[2]);
    x[4] += Ag[4][3]*(vel[0]) + Ag[4][4]*(vel[1]) + Ag[4][5]*(vel[2]);
    x[4] += Bg[4][0]*dU[0] + Bg[4][1]*dU[1] + Bg[4][2]*dU[2];

    x[5] = Ag[5][0]*(vel[0]-old_vel[0]) + Ag[5][1]*(vel[1]- old_vel[1]) + Ag[5][2]*(vel[2]-old_vel[2]);
    x[5] += Ag[5][3]*(vel[0]) + Ag[5][4]*(vel[1]) + Ag[5][5]*(vel[2]);
    x[5] += Bg[5][0]*dU[0] + Bg[5][1]*dU[1] + Bg[5][2]*dU[2];

    QSI = (cv::Mat_<float>(6,1) << 0, 0, 0, 0, 0, 0);

    QSI.at<float>(0,0)= x[0];
    QSI.at<float>(1,0)= x[1];
    QSI.at<float>(2,0)= x[2];
    QSI.at<float>(3,0)= x[3];
    QSI.at<float>(4,0)= x[4];
    QSI.at<float>(5,0)= x[5];

    Mat K = ((BB.t()*CC.t()*Q.t()*CC*BB+R).inv())*(BB.t()*CC.t()*Q.t());

    K = K*(W-CC*AA*QSI);

    dU[0] = K.at<float>(0,0);
    dU[1] = K.at<float>(1,0);
    dU[2] = K.at<float>(2,0);

    //Calculando a ação de controle utilizando o LQR
    //dU[0] = -Kdlqr[0][0]*x[0] - Kdlqr[0][1]*x[1] - Kdlqr[0][2]*x[2];
    //dU[0] += Kdlqr[0][3]*(Vref[0] - x[3]) + Kdlqr[0][4]*(Vref[1] - x[4]) + Kdlqr[0][5]*(Vref[2] - x[5]);

    //dU[1] = -Kdlqr[1][0]*x[0] - Kdlqr[1][1]*x[1] - Kdlqr[1][2]*x[2];
    //dU[1] += Kdlqr[1][3]*(Vref[0] - x[3]) + Kdlqr[1][4]*(Vref[1] - x[4]) + Kdlqr[1][5]*(Vref[2] - x[5]);

    //dU[2] = -Kdlqr[2][0]*x[0] - Kdlqr[2][1]*x[1] - Kdlqr[2][2]*x[2];
    //dU[2] += Kdlqr[2][3]*(Vref[0] - x[3]) + Kdlqr[2][4]*(Vref[1] - x[4]) + Kdlqr[2][5]*(Vref[2] - x[5]);

    QSI.release();
    K.release();

}

void Controller::log( const LogLevel &level, const std::string &msg)
{
    logging_model.insertRows(logging_model.rowCount(),1);
    std::stringstream logging_model_msg;
    switch ( level )
    {
        case(Debug) :
        {
                ROS_DEBUG_STREAM(msg);
                logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Info) :
        {
                ROS_INFO_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Warn) :
        {
                ROS_WARN_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Error) :
        {
                ROS_ERROR_STREAM(msg);
                logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Fatal) :
        {
                ROS_FATAL_STREAM(msg);
                logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                break;
        }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
    Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

void Controller::trajetoria(int time) {

    double t = time/1000.0;
   if(newAprilTag==true){
        cv::Mat dados = ProcessaDados();
        cv::Mat aux;
        aux = Robo_Tag(dados, velrad[0], velrad[1], velrad[2], t, flagI);

        // Primeira iteração do filtro
        if(flagI==true)
            flagI = false;
        // Posições estimadas
        xr = mi.at<double>(0,0);
        yr = mi.at<double>(1,0);
        theta = mi.at<double>(2,0);
        newAprilTag = false;
        // Memória dos tags
        xv1 = dados.at<double>(0,0);
        yv1 = dados.at<double>(0,1);
        thetav1 = dados.at<double>(0,2);
        idv1 = dados.at<double>(0,3);

        if(dados.rows > 1){
            xv2 = dados.at<double>(1,0);
            yv2 = dados.at<double>(1,1);
            thetav2 = dados.at<double>(1,2);
            idv2 = dados.at<double>(1,3);
        }else{
            xv2 = 0;
            yv2 = 0;
            thetav2 = 0;
            idv2 = 0;
        }

    }else{
        cv::Mat aux;
        aux  = Robo_Odometria(velrad[0], velrad[1], velrad[2], t, flagI);
        // Primeira iteração do filtro
        if(flagI==true)
            flagI = false;
        // Posições estimadas
        xr = aux.at<double>(0,0);
        yr = aux.at<double>(1,0);
        theta = aux.at<double>(2,0);
        // Memória dos tags
        xv1 = 0;
        yv1 = 0;
        thetav1 = 0;
        idv1 = 0;
        xv2 = 0;
        yv2 = 0;
        thetav2 = 0;
        idv2 = 0;
  }

   xr_odom += (vel[0]*cos(theta_odom) - vel[1]*sin(theta_odom))*t;//0.05;
   yr_odom += (vel[0]*sin(theta_odom) + vel[1]*cos(theta_odom))*t;//0.05;
   theta_odom += vel[2]*t;//0.05;

//   xr = xr_odom;
//   yr = yr_odom;
//   theta = theta_odom;

    TrajectoryControl(xr, yr, theta);

    W.release();

    if(TrajOK==1) {
        W = Mat::zeros(3*HP, 1, CV_32F);

        Vref[0] = 0;
        Vref[1] = 0;
        Vref[2] = 0;
    }
    else {
        W.create(0,0,CV_32F);

        for(int i = 0; i < HP; i++){
                int z;

                if(Index+i<TrajPoints-1)
                    z = Index+i;
                else
                    z = TrajPoints-2;

                Mat r = referenciaFutura(z);
                W.push_back(r);
        }
        //Ainda utilizado devido ao log
        Vref[0] = W.at<float>(0,0);
        Vref[1] = W.at<float>(1,0);
        Vref[2] = W.at<float>(2,0);
    }
}

Mat Controller::referenciaFutura(int index){

    float e[3];
    float phi;
    float Vnav = 0.15;
// MUDEI AQUI
    phi = atan2((TrajY[index+1] - yr_odom),(TrajX[index+1] - xr_odom));

    e[0] = Vnav*cos(phi);
    e[1] = Vnav*sin(phi);
    e[2] = TrajTheta[index+1] - theta;// - atan2(TrajY[Index+1],TrajX[Index+1]) - PI/2 - theta;// atan2(TrajY[Index+1],TrajX[Index+1]) - theta;//- theta

    while (e[2]>PI) e[2] -= 2*PI;
    while (e[2]<=-PI) e[2] += 2*PI;

    if (fabs(e[2]) < Rad(0.005))
        e[2] = 0;

    Mat r = (cv::Mat_<float>(3,1) << cos(theta)*e[0] + sin(theta)*e[1],
                                    -sin(theta)*e[0] + cos(theta)*e[1],
                                                   e[2]);

//    Mat r = (cv::Mat_<float>(3,1) << 0.3, 0, 0);

    return r;
}

void Controller::TrajectoryControl(double x, double y, double theta)
{

double ang;

 ang = fabs(DiffAngle(atan2((y-TrajY[Index+1]),(x-TrajX[Index+1])),atan2((TrajY[Index+1]-TrajY[Index]),(TrajX[Index+1]-TrajX[Index]))));
//cout << ang << "  " << TrajOK << "    " << Index << "    " << PI/2 <<"\n";
 if (ang < PI/2) {

   if (Index == TrajPoints-1) {
       TrajOK=1;
        //cout << "a1 \n\n";
   }
   else {
       Index++;
       cout << Index << "  " <<TrajPoints-1 <<" \n\n";
   }

    if (Index == TrajPoints-2) {
      if (Dist((x-TrajX[TrajPoints-1]),(y-TrajY[TrajPoints-1])) < 0.1) {
        TrajOK=1;
        //cout << "a2 \n\n";
      }
    }

 }

}

double Controller::DiffAngle(double a1, double a2)
{
    double result;

    result = a1-a2;
    if (result<0) result = -fmod(-result,2*PI);
    if (result<-PI) result = result+2*PI;
        else result = fmod(result,2*PI);
    if (result>PI) result = result-2*PI;

    return result;
}

double Controller::Dist(double x, double y)
{
  return sqrt(x*x+y*y);
}

double Controller::Rad(double xw){
  return xw*(PI/180);
}

void Controller::print(Mat mat, int prec) {

    std_msgs::String msg;
    std::stringstream ss;

    for(int i=0; i<mat.size().height; i++)
    {
        ss << "[";
        for(int j=0; j<mat.size().width; j++)
        {
            ss << std::setprecision(prec) << mat.at<float>(i,j);
            if(j != mat.size().width-1)
                ss << ", ";
            else
                ss << "]" << endl;
        }
    }

    ss << "\n\n";

    msg.data = ss.str();
    log(Info,msg.data);

}


/*********************
** AprilTags
**********************/

/*------------------------------------Constantes-----------------------------------*/
const double pi = 3.14159265358979323846;
const double r = 0.0505; 					  // Raio da roda (m)
const double l = 0.1;                         // Raio do robô (m)

/*-------------------------------------Funções-------------------------------------*/
/*---------------------------------------de----------------------------------------*/
/*------------------------------------Uso Geral------------------------------------*/

/*  Normaliza o ângulo para o internalo [-pi,pi]                                   */
double Controller::standardRad(double t){
    if (t >= 0.)
        t = fmod(t+pi, 2*pi) - pi;
    else
        t = fmod(t-pi, -2*pi) + pi;
    return t;
}

/*  Converte as matrizes de rotação para os ângulos de Euler                       */
void Controller::wRo_to_euler(const Mat& wRo, double& yaw, double& pitch, double& roll){
    double ang = atan2(wRo.at<double>(1,0), wRo.at<double>(0,0));
    yaw = standardRad(ang);
    double c = cos(yaw);
    double s = sin(yaw);
    pitch = standardRad(atan2(-wRo.at<double>(2,0), wRo.at<double>(0,0)*c + wRo.at<double>(1,0)*s));
    roll  = standardRad(atan2(wRo.at<double>(0,2)*s - wRo.at<double>(1,2)*c, -wRo.at<double>(0,1)*s + wRo.at<double>(1,1)*c));
}

/* Função que calcula o produto de kronecker                                       */
Mat Controller::Kron(const Mat& A, const Mat& B){
    Mat temp, res;
    for (int i=0; i<(B.rows); i++)
    {
    for (int j=0; j<(A.rows); j++)
    {
        for(int k = 0; k<(B.cols); k++){
        Mat a = A.row(j) * B.at<double>(i, k);
        if(k>0)
          hconcat(temp, a, temp);
        else
          temp = a;
        }
        res.push_back(temp);
    }
    }
    return res;
}

/*-------------------------------------Funções-------------------------------------*/
/*---------------------------------------de----------------------------------------*/
/*------------------------------------Controle-------------------------------------*/

/* Kalman( [x;y;theta], W1, W2, W3, mi_a, sigma_a) implementa um filtro de Kalman
    estendido baseado no modelo de um robô omnid. tendo como entradas as imforma-
    ções de odometria. No filtro é feita a fusão entre os dados visuais e  odome-
    tria. Instancia com informação visual                                         */
Mat Controller::Kalman(const Mat& Z, const double& W1, const double& W2, const double& W3,
                          const Mat& mi_a, const Mat& sigma_a, const double Ts){
    //Definição de variáveis
    double x_est, y_est, theta_est;
    double g13, g23, v11, v12, v13, v21, v22, v23, v31, v32, v33;
    double m, n;
    // Quantidade dados
    m = Z.rows;
    // Covariância do Sensor Visual
    double err_x = 9.2;                                                       // (m)
    double err_y = 9.5;                                                       // (m)
    double err_theta = 100;                                          // 5.1566 graus

//    double err_x = 0.001;
//    double err_y = 0.001;
//    double err_theta = 0.001;

    // Matriz de covariancia
    Mat qk = (Mat_<double>(3,3) << err_x*err_x,    0,             0,
                                        0   , err_y*err_y,        0,
                                        0   ,      0   , err_theta*err_theta);
    Mat Imn = Mat::eye( m/4, m/4, CV_64F);
    Mat Qk = Kron(qk,Imn);
    // Estados iniciais
    double x_esta = mi_a.at<double>(0,0);
    double y_esta = mi_a.at<double>(1,0);
    double theta_esta = mi_a.at<double>(2,0);
    // Deslocamento angular baseado na velocidade (Não nesse caso)
    double W1_est = W1*Ts;
    double W2_est = W2*Ts;
    double W3_est = W3*Ts;
    // Atualiza o modelo
    x_est = x_esta + (r/3)*(2*sin(theta_esta)*W1_est + (sqrt(3)*cos(theta_esta) - sin(theta_esta))*W2_est
                                                     + (-sqrt(3)*cos(theta_esta) - sin(theta_esta))*W3_est);
    y_est = y_esta + (r/3)*(-2*cos(theta_esta)*W1_est + (sqrt(3)*sin(theta_esta) + cos(theta_esta))*W2_est
                                                      + (-sqrt(3)*sin(theta_esta) + cos(theta_esta))*W3_est);
    theta_est = theta_esta + (r/3)*((1/l)*W1_est + (1/l)*W2_est + (1/l)*W3_est);
    // Calcula a predição da média dos estados
    Mat mi_barra = (Mat_<double>(3,1) <<   x_est,
                                           y_est,
                                         theta_est);
    // Cálculo das matrizes de Predição da Covariância
    g13 = (r/3)*(2*cos(theta_esta)*W1_est + (-sqrt(3)*sin(theta_esta) - cos(theta_esta))*W2_est
                                          + (sqrt(3)*sin(theta_esta) - cos(theta_esta))*W3_est);

    g23 = (r/3)*(2*sin(theta_esta)*W1_est + (sqrt(3)*cos(theta_esta) - sin(theta_esta))*W2_est
                                          + (-sqrt(3)*cos(theta_esta) - sin(theta_esta))*W3_est);

    v11 = (r/3)*2*sin(theta_esta);
    v12 = (r/3)*(sqrt(3)*cos(theta_esta) - sin(theta_esta));
    v13 = (r/3)*(-sqrt(3)*cos(theta_esta) - sin(theta_esta));
    v21 = (r/3)*(-2)*cos(theta_esta);
    v22 = (r/3)*(sqrt(3)*sin(theta_esta) + cos(theta_esta));
    v23 = (r/3)*(-sqrt(3)*sin(theta_esta) + cos(theta_esta));
    v31 = (r/3)/l;
    v32 = (r/3)/l;
    v33 = (r/3)/l;

    // Calcula as matrizes Jacobianas
    Mat Gk = (Mat_<double>(3,3) <<  1, 0, g13,
                                    0, 1, g23,
                                    0, 0,  1  );
    Mat Vk = (Mat_<double>(3,3) << v11,  v12, v13,
                                   v21,  v22, v23,
                                   v31,  v32, v33);
    // Covariância do encoder, considerado proporcional à leitura
    double alfa1 = 0.25;
    double alfa2 = 0.25;
    double alfa3 = 0.25;
    Mat Mk = (Mat_<double>(3,3) << (alfa1*(W1_est))*(alfa1*(W1_est)),             0,                             0,
                                                   0,          (alfa2*abs(W2_est))*(alfa2*(W2_est)),             0,
                                                   0,                             0,          (alfa3*abs(W3_est))*(alfa3*(W3_est)));
    // Predição da variância
    Mat sigma_barra;
    sigma_barra = (Gk*sigma_a*Gk.t()) + (Vk*Mk*Vk.t());
    // Sensor visual modelado como contendo um erro gaussiano e varia da mesma
    // forma que o robô em relação à variação dos estados
    Mat KiHi = (Mat_<double>(3,3) <<  0,0,0,0,0,0,0,0,0);	// Somatório de Ki*Hi
    Mat KiZ = (Mat_<double>(3,1) <<  0,0,0);		  // Somatório de Ki*(Z - zi)
    for(int i=0; i<m/4; i++){
        double deltai_x = Z.at<double>(i*3,0) - x_est;
        double deltai_y = Z.at<double>(i*3 + 1,0) - y_est;
        Mat deltai = (Mat_<double>(2,1) << deltai_x, deltai_y);
        double q = norm(deltai,NORM_L2);
        // Modelo do sensor visual
        Mat zi = (Mat_<double>(3,1) <<                     sqrt(q),
                                       standardRad(atan2(deltai_y, deltai_x)) - theta_est,
                                                  Z.at<double>(i*3 + 2,0)		 );
        Mat Hi = (Mat_<double>(3,3) <<  deltai_x/(sqrt(q)), deltai_y/(sqrt(q)),   0,
                                            deltai_y/q,         deltai_x/q,     -1/q,
                                               0,                  0,            1  );

        // Ganho de Kalman
        Mat Aux;
        Aux = (Hi*sigma_barra*Hi.t() + qk);
        Mat Ki;
        Ki = sigma_barra*Hi.t()*Aux.inv();
        // Somatórios
        KiHi = KiHi + Ki*Hi;
        Mat Aux2;
        Z.rowRange(i*3,i*3+3).copyTo(Aux2);
        KiZ = KiZ + Ki*(Aux2 - zi);
    }
    // Atualizações
    Mat I = (Mat_<double>(3,3) <<  1, 0, 0,
                                   0, 1, 0,
                                   0, 0, 1 );
    Mat sigma = (I - KiHi)*sigma_barra;
//    cout <<"\n KiZ: "<< KiZ << endl;
//    cout <<"\n mi_barra : "<< mi_barra  << endl;

    Mat mi = mi_barra + KiZ;
     cout <<"\n mi: "<< mi  << endl;

    // Cria a matriz de saídas
    Mat Res(3, 4, CV_64F);
    hconcat(mi, sigma, Res);
    return Res;
}


/* Odometria( mi_a, W1, W2, W3, sigma_a) implementa  um  filtro de Kalman  esten-
    dido baseado no modelo de um robô diferencial tendo como entradas as imforma-
    ções de odometria. No filtro é feita a fusão entre os dados visuais e  odome-
    tria. Instancia sem informação visual                                         */
Mat Controller::Odometria( const Mat& mi_a, const double& W1, const double& W2,
              const double& W3, const Mat& sigma_a, const double Ts){
      //Definição de variáveis
    double x_est, y_est, theta_est;
    double g13, g23, v11, v12, v13, v21, v22, v23, v31, v32, v33;
    // Covariância do Sensor Visual
    double err_x = 9.2;                                                       // (m)
    double err_y = 9.5;                                                       // (m)
    double err_theta = 100;                                          // 5.1566 graus

//    double err_x = 0.001;
//    double err_y = 0.001;
//    double err_theta = 0.001;

    // Matriz de covariancia
    Mat Qk = (Mat_<double>(3,3) << err_x*err_x,    0,             0,
                                        0   , err_y*err_y,        0,
                                        0   ,      0   , err_theta*err_theta);
    // Estados iniciais
    double x_esta = mi_a.at<double>(0,0);
    double y_esta = mi_a.at<double>(1,0);
    double theta_esta = mi_a.at<double>(2,0);
    // Deslocamento angular baseado na velocidade (Não nesse caso)
    double w1_est = W1*Ts;
    double w2_est = W2*Ts;
    double w3_est = W3*Ts;
    // Atualiza o modelo
    x_est = x_esta + (r/3)*(2*sin(theta_esta)*w1_est + ( sqrt(3)*cos(theta_esta) - sin(theta_esta))*w2_est
                                                     + (-sqrt(3)*cos(theta_esta) - sin(theta_esta))*w3_est);
    y_est = y_esta + (r/3)*(-2*cos(theta_esta)*w1_est + ( sqrt(3)*sin(theta_esta) + cos(theta_esta))*w2_est
                                                      + (-sqrt(3)*sin(theta_esta) + cos(theta_esta))*w3_est);
    theta_est = theta_esta + (r/3)*((1/l)*w1_est + (1/l)*w2_est + (1/l)*w3_est);
    // Calcula a predição da média dos estados
    Mat mi_barra = (Mat_<double>(3,1) <<   x_est,
                                           y_est,
                                         theta_est);
    // Cálculo das matrizes de Predição da Covariância
    g13 = (r/3)*(2*cos(theta_esta)*w1_est + (-sqrt(3)*sin(theta_esta) - cos(theta_esta))*w2_est
                                          + ( sqrt(3)*sin(theta_esta) - cos(theta_esta))*w3_est);

    g23 = (r/3)*(2*sin(theta_esta)*w1_est + ( sqrt(3)*cos(theta_esta) - sin(theta_esta))*w2_est
                                          + (-sqrt(3)*cos(theta_esta) - sin(theta_esta))*w3_est);

    v11 = (r/3)*2*sin(theta_esta);
    v12 = (r/3)*(sqrt(3)*cos(theta_esta) - sin(theta_esta));
    v13 = (r/3)*(-sqrt(3)*cos(theta_esta) - sin(theta_esta));
    v21 = (r/3)*(-2)*cos(theta_esta);
    v22 = (r/3)*(sqrt(3)*sin(theta_esta) + cos(theta_esta));
    v23 = (r/3)*(-sqrt(3)*sin(theta_esta) + cos(theta_esta));
    v31 = (r/3)/l;
    v32 = (r/3)/l;
    v33 = (r/3)/l;

    // Calcula as matrizes Jacobianas
    Mat Gk = (Mat_<double>(3,3) <<  1, 0, g13,
                                    0, 1, g23,
                                    0, 0,  1  );
    Mat Vk = (Mat_<double>(3,3) << v11,  v12, v13,
                                   v21,  v22, v23,
                                   v31,  v32, v33);
    // Covariância do encoder, considerado proporcional à leitura
    double alfa1 = 0.25;
    double alfa2 = 0.25;
    double alfa3 = 0.25;
    Mat Mk = (Mat_<double>(3,3) << (alfa1*(w1_est))*(alfa1*(w1_est)),             0,                             0,
                                                   0,             (alfa2*(w2_est))*(alfa2*(w2_est)),             0,
                                                   0,                             0,             (alfa3*(w3_est))*(alfa3*(w3_est)));
    // Predição da variância
    Mat sigma_barra;
    sigma_barra = (Gk*sigma_a*Gk.t()) + (Vk*Mk*Vk.t());

    // Cria a matriz de saídas
    Mat Res(3, 4, CV_64F);
    hconcat(mi_barra, sigma_barra, Res);

    return Res;
}

/*-------------------------------------Funções-------------------------------------*/
/*---------------------------------------de----------------------------------------*/
/*------------------------------------Tratamento-----------------------------------*/

/* Estimação de posição do tag                                                 */
Mat Controller::AjustaDeteccao(const Mat&  Deteccao){
    // Definne Matrizes
    cv::Mat translacao, translacao_A, rotacao, rotacao_A, T, Ti;
    cv::Mat row4 = (Mat_<double>(1,4) <<  0, 0, 0, 1);
    double yaw, pitch, roll, direcao;
    double id = Deteccao.at<double>(3, 3);
    // Separa a translação e a rotação
    Deteccao.rowRange(0,3).col(3).copyTo(translacao_A);
    Deteccao.rowRange(0,3).colRange(0,3).copyTo(rotacao_A);
    // Orienta o referencial para o alvo e não para a câmera
    //                 Convenções
    //     Câmera (z frente, x direita, y baixo)
    //     Objeto (x frente, y esquerda, z cima)
    //     Robô   (x frente, y direita, z baixo)

    // Reorientando a Matriz para que o ponto fixo seja o o-
    // bjeto e não o robô, muda o referencial do sistema.
    hconcat(rotacao_A, translacao_A, T);
    vconcat(T, row4, T);
    // Translação do Tag em relação à câmera
    T.rowRange(0,3).col(3).copyTo(translacao);
    // Ajuste das coordenadas
    cv::Mat MA = (Mat_<double>(3,3) <<  0, 0, -1,
                                        1, 0,  0,
                                        0, 1,  0);
    // Ajuste da translação
    cv::Mat translAjust = MA*translacao;
    cv::Mat F = (Mat_<double>(3,3) <<   1,  0,  0,
                                        0,  1,  0,
                                        0,  0,  1);

    cv::Mat rot = F*rotacao_A;
    wRo_to_euler(rotacao_A, yaw, pitch, roll);
    // Matriz de saída
    cv::Mat Out = (Mat_<double>(1,4) << translAjust.at<double>(0,0),
                                        translAjust.at<double>(1,0),
                                                 -pitch,
                                                   id        );
    // Descomente para escrever informações na tela
//    cout << "\nAlvo: " <<  Out.at<double>(0,3) << endl;
//    cout << "\nx =" << Out.at<double>(0,0)
//         << ", y =" << Out.at<double>(0,1)
//         << ", theta =" << Out.at<double>(0,2)
//         << endl;
        return Out;
}

/* Realiza a translação nas estimações do Tag de acordo com sua Posição        */
void Controller::CompatibilizaCoordenadas(Mat& Dados, const int& i){
    Mat T, T2, Talvo, Ralvo, DadosVelho, DadosNovo;
    double Rot, Rot_ant, Rot_novo;
    int id = (int) Dados.at<double>(i,3);
    // Posição da câmera em relação ao zero
    T = (Mat_<double>(3,3) << 1,  0,   2,
                              0,  1,   0,
                              0,  0,   1);
    switch (id){
        case 1:
        // Posição do alvo no robô
        T2 = (Mat_<double>(3,3) << 1,  0,   0,
                                   0,  1, -0.055,
                                   0,  0,   1);
        Rot = pi/2;
        break;
        case 2:
        // Posição da câmera em relação ao zero
        T2 = (Mat_<double>(3,3) << 1,  0, -0.055,
                                   0,  1,   0,
                                   0,  0,   1);
        Rot = 0;
        break;
        case 3:
        // Posição da câmera em relação ao zero
        T2 = (Mat_<double>(3,3) << 1,  0,   0,
                                   0,  1,-0.055,
                                   0,  0,   1);
        Rot = -pi/2;
        break;
        case 4:
        // Posição da câmera em relação ao zero
        T2 = (Mat_<double>(3,3) << 1,  0, 0.055,
                                   0,  1,   0,
                                   0,  0,   1);
        Rot = +pi;
        break;
        default:
                //cout << "\nErro Tag com id Inválido " << endl;
        break;
    }
    Rot_ant = Dados.at<double>(i,2);
    DadosVelho = (Mat_<double>(3,1) << Dados.at<double>(i,0),
                                       Dados.at<double>(i,1),
                                                 1           );
    Rot_novo = Rot_ant + Rot;

    Ralvo = (Mat_<double>(3,3) << cos(Rot_novo), -sin(Rot_novo),  0,
                                  sin(Rot_novo),  cos(Rot_novo),  0,
                                         0,              0,       1);
    Mat aux = Ralvo*T2;
    Talvo = (Mat_<double>(3,3) <<  1, 0, aux.at<double>(0,2),
                                   0, 1, aux.at<double>(1,2),
                                   0, 0,          1);
    DadosNovo = Talvo*T*DadosVelho;
    Dados.at<double>(i,0) = DadosNovo.at<double>(0,0);
    Dados.at<double>(i,1) = DadosNovo.at<double>(1,0);
    Dados.at<double>(i,2) = standardRad(Rot_ant + Rot);
    // Descomente para escrever informações na tela
//    cout << "\nAlvo: " << id << endl;
//    cout << "\nx =" << Dados.at<double>(i,0)
//         << ", y =" << Dados.at<double>(i,1)
//         << ", theta =" << Dados.at<double>(i,2)
//         << endl;
}

/* Processa as detecções de modo a obter a posição de cada alvo detectado      */
Mat Controller::ProcessaDados() {
    cv::Mat DadosTag;
    int m = pose.rows;                        // Quantidade dados

    for (int i=0; i<m/4; i++){
         cv::Mat Deteccao_i;
         pose.rowRange(i*4,i*4+4).copyTo(Deteccao_i);
         cv::Mat row = AjustaDeteccao(Deteccao_i);
         DadosTag.push_back(row);
    }

    // Função que translada as detecções e impõe a rotação do alvo
    for (int i=0; i<m/4; i++){
        CompatibilizaCoordenadas( DadosTag, i);
    }
    return DadosTag;
}

/* Executa leituras e comandos do robô caso o tag seja detectado               */
Mat Controller::Robo_Tag(const Mat& DadosSensoriais, const double W1, const double W2,
                              const double W3, const double t, bool flagI  ){
    // Inicializa variáveis
    double xest=0, yest=0, theta_est=0;
    cv::Mat Ek, Z;
    // Ajusta os dados dos sensor
    double m = DadosSensoriais.rows;
    for(int i = 0; i < m; i++){
        if(i>0)
        vconcat(Z, DadosSensoriais.row(i).t(), Z);
        else
        Z = DadosSensoriais.row(i).t();
    }
    // Primeira iteração do filtro
    if(flagI==true){
        Ek = (Mat_<double>(3,1) << 0, 0, 0);
        mi = Ek.col(0);
    }
    else{                      // Demais iterações
        Ek = Kalman( Z, W1, W2, W3, mi, sigma,t);
        // Atualiza mi e sigma
        mi = Ek.col(0);
        Ek.colRange(1, 4).copyTo(sigma);
    }
//    cout << "\n Posição Estimada: "<< mi << endl;
    return mi;
}

/* Executa leituras e comandos do robô caso o tag não seja detectado           */
Mat Controller::Robo_Odometria(const double W1, const double W2,
                    const double W3, const double t, const bool flagI){
    Mat Ek;
    if(flagI==true){
        Ek = (Mat_<double>(3,1) <<  0, 0, 0);
        mi = Ek.col(0);
        cout << "\n Iniciou sem um alvo visível \n" << endl;
    }
    else{                      // Demais iterações
        Ek = Odometria( mi, W1, W2, W3, sigma, t);
        // Atualiza mi e Sigma
        mi = Ek.col(0);
        Ek.colRange(1, 4).copyTo(sigma);
        cout << "\n Sem um alvo visível \n" << endl;

    }
    return mi;
}

}  // namespace ros_gui

