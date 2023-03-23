#include "main.h"

#include "auton.h"
#include "devices.h"
#include "drive.h"
#include "flywheel.h"
#include "selector.h"

void initialize() {
  // pros::lcd::initialize();
  selector::init();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  // SETUP
  snail_constants();
  flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  left_front.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_middle.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_back.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_front.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_middle.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_back.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // AUTON SELECTOR
  if (selector::auton == 1) {
    skills();
  }
  if (selector::auton == 2) {
    left();
  }
  if (selector::auton == 3) {
    right();
  }
  if (selector::auton == 4) {
    awp();
  }
  if (selector::auton == 5) {
    // NULL or
    test();
  }
}

void opcontrol() {
  // SETUP
  flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  left_front.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  left_middle.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  left_back.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_front.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_middle.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  right_back.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  set_flywheel_speed(350);

  // DRIVE LOOP
  while (true) {
    update_drivetrain();
    update_intake();
    update_indexer();

    pros::delay(10);
  }
}
