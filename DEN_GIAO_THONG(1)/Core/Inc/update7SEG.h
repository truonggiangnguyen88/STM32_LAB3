/*
 * update7SEG.h
 *
 *  Created on: Oct 23, 2024
 *      Author: ASUS
 */

#ifndef INC_UPDATE7SEG_H_
#define INC_UPDATE7SEG_H_
extern int index_led;
extern const int MAX_LED;
extern int led_buffer[4];
void update7SEG(int index);
void clear_all_led();
void scan_7SEG();
#endif /* INC_UPDATE7SEG_H_ */
