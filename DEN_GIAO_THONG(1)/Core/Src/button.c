/*
 * button.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ASUS
 */

#include "button.h"
static  GPIO_PinState		buttonBuffer[NO_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static	GPIO_PinState		Key0[NO_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static	GPIO_PinState		Key1[NO_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static	GPIO_PinState		Key2[NO_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
static	int 				button_flag_Press[NO_OF_BUTTONS] = {0, 0, 0};
static	int					button_flag_Press1s[NO_OF_BUTTONS] = {0, 0, 0};
static	int					counter_button_flag_Press1s[NO_OF_BUTTONS] = {0, 0, 0};
GPIO_TypeDef* Button_Ports[] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t Button_Pins[] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int is_button_pressed(int index){
	if(button_flag_Press[index] == 1){
		button_flag_Press[index] = 0;
		return 1;
	}
	return 0;
}

int is_button_pressed_1s(int index){
	if(button_flag_Press1s[index] == 1){
		button_flag_Press1s[index] = 0;
		return 1;
	}
	return 0;
}


void getKeyInput(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		Key0[i] = Key1[i];
		Key1[i] = Key2[i];
		Key2[i] = HAL_GPIO_ReadPin(Button_Ports[i], Button_Pins[i]);
		if((Key0[i] == Key1[i]) && (Key1[i] == Key2[i])){
			if(buttonBuffer[i] != Key2[i]){
				buttonBuffer[i] = Key2[i];
				if(Key2[i] == PRESSED_STATE){
					//todo
					button_flag_Press[i] = 1;
				}
			}
			else{
				counter_button_flag_Press1s[i]++;
				if(counter_button_flag_Press1s[i] >= DURATION_FOR_AUTO_INCREASING){
					if(Key2[i] == PRESSED_STATE){
						button_flag_Press1s[i] = 1;
					}
					counter_button_flag_Press1s[i] = 0;
				}
			}
		}
	}
}

//	Key0 = Key1;
//	Key1 = Key2;
//	Key2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//	if((Key0 == Key1) && (Key1 == Key2)){
//		if(Key3 != Key2){
//			Key3 = Key2;
//			if(Key2 == PRESSED_STATE){
//				subKeyProcess();
//				TimerForKeyPress = 200;
//			}
//		}
//		else{
//			TimerForKeyPress--;
//			if(TimerForKeyPress == 0){
//				Key3 = NORMAL_STATE;
//			}
//		}
//	}
//}

