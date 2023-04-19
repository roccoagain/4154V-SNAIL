#pragma once
#include <vector>

namespace auton {

constexpr int DRIVE_SPEED = 110;
constexpr int TURN_SPEED = 90;
constexpr int SWING_SPEED = 90;
constexpr int SHOT_DELAY = 700;

const std::vector<int> LEFT_MOTOR_PORTS = {-4, 5, -6};
const std::vector<int> RIGHT_MOTOR_PORTS = {1, -2, 3};
constexpr int IMU_PORT = 7;
constexpr double WHEEL_DIAMETER = 2.75;
constexpr int CARTRIDGE_RPM = 600;
const double EXTERNAL_GEAR_RATIO = .8;  // 48:60

void snail_constants();
void skills();
void left();
void right();
void awp();
}