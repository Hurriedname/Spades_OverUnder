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
LV_IMG_DECLARE(SpadeCardFull);
int auton;
static lv_res_t btn_far_side(lv_obj_t * btn){
	uint8_t id = lv_obj_get_free_num(btn);
	auton++;
	switch(auton){
		case(1):
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Far Side");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;

		case(2):
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Close Side");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;

		case(3):
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Far Side Elim");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;

		case(4):
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Close Side Elim");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;

		case(5):
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Skills");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;

		case(6):
		auton = 1;
		lv_obj_clean(lv_scr_act());
		spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
		lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
		lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
		lv_obj_set_style(spade4, &buttonPressed);
		lv_obj_set_style(spade4, &buttonReleased);
		lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);
		nameBox = lv_label_create(lv_scr_act(), NULL);
		lv_label_set_text(nameBox, "Far Side");
		lv_obj_align(nameBox, NULL ,LV_ALIGN_CENTER, 0 , 0);
		break;
	}
	return LV_RES_OK;
}
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
pros::Motor frontLeft(4, MOTOR_GEAR_600, true);
pros::Motor middleLeft(6, MOTOR_GEAR_600, true);
pros::Motor backLeft(3, MOTOR_GEAR_600, true);

//Define Right Motors;
pros::Motor frontRight(12, MOTOR_GEAR_600, false);
pros::Motor middleRight(16, MOTOR_GEAR_600, false);
pros::Motor backRight(13, MOTOR_GEAR_600, false);

//Group Left & Right Motors;
pros::Motor_Group leftSideDrive({frontLeft, middleLeft, backLeft});
pros::Motor_Group rightSideDrive({frontRight, middleRight, backRight});

//Define Intake;
pros::Motor intake(1, MOTOR_GEAR_600, true);

//pros::Imu intertialSensor();
pros::Rotation verticalSensor(17);
lemlib::TrackingWheel verticalTracker(&verticalSensor , lemlib::Omniwheel::NEW_275_HALF , 0 );
//Define Odomsensors
lemlib::OdomSensors sensors{ &verticalTracker, nullptr, nullptr, nullptr, &inertialSensor};
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

void autonSelctor(){
}
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
		pros::lcd::initialize;
	spadeDrive.calibrate();
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
		spadeDrive.calibrate();
	pros::screen::erase;

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

	spade4 = lv_imgbtn_create(lv_scr_act(), NULL);
	lv_imgbtn_set_action(spade4, LV_BTN_ACTION_CLICK, btn_far_side);
	lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_REL, &SpadeCardFull);
	lv_imgbtn_set_src(spade4, LV_IMGBTN_STYLE_PR, &SpadeCardFull);
	lv_obj_set_style(spade4, &buttonPressed);
	lv_obj_set_style(spade4, &buttonReleased);
	lv_obj_align(spade4, NULL, LV_ALIGN_CENTER, 0,0);

	nameBox = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(nameBox, "Button Not Clicked");
	lv_obj_align(nameBox, NULL, LV_ALIGN_CENTER, 10, 0);
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
	// switch (auton)
	// {
	// case(1):
	// 	spadeDrive.setPose(0,0, 0);
	// 	spadeDrive.moveTo(10,10, 0, 2000);
	// 	break;
	// case(2):
	// 	leftSideDrive.move(100);
	// 	break;
	// case(3):
	// 	rightSideDrive.move(100);
	// 	break;
	// case(4):
	// 	intake.move(-100);
	// 	break;
	// case(5):
	// 	rightSideDrive.move(100);
	// 	leftSideDrive.move(100);
	// 	break;
	// }
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
pros::Controller spades(pros::E_CONTROLLER_MASTER);

void intakeController(){
  while (true){
    if(spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1)){
      intake.move(-127);
    }
    else if(spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2)){
      intake.move(127);
    }
    else{
      intake = 0;
    }
  }
}
// void pneumaticController(){
//   bool wingsToggle = true;
//   bool blockerToggle = true;
//   while(true){
//       if(wingsToggle == false && spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2)){
//         wings.set_value(true);
//         pros::delay(100);
//         wingsToggle = true;
//       }
//       else if (wingsToggle == true && spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2)){
//         wings.set_value(false);
//         pros::delay(100);
//         wingsToggle = false;
//       }
//       if(blockerToggle == false && spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_A)){
//         blocker.set_value(true);
//         pros::delay(100);
//         blockerToggle = true;
//       }
//       else if (blockerToggle == true && spades.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_A)){
//         blocker.set_value(false);
//         blockerToggle = false;
//       }
//       pros::delay(100);
//   }
// }
// void cardController(){
// 	if(true){
// 		lv_obj_clean(lv_scr_act());
// 		spade1 = lv_img_create(lv_scr_act(), NULL);
// 		lv_img_set_src(spade1, &SpadeCardFull);
// 		lv_obj_align(spade1, NULL, LV_ALIGN_CENTER, 0,0);
// 	}
// }
void flywheelController(){
	while (true);{

	}
	
}
void driveController(){
	while (true){
		//Fetch Analog Positions
		int leftY = spades.get_analog(ANALOG_LEFT_Y);
		int rightX = spades.get_analog(ANALOG_RIGHT_X);
			
		//Move the Robot
		spadeDrive.arcade(leftY, rightX);
		}
}
void opcontrol() {
	pros::Task::create(driveController);
	pros::Task::create(intakeController);
}
