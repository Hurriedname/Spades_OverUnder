#include "main.h"
#include "lemlib/api.hpp"

lv_obj_t * nameBox;
lv_obj_t * describingBox;
lv_obj_t * spade1;
lv_obj_t * spade2;
lv_obj_t * spade3;
lv_obj_t * spade4;
lv_obj_t * nextButton;
lv_obj_t * previousButton;
lv_obj_t * page1;
lv_obj_t * page2;

lv_style_t buttonPressed;
lv_style_t buttonReleased;

static lv_res_t btn_click_action(lv_obj_t * btn){
	uint8_t id = lv_obj_get_free_num(btn);
	if(id == 0){
		char buffer[100];
		sprintf(buffer, "Button was Clicked %i msec from start", pros::millis);
		lv_label_set_text(nameBox, buffer);
	}
	return LV_RES_OK;
}
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
//Very Basic Auton Selector
/*int autonSelection(){
	int auton;
	int line = 1;
	bool pressed;
	pros::screen::set_pen(COLOR_WHITE);
	pros::screen::fill_rect(1, 1, 480, 272);
	pros::screen::set_pen(COLOR_BLACK);
	pros::screen::draw_rect(11, 34, 240, 50);
	pros::screen::draw_rect(11, 60, 240, 200);
	pros::screen::fill_circle(320, 68, 35);
	pros::screen::fill_circle(420, 68, 35);
	pros::screen::fill_circle(320, 150, 35);
	pros::screen::fill_circle(420, 150, 35);
	pros::screen::draw_rect(385, 200, 455, 230);
	pros::screen::draw_rect(285, 200, 355, 230);
	while(1){
		pros::screen_touch_status_s_t draw = pros::screen::touch_status();
		if ( 385 < draw.x && draw.x < 455 && draw.y > 33 && draw.y < 103){
			pros::screen::erase_rect(12, 35, 239, 49);
			pros::screen::set_pen(COLOR_CYAN);
			pros::screen::print(TEXT_MEDIUM, 12, 34, "CLOSE SIDE AUTON");
			}
			pros::
		else if ( 285 < draw.x && draw.x < 355 && draw.y > 33 && draw.y < 103){
			pros::screen::erase_rect(12, 35, 239, 49);
			pros::screen::set_pen(COLOR_CYAN);
			pros::screen::print(TEXT_MEDIUM, 12, 34, "FAR SIDE AUTON");
			}
		else if ( 385 < draw.x && draw.x < 455 && draw.y > 33 && draw.y < 103){
			pros::screen::erase_rect(12, 35, 239, 49);
			pros::screen::set_pen(COLOR_CYAN);
			pros::screen::print(TEXT_MEDIUM, 12, 34, "CLOSE SIDE AUTON");
			}
		}
}*/
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
	pros::screen::erase;
	//pros::Task::create(autonSelection);
	lv_style_copy(&buttonReleased, &lv_style_plain);
	buttonReleased.body.main_color.blue;
	buttonReleased.body.grad_color.green;
	buttonReleased.body.radius = 0;
	buttonReleased.text.color = LV_COLOR_WHITE;
	
	lv_style_copy(&buttonPressed, &lv_style_plain);
	buttonPressed.body.main_color.blue;
	buttonPressed.body.grad_color.green;
	buttonPressed.body.radius = 0;
	buttonPressed.text.color = LV_COLOR_WHITE;

	spade1 = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_free_num(spade1, 0);
	lv_btn_set_action(spade1, LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(spade1, LV_KB_STYLE_BTN_REL, &buttonReleased);
	lv_btn_set_style(spade1, LV_KB_STYLE_BTN_PR, &buttonPressed);
	lv_obj_set_size(spade1, 200, 50);
	lv_obj_align(spade1, NULL, LV_ALIGN_IN_TOP_MID, 10, 10);

	describingBox = lv_label_create(spade1, NULL);
	lv_label_set_text(describingBox, "Click This");

	nameBox = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(nameBox, "Button Not Clicked");
	lv_obj_align(nameBox, NULL, LV_ALIGN_CENTER, 10, 0);
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
void competition_initialize() {


}

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
	spadeDrive.setPose(5,5,0);
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
pros::Controller master(pros::E_CONTROLLER_MASTER);
void opcontrol() {
	
	while (true) {
		//Fetch Analog Positions
		int leftY = master.get_analog(ANALOG_LEFT_Y);
		int rightX = master.get_analog(ANALOG_RIGHT_X);
		
		//Move the Robot
		spadeDrive.arcade(leftY, rightX);


		pros::delay(10);
	}
}
