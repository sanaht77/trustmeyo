#include "EZ-Template/util.hpp"
#include "main.h"
#include "global.h"
#include "functions.h"
#include "definitions.h"
#include "mainFunctions.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

class Drive;

using namespace assignments;


void opControl() {

	int intakeSpeed;
	int cataSpeed;
	bool latch = false;
	bool latch2 = false;
	bool flapOn = false;
	bool intakeOn = false;

	while (true) {

		//drive code //

		chassis.arcade_standard(SINGLE);

		//catapult code//

		if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		
			cataSpeed = 100;

		} else {

			cataSpeed = 0;

		}

		//intake code//
		
		if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {

			intakeSpeed = -600;

		} 
		else if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {

			intakeSpeed = 600;

		} 
		else {

			intakeSpeed = 0;

		}

		cataMotor->move_velocity(cataSpeed);
		intakeMotor->move_velocity(intakeSpeed);
		pros::delay(30);

		//blocker piston control

		if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		if (!latch2){
			intakeOn = !intakeOn;
			latch2 = true;
			if (intakeOn) {
				blockerPiston->set_value(1);
			} else {
				blockerPiston->set_value(0);
			}
			}
		} else {
			latch2 = false;
		}

		// wing control

		if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
		if (!latch){
			flapOn = !flapOn;
			latch = true;
			if (flapOn) {
				flapper->set_value(1);
			} else {
				flapper->set_value(0);
			}
			}
		} else {
			latch = false;
		}


	}

	}