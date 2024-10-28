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

		led_buffer[0] = selected_duration/10;
		led_buffer[1] = selected_duration%10;
		led_buffer[2] = 2/10;
		led_buffer[3] = 2%10;

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
			timeRed = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = SETTING_GREEN;
			selected_duration = timeGreen;
			clear_all_led();
		}
		scan_7SEG();
		break;
	case SETTING_GREEN:
		if(timer_flag1[3] == 1){
			setTimer(3, 25);
			blink_green1_and_green2();
		}

		led_buffer[0] = selected_duration/10;
		led_buffer[1] = selected_duration%10;
		led_buffer[2] = 3/10;
		led_buffer[3] = 3%10;

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
			timeGreen = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = SETTING_YELLOW;
			selected_duration = timeYellow;
			clear_all_led();
		}
		scan_7SEG();
		break;
	case SETTING_YELLOW:
		if(timer_flag1[3] == 1){
			setTimer(3, 25);
			blink_yellow1_and_yellow2();
		}

		led_buffer[0] = selected_duration/10;
		led_buffer[1] = selected_duration%10;
		led_buffer[2] = 4/10;
		led_buffer[3] = 4%10;

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
			timeYellow = selected_duration;
		}
		if(is_button_pressed(0) == 1){
			status = INIT;
			selected_duration = 0;
			clear_all_led();
		}
		scan_7SEG();
		break;
	default:
		break;
	}
}
