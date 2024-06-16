/*
 * velocityControl.c
 *
 *  Created on: Mar 4, 2024
 *      Author: juan
 */

#include "motorControl.h"



void initControlStructure(double K, double zeroPosition, struct controlData *a){
	a->K=K;
	a->zeroPosition=zeroPosition;
	return;
}

double applySpeedControl(struct controlData *a){
	a->input[1]=a->input[0];

	a->input[0]=a->error;
	a->output[1]=a->output[0];
	a->output[0]=a->K*(a->input[0]-a->zeroPosition*a->input[1])+a->output[1];
	return fabs(a->output[0]);

}

double applyPosControl( struct controlData *a){
	a->input[1]=a->input[0];
	a->input[0]=a->error;
	a->output[1]=a->output[0];
	a->output[0]=a->K*(a->input[0]-a->zeroPosition*a->input[1]);
	if (a->error>=0){
		a->rotDirection=1;
	}
	else{
		a->rotDirection=0;
	}
	if (fabs(a->output[0]) > 50)
			return 50;
	return fabs(a->output[0]);
}
