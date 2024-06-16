/*
 * flowcontrol.c
 *
 *  Created on: Mar 7, 2024
 *      Author: juan
 */
#include "flowControl.h"

void initMainStructures( struct mode *controlMode, struct controlSignals* controlValues){
	controlMode->controlMode=0;
	controlMode->verbose=0;
	controlValues->direction=0;
	controlValues->positionReference=0;
	controlValues->speedReference=0;
}

void printData(uint8_t* data, struct mode *controlMode, struct controlSignals* controlValues){
	memset(controlMode->res_string, '\000', sizeof(controlMode->res_string));
	if( data[0]=='P' && strcmp(data,"POSITION")){
		double extractedNumber;
		if (sscanf(data, "P%lf", &extractedNumber) == 1) {
			sprintf(controlMode->res_string, "Position reference updated to %.2f\r\n", extractedNumber);
			controlValues->positionReference=extractedNumber;
		}
		else{
			sprintf(controlMode->res_string,"Error format is P0.000\r\n");
		}

	}
	else if( data[0]=='V' && (strcmp(data,"VERBOSE0")!=0 && strcmp(data,"VELOCITY")!=0) ){
		double extractedNumber;
		if (sscanf(data, "V%lf", &extractedNumber) == 1) {
			sprintf(controlMode->res_string, "Velocity reference updated to %.2f\r\n", extractedNumber);
			controlValues->speedReference=extractedNumber;
		}
		else{
			sprintf(controlMode->res_string,"Error format is V000.00\r\n");
		}
	}
	else if( strcmp(data,"ssssssss")==0){
			controlMode->controlMode=3;
			sprintf(controlMode->res_string, "System OFF\r\n");

		}
	else if( strcmp(data,"VERBOSE0")==0){
		if (controlMode->verbose) {
			sprintf(controlMode->res_string, "Verbose turned OFF\r\n");
			controlMode->verbose=0;
		}
		else{
			sprintf(controlMode->res_string,"Verbose turned ON\r\n");
			controlMode->verbose=1;
		}
	}
	else if( strcmp(data,"POSITION")==0){
		if (controlMode->controlMode) {
			sprintf(controlMode->res_string, "Control MODE is in Position mode\r\n");
			controlMode->controlMode=1;
		}
		else{
			sprintf(controlMode->res_string,"Control MODE pass to position\r\n");
			controlMode->controlMode=1;
		}
	}
	else if( strcmp(data,"VELOCITY")==0){
		if (controlMode->controlMode==0) {
			sprintf(controlMode->res_string, "Control MODE is in velocity mode\r\n");
			controlMode->controlMode=0;
		}
		else{
			sprintf(controlMode->res_string,"Control MODE pass to velocity\r\n");
			controlMode->controlMode=0;
		}
	}
	else if( strcmp(data,"FORWARD0")==0){
		if (controlValues->direction==0) {
			sprintf(controlMode->res_string, "Direction is forward\r\n");
			controlValues->direction=0;
		}
		else{
			sprintf(controlMode->res_string,"Direction change to Forward, velocity set to 0\r\n");
			controlValues->direction=0;
			controlValues->speedReference=0;
		}
	}
	else if( strcmp(data,"BACKWARD")==0){
		if (controlValues->direction==1) {
			sprintf(controlMode->res_string, "Direction is backward\r\n");
			controlValues->direction=1;
		}
		else{
			sprintf(controlMode->res_string,"Direction change to Backward, velocity set to 0\r\n");
			controlValues->direction=1;
			controlValues->speedReference=0;
		}
	}
	else{
		sprintf(controlMode->res_string,"other thing\r\n");
	}

}

