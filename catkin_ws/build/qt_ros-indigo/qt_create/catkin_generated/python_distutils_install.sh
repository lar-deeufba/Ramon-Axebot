#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/ramonoliveira/catkin_ws/src/qt_ros-indigo/qt_create"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/ramonoliveira/catkin_ws/install/lib/python2.7/dist-packages:/home/ramonoliveira/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/ramonoliveira/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/ramonoliveira/catkin_ws/src/qt_ros-indigo/qt_create/setup.py" \
    build --build-base "/home/ramonoliveira/catkin_ws/build/qt_ros-indigo/qt_create" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/ramonoliveira/catkin_ws/install" --install-scripts="/home/ramonoliveira/catkin_ws/install/bin"
