#include "auton.h"

#include "devices.h"
#include "main.h"

// DRIVE CONSTANTS
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;
const int PISTON_HOLD_DELAY = 300;
const int PISTON_RESET_DELAY = 900;

// EZ TEMPLATE SETUP
const std::vector<int> LEFT_MOTOR_PORTS = {2, 1, 3};
const std::vector<int> RIGHT_MOTOR_PORTS = {5, 4, 6};
const int IMU_PORT = 10;
const double WHEEL_DIAMETER = 3.25;
const int CARTRIDGE_RPM = 600;
const double EXTERNAL_GEAR_RATIO = 1.666;
Drive ezChassis(LEFT_MOTOR_PORTS, RIGHT_MOTOR_PORTS, IMU_PORT, WHEEL_DIAMETER,
                CARTRIDGE_RPM, EXTERNAL_GEAR_RATIO);

void snail_constants() {
  ezChassis.set_slew_min_power(80, 80);
  ezChassis.set_slew_distance(7, 7);
  ezChassis.set_pid_constants(&ezChassis.headingPID, 11, 0, 20, 0);
  ezChassis.set_pid_constants(&ezChassis.forward_drivePID, 0.45, 0, 5, 0);
  ezChassis.set_pid_constants(&ezChassis.backward_drivePID, 0.45, 0, 5, 0);
  ezChassis.set_pid_constants(&ezChassis.turnPID, 5, 0.003, 35, 15);
  ezChassis.set_pid_constants(&ezChassis.swingPID, 7, 0, 45, 0);
}

// CUSTOM FUNCTIONS
void spin_roller(int time) {
  intake = -127;
  pros::delay(time);
  intake = 0;
}

void index(int shot_count = 1) {
  for (int i = 0; i < shot_count; i++) {
    indexer.set_value(true);
    pros::delay(PISTON_HOLD_DELAY);
    indexer.set_value(false);
    pros::delay(PISTON_RESET_DELAY);
  }
}

// AUTONS
void skills() {
  // TODO
}

void left() {
  // TODO
}

void right() {
  // TODO
}

void awp() {
  // TODO
}
