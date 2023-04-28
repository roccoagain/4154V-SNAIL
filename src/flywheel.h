#pragma once

namespace flywheel {

constexpr double p = 0.1;
constexpr double v = 0.21166666667;

void start_pid(double target);
void retarget_pid(double target);

}