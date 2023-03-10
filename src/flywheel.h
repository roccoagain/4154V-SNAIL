#pragma once

/**
 * @brief Updates flywheel voltage for target RPM using error.
 * @param target Target motor RPM from 0-600
 */
void flywheelPID(double target);

/**
 * @brief Creates a flywheel PID task. Any existing flywheel PIDs is
 * overwritten.
 * @param target Target motor RPM from 0-600
 */
void set_flywheel_speed(double target);