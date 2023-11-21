#include "main.h"
#include "lemlib/api.hpp"

//Define IMU
pros::Imu inertialSensor (12);

//Define Left Motors;
pros::Motor frontLeft(MOTOR_GEAR_600, true);
pros::Motor middleLeft(MOTOR_GEAR_600, true);
pros::Motor backLeft(MOTOR_GEAR_600, true);

//Define Right Motors;
pros::Motor frontRight(MOTOR_GEAR_600, false);
pros::Motor middleRight(MOTOR_GEAR_600, false);
pros::Motor backRight(MOTOR_GEAR_600, false);

//Group Left & Right Motors;
pros::Motor_Group leftSideDrive({frontLeft, middleLeft, backLeft});
pros::Motor_Group rightSideDrive({frontRight, middleRight, backRight});

//Define Odomsensors
lemlib::OdomSensors sensors{nullptr, nullptr, nullptr, nullptr, &inertialSensor};

//Define Chassis Properties
lemlib::Drivetrain drivetrain{
	&leftSideDrive, //Left Side of Drive
	&rightSideDrive, //Right Side of Drive
	12.6, //Wheel to Wheel Distance in inches
	lemlib::Omniwheel::NEW_325, //Wheel Size in inches
	360, //Wheel RPM
	8
	};

//PID for Linear Movement
lemlib::ControllerSettings linearController(
    10,
    30,
    1,
    100,
    3,
    500,
    20
);

//PID for Angular Movement
lemlib::ControllerSettings angularController(
    2,
    10,
    1,
    100,
    3,
    500,
    0
);

//Combine All Definitions
lemlib::Chassis spadeDrive(drivetrain, linearController, angularController, sensors);


void testAuton(){
	spadeDrive.moveTo(0, 0, 0, 1000);
}
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	spadeDrive.calibrate();

	//Print X, Y, & Heading to Brain
	pros::Task screenTask([&](){
		while(true){
			lemlib::Pose pose = spadeDrive.getPose();
			pros::lcd::print(0, "X: %F", pose.x);
			pros::lcd::print(1, "Y: %F", pose.y);
			pros::lcd::print(2, "Heading_Angle: %F", pose.theta);
			pros::delay(10); 
		}
	});
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	spadeDrive.setPose(0,0,0);
	spadeDrive.turnTo(10,10,1000,false);
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while (true) {
		//Fetch Analog Positions
		int leftY = master.get_analog(ANALOG_LEFT_Y);
		int rightX = master.get_analog(ANALOG_RIGHT_X);
		
		//Move the Robot
		spadeDrive.arcade(leftY, rightX, 10);


		pros::delay(10);
	}
}
