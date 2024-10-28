/*
 * run_traffic_light.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ASUS
 */
#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic(){
	switch(status){
		case INIT:
			clear_all_led();
			timeWay1 = timeRed;
			timeWay2 = timeGreen;
			status = RED1_GREEN2;
			setTimer(0, timeGreen*100);
			setTimer(1, 2);
			setTimer(2, 3);
			setTimer(3, 5);
			setTimer(4, 7);
			break;

		case RED1_GREEN2:
			red1_and_green2();
			if(timer_flag1[0] == 1){
				setTimer(0, timeYellow*100);
				status = RED1_YELLOW2;
				timeWay2 = timeYellow;
			}

			if(timer_flag1[1] == 1){
				setTimer(1, 100);
				timeWay1--;
				timeWay2--;
			}
			led_buffer[0] = timeWay1/10;
			led_buffer[1] = timeWay1%10;
			led_buffer[2] = timeWay2/10;
			led_buffer[3] = timeWay2%10;

			if(is_button_pressed(0) == 1){
				status = SETTING_RED;
				setTimer(3, 5);
				selected_duration = timeRed;
				clear_all_led();
			 }
			scan_7SEG();
			break;
		case RED1_YELLOW2:
			red1_and_yellow2();
			if(timer_flag1[0] == 1){
				setTimer(0, timeGreen*100);
				status = GREEN1_RED2;
				timeWay1 = timeGreen;
				timeWay2 = timeRed;
			}
			if(timer_flag1[1] == 1){
				setTimer(1, 100);
				timeWay1--;
				timeWay2--;
			}
			led_buffer[0] = timeWay1/10;
			led_buffer[1] = timeWay1%10;
			led_buffer[2] = timeWay2/10;
			led_buffer[3] = timeWay2%10;

			if(is_button_pressed(0) == 1){
				status = SETTING_RED;
				setTimer(3, 5);
				selected_duration = timeRed;
				clear_all_led();
			 }
			scan_7SEG();
			break;
		case GREEN1_RED2:
			green1_and_red2();
			if(timer_flag1[0] == 1){
				setTimer(0, timeYellow*100);
				status = YELLOW1_RED2;
				timeWay1 = timeYellow;
				//timeWay2 = timeYellow;
			}
			if(timer_flag1[1] == 1){
				setTimer(1, 100);
				timeWay1--;
				timeWay2--;
			}
			led_buffer[0] = timeWay1/10;
			led_buffer[1] = timeWay1%10;
			led_buffer[2] = timeWay2/10;
			led_buffer[3] = timeWay2%10;

			if(is_button_pressed(0) == 1){
				status = SETTING_RED;
				setTimer(3, 5);
				selected_duration = timeRed;
				clear_all_led();
			 }
			scan_7SEG();
			break;
		case YELLOW1_RED2:
			yellow1_and_red2();
			if(timer_flag1[0] == 1){
				setTimer(0, timeGreen*100);
				status = RED1_GREEN2;
				timeWay1 = timeRed;
				timeWay2 = timeGreen;
			}
			if(timer_flag1[1] == 1){
				setTimer(1, 100);
				timeWay1--;
				timeWay2--;
			}
			led_buffer[0] = timeWay1/10;
			led_buffer[1] = timeWay1%10;
			led_buffer[2] = timeWay2/10;
			led_buffer[3] = timeWay2%10;

			if(is_button_pressed(0) == 1){
				status = SETTING_RED;
				selected_duration = timeRed;
				clear_all_led();
			 }
			scan_7SEG();
			break;
		default:
			break;
		}
}

