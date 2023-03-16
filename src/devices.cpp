#include "devices.h"

#include "main.h"

// CONTROLLER
pros::Controller master(pros::E_CONTROLLER_MASTER);

// // MOTORS
// pros::Motor left_front(1, pros::E_MOTOR_GEARSET_06, true,
//                        pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor left_middle(2, pros::E_MOTOR_GEARSET_06, true,
//                         pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor left_back(3, pros::E_MOTOR_GEARSET_06, true,
//                       pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor right_front(4, pros::E_MOTOR_GEARSET_06, false,
//                         pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor right_middle(5, pros::E_MOTOR_GEARSET_06, false,
//                          pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor right_back(6, pros::E_MOTOR_GEARSET_06, false,
//                        pros::E_MOTOR_ENCODER_COUNTS);

// pros::Motor intake(7, pros::E_MOTOR_GEARSET_06, true,
//                    pros::E_MOTOR_ENCODER_COUNTS);
// pros::Motor flywheel(8, pros::E_MOTOR_GEARSET_06, false,
//                      pros::E_MOTOR_ENCODER_COUNTS);

// MOTORS
pros::Motor left_front(4, pros::E_MOTOR_GEARSET_06, true,
                       pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_middle(9, pros::E_MOTOR_GEARSET_06, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_back(10, pros::E_MOTOR_GEARSET_06, true,
                      pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_front(2, pros::E_MOTOR_GEARSET_06, false,
                        pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_middle(1, pros::E_MOTOR_GEARSET_06, true,
                         pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_back(8, pros::E_MOTOR_GEARSET_06, false,
                       pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor intake(19, pros::E_MOTOR_GEARSET_06, true,
                   pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel(20, pros::E_MOTOR_GEARSET_06, false,
                     pros::E_MOTOR_ENCODER_COUNTS);

// PISTONS
pros::ADIDigitalOut indexer('A');
pros::ADIDigitalOut angler('B');
pros::ADIDigitalOut expander('C');
pros::ADIDigitalOut lifter('D');
