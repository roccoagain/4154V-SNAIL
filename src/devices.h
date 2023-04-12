#pragma once
#include "main.h"

namespace devices {

// CONTROLLER
extern pros::Controller master;

// MOTORS
extern pros::Motor left_front;
extern pros::Motor left_raised;
extern pros::Motor left_back;
extern pros::Motor right_front;
extern pros::Motor right_raised;
extern pros::Motor right_back;

extern pros::Motor intake;
extern pros::Motor flywheel;

// PISTONS
extern pros::ADIDigitalOut indexer;
extern pros::ADIDigitalOut flywheel_angler;
extern pros::ADIDigitalOut expander;
extern pros::ADIDigitalOut intake_lifter;

void set_brakes(pros::motor_brake_mode_e);

}  // namespace devices
