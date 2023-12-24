#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "main.h"

namespace assignments {
    
    //Controllers//

    extern pros::Controller * Controller;

    //Drive Motors//


    extern pros::Motor * leftFront;
    extern pros::Motor * leftBottom;
    extern pros::Motor * leftTop;
    extern pros::Motor * rightFront;
    extern pros::Motor * rightBottom;
    extern pros::Motor * rightTop;

    //Catapult/Intake Motors//
    
    extern pros::Motor * cataMotor;
    extern pros::Motor * intakeMotor;

    //Sensors//

    extern pros::Imu * inertial;
    
    extern pros::ADIButton * limitSwitch;
    extern pros::ADIButton * limitSwitch2;

    extern pros::ADIDigitalOut * blockerPiston;

    extern pros::ADIDigitalOut * flapper;

    extern pros::ADIButton * limit;
}

#endif 