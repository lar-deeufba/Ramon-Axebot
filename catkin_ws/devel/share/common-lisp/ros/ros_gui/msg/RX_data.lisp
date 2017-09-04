; Auto-generated. Do not edit!


(cl:in-package ros_gui-msg)


;//! \htmlinclude RX_data.msg.html

(cl:defclass <RX_data> (roslisp-msg-protocol:ros-message)
  ((m1_velocity
    :reader m1_velocity
    :initarg :m1_velocity
    :type cl:fixnum
    :initform 0)
   (m2_velocity
    :reader m2_velocity
    :initarg :m2_velocity
    :type cl:fixnum
    :initform 0)
   (m3_velocity
    :reader m3_velocity
    :initarg :m3_velocity
    :type cl:fixnum
    :initform 0)
   (m1_current
    :reader m1_current
    :initarg :m1_current
    :type cl:fixnum
    :initform 0)
   (m2_current
    :reader m2_current
    :initarg :m2_current
    :type cl:fixnum
    :initform 0)
   (m3_current
    :reader m3_current
    :initarg :m3_current
    :type cl:fixnum
    :initform 0)
   (x_acelleration
    :reader x_acelleration
    :initarg :x_acelleration
    :type cl:fixnum
    :initform 0)
   (y_acelleration
    :reader y_acelleration
    :initarg :y_acelleration
    :type cl:fixnum
    :initform 0)
   (angular_velocity
    :reader angular_velocity
    :initarg :angular_velocity
    :type cl:fixnum
    :initform 0)
   (compass
    :reader compass
    :initarg :compass
    :type cl:fixnum
    :initform 0)
   (m1_dutycycle
    :reader m1_dutycycle
    :initarg :m1_dutycycle
    :type cl:fixnum
    :initform 0)
   (m2_dutycycle
    :reader m2_dutycycle
    :initarg :m2_dutycycle
    :type cl:fixnum
    :initform 0)
   (m3_dutycycle
    :reader m3_dutycycle
    :initarg :m3_dutycycle
    :type cl:fixnum
    :initform 0)
   (m1_setpoint
    :reader m1_setpoint
    :initarg :m1_setpoint
    :type cl:fixnum
    :initform 0)
   (m2_setpoint
    :reader m2_setpoint
    :initarg :m2_setpoint
    :type cl:fixnum
    :initform 0)
   (m3_setpoint
    :reader m3_setpoint
    :initarg :m3_setpoint
    :type cl:fixnum
    :initform 0)
   (m1_inc_control_signal
    :reader m1_inc_control_signal
    :initarg :m1_inc_control_signal
    :type cl:float
    :initform 0.0)
   (m2_inc_control_signal
    :reader m2_inc_control_signal
    :initarg :m2_inc_control_signal
    :type cl:float
    :initform 0.0)
   (m3_inc_control_signal
    :reader m3_inc_control_signal
    :initarg :m3_inc_control_signal
    :type cl:float
    :initform 0.0)
   (m1_control_signal
    :reader m1_control_signal
    :initarg :m1_control_signal
    :type cl:float
    :initform 0.0)
   (m2_control_signal
    :reader m2_control_signal
    :initarg :m2_control_signal
    :type cl:float
    :initform 0.0)
   (m3_control_signal
    :reader m3_control_signal
    :initarg :m3_control_signal
    :type cl:float
    :initform 0.0)
   (V
    :reader V
    :initarg :V
    :type cl:float
    :initform 0.0)
   (Vn
    :reader Vn
    :initarg :Vn
    :type cl:float
    :initform 0.0)
   (W
    :reader W
    :initarg :W
    :type cl:float
    :initform 0.0)
   (delta_time
    :reader delta_time
    :initarg :delta_time
    :type cl:fixnum
    :initform 0)
   (X_robot
    :reader X_robot
    :initarg :X_robot
    :type cl:float
    :initform 0.0)
   (Y_robot
    :reader Y_robot
    :initarg :Y_robot
    :type cl:float
    :initform 0.0)
   (Theta_robot
    :reader Theta_robot
    :initarg :Theta_robot
    :type cl:float
    :initform 0.0)
   (Vref
    :reader Vref
    :initarg :Vref
    :type cl:float
    :initform 0.0)
   (Vnref
    :reader Vnref
    :initarg :Vnref
    :type cl:float
    :initform 0.0)
   (Wref
    :reader Wref
    :initarg :Wref
    :type cl:float
    :initform 0.0)
   (X_robot_Odom
    :reader X_robot_Odom
    :initarg :X_robot_Odom
    :type cl:float
    :initform 0.0)
   (Y_robot_Odom
    :reader Y_robot_Odom
    :initarg :Y_robot_Odom
    :type cl:float
    :initform 0.0)
   (Theta_robot_Odom
    :reader Theta_robot_Odom
    :initarg :Theta_robot_Odom
    :type cl:float
    :initform 0.0)
   (X_v1
    :reader X_v1
    :initarg :X_v1
    :type cl:float
    :initform 0.0)
   (Y_v1
    :reader Y_v1
    :initarg :Y_v1
    :type cl:float
    :initform 0.0)
   (Theta_v1
    :reader Theta_v1
    :initarg :Theta_v1
    :type cl:float
    :initform 0.0)
   (id_v1
    :reader id_v1
    :initarg :id_v1
    :type cl:float
    :initform 0.0)
   (X_v2
    :reader X_v2
    :initarg :X_v2
    :type cl:float
    :initform 0.0)
   (Y_v2
    :reader Y_v2
    :initarg :Y_v2
    :type cl:float
    :initform 0.0)
   (Theta_v2
    :reader Theta_v2
    :initarg :Theta_v2
    :type cl:float
    :initform 0.0)
   (id_v2
    :reader id_v2
    :initarg :id_v2
    :type cl:float
    :initform 0.0))
)

