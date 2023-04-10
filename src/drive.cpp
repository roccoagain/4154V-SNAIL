#include "drive.h"

#include "devices.h"
#include "flywheel.h"
#include "main.h"

bool flywheel_toggle = true;

void update_drivetrain() {
  int left_voltage = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int right_voltage = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  left_back.move(left_voltage);
  left_raised.move(left_voltage);
  left_front.move(left_voltage);
  right_back.move(right_voltage);
  right_raised.move(right_voltage);
  right_front.move(right_voltage);
}

void update_intake() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    intake = -127;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    intake = 127;
  } else {
    intake = 0;
  }
}

void update_indexer() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    indexer.set_value(true);
  } else {
    indexer.set_value(false);
  }
}

void update_flywheel() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    flywheel_toggle = !flywheel_toggle;
    if (flywheel_toggle) {
      flywheel.move_velocity(350);
    } else {
      flywheel = 0;
    }
    pros::delay(250);
  }
}