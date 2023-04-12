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
  auton::snail_constants();
  devices::set_brakes(pros::E_MOTOR_BRAKE_HOLD);

  // AUTON SELECTOR
  if (selector::auton == 1) {
    auton::skills();
  }
  if (selector::auton == 2) {
    auton::left();
  }
  if (selector::auton == 3) {
    auton::right();
  }
  if (selector::auton == 4) {
    auton::awp();
  }
  if (selector::auton == 5) {
    // NULL or
    auton::test();
  }
}

void opcontrol() {
  // SETUP
  devices::set_brakes(pros::E_MOTOR_BRAKE_COAST);
  flywheel::retarget_pid(350);

  // DRIVE LOOP
  while (true) {
    drive::drivetrain();
    drive::intake();
    drive::indexer();
    drive::flywheel();
    drive::flywheel_angler();
    drive::intake_lifter();

    pros::delay(10);
  }
}
