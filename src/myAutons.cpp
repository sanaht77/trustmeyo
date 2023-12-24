#include "EZ-Template/util.hpp"
#include "global.h"
#include "main.h"
#include "autons.hpp"
#include "functions.h"
#include "pros/rtos.hpp"

const int DRIVE_SPEED = 90;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
const int INTAKE_SPEED = 50;
const int SLOWER_INTAKE_SPEED = 30;
const int EIGHTY_PERCENT = 80;
const int SEVENTY_PERCENT = 70;
const int SIXTY_PERCENT = 60;

void doNothing() {

    //do nothing :)

}

void  driveTest() {

    // chassis.set_turn_pid(90, TURN_SPEED);
    // chassis.wait_drive();
    chassis.set_drive_pid(24, DRIVE_SPEED, true);
    chassis.wait_drive();
}
 
void SweepAuto(){

    intake();
    pros::delay(500);
    stopIntake();

    chassis.set_drive_pid(16, 110);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 45, 50);
    chassis.wait_drive();

    outtake();
    pros::delay(250);
    stopIntake();

    chassis.set_swing_pid(ez::LEFT_SWING, 47, 50);
    chassis.wait_drive();
   
    chassis.set_drive_pid(18, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(-12, 60);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 2, 80);
    chassis.wait_drive();

    // chassis.set_turn_pid(367, 60);
    // chassis.wait_drive();

    flapperDown();
     
    chassis.set_drive_pid(-17, 110);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, -70, 90);
    chassis.wait_drive();

    flapperUp();

    // chassis.set_drive_pid(26, 60);
    // chassis.wait_drive();

    chassis.set_turn_pid(152, 60);
    chassis.wait_drive();

    blockerPiston->set_value(1);

    chassis.set_drive_pid(36, 60);
    chassis.wait_drive();

    blockerPiston->set_value(0);

    // chassis.set_swing_pid(ez::LEFT_SWING, 180, 50);
    // chassis.wait_drive();

    // chassis.set_drive_pid(5, 60);
    // chassis.wait_drive();

    // chassis.set_swing_pid(ez::LEFT_SWING, 160, 50);
    // chassis.wait_drive();

    // chassis.set_drive_pid(5, 60);
    // chassis.wait_drive();

    // chassis.set_turn_pid(140, 60);
    // chassis.wait_drive();

    //


    ///old auto///

    // intake();
    // pros::delay(500);
    // stopIntake();

    // chassis.set_drive_pid(20, 110);
    // chassis.wait_drive();
    // // chassis.set_swing_pid(ez::LEFT_SWING, 45, 40);
    // // chassis.wait_drive();
    // // pros::delay(1000);
    // // pros::delay(100);
    // // blockerPiston->set_value(0);
    // // pros::delay(500);
    // chassis.set_swing_pid(ez::LEFT_SWING, 42, 50);
    // chassis.wait_drive();

    // outtake();
    // pros::delay(500);
    // stopIntake();

   
    // chassis.set_drive_pid(16, 60);
    // chassis.wait_drive();

    // chassis.set_drive_pid(-18, 60);
    // chassis.wait_drive();
    
    // chassis.set_swing_pid(ez::LEFT_SWING, -25, 50);
    // chassis.wait_drive();
    // flapperDown();
    // pros::delay(800);
    // chassis.set_drive_pid(-15, 60);
    // chassis.wait_drive();
    // flapperUp();
    // chassis.set_swing_pid(ez::RIGHT_SWING, 45, 90);
    // chassis.wait_drive();
    // chassis.set_turn_pid(140, 90);
    // chassis.wait_drive();
    // blockerPiston->set_value(1);
    // chassis.set_drive_pid(31, 110);
    // chassis.wait_drive();
    // blockerPiston->set_value(0);
    
}



void NoSweepAuto() {

    // intake();
    // pros::delay(500);
    // stopIntake();

    flapperDown();

    // intakeDown();
    chassis.set_drive_pid(20, 110);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, -5, 90);
    chassis.wait_drive();

    chassis.set_drive_pid(5, 110);
    chassis.wait_drive();

    chassis.set_turn_pid(-45, 90);
    chassis.wait_drive();

    outtake();

    chassis.set_drive_pid(10, 110);
    chassis.wait_drive();




    // stopIntake();
    
    chassis.set_turn_pid(205, 90);
    pros::delay(250);
    //intakeMotor->move_velocity(-300);
    // outtake();
    chassis.wait_drive();
    outtake();

    chassis.set_drive_pid(5,110);
    chassis.wait_drive();

     intake();

    chassis.set_turn_pid(105, 90);
    chassis.wait_drive();

    intake();

    chassis.set_drive_pid(20, 90);
    chassis.wait_drive();

    // stopIntake();
    // flapperDown();

    chassis.set_turn_pid(220,90);
    chassis.wait_drive();
 flapperDown();
    outtake();
    // flapperDown();

    //intakeUp();
    chassis.set_drive_pid(36, 110);
    chassis.wait_drive();
    chassis.set_drive_pid(-20, 110);
    chassis.wait_drive();
    stopIntake();
    chassis.set_drive_pid(23, 110);
    chassis.wait_drive();
    chassis.set_drive_pid(-20, 110);
    




 
}

void bUpRightSideAuto(){

   cataMotor->move_velocity(100);
   pros::delay(40000);
   cataMotor->move_velocity(0);
}

