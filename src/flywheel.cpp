#include "flywheel.h"

#include "devices.h"
#include "main.h"

void flywheelPID(double target) {
  double kP = 0.25;
  double kV = 0.21166;  // 127/600 (max voltage / max rpm)

  double error = 0;
  double prevError = 0;

  double output = 0;

  while (true) {
    // CALCULATE VOLTAGE
    error = target - flywheel.get_actual_velocity();
    output = (kV * target) + (kP * error);

    // CLAMP VOLTAGE
    if (output > 127) {
      output = 127;
    }
    if (output < 0) {
      output = 0;
    }

    // SET VOLTAGE
    flywheel.move(output);
    pros::delay(100);

    // OUTPUT FOR TUNING
    // printf("%lf error \n", error);
    // printf("%lf output \n", output);
    // printf("%lf RPM \n \n", flywheel.get_actual_velocity());
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
