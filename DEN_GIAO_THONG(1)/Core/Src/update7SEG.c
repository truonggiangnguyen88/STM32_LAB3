

/*
 * update7SEG.c
 *
 *  Created on: Oct 20, 2024
 *      Author: ASUS
 */

#include "update7SEG.h"
#include "global.h"

void scan_7SEG(){
	if(timer_flag1[2] == 1){
		if(mode == 1){
			led_buffer[0] = timeWay1/10;
			led_buffer[1] = timeWay1%10;
			led_buffer[2] = timeWay2/10;
			led_buffer[3] = timeWay2%10;
		}
		if(mode > 1){
			led_buffer[0] = selected_duration/10;
			led_buffer[1] = selected_duration%10;
			led_buffer[2] = mode/10;
			led_buffer[3] = mode%10;
		}
		setTimer(2, 25);
		update7SEG(index_led++);
		if(index_led >= MAX_LED) index_led = 0;
	}
}
void update7SEG(int index) {
    switch (index) {
        case 0:
            display7SEG(led_buffer[0]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 1:
            display7SEG(led_buffer[1]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 2:
            display7SEG(led_buffer[2]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 3:
            display7SEG(led_buffer[3]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