void skills(){

    ///first triballs into side of goal

    intake();
    pros::delay(500);
    stopIntake();

    chassis.set_drive_pid(20, 110);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 45, 50);
    chassis.wait_drive();

    outtake();
    pros::delay(250);
    stopIntake();
   
    chassis.set_drive_pid(18, 60);
    chassis.wait_drive();

    chassis.set_drive_pid(-5, 60);
    chassis.wait_drive();

    // pros::delay(250);

    /// back up into match load

    chassis.set_swing_pid(ez::RIGHT_SWING, 120, 50);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 125, 50);
    chassis.wait_drive();
    //was 128

    chassis.set_drive_pid(-2, 60);
    chassis.wait_drive();

    // pros::delay(500);

    cataMotor->move_velocity(100);
    pros::delay(29000);
    cataMotor->move_velocity(0);

    chassis.set_swing_pid(ez::LEFT_SWING, 180, 50);
    chassis.wait_drive();

    chassis.set_drive_pid(34, 100);
    chassis.wait_drive();
    
    chassis.set_turn_pid(140,80);
    chassis.wait_drive();

     chassis.set_drive_pid(87, 100);
    chassis.wait_drive();

    chassis.set_turn_pid(25,80);
    chassis.wait_drive();

    chassis.set_drive_pid(35, 100);
    chassis.wait_drive();

    chassis.set_turn_pid(-20,100);
    chassis.wait_drive();

    chassis.set_drive_pid(12, 100);
    chassis.wait_drive();

     chassis.set_turn_pid(45,100);
    chassis.wait_drive();

    flapperDown();

    chassis.set_drive_pid(15, 100);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 140, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(35, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(-15, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(15, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(-30, 100);
    chassis.wait_drive();

    chassis.set_turn_pid(45,100);
    chassis.wait_drive();

    chassis.set_drive_pid(25, 100);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, 187, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(45, 100);
    chassis.wait_drive();

    chassis.set_swing_pid(ez::RIGHT_SWING, 140, 100);
    chassis.wait_drive();
    
    chassis.set_drive_pid(-10, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(15, 100);
    chassis.wait_drive();

    chassis.set_drive_pid(-25, 100);
    chassis.wait_drive();

    // chassis.set_drive_pid(15, 100);
    // chassis.wait_drive();

    // chassis.set_drive_pid(-30, 100);
    // chassis.wait_drive();

    // flapperUp();

    // chassis.set_turn_pid(250,100);
    // chassis.wait_drive();

    // chassis.set_drive_pid(-60, 100);
    // chassis.wait_drive();

    // chassis.set_turn_pid(35,100);
    // chassis.wait_drive();


    // chassis.set_drive_pid(37, 100);
    // chassis.wait_drive();

    // chassis.set_drive_pid(-37, 100);
    // chassis.wait_drive();

}

void noSweepAuto2(){
     
    intake();
    chassis.set_drive_pid(8, 40);
    chassis.wait_drive();

    pros::delay(500);

    chassis.set_drive_pid(-40, 127);
    chassis.wait_drive();

    // chassis.set_turn_pid(-38, 127);
    // chassis.wait_drive();

    chassis.set_swing_pid(ez::LEFT_SWING, -38, 127);
    chassis.wait_drive();
    //was 40


    chassis.set_drive_pid(-24, 127);
    chassis.wait_until(-18);
    flapperDown();
    chassis.wait_drive();


    chassis.set_swing_pid(ez::LEFT_SWING, -90, 127);
    chassis.wait_drive();

    flapperUp();


    chassis.set_turn_pid(-255, 127);
    chassis.wait_drive();

    outtake();
    pros::delay(500);
    stopIntake();
    
    // chassis.set_drive_pid(8, 127);
    // chassis.wait_drive();

    // chassis.set_swing_pid(ez::RIGHT_SWING, 90, 127);
    // chassis.wait_drive();

    chassis.set_drive_pid(25, 127);
    chassis.wait_drive();

    //was 20

    chassis.set_drive_pid(-25, 127);
    chassis.wait_drive();

     chassis.set_drive_pid(25, 127);
    chassis.wait_drive();

    chassis.set_drive_pid(-25, 127);
    chassis.wait_drive();

    // chassis.set_turn_pid(-325, 127);
    // chassis.wait_drive();

    // intake();

    // chassis.set_drive_pid(54, 127);
    // chassis.wait_drive();

    // chassis.set_swing_pid(ez::LEFT_SWING, 180, 127);
    // chassis.wait_drive();




}

void sweepAuto2(){

     chassis.set_drive_pid(-24, 127);
     chassis.wait_drive();

    chassis.set_swing_pid(ez::RIGHT_SWING, 38, 127);
    chassis.wait_drive();
    //was 40


    chassis.set_drive_pid(-24, 127);
    chassis.wait_until(-18);
    flapperDown();
    chassis.wait_drive();


    chassis.set_swing_pid(ez::RIGHT_SWING, 90, 127);
    chassis.wait_drive();

    flapperUp();

    chassis.set_turn_pid(255, 127);
    chassis.wait_drive();

    outtake();
    pros::delay(500);
    stopIntake();
    
    // chassis.set_drive_pid(8, 127);
    // chassis.wait_drive();

    // chassis.set_swing_pid(ez::RIGHT_SWING, 90, 127);
    // chassis.wait_drive();

    chassis.set_drive_pid(25, 127);
    chassis.wait_drive();

    //was 20

    chassis.set_drive_pid(-25, 127);
    chassis.wait_drive();

}


