#include "flywheel.h"

#include "devices.h"
#include "main.h"

void flywheelPID(double target) {
  double kP = 0.25;
  double kV = 0.21166;  // 127/600

  double error = 0;
  double prevError = 0;

  double output = 0;

  while (true) {
    error = target - flywheel.get_actual_velocity();
    output = (kV * target) + (kP * error);

    // CLAMP
    if (output > 127) {
      output = 127;
    }
    if (output < 0) {
      output = 0;
    }

    flywheel.move(output);

    // OUTPUT FOR TUNING
    // printf("%lf error \n", error);
    // printf("%lf output \n", output);
    // printf("%lf RPM \n \n", flywheel.get_actual_velocity());

    // prevError = error;
    pros::delay(100);
  }
}

void set_flywheel_speed(double target) {
  static std::unique_ptr<pros::Task> pidTask{};
  if (pidTask != nullptr) {
    pidTask->remove();
  }
  pidTask = (target == -1)
                ? nullptr
                : std::make_unique<pros::Task>([=] { flywheelPID(target); });
}
