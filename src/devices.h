#pragma once
#include "main.h"

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
extern pros::ADIDigitalOut angler;
extern pros::ADIDigitalOut expander;
extern pros::ADIDigitalOut lifter;
