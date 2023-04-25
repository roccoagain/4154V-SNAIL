#include "devices.h"

#include "main.h"

namespace devices {

pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors
pros::Motor right_front(1, pros::E_MOTOR_GEARSET_06, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_raised(2, pros::E_MOTOR_GEARSET_06, true,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_back(3, pros::E_MOTOR_GEARSET_06, false,
                       pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_front(4, pros::E_MOTOR_GEARSET_06, true,
                       pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_raised(5, pros::E_MOTOR_GEARSET_06, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_back(6, pros::E_MOTOR_GEARSET_06, true,
                      pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor intake(8, pros::E_MOTOR_GEARSET_06, false,
                   pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel(9, pros::E_MOTOR_GEARSET_06, true,
                     pros::E_MOTOR_ENCODER_COUNTS);

// Pistons
pros::ADIDigitalOut indexer('A');
pros::ADIDigitalOut flywheel_angler('B');
pros::ADIDigitalOut expander('E');
pros::ADIDigitalOut intake_lifter('D');

void set_brakes(pros::motor_brake_mode_e mode) {
  flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  left_front.set_brake_mode(mode);
  left_raised.set_brake_mode(mode);
  left_back.set_brake_mode(mode);
  right_front.set_brake_mode(mode);
  right_raised.set_brake_mode(mode);
  right_back.set_brake_mode(mode);
}

}  // namespace devices
