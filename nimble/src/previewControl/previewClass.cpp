#include "previewClass.h"
/*
 * Copyright: (C) 2014 Walkman Consortium
 * Authors: Juan Alecandro Castano
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
*/

/**
 * @brief PreviewClass::PreviewClass
 * default constructor initialize the preview window in 400 (see zmpupdate.h)
 * z_c is 0.7 by default and footDelta=0.05 by default
 *
 */
PreviewClass::PreviewClass(double COMhigh,double footDelta){
    this->N2=zmpUpdate::preview_window;
    this->Gd.resize(this->N2);
    this->z_c=COMhigh;
    this->footDelta=footDelta;
    sysdC[2]=-COMhigh/9.81;

    this->loadGains("../nimble/src/previewControl/Gd.txt");


}
PreviewClass::~PreviewClass() {}
/**
 * @brief PreviewClass::loadGains
 * This Function allows the user to load the set of gain for the
 * preview controller in the following order Gd[previewwindow],Gd1[3], GI[1]
 *
 * @param FILE
 * indicates where is the file located "../../example.txt"
 *
 */
void PreviewClass::loadGains(std::string FILE){
    //the file is organized as [Gd(N2) GD1(3) GI(1)]
    ifstream in;
    //model matrix
        in.open(FILE.c_str());
        //in.open("../../src/RealGmatrix.txt");
        for (int j=0;j<N2;j++){
            if(!in.eof()){
                in>>this->Gd[j];
               cout<<this->Gd[j]<<endl;

             }
         }
        for (int j=0;j<3;j++){
            if(!in.eof()){
                in>>this->Gd1[j];
                //cout<<"GD1: "<<this->Gd1[j]<<endl;
            }
        }
        if(!in.eof()){
            in>>this->GI;
            //cout<<this->GI<<endl;
        }
        //optimization F matrix
        in.close();

}
/**
 * @brief PreviewClass::saturate
 * Apply the acceleration contraint in the control effort to provide
 * stability conditions to the system
 *
 * @param PseudoZMP: ZMP due to the unconstrainet control input it the
 * model states
 *
 * @param desiredZMP: ZMP location at present time
 *
 * @param actualPosition: COM actual position
 * @param z_c: hight of the COM
 * @param delta: constraint distance from the desired ZMP
 * @return contrained accceleration
 */
double PreviewClass::saturate(double PseudoZMP,double desiredZMP,double actualPosition){
    //This function creates the ZMP saturation given the parameter DELTA and the desired and expected
    //(pseudo) ZMP, Delta is refered to the stabillity polygon size,
    //The output is the system acceleration to keep the ZMP into the polygon
    double g=9.81;
    //
    if  (PseudoZMP > (desiredZMP+ this->footDelta)){
        PseudoZMP = (desiredZMP+ this->footDelta);
    }
    else if( PseudoZMP < (desiredZMP- this->footDelta) ){

        PseudoZMP = (desiredZMP- this->footDelta);
    }
    return  (actualPosition - PseudoZMP)*g/z_c;
}
/**
 * @brief PreviewClass::previewControl
 * apply the controller
 * @param returnState: output states once the cosntraint control effort is used
 *
 * @param states: system states
 * @param sysdA: A matrix of the system
 * @param sysdB: Input matrix of the system
 * @param sysdC: output matrix of the system
 * @param zmp: ZMP reference
 * @param limit: saturation limit
 * @param z_c: COM hight
 */
double PreviewClass::previewControl(double *states, std::vector<double> zmp){
    //THis function takes as inputs the states in t+1, the gains of the preview controller the actual states, the description of the system A,B,C the zmp reference the limit for the saturation the sample time, the higth of the COM
    // once the controller is evaluated the desired states are save in returnState
    double temporal=0;
    double temporal2=0;

    for (int i=0; i<N2; i++){
        temporal+=this->Gd[i]*zmp[i];
        //evaluate control effort due to the preview window gain
    }
    for (int i=0;i<3;i++){
        //evaluate control effort due to the actual states
        temporal2+=this->Gd1[i]* states[i];
    }
    double ZMPerror=(states[0]-states[2]*z_c/9.81)-(zmp[0]);
    //evaluate control effort do to the ZMP error
    double u=this->GI*ZMPerror-temporal2-temporal;

    //apply saturation
    double P[3]={0,0,0};
    double Temp=0;
    for(int k=0; k<3; k++){
        Temp=0;
        for(int i=0; i<3; i++){
            Temp+=sysdA[k][i] * states[i];
        }
        P[k] = Temp + sysdB[k] * u;

    }
    double Yt=0;
    for(int k=0;k<3; k++){
        Yt+=sysdC[k]*P[k];
    }
   // stauration
    P[2]=saturate(Yt,zmp[0],states[0]);
    double usat=(P[2]-states[2])/sysdB[2];

    //Evaluate control effor on the cart table model
    double tempStates[3]={0,0,0};
    for(int k=0; k<3; k++){
        double Temp=0;
        for(int i=0; i<3; i++){
            Temp+=this->sysdA[k][i] * states[i];
        }
        tempStates[k] = Temp + this->sysdB[k] * usat;
    }
    for(int i=0;i<3;i++)
        states[i]=tempStates[i];




    return tempStates[0];
}

double PreviewClass::evalControlEffort(){

}
