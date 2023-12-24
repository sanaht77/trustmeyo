#include "main.h"
#include "global.h"
#include "definitions.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"

namespace assignments {

    //controllers//

    pros::Controller * Controller = new pros::Controller(pros::E_CONTROLLER_MASTER);

    //cata/intake motors//

    pros::Motor * cataMotor = new pros::Motor(18, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * intakeMotor = new pros::Motor(8, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

    //sensors//

    pros::ADIButton * limitSwitch = new pros::ADIButton('C');
    pros::ADIButton * limitSwitch2 = new pros::ADIButton('G'); // was G
    pros::ADIDigitalOut * blockerPiston = new pros::ADIDigitalOut('A');
    pros::ADIDigitalOut * flapper = new pros::ADIDigitalOut('B');
    pros::ADIDigitalOut * muncher = new pros::ADIDigitalOut('F');

    //

    pros::ADIDigitalIn * limit = new pros::ADIDigitalIn({{6, 'A'}});

    //drive motors

    pros::Motor * leftFront = new pros::Motor(13, BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * leftBottom = new pros::Motor(11, BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * leftTop = new pros::Motor(14, BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * rightFront = new pros::Motor(16, BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * rightBottom = new pros::Motor(19, BLUE, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor * rightTop = new pros::Motor(20, BLUE, true, pros::E_MOTOR_ENCODER_DEGREES);
  

}