(cl:defclass RX_data (<RX_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RX_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RX_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_gui-msg:<RX_data> is deprecated: use ros_gui-msg:RX_data instead.")))

(cl:ensure-generic-function 'm1_velocity-val :lambda-list '(m))
(cl:defmethod m1_velocity-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_velocity-val is deprecated.  Use ros_gui-msg:m1_velocity instead.")
  (m1_velocity m))

(cl:ensure-generic-function 'm2_velocity-val :lambda-list '(m))
(cl:defmethod m2_velocity-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_velocity-val is deprecated.  Use ros_gui-msg:m2_velocity instead.")
  (m2_velocity m))

(cl:ensure-generic-function 'm3_velocity-val :lambda-list '(m))
(cl:defmethod m3_velocity-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_velocity-val is deprecated.  Use ros_gui-msg:m3_velocity instead.")
  (m3_velocity m))

(cl:ensure-generic-function 'm1_current-val :lambda-list '(m))
(cl:defmethod m1_current-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_current-val is deprecated.  Use ros_gui-msg:m1_current instead.")
  (m1_current m))

(cl:ensure-generic-function 'm2_current-val :lambda-list '(m))
(cl:defmethod m2_current-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_current-val is deprecated.  Use ros_gui-msg:m2_current instead.")
  (m2_current m))

(cl:ensure-generic-function 'm3_current-val :lambda-list '(m))
(cl:defmethod m3_current-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_current-val is deprecated.  Use ros_gui-msg:m3_current instead.")
  (m3_current m))

(cl:ensure-generic-function 'x_acelleration-val :lambda-list '(m))
(cl:defmethod x_acelleration-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:x_acelleration-val is deprecated.  Use ros_gui-msg:x_acelleration instead.")
  (x_acelleration m))

(cl:ensure-generic-function 'y_acelleration-val :lambda-list '(m))
(cl:defmethod y_acelleration-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:y_acelleration-val is deprecated.  Use ros_gui-msg:y_acelleration instead.")
  (y_acelleration m))

(cl:ensure-generic-function 'angular_velocity-val :lambda-list '(m))
(cl:defmethod angular_velocity-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:angular_velocity-val is deprecated.  Use ros_gui-msg:angular_velocity instead.")
  (angular_velocity m))

(cl:ensure-generic-function 'compass-val :lambda-list '(m))
(cl:defmethod compass-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:compass-val is deprecated.  Use ros_gui-msg:compass instead.")
  (compass m))

(cl:ensure-generic-function 'm1_dutycycle-val :lambda-list '(m))
(cl:defmethod m1_dutycycle-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_dutycycle-val is deprecated.  Use ros_gui-msg:m1_dutycycle instead.")
  (m1_dutycycle m))

(cl:ensure-generic-function 'm2_dutycycle-val :lambda-list '(m))
(cl:defmethod m2_dutycycle-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_dutycycle-val is deprecated.  Use ros_gui-msg:m2_dutycycle instead.")
  (m2_dutycycle m))

(cl:ensure-generic-function 'm3_dutycycle-val :lambda-list '(m))
(cl:defmethod m3_dutycycle-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_dutycycle-val is deprecated.  Use ros_gui-msg:m3_dutycycle instead.")
  (m3_dutycycle m))

(cl:ensure-generic-function 'm1_setpoint-val :lambda-list '(m))
(cl:defmethod m1_setpoint-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_setpoint-val is deprecated.  Use ros_gui-msg:m1_setpoint instead.")
  (m1_setpoint m))

(cl:ensure-generic-function 'm2_setpoint-val :lambda-list '(m))
(cl:defmethod m2_setpoint-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_setpoint-val is deprecated.  Use ros_gui-msg:m2_setpoint instead.")
  (m2_setpoint m))

(cl:ensure-generic-function 'm3_setpoint-val :lambda-list '(m))
(cl:defmethod m3_setpoint-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_setpoint-val is deprecated.  Use ros_gui-msg:m3_setpoint instead.")
  (m3_setpoint m))

(cl:ensure-generic-function 'm1_inc_control_signal-val :lambda-list '(m))
(cl:defmethod m1_inc_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_inc_control_signal-val is deprecated.  Use ros_gui-msg:m1_inc_control_signal instead.")
  (m1_inc_control_signal m))

(cl:ensure-generic-function 'm2_inc_control_signal-val :lambda-list '(m))
(cl:defmethod m2_inc_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_inc_control_signal-val is deprecated.  Use ros_gui-msg:m2_inc_control_signal instead.")
  (m2_inc_control_signal m))

(cl:ensure-generic-function 'm3_inc_control_signal-val :lambda-list '(m))
(cl:defmethod m3_inc_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_inc_control_signal-val is deprecated.  Use ros_gui-msg:m3_inc_control_signal instead.")
  (m3_inc_control_signal m))

(cl:ensure-generic-function 'm1_control_signal-val :lambda-list '(m))
(cl:defmethod m1_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m1_control_signal-val is deprecated.  Use ros_gui-msg:m1_control_signal instead.")
  (m1_control_signal m))

(cl:ensure-generic-function 'm2_control_signal-val :lambda-list '(m))
(cl:defmethod m2_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m2_control_signal-val is deprecated.  Use ros_gui-msg:m2_control_signal instead.")
  (m2_control_signal m))

(cl:ensure-generic-function 'm3_control_signal-val :lambda-list '(m))
(cl:defmethod m3_control_signal-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:m3_control_signal-val is deprecated.  Use ros_gui-msg:m3_control_signal instead.")
  (m3_control_signal m))

(cl:ensure-generic-function 'V-val :lambda-list '(m))
(cl:defmethod V-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:V-val is deprecated.  Use ros_gui-msg:V instead.")
  (V m))

(cl:ensure-generic-function 'Vn-val :lambda-list '(m))
(cl:defmethod Vn-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Vn-val is deprecated.  Use ros_gui-msg:Vn instead.")
  (Vn m))

(cl:ensure-generic-function 'W-val :lambda-list '(m))
(cl:defmethod W-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:W-val is deprecated.  Use ros_gui-msg:W instead.")
  (W m))

(cl:ensure-generic-function 'delta_time-val :lambda-list '(m))
(cl:defmethod delta_time-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:delta_time-val is deprecated.  Use ros_gui-msg:delta_time instead.")
  (delta_time m))

(cl:ensure-generic-function 'X_robot-val :lambda-list '(m))
(cl:defmethod X_robot-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:X_robot-val is deprecated.  Use ros_gui-msg:X_robot instead.")
  (X_robot m))

(cl:ensure-generic-function 'Y_robot-val :lambda-list '(m))
(cl:defmethod Y_robot-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Y_robot-val is deprecated.  Use ros_gui-msg:Y_robot instead.")
  (Y_robot m))

(cl:ensure-generic-function 'Theta_robot-val :lambda-list '(m))
(cl:defmethod Theta_robot-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Theta_robot-val is deprecated.  Use ros_gui-msg:Theta_robot instead.")
  (Theta_robot m))

(cl:ensure-generic-function 'Vref-val :lambda-list '(m))
(cl:defmethod Vref-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Vref-val is deprecated.  Use ros_gui-msg:Vref instead.")
  (Vref m))

(cl:ensure-generic-function 'Vnref-val :lambda-list '(m))
(cl:defmethod Vnref-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Vnref-val is deprecated.  Use ros_gui-msg:Vnref instead.")
  (Vnref m))

(cl:ensure-generic-function 'Wref-val :lambda-list '(m))
(cl:defmethod Wref-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Wref-val is deprecated.  Use ros_gui-msg:Wref instead.")
  (Wref m))

(cl:ensure-generic-function 'X_robot_Odom-val :lambda-list '(m))
(cl:defmethod X_robot_Odom-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:X_robot_Odom-val is deprecated.  Use ros_gui-msg:X_robot_Odom instead.")
  (X_robot_Odom m))

(cl:ensure-generic-function 'Y_robot_Odom-val :lambda-list '(m))
(cl:defmethod Y_robot_Odom-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Y_robot_Odom-val is deprecated.  Use ros_gui-msg:Y_robot_Odom instead.")
  (Y_robot_Odom m))

(cl:ensure-generic-function 'Theta_robot_Odom-val :lambda-list '(m))
(cl:defmethod Theta_robot_Odom-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Theta_robot_Odom-val is deprecated.  Use ros_gui-msg:Theta_robot_Odom instead.")
  (Theta_robot_Odom m))

(cl:ensure-generic-function 'X_v1-val :lambda-list '(m))
(cl:defmethod X_v1-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:X_v1-val is deprecated.  Use ros_gui-msg:X_v1 instead.")
  (X_v1 m))

(cl:ensure-generic-function 'Y_v1-val :lambda-list '(m))
(cl:defmethod Y_v1-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Y_v1-val is deprecated.  Use ros_gui-msg:Y_v1 instead.")
  (Y_v1 m))

(cl:ensure-generic-function 'Theta_v1-val :lambda-list '(m))
(cl:defmethod Theta_v1-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Theta_v1-val is deprecated.  Use ros_gui-msg:Theta_v1 instead.")
  (Theta_v1 m))

(cl:ensure-generic-function 'id_v1-val :lambda-list '(m))
(cl:defmethod id_v1-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:id_v1-val is deprecated.  Use ros_gui-msg:id_v1 instead.")
  (id_v1 m))

(cl:ensure-generic-function 'X_v2-val :lambda-list '(m))
(cl:defmethod X_v2-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:X_v2-val is deprecated.  Use ros_gui-msg:X_v2 instead.")
  (X_v2 m))

(cl:ensure-generic-function 'Y_v2-val :lambda-list '(m))
(cl:defmethod Y_v2-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Y_v2-val is deprecated.  Use ros_gui-msg:Y_v2 instead.")
  (Y_v2 m))

(cl:ensure-generic-function 'Theta_v2-val :lambda-list '(m))
(cl:defmethod Theta_v2-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:Theta_v2-val is deprecated.  Use ros_gui-msg:Theta_v2 instead.")
  (Theta_v2 m))

(cl:ensure-generic-function 'id_v2-val :lambda-list '(m))
(cl:defmethod id_v2-val ((m <RX_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_gui-msg:id_v2-val is deprecated.  Use ros_gui-msg:id_v2 instead.")
  (id_v2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RX_data>) ostream)
  "Serializes a message object of type '<RX_data>"
  (cl:let* ((signed (cl:slot-value msg 'm1_velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm2_velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm3_velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm1_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm2_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm3_current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'x_acelleration)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y_acelleration)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'angular_velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'compass)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm1_dutycycle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm2_dutycycle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm3_dutycycle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm1_setpoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm2_setpoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'm3_setpoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm1_inc_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm2_inc_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm3_inc_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm1_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm2_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'm3_control_signal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'V))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Vn))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'W))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'delta_time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'X_robot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Y_robot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Theta_robot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Vref))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Vnref))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Wref))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'X_robot_Odom))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Y_robot_Odom))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Theta_robot_Odom))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'X_v1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Y_v1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Theta_v1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'id_v1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'X_v2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Y_v2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Theta_v2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'id_v2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RX_data>) istream)
  "Deserializes a message object of type '<RX_data>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm1_velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm2_velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm3_velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm1_current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm2_current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm3_current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x_acelleration) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y_acelleration) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'angular_velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'compass) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm1_dutycycle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm2_dutycycle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm3_dutycycle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm1_setpoint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm2_setpoint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'm3_setpoint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm1_inc_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm2_inc_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm3_inc_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm1_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm2_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'm3_control_signal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'V) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vn) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'W) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'delta_time) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X_robot) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y_robot) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Theta_robot) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vref) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vnref) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Wref) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X_robot_Odom) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y_robot_Odom) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Theta_robot_Odom) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X_v1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y_v1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Theta_v1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'id_v1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X_v2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y_v2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Theta_v2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'id_v2) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RX_data>)))
  "Returns string type for a message object of type '<RX_data>"
  "ros_gui/RX_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RX_data)))
  "Returns string type for a message object of type 'RX_data"
  "ros_gui/RX_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RX_data>)))
  "Returns md5sum for a message object of type '<RX_data>"
  "9cbb632bcd28f1c68281f54e66f805fd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RX_data)))
  "Returns md5sum for a message object of type 'RX_data"
  "9cbb632bcd28f1c68281f54e66f805fd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RX_data>)))
  "Returns full string definition for message of type '<RX_data>"
  (cl:format cl:nil "int16 m1_velocity~%int16 m2_velocity~%int16 m3_velocity~%int16 m1_current~%int16 m2_current~%int16 m3_current~%int16 x_acelleration~%int16 y_acelleration~%int16 angular_velocity~%int16 compass~%int8 m1_dutycycle~%int8 m2_dutycycle~%int8 m3_dutycycle~%int16 m1_setpoint~%int16 m2_setpoint~%int16 m3_setpoint~%float64 m1_inc_control_signal~%float64 m2_inc_control_signal~%float64 m3_inc_control_signal~%float64 m1_control_signal~%float64 m2_control_signal~%float64 m3_control_signal~%float64 V~%float64 Vn~%float64 W~%int16 delta_time~%float64 X_robot~%float64 Y_robot~%float64 Theta_robot~%float64 Vref~%float64 Vnref~%float64 Wref~%float64 X_robot_Odom~%float64 Y_robot_Odom~%float64 Theta_robot_Odom~%float64 X_v1~%float64 Y_v1~%float64 Theta_v1~%float64 id_v1~%float64 X_v2~%float64 Y_v2~%float64 Theta_v2~%float64 id_v2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RX_data)))
  "Returns full string definition for message of type 'RX_data"
  (cl:format cl:nil "int16 m1_velocity~%int16 m2_velocity~%int16 m3_velocity~%int16 m1_current~%int16 m2_current~%int16 m3_current~%int16 x_acelleration~%int16 y_acelleration~%int16 angular_velocity~%int16 compass~%int8 m1_dutycycle~%int8 m2_dutycycle~%int8 m3_dutycycle~%int16 m1_setpoint~%int16 m2_setpoint~%int16 m3_setpoint~%float64 m1_inc_control_signal~%float64 m2_inc_control_signal~%float64 m3_inc_control_signal~%float64 m1_control_signal~%float64 m2_control_signal~%float64 m3_control_signal~%float64 V~%float64 Vn~%float64 W~%int16 delta_time~%float64 X_robot~%float64 Y_robot~%float64 Theta_robot~%float64 Vref~%float64 Vnref~%float64 Wref~%float64 X_robot_Odom~%float64 Y_robot_Odom~%float64 Theta_robot_Odom~%float64 X_v1~%float64 Y_v1~%float64 Theta_v1~%float64 id_v1~%float64 X_v2~%float64 Y_v2~%float64 Theta_v2~%float64 id_v2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RX_data>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
     2
     2
     1
     1
     1
     2
     2
     2
     8
     8
     8
     8
     8
     8
     8
     8
     8
     2
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RX_data>))
  "Converts a ROS message object to a list"
  (cl:list 'RX_data
    (cl:cons ':m1_velocity (m1_velocity msg))
    (cl:cons ':m2_velocity (m2_velocity msg))
    (cl:cons ':m3_velocity (m3_velocity msg))
    (cl:cons ':m1_current (m1_current msg))
    (cl:cons ':m2_current (m2_current msg))
    (cl:cons ':m3_current (m3_current msg))
    (cl:cons ':x_acelleration (x_acelleration msg))
    (cl:cons ':y_acelleration (y_acelleration msg))
    (cl:cons ':angular_velocity (angular_velocity msg))
    (cl:cons ':compass (compass msg))
    (cl:cons ':m1_dutycycle (m1_dutycycle msg))
    (cl:cons ':m2_dutycycle (m2_dutycycle msg))
    (cl:cons ':m3_dutycycle (m3_dutycycle msg))
    (cl:cons ':m1_setpoint (m1_setpoint msg))
    (cl:cons ':m2_setpoint (m2_setpoint msg))
    (cl:cons ':m3_setpoint (m3_setpoint msg))
    (cl:cons ':m1_inc_control_signal (m1_inc_control_signal msg))
    (cl:cons ':m2_inc_control_signal (m2_inc_control_signal msg))
    (cl:cons ':m3_inc_control_signal (m3_inc_control_signal msg))
    (cl:cons ':m1_control_signal (m1_control_signal msg))
    (cl:cons ':m2_control_signal (m2_control_signal msg))
    (cl:cons ':m3_control_signal (m3_control_signal msg))
    (cl:cons ':V (V msg))
    (cl:cons ':Vn (Vn msg))
    (cl:cons ':W (W msg))
    (cl:cons ':delta_time (delta_time msg))
    (cl:cons ':X_robot (X_robot msg))
    (cl:cons ':Y_robot (Y_robot msg))
    (cl:cons ':Theta_robot (Theta_robot msg))
    (cl:cons ':Vref (Vref msg))
    (cl:cons ':Vnref (Vnref msg))
    (cl:cons ':Wref (Wref msg))
    (cl:cons ':X_robot_Odom (X_robot_Odom msg))
    (cl:cons ':Y_robot_Odom (Y_robot_Odom msg))
    (cl:cons ':Theta_robot_Odom (Theta_robot_Odom msg))
    (cl:cons ':X_v1 (X_v1 msg))
    (cl:cons ':Y_v1 (Y_v1 msg))
    (cl:cons ':Theta_v1 (Theta_v1 msg))
    (cl:cons ':id_v1 (id_v1 msg))
    (cl:cons ':X_v2 (X_v2 msg))
    (cl:cons ':Y_v2 (Y_v2 msg))
    (cl:cons ':Theta_v2 (Theta_v2 msg))
    (cl:cons ':id_v2 (id_v2 msg))
))
