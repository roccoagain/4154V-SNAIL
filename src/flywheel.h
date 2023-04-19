#pragma once

namespace flywheel {

constexpr double p = 0.25;
constexpr double v = 0.21166;

void start_pid(double target);
void retarget_pid(double target);

}