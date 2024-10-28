/*
 * global.c
 *
 *  Created on: Oct 27, 2024
 *      Author: ASUS
 */



#include "global.h"
int status = INIT;
int timeRed = 5;
int timeYellow = 2;
int timeGreen = 3;
int timeWay1 = 0;
int timeWay2 = 0;
int selected_duration = 0;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4]={0} ;
