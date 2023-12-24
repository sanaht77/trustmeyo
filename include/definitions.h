#ifndef _DEFINITIONS_HPP_
#define _DEFINITIONS_HPP_

#include "main.h"

//Controller enumeration values

    #define MAIN pros::E_CONTROLLER_MASTER
    #define PARTNER pros::E_CONTROLLER_PARTNER

    #define BTN_A pros::E_CONTROLLER_DIGITAL_A
    #define BTN_B pros::E_CONTROLLER_DIGITAL_B
    #define BTN_X pros::E_CONTROLLER_DIGITAL_X
    #define BTN_Y pros::E_CONTROLLER_DIGITAL_Y

    #define BTN_UP pros::E_CONTROLLER_DIGITAL_UP
    #define BTN_DOWN pros::E_CONTROLLER_DIGITAL_DOWN
    #define BTN_RIGHT pros::E_CONTROLLER_DIGITAL_RIGHT
    #define BTN_LEFT pros::E_CONTROLLER_DIGITAL_LEFT

    #define BTN_L2 pros::E_CONTROLLER_DIGITAL_L2
    #define BTN_L1 pros::E_CONTROLLER_DIGITAL_L1
    #define BTN_R2 pros::E_CONTROLLER_DIGITAL_R2
    #define BTN_R1 pros::E_CONTROLLER_DIGITAL_R1

    #define LEFT_Y pros::E_CONTROLLER_ANALOG_LEFT_Y
    #define LEFT_X pros::E_CONTROLLER_ANALOG_LEFT_X
    #define RIGHT_Y pros::E_CONTROLLER_ANALOG_RIGHT_Y
    #define RIGHT_X pros::E_CONTROLLER_ANALOG_RIGHT_X


//Motor enumeration values

    #define BLUE pros::E_MOTOR_GEARSET_06
    #define GREEN pros::E_MOTOR_GEARSET_18
    #define RED pros::E_MOTOR_GEARSET_36

    #define DEGREES pros::E_MOTOR_ENCODER_DEGREES
    #define ROTATIONS pros::E_MOTOR_ENCODER_ROTATIONS
    #define COUNTS pros::E_MOTOR_ENCODER_COUNTS

    #define REV true
    #define N_REV false

    #define COAST pros::E_MOTOR_BRAKE_COAST
    #define BRAKE pros::E_MOTOR_BRAKE_BRAKE
    #define HOLD pros::E_MOTOR_BRAKE_HOLD


#endif
