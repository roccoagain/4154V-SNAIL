#include "devices.h"

#include "main.h"

namespace devices {

pros::Controller master(pros::E_CONTROLLER_MASTER);

// MOTORS
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

// PISTONS
pros::ADIDigitalOut indexer('A');
pros::ADIDigitalOut flywheel_angler('B');
pros::ADIDigitalOut expander('C');
pros::ADIDigitalOut intake_lifter('D');

void set_brakes(pros::motor_brake_mode_e mode) {
  devices::flywheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  devices::left_front.set_brake_mode(mode);
  devices::left_raised.set_brake_mode(mode);
  devices::left_back.set_brake_mode(mode);
  devices::right_front.set_brake_mode(mode);
  devices::right_raised.set_brake_mode(mode);
  devices::right_back.set_brake_mode(mode);
}

}  // namespace devices
