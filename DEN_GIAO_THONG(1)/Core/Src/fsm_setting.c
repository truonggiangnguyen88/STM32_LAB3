/*
 * fsm_setting.c
 *
 *  Created on: Oct 28, 2024
 *      Author: ASUS
 */


#include "global.h"
void fsm_setting(){
	switch(status){
	case SETTING_RED:
		if(timer_flag1[3] == 1){
			setTimer(3, 25);
			blink_red1_and_red2();
		}
		if(is_button_pressed(1) == 1){
			selected_duration++;
		}
		if(is_button_pressed_1s(1) == 1){
			if(timer_flag1[4] == 1){
				setTimer(4, 50);
				selected_duration++;
			}
		}
		if(is_button_pressed(2) == 1){
			duration_red = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = SETTING_GREEN;
			mode = 3;
			selected_duration = timeGreen;
			duration_green = timeGreen;
			clear_all_led();
		}
		scan_7SEG();
		break;
	case SETTING_GREEN:
		if(timer_flag1[3] == 1){
			setTimer(3, 25);
			blink_green1_and_green2();
		}

		if(is_button_pressed(1) == 1){
			selected_duration++;
		}
		if(is_button_pressed_1s(1) == 1){
			if(timer_flag1[4] == 1){
				setTimer(4, 50);
				selected_duration++;
			}
		}
		if(is_button_pressed(2) == 1){
			duration_green = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = SETTING_YELLOW;
			mode = 4;
			selected_duration = timeYellow;
			duration_yellow = timeYellow;
			clear_all_led();
		}
		scan_7SEG();
		break;
	case SETTING_YELLOW:
		if(timer_flag1[3] == 1){
			setTimer(3, 25);
			blink_yellow1_and_yellow2();
		}

		if(is_button_pressed(1) == 1){
			selected_duration++;
		}
		if(is_button_pressed_1s(1) == 1){
			if(timer_flag1[4] == 1){
				setTimer(4, 50);
				selected_duration++;
			}
		}
		if(is_button_pressed(2) == 1){
			duration_yellow = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = INIT;
			if(duration_red == duration_green + duration_yellow){
				timeRed = duration_red;
				timeGreen = duration_green;
				timeYellow = duration_yellow;
			}
		}
		scan_7SEG();
		break;
	default:
		break;
	}
}
