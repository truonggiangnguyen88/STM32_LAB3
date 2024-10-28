/*
 * button.h
 *
 *  Created on: Oct 23, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE		GPIO_PIN_SET
#define PRESSED_STATE		GPIO_PIN_RESET
#define NO_OF_BUTTONS		3
#define DURATION_FOR_AUTO_INCREASING 100


int is_button_pressed(int index);
int is_button_pressed_1s(int index);
void subKeyProcess();
void getKeyInput();



#endif /* INC_BUTTON_H_ */
