#pragma once

namespace flywheel {
/**
 * @brief Updates flywheel voltage for target RPM using error.
 * @param target Target motor RPM from 0-600
 */
void start_pid(double target);

/**
 * @brief Creates a flywheel PID task. Any existing flywheel PIDs is
 * overwritten.
 * @param target Target motor RPM from 0-600
 */
void retarget_pid(double target);

}