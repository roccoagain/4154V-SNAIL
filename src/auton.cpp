#include "auton.h"

#include "devices.h"
#include "main.h"

namespace auton {

constexpr int DRIVE_SPEED = 110;
constexpr int TURN_SPEED = 90;
constexpr int SWING_SPEED = 90;

const std::vector<int> LEFT_MOTOR_PORTS = {-4, 5, -6};
const std::vector<int> RIGHT_MOTOR_PORTS = {1, -2, 3};
constexpr int IMU_PORT = 7;
constexpr double WHEEL_DIAMETER = 2.75;
constexpr int CARTRIDGE_RPM = 600;
const double EXTERNAL_GEAR_RATIO = .8;  // 48:60
Drive chassis(LEFT_MOTOR_PORTS, RIGHT_MOTOR_PORTS, IMU_PORT, WHEEL_DIAMETER,
              CARTRIDGE_RPM, EXTERNAL_GEAR_RATIO);

void snail_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void spin_roller(int time) {
  devices::intake = 127;
  pros::delay(time);
  devices::intake = 0;
}

void shoot(int shot_count = 1) {
  for (int i = 0; i < shot_count; i++) {
    devices::intake = -127;
    pros::delay(150);
    devices::intake = 0;
    pros::delay(800);
  }
}

void skills() {}

void left() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.reset_pid_targets();

  // Start flywheel
  devices::flywheel.move_velocity(580);

  // Get roller 1
  chassis.set_drive_pid(-10, DRIVE_SPEED / 2);
  chassis.wait_drive();
  spin_roller(300);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();

  // Face goal
  chassis.set_turn_pid(-7, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(1500);

  // Shoot preloads
  shoot(2);

  // Set flywheel for midline shot
  devices::flywheel.move_velocity(520);

  // Face triple stack
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  // Get triple stack
  devices::intake_lifter.set_value(true);
  devices::intake = 127;
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  devices::intake_lifter.set_value(false);
  pros::delay(2000);

  // Face goal
  chassis.set_turn_pid(-21, TURN_SPEED);
  chassis.wait_drive();

  // Shoot Triple Stack
  shoot(3);

  devices::flywheel = 0;
  devices::intake = 0;
}

void right() {}

void awp() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.reset_pid_targets();

  // Set flywheel
  devices::flywheel.move_velocity(480);

  // Get roller 1
  chassis.set_drive_pid(-10, DRIVE_SPEED / 2);
  chassis.wait_drive();
  spin_roller(300);
  chassis.set_drive_pid(8, DRIVE_SPEED);
  chassis.wait_drive();

  // Face triple stack
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  // Get triple stack
  devices::intake_lifter.set_value(true);
  devices::intake = 127;
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  devices::intake_lifter.set_value(false);
  pros::delay(2000);

  // Turn to face goal
  chassis.set_turn_pid(-20, TURN_SPEED);
  chassis.wait_drive();

  // Shoot Triple Stack
  shoot(3);

  // Drive to roller 2
  devices::intake = 127;
  chassis.set_turn_pid(44, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(165, DRIVE_SPEED);
  chassis.wait_drive();

  // Get roller
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  devices::intake = 90;
  pros::delay(500);
  devices::intake = 0;
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  spin_roller(350);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  chassis.wait_drive();

  // Turn everything off
  devices::flywheel.move_velocity(0);
  devices::intake = 0;
}

void test() {
  chassis.set_drive_pid(30, DRIVE_SPEED);
  chassis.wait_drive();

  devices::intake = 127;
  pros::delay(2000);
  devices::intake = -127;
}
}  // namespace auton