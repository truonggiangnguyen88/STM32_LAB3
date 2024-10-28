/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2024
 *      Author: ASUS
 */

#include "software_timer.h"


int timer_counter1[5];
int timer_flag1[5];

void setTimer(int index, int counter){
	timer_counter1[index] = counter;
	timer_flag1[index] = 0;
}

void timerRun(){
	for(int i = 0; i < 5; i++){
		if(timer_counter1[i] > 0){
			timer_counter1[i]--;
			if(timer_counter1[i] <= 0){
			timer_flag1[i] = 1;

			}
		}
	}
}

