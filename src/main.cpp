#include "main.h"

#include "auton.h"
#include "devices.h"
#include "drive.h"
#include "flywheel.h"
#include "selector.h"

void initialize() { selector::init(); }

void disabled() {}

void competition_initialize() {}

void autonomous() {
  auton::snail_constants();
  devices::set_brakes(pros::E_MOTOR_BRAKE_HOLD);

  switch (selector::auton) {
    case 1:
      auton::skills();
      break;
    case 2:
      auton::left();
      break;
    case 3:
      auton::right();
      break;
    case 4:
      auton::awp();
      break;
    case 5:
      break;
  }
}

void opcontrol() {
  devices::set_brakes(pros::E_MOTOR_BRAKE_COAST);
  // flywheel::retarget_pid(350);

  devices::flywheel.move_velocity(drive::flywheel_velocity);
  devices::flywheel_angler.set_value(drive::toggles.flywheel_angler_toggle);

  while (true) {
    drive::update_drivetrain();
    drive::update_intake();
    drive::update_indexer();
    drive::update_flywheel();
    drive::update_flywheel_angler();
    drive::update_intake_lifter();
    drive::update_expansion();

    pros::delay(10);
  }
}
