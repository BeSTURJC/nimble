/*
 * flowControl.h
 *
 *  Created on: Mar 7, 2024
 *      Author: juan
 */

#ifndef INC_FLOWCONTROL_H_
#define INC_FLOWCONTROL_H_
#include <stdint.h>
struct mode{
	int8_t verbose; // defines the verbose state 0 off- 1 on
	int8_t controlMode; //Position 0, velocity 1
	char res_string[50];
};

struct controlSignals{
	double positionReference;
	double speedReference;
	int8_t direction; // 0 forward, 1 backwards

};

void initStrctures(void);

void printData(uint8_t* data, struct mode *controlMode, struct controlSignals* controlValues);


#endif /* INC_FLOWCONTROL_H_ */
