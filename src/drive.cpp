#include "drive.h"

#include "devices.h"
#include "flywheel.h"
#include "main.h"

namespace drive {

// CONSTANTS
constexpr int intake_speed = 127;       // volts
constexpr int flywheel_velocity = 350;  // motor rpm
constexpr int toggle_delay = 200;       // ms

// TOGGLING STUFF
struct {
  bool flywheel_toggle;
  bool flywheel_angler_toggle;
  bool intake_lifter_toggle;
} toggles;

void toggle(bool &toggle_variable) {
  toggle_variable = !toggle_variable;
  pros::delay(toggle_delay);
}

void drivetrain() {
  int left_voltage = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int right_voltage = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

  devices::left_back.move(left_voltage);
  devices::left_raised.move(left_voltage);
  devices::left_front.move(left_voltage);
  devices::right_back.move(right_voltage);
  devices::right_raised.move(right_voltage);
  devices::right_front.move(right_voltage);
}

void intake() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    devices::intake = intake_speed;
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    devices::intake = -intake_speed;
  } else {
    devices::intake = 0;
  }
}

void indexer() {
  devices::indexer.set_value(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
}

void flywheel() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    toggle(toggles.flywheel_toggle);
    if (toggles.flywheel_toggle) {
      devices::flywheel.move_velocity(flywheel_velocity);
    } else {
      devices::flywheel = 0;
    }
  }
}

void flywheel_angler() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
    toggle(toggles.flywheel_angler_toggle);
    devices::flywheel_angler.set_value(toggles.flywheel_angler_toggle);
  }
}

void intake_lifter() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    toggle(toggles.intake_lifter_toggle);
    devices::intake_lifter.set_value(toggles.intake_lifter_toggle);
  }
}

void expansion() {
  devices::expander.set_value(
      master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT));
}

}  // namespace drive