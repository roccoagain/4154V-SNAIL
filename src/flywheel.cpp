#include "flywheel.h"

#include "devices.h"
#include "main.h"

namespace flywheel {

constexpr double p = 0.25;
constexpr double v = 0.21166;

void start_pid(double target) {
  // 127/600 (max voltage / max rpm)

  double error = 0;
  double prevError = 0;

  double output = 0;

  while (true) {
    // Calculate voltage
    error = target - devices::flywheel.get_actual_velocity();
    output = (v * target) + (p * error);
    std::clamp(output, 0.0, 127.0);

    // Set voltage
    devices::flywheel.move(output);
    pros::delay(100);

    // Debug
    // printf("%lf error \n", error);
    // printf("%lf output \n", output);
    printf("%lf RPM \n \n", devices::flywheel.get_actual_velocity());
  }
}

void retarget_pid(double target) {
  static std::unique_ptr<pros::Task> pidTask{};
  if (pidTask != nullptr) {
    pidTask->remove();
  }
  pidTask = (target == -1)
                ? nullptr
                : std::make_unique<pros::Task>([=] { start_pid(target); });
}

}  // namespace flywheel
