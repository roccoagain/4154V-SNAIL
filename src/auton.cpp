#include "auton.h"

#include "devices.h"

namespace auton {
Drive chassis(LEFT_MOTOR_PORTS, RIGHT_MOTOR_PORTS, IMU_PORT, WHEEL_DIAMETER,
              CARTRIDGE_RPM, EXTERNAL_GEAR_RATIO);

void snail_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7 * 2, 7 * 2);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void shoot() {
  devices::intake = -127;
  pros::delay(150);
  devices::intake = 0;
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
  // spin_roller(300);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();

  // Face goal
  chassis.set_turn_pid(-7, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(1500);

  // Shoot preloads
  shoot();  // DO THIS TWICE LATER

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
  shoot();  // DO THIS THREE TIMES

  devices::flywheel = 0;
  devices::intake = 0;
}

void right() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.reset_pid_targets();

  devices::flywheel.move_velocity(440);

  // Get roller 1
  devices::intake = 127;
  chassis.set_drive_pid(-30, DRIVE_SPEED * .8);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-7, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(100);
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();

  // Turn to face goal 1
  chassis.set_turn_pid(102, TURN_SPEED);
  chassis.wait_drive();
  pros::delay(500);

  // Shoot 1
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();

  // Set flywheel for midline
  devices::flywheel.move_velocity(420);

  // Intake 1
  devices::intake = 127;
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(90, DRIVE_SPEED * 0.6);
  chassis.wait_drive();
  pros::delay(1000);

  // Face goal 2
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  shoot();
  pros::delay(SHOT_DELAY);
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();

  // Goal discs
  chassis.set_swing_pid(ez::RIGHT_SWING, -90, TURN_SPEED);
  chassis.wait_drive();
  devices::intake = 127;
  chassis.set_drive_pid(60, DRIVE_SPEED * 0.5);
  chassis.wait_drive();

  // All off
  devices::intake = 0;
  devices::flywheel.move_velocity(0);
}

void awp() {
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.reset_pid_targets();

  // Set flywheel
  devices::flywheel.move_velocity(430);
  // devices::flywheel = 120;

  // Get roller 1
  devices::intake = 127;
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(50);
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
  chassis.set_turn_pid(-21, TURN_SPEED);
  chassis.wait_drive();

  // Shoot Triple Stack
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();

  // Drive to shoot 2
  devices::intake = 127;
  chassis.set_turn_pid(44, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(135, DRIVE_SPEED * .7);
  chassis.wait_drive();

  // Turn to face goal
  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_drive();

  shoot();
  pros::delay(SHOT_DELAY);
  shoot();
  pros::delay(SHOT_DELAY);
  shoot();

  // Drive to roller 2
  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-29, DRIVE_SPEED);
  chassis.wait_drive();

  // Get roller
  devices::intake = 127;
  chassis.set_swing_pid(ez::RIGHT_SWING, -90, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-4, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(50);

  // Turn everything off
  devices::intake = 0;
  devices::flywheel.move_velocity(0);
}
}  // namespace auton
