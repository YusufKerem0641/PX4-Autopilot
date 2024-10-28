px4_add_module(
    MODULE examples_servo_control
    MAIN servo_control
    SRCS servo_control.cpp
    DEPENDS
    uORB
    systemlib
)

