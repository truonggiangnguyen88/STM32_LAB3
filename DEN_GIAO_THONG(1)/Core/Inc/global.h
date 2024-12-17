/*
 * global.h
 *
 *  Created on: Oct 27, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "display7SEG.h"
#include "software_timer.h"
#include "button.h"
#include "traffic_light.h"
#include "update7SEG.h"
#include "fsm_manual.h"
#include "fsm_setting.h"
#include "fsm_automatic.h"
#define INIT 			1
#define RED1_GREEN2		2
#define RED1_YELLOW2	3
#define GREEN1_RED2		4
#define YELLOW1_RED2	5

#define SETTING_RED			11
#define SETTING_GREEN		12
#define SETTING_YELLOW		13

extern int status;

extern int timeRed;
extern int timeYellow;
extern int timeGreen;
extern int duration_red;
extern int duration_yellow;
extern int duration_green;
extern int mode;
extern int led_buffer[4];
extern int index7SEG;
extern int timeWay1;
extern int timeWay2;
extern int selected_duration;
extern int index_led;
extern const int MAX_LED;
#endif /* INC_GLOBAL_H_ */
