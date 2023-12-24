#include "EZ-Template/drive/drive.hpp"
#include "autons.hpp"
#include "display/lv_objx/lv_label.h"
#include "main.h"
#include "global.h"
#include "functions.h"
#include "definitions.h"
#include "mainFunctions.h"

using namespace assignments;

void init() {

    pros::lcd::set_text(1, "Hello SANAH!");

    pros::delay(500); // Stop the user from doing anything while legacy ports configure.

    // Configure your chassis controls
    chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
    chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
    chassis.set_curve_default(0, 0.50); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
    default_constants(); // Set the drive to your own constants from autons.cpp!
    exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!
    //void set_drive_brake(pros::motor_brake_mode_e_t MOTOR_BRAKE_COAST);

    // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
    //chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
    // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);
    intakeUp();
    // Autonomous Selector using LLEMU
    ez::as::auton_selector.add_autons({

         Auton("Sweep", SweepAuto),
         Auton("NoSweep", noSweepAuto2),
         Auton("Sweep", SweepAuto),
     Auton("do not use", NoSweepAuto),
    Auton("skills", skills),
    Auton("Sweep", SweepAuto),
      
    });

    // Initialize chassis and auton selector

    //chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);
    chassis.initialize();
    ez::as::initialize();
    // chassis.set_joystick_threshold(5);

}

