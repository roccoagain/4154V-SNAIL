#include "flywheel.h"

#include "devices.h"
#include "main.h"

namespace flywheel {

void start_pid(double target) {
  double kP = 0.25;
  double kV = 0.21166;  // 127/600 (max voltage / max rpm)

  double error = 0;
  double prevError = 0;

  double output = 0;

  while (true) {
    // CALCULATE VOLTAGE
    error = target - devices::flywheel.get_actual_velocity();
    output = (kV * target) + (kP * error);

    // CLAMP VOLTAGE
    if (output > 127) {
      output = 127;
    }
    if (output < 0) {
      output = 0;
    }

    // SET VOLTAGE
    devices::flywheel.move(output);
    pros::delay(100);

    // OUTPUT FOR TUNING
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

}
