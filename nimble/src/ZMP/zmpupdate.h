/*
 * Copyright: (C) 2014 Walkman Consortium
 * Authors: Juan Alecandro Castano
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
*/
#ifndef ZMPUPDATE_H
#define ZMPUPDATE_H
#include <vector>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace zmpUpdate{

const int preview_window=400; //4 seconds at 10 ms;
const double SamplingTime=0.010;
//std::ofstream in;
class ZMPupdate
{
public:
    double NextFootPosition;

    double ActualFootPositionX;
    double ActualFootPositionY;
    double DesiredStepLengthX;
    double DesiredStepLengthY;
    double desiredStepTime;
    double RemainingSSTime;
    double RemainingDSTime;
    double DS_SS_Ratio;
    std::vector<double> ZMPX;
    std::vector<double> ZMPY;
    double stepCount=-1;
    double COMyDesiredPosition=0;
    bool goLeft=false;
    bool goRight=true;
    bool footChangeFlag;
    double nextFootHold;

    double Poly3(double s0,double t0,double sf,double tf,double time);
public:

    ZMPupdate(double DesiredStepLengthX=0.2,
              double DesiredStepLengthY=0.2,
              double desiredStepTime=0.5,
              double DS_SS_Ratio=0.6,
              double YdesiredPosition=0);
    ~ZMPupdate();
    void UpdateZMPData(double RemainingSSTime,
                       double RemainingDSTime,
                       double DesiredStepLengthX=0.2,
                       double DesiredStepLengthY=0.2,
                       double desiredStepTime=1.5,
                       double DS_SS_Ratio=0.6,
                       double desiredYpos=0);
    std::vector<double> ZmpUpdatex();
    std::vector<double> ZmpUpdatey();
    void footChange(void);

    void setNextFootHold(double value);
    void setDesiredStepLengthX(double value);
    void checkZMP();
};
}
#endif // ZMPUPDATE_H
