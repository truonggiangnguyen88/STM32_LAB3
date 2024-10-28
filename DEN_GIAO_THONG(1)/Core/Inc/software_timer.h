/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
extern int timer_flag1[5];

void setTimer(int index, int counter);
void timerRun();



#endif /* INC_SOFTWARE_TIMER_H_ */
