#include "main.h"
#include "global.h"
#include "definitions.h"
#include "functions.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include <cstdio>


void launchDisk() {

    //one function
    //shooting code (move 100, 500 ms and stop)
    //priming code (while not touching limit switch, bring down, then stop it )
    //all in task
    //code to shoot and put back in same task
    //shoot first then back

    pros::Task cataTask {[=]{

        cataMotor->move_velocity(100);
       pros::delay(750);

        while(limitSwitch->get_value() == 0) {


        }

        cataMotor->move_velocity(0);
        cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);




    }};


}


void cataDown(){

    pros::Task cataDown{[=]{

		while (limitSwitch->get_value() == 0){

			cataMotor->move_velocity(100);

			if (limitSwitch->get_value() == 1){

				break;

			}

		}

        cataMotor->move_velocity(0);
		cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    }};

}

void launchDiskAuton(){

    cataMotor->move_velocity(100);
    pros::delay(850);
    cataMotor->move_velocity(0);

}

void AintakeOn() {

    intakeMotor->move_velocity(200);

}

void intakeOff() {

    intakeMotor->move_velocity(0);

}


void driverControl() {

    float left, right, leftV, rightV;
    left = Controller->get_analog(LEFT_Y);
    right = Controller->get_analog(LEFT_X);
    leftV = ((left + right)/2*1.7);
    rightV = ((left - right)/2*1.7);

    leftFront->move_velocity(-leftV);
    leftBottom->move_velocity(-leftV);
    leftTop->move_velocity(leftV);
    rightFront->move_velocity(rightV);
    rightBottom->move_velocity(rightV);
    rightTop->move_velocity(-rightV);


}

void cataDown100() {

    cataMotor->move_velocity(50);               // this moves the catapult,
	pros::delay(500);                       // for half a second,
	cataMotor->move_velocity(0);                // (shoots triball)

	// if(limitSwitch->get_value() == 0) {                  // catapult is not in down position

		cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // hold motor in place
		
		pros::Task cataTask{[=]{        // task begins	

			while (limitSwitch->get_value() == false){      // while catapult is not in down position

				cataMotor->move_velocity(80); // move catapult until it is down

				pros::delay(10);

			}

			cataMotor->move_velocity(0);      // set velocity to 0

		}};	

	// } else {

	//     cataMotor->move_velocity(0);           //don't move if already in down position

	// }

}

void cataDown50() {

	// cataMotor->move_velocity(70);
	// pros::delay(500);
	// cataMotor->move_velocity(0);

	// if(limit->get_value() == 0) {
		cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

		pros::Task cataTask{[=]{

			while (limit->get_value() == false){

				cataMotor->move_velocity(80);

				pros::delay(10);

			}

			cataMotor->move_velocity(0);

		}};	

	// } else {

		// cataMotor->move_velocity(0);

	// }

}

void intake() {
	intakeMotor->move_velocity(600);
}

void outtake() {
	intakeMotor->move_velocity(-600);
}

void stopIntake() {
	intakeMotor->move_velocity(0);
}

void flapperDown() {
	flapper->set_value(1);
}

void flapperUp() {
	flapper->set_value(0);
}

void intakeDown() {
	blockerPiston->set_value(1);
}

void intakeUp() {
	blockerPiston->set_value(0);
}

void initOpControl(){
	//put before while loop in op control to put cata down
	pros::Task cataTask2{[=]{

					while (limitSwitch->get_value() == 0){

						cataMotor->move_velocity(70);
						//was 100

						if (limitSwitch->get_value() == 1){

							break;

						}

					}

					cataMotor->move_velocity(0);
					cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

		    	}};	

	//cata failsafe

	if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
				
				pros::Task cataTask2{[=]{

						while (limitSwitch->get_value() == 0){

							cataMotor->move_velocity(80);
							//was 100

							if (limitSwitch->get_value() == 1){

								break;

							}

						}

						cataMotor->move_velocity(0);
						cataMotor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

					}};	
				
				
			}

	//catapult code//

	if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
	
			cataDown100();

	} else if (Controller->get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {

		cataDown50();

	}

}