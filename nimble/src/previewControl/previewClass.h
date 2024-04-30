#ifndef PreviewClass_H
#define PreviewClass_H
/*
 * Copyright: (C) 2014 Walkman Consortium
 * Authors: Juan Alecandro Castano
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "../ZMP/zmpupdate.h"
using namespace std;
class PreviewClass
{
public:
    int N2=zmpUpdate::preview_window;
    std::vector<double> Gd;
    double Gd1[3];
    double GI;
    double footDelta;
    double z_c;
    double sysdA[3][3]={{1,zmpUpdate::SamplingTime, pow(zmpUpdate::SamplingTime,2)/2},{ 0, 1, zmpUpdate::SamplingTime},{ 0, 0, 1}};
    double sysdB[3]={pow(zmpUpdate::SamplingTime,3)/6, pow(zmpUpdate::SamplingTime,2)/2, zmpUpdate::SamplingTime};
    double sysdC[3]={1, 0, -z_c/9.81};
    double saturate(double PseudoZMP,double desiredZMP,double actualPosition);
public:
    PreviewClass(double COMhigh=0.7,double footDelta=0.07);
    ~PreviewClass();
    void loadGains(string FILE);
    double previewControl(double *states, std::vector<double> zmp);
    double evalControlEffort();

};

#endif
