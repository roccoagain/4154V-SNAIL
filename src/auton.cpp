#include "auton.h"

#include "devices.h"
#include "main.h"

// DRIVE CONSTANTS
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;
const int INDEXER_HOLD = 300;  // ms
const int INDEXER_RESET = 900; // ms

// EZ TEMPLATE CHASSIS SETUP
const std::vector<int> LEFT_MOTOR_PORTS = {2, 1, 3};
const std::vector<int> RIGHT_MOTOR_PORTS = {5, 4, 6};
const int IMU_PORT = 10;
const double WHEEL_DIAMETER = 3.25;
const int CARTRIDGE_RPM = 600;
// eg. if your drive is 84:36 where the 36t is sensored, your RATIO would
// be 2.333. eg. if your drive is 36:60 where the 60t is sensored, your RATIO
// would be 0.6.
const double EXTERNAL_GEAR_RATIO = 1.666;
Drive chassis(LEFT_MOTOR_PORTS, RIGHT_MOTOR_PORTS, IMU_PORT, WHEEL_DIAMETER,
              CARTRIDGE_RPM, EXTERNAL_GEAR_RATIO);

void snail_constants()
{
    chassis.set_slew_min_power(80, 80);
    chassis.set_slew_distance(7, 7);
    chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
    chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
    chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
    chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
    chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

// CUSTOM FUNCTIONS
void spin_roller(int time)
{
    intake = -127;
    pros::delay(time);
    intake = 0;
}

void index(int shot_count = 1)
{
    for (int i = 0; i < shot_count; i++)
    {
        indexer.set_value(true);
        pros::delay(INDEXER_HOLD);
        indexer.set_value(false);
        pros::delay(INDEXER_RESET);
    }
}

// AUTONS
void skills()
{
    // TODO
}

void left()
{
    // TODO
}

void right()
{
    // TODO
}

void awp()
{
    // TODO
}

void test()
{
    chassis.set_drive_pid(30, DRIVE_SPEED);
    chassis.wait_drive();

    intake = 127;
    pros::delay(2000);
    intake = -127;
}
