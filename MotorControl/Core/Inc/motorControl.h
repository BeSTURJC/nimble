/*
 * velocityControl.h
 *
 *  Created on: Mar 4, 2024
 *      Author: juan
 */

#ifndef INC_VELOCITYCONTROL_H_
#define INC_VELOCITYCONTROL_H_

#include <math.h>

struct controlData{
	double output[2];
	double input[2];
	double K;
	double zeroPosition;
	double error;
	double positionReference;
	double speedReference;
	double rotDirection;

};
void initControlStructure(double K, double zeroPosition, struct controlData *a);

double applySpeedControl( struct controlData *a);

double applyPosControl( struct controlData *a);

#endif /* INC_VELOCITYCONTROL_H_ */
