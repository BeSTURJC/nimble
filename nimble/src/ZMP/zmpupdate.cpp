#include "zmpupdate.h"
/*
 * Copyright: (C) 2014 Walkman Consortium
 * Authors: Juan Alecandro Castano
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
*/
using namespace zmpUpdate;

/** @brief ZMPupdate::ZMPupdate Defauld constructor
 *  assumes 20 cm step lenght and width every 1.5 seconds
 *  with samplig 10 ms
 *  other values start accordingly.
 *  * @param DesiredStepLengthX StepLenght if different from 0.2
 *  * @param DesiredStepLengthY StepWidth if different from 0.2
 *  * @param desiredStepTime Steptime if different from 1.5
 *  * @param DS_SS_Ratio DoubleSupport(DS) Single Support(SS) Ration if different from 0.6 (60% SS, 40% DS)
 *  * @param YdesiredPosition Hip center position, use the construct the ZMPy knowin if the alctual foot is left or right
 */
ZMPupdate::ZMPupdate(double DesiredStepLengthX,
                     double DesiredStepLengthY,
                     double desiredStepTime,
                     double DS_SS_Ratio,
                     double YdesiredPosition){

    this->NextFootPosition=0;
    this->ActualFootPositionX=0;
    this->ActualFootPositionY=0;
    this->DesiredStepLengthX=DesiredStepLengthX;
    this->nextFootHold=DesiredStepLengthX;
    this->DesiredStepLengthY=DesiredStepLengthY;
    this->desiredStepTime=desiredStepTime;
    this->RemainingSSTime=desiredStepTime*DS_SS_Ratio;
    this->RemainingDSTime=desiredStepTime*(1-DS_SS_Ratio);
    this->DS_SS_Ratio=DS_SS_Ratio;
    this->COMyDesiredPosition=YdesiredPosition;

    ZMPX.resize(preview_window);
    ZMPY.resize(preview_window);
    for (int i=0;i<preview_window;i++){
        ZMPX[i]=0;
        ZMPY[i]=0;
    }

}

/** @brief ZMPupdate::~ZMPupdate() Default destructor */
ZMPupdate::~ZMPupdate(){}

/** @brief ZMPupdate::UpdateZMPData Update Values to generate dynamically the ZMP
 *      This function is to be call every sample loop.
 *      the four last parameters have default values as 0.2,0.2, 1.5, 0.6
 * @param  ActualFootPositionX changes every gine step refears to the global X coordinate
 * @param  ActualFootPositionY changes every gine step refears to the global Y coordinate
 * @param  RemainingSSTime     Changes every SampleTime based on static variability or dynamic model
 * @param  RemainingDSTime     Changes every SampleTime based on static variability or dynamic model
 * @param  DesiredStepLengthX  Changes if different from 0.2 m
 * @param  DesiredStepLengthY  Changes if different from 0.2 m
 * @param  desiredStepTime     Changes if different from 1.5 s
 * @param  DS_SS_Ratio         Changes if different from 60%
 * @param YdesiredPosition Hip center position chenged if different from 0
 *
 */
void ZMPupdate::UpdateZMPData(
    double RemainingSSTime,
    double RemainingDSTime,
    double DesiredStepLengthX,
    double DesiredStepLengthY,
    double desiredStepTime,
    double DS_SS_Ratio,
    double desiredYpos){

    this->DesiredStepLengthX=DesiredStepLengthX;


    this->DesiredStepLengthY=DesiredStepLengthY;
    this->desiredStepTime=desiredStepTime;
    this->RemainingSSTime=RemainingSSTime;
    this->RemainingDSTime=RemainingDSTime;
    this->DS_SS_Ratio=DS_SS_Ratio;
    this->COMyDesiredPosition=desiredYpos;
    footChange();
    ZMPX=ZmpUpdatex();
    ZMPY=ZmpUpdatey();

};

/**
 * @brief zmpgenerator::ZmpUpdatex Generates the zmp trajectory for the  x axis
 * uses internal values after using ZMPupdate::UpdateZMPData
 * @return std::vector<double> ZMPX the constructed ZMPXvector
*/

std::vector<double> ZMPupdate::ZmpUpdatex(){

    /************ Default step ZMPtrajectory ******************/
    int SSStepSize=desiredStepTime*(1-DS_SS_Ratio)/SamplingTime +0.5;
    int DSStepSize=desiredStepTime*DS_SS_Ratio/SamplingTime +0.5;
    int  SSRemainingStepSize=RemainingSSTime/SamplingTime +0.5;
    int  DSRemainingStepSize=RemainingDSTime/SamplingTime +0.5;
    int NominalDSStepSize=DSStepSize;
    double desiredStep=0;
    if (stepCount==0)
        desiredStep=0;
    else
        desiredStep=DesiredStepLengthX;

    std::vector<double> nominalStep(SSStepSize,0);
    double nominalStepSize=SSStepSize+DSStepSize;
    for (int i=1;i<DSStepSize;i++){
        nominalStep.push_back(Poly3(0,0,DesiredStepLengthX,DSStepSize*SamplingTime,i*SamplingTime));
    }
    /******************************************************/



    std::vector<double>  auxiliar;

    //first step uses half the desired Step lenght

    // When swinging
    if (SSRemainingStepSize>1 && DSRemainingStepSize==0){
        //Critical case when swinging time is expected to be greater than 800 samples (4s)
        //Fill the vector with the actual footPosition
        if(SSRemainingStepSize>=preview_window){
            for (int i=0;i<preview_window;i++)
                ZMPX[i]=ActualFootPositionX;
        }
        //If not the critical case
        else{
            //fill the zmp vector with the actual footposition only the first PhaseSize samples
            auxiliar.resize(SSRemainingStepSize,ActualFootPositionX);
            //Critical case where the Actual step is consider to take more that 4 seconds
            //Fill the remaining zmp vector with a polynomial from the actual foot position to the desired new step
            //Using all the remaining SS time for creating the polinomia but filling the ZMP till 400 samples;
            for(int i=SSRemainingStepSize;i<(NominalDSStepSize+SSRemainingStepSize) || i==preview_window-1;i++){
                auxiliar.push_back(Poly3(ActualFootPositionX,0,ActualFootPositionX+this->nextFootHold,NominalDSStepSize*SamplingTime,(i-SSRemainingStepSize)*SamplingTime));
            }
            //If the actual step feets into the preview window size
            if (auxiliar.size()<preview_window){
                double addionalSteps=1;
                //Fill the remaining vector with nominal steps as many times as required
                while(auxiliar.size()+nominalStepSize<=preview_window){
                    std::vector<double> auxiliar1;
                    for (int i=0; i < nominalStep.size();i++)
                        auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                    auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
                    addionalSteps++;
                }
                //when almost full complete the ZMP vector with the nominal step vector
                if(auxiliar.size()<preview_window){
                    double remainingValue=preview_window-auxiliar.size();
                    std::vector<double> auxiliar1;
                    for (int i=0; i < remainingValue;i++)
                        auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                    auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
                }
            }
            ZMPX=auxiliar;
        }
    }
    else if(DSRemainingStepSize<=1 || (SSRemainingStepSize>=1 && DSRemainingStepSize==0)){
        auxiliar.insert(auxiliar.end(),ZMPX.begin()+1,ZMPX.end());
        auxiliar.push_back(ZMPX[ZMPX.size()-1]);
    }
    //Is step state is in DS
    else{
        //If the remaining time is greater that expected
        if(DSRemainingStepSize>NominalDSStepSize && DSRemainingStepSize>1){
            //Inster the nominal DS vector
            auxiliar.resize(NominalDSStepSize);
            //
            for (int i=0;i<NominalDSStepSize;i++){
                auxiliar[i]=Poly3(ActualFootPositionX,0,ActualFootPositionX+NextFootPosition,NominalDSStepSize*SamplingTime,i*SamplingTime);
            }
            double addionalSteps=1;
            //Complete the vector with nominal steps
            while(auxiliar.size()+nominalStepSize<=preview_window){
                std::vector<double> auxiliar1;
                for (int i=0; i < nominalStep.size();i++)
                    auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
                addionalSteps++;
            }
            if(auxiliar.size()<preview_window){
                double remainingValue=preview_window-auxiliar.size();
                std::vector<double> auxiliar1;
                for (int i=0; i < remainingValue;i++)
                    auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
            }
        }

        else{
            //Is the DSRemaining time is smaller that the nominal
            if(DSRemainingStepSize>0){
                auxiliar.resize(DSRemainingStepSize);
                for (int i=(NominalDSStepSize-DSRemainingStepSize);i<NominalDSStepSize;i++){
                    auxiliar[i-(NominalDSStepSize-DSRemainingStepSize)]=Poly3(ActualFootPositionX,0,ActualFootPositionX+NextFootPosition,NominalDSStepSize*SamplingTime,i*SamplingTime);
                }
            }
            else{
                auxiliar.resize(1);
                auxiliar[0]=ZMPX[0];
            }

            //the fisrt samples of the ZMP will take the last samples DSRemaining time  samples from the nominal case

            //Complete the vector with nominal steps
            double addionalSteps=1;
            while(auxiliar.size()+nominalStepSize<=preview_window){
                std::vector<double> auxiliar1;
                for (int i=0; i < nominalStep.size();i++)
                    auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
                addionalSteps++;
            }
            if(auxiliar.size()<preview_window){
                double remainingValue=preview_window-auxiliar.size();
                std::vector<double> auxiliar1;
                for (int i=0; i < remainingValue;i++)

                    auxiliar1.push_back(nominalStep[i]+auxiliar[auxiliar.size()-1]);
                auxiliar.insert(auxiliar.end(),auxiliar1.begin(),auxiliar1.end());
            }

        }
        ZMPX=auxiliar;

    }
    return ZMPX;
}


/**
 * @brief zmpgenerator::ZmpUpdatex Generates the zmp trajectory for the  x axis
 * uses internal values after using ZMPupdate::UpdateZMPData
 * @return std::vector<double> ZMPX the constructed ZMPXvector
*/
std::vector<double> ZMPupdate::ZmpUpdatey(){



    float stepLength2=0;

    std::vector<double> softzmpNeg;
    std::vector<double> softzmp2;
    std::vector<double> softzmp3;
    std::vector<double> zmp2;


    std::vector<double> softDS(int(this->desiredStepTime*(DS_SS_Ratio)/SamplingTime+0.5),0);
    std::vector<double> softDS2(int(this->desiredStepTime*(DS_SS_Ratio)/SamplingTime+0.5),0);
    std::vector<double> softDS1(int(this->desiredStepTime*(DS_SS_Ratio)/SamplingTime+0.5));
    int sizeDS1=int(this->desiredStepTime*(DS_SS_Ratio)/SamplingTime+0.5);

    std::vector<double> temp;

    int SSStepSize=desiredStepTime*(1-DS_SS_Ratio)/SamplingTime +0.5;
    int DSStepSize=desiredStepTime*(DS_SS_Ratio)/SamplingTime +0.5;
    int SSRemainingStepSize=int(RemainingSSTime/SamplingTime +0.5);
    int DSRemainingStepSize=int(RemainingDSTime/SamplingTime +0.5);
    //Identify is weight is on left, right or none (start walk mith be a useful variable )
    if (ActualFootPositionY<=this->COMyDesiredPosition ){
        stepLength2=this->DesiredStepLengthY;
        for (int i=0;i<DSStepSize;i++){
            if(stepCount==-1)
                softDS1[i]=Poly3(ActualFootPositionY,0,ActualFootPositionY+this->DesiredStepLengthY/2,DSStepSize*SamplingTime,i*SamplingTime);
            else
                softDS1[i]=Poly3(ActualFootPositionY,0,ActualFootPositionY+this->DesiredStepLengthY,DSStepSize*SamplingTime,i*SamplingTime);
        }
    }
    else if (ActualFootPositionY>COMyDesiredPosition ){
        stepLength2=-this->DesiredStepLengthY;
        for (int i=0;i<DSStepSize;i++){
            if(stepCount==-1)
                softDS1[i]=Poly3(ActualFootPositionY,0,ActualFootPositionY-this->DesiredStepLengthY/2,DSStepSize*SamplingTime,i*SamplingTime);
            else
                 softDS1[i]=Poly3(ActualFootPositionY,0,ActualFootPositionY-this->DesiredStepLengthY,DSStepSize*SamplingTime,i*SamplingTime);
        }

    }

    //Create nominal soft transition when in double support
    for (int i=0;i<DSStepSize;i++){
        softDS2[i]=Poly3(0,0,-stepLength2,DSStepSize*SamplingTime,i*SamplingTime);

    }
    //Create actual soft transition when in double support
    //First SS size samples are 0 for the nominal step
    softzmp2.resize(SSStepSize,0);
    //create the nominal step concatanating the soft DS vector
    softzmp2.insert(softzmp2.end(),softDS2.begin(),softDS2.end());
    //copy of the softvector
    softzmp3=softzmp2;
    //Copy of the soft vector with inverted step
    for(int i=0;i<softzmp2.size();i++)
        softzmpNeg.push_back(-softzmp2[i]);
    int m=1; //Use for odd even step recognition
    //while the soft vector size is smaller that the preview window (4s,400)
    //***Create the nominal zmpvector considering it from zero to positive motion***/
    while(softzmp3.size()<preview_window){
        if (m%2==0){ //If odd step is given
              std::vector<double> temporalvector2;
            for (int i=0; i < softzmp2.size();i++)
                temporalvector2.push_back(softzmp2[i]+softzmp3[softzmp3.size()-1]);
            softzmp3.insert(softzmp3.end(),temporalvector2.begin(),temporalvector2.end());
        }
        else{
              std::vector<double> temporalvector2;
            for (int i=0; i < softzmpNeg.size();i++)
                temporalvector2.push_back(softzmpNeg[i]+softzmp3[softzmp3.size()-1]);
            softzmp3.insert(softzmp3.end(),temporalvector2.begin(),temporalvector2.end());
        }
        m=m+1;
    }
    /***********************************************************************************/

    //If in single support
    if (SSRemainingStepSize>1 && DSRemainingStepSize==0){
        if (SSRemainingStepSize<=preview_window){
              std::vector<double> temporalvector2;
            //Create a ZMP from the actual foot position
            zmp2.resize(SSRemainingStepSize,ActualFootPositionY);
            //And concataned the expected transition afterwards
            zmp2.insert(zmp2.end(),softDS1.begin(),softDS1.end());
            for (int i=0; i < softzmp3.size();i++)
                temporalvector2.push_back(softzmp3[i]+zmp2[zmp2.size()-1]);

            zmp2.insert(zmp2.end(),temporalvector2.begin(),temporalvector2.end());
            zmp2.resize(preview_window);
        }
        else{//Create a ZMP using only the actual foot position
            zmp2.resize(SSRemainingStepSize,ActualFootPositionY);
        }
    }
    else if(DSRemainingStepSize<=1 || (SSRemainingStepSize>=1 && DSRemainingStepSize==0)){
        zmp2.insert(temp.end(),ZMPY.begin()+1,ZMPY.end());
        zmp2.push_back(ZMPY[ZMPY.size()-1]);
    }
    else {
        int Nsamples=DSRemainingStepSize;

        if (DSRemainingStepSize>DSStepSize){
            //Add the expected ZMP transition
            temp=softDS1;
            //Add SSStepSize elements with value expected next ZMP
            Nsamples=temp.size();//+SSPhaseSize;
        }
        else { //If already in the transition phase
            if(Nsamples==0){
                Nsamples=1;
                temp.resize(Nsamples);
                temp[0]=softDS1[softDS1.size()-1];
            }
            else{
                temp.resize(Nsamples);
                //copy the last elements for the polinomial from the expected transition
                for (int i=(DSStepSize-Nsamples);i<DSStepSize;i++){
                    temp[i-(DSStepSize-Nsamples)]=softDS1[i];
                }
            }
            Nsamples=temp.size();//+SSPhaseSize;
        }

        //if the constructed vector is smaller than the preview window
        if (Nsamples<=preview_window){
              std::vector<double> temporalvector2;
            for (int i=0;i<Nsamples;i++){
                zmp2.push_back(temp[i]);
            }
            for (int i=0; i <preview_window-zmp2.size();i++)
                temporalvector2.push_back(softzmp3[i]+temp[temp.size()-1]);

            temporalvector2.resize(preview_window-zmp2.size());
            zmp2.insert(zmp2.end(),temporalvector2.begin(),temporalvector2.end());

        }
        else{
            for (int i=0;i<preview_window;i++){
                zmp2.push_back(temp[i]);
            }
        }
    }
    zmp2.resize(preview_window);
    ZMPY=zmp2;
    return zmp2;

};
/**
     * @brief ZMPupdate::Poly3 Third order polynomia interpolation
     * @param s0    initial position
     * @param t0    initial time
     * @param sf    Final Position
     * @param tf    Final time
     * @param time  Actual time
     * @return  the correstond value of the third order function at present
     *              time "time"
     */
void ZMPupdate::setNextFootHold(double value)
{
    nextFootHold = value;
}

void ZMPupdate::setDesiredStepLengthX(double value)
{
    DesiredStepLengthX = value;
}

double ZMPupdate::Poly3(double s0,double t0,double sf,double tf,double time){
    if (tf==t0)
        return 0;
    double a0=s0;
    double a2=3/pow((tf-t0),2)*(sf-s0);
    double a3=-2/pow((tf-t0),3)*(sf-s0);
    double t=time-t0;
    if (time<t0 ){
        return s0;
    }
    else if (time>tf){
        return sf;
    }
    else{
        return a0+a2*pow(t,2)+a3*pow(t,3);
    }
}
/**
 * @brief ZMPupdate::footChange This function change the stand foot according to the conditions
 *if a change is allow and if the step is finish
 * NOTE: The step "overs at the end of the DSphase

 */
void ZMPupdate::footChange(){

    if (RemainingDSTime<=0.01 && goRight==0 && footChangeFlag==1){
        //stand foot take the left foot y position
        stepCount++;
        ActualFootPositionY=-DesiredStepLengthY/2;
        if(stepCount==0)
            NextFootPosition=DesiredStepLengthX;
        else
            NextFootPosition=DesiredStepLengthX;
        if(stepCount>0)
            //Para modificarse cuando se cambie el valor de ejecución de pisada
            ActualFootPositionX+=DesiredStepLengthX;
        goRight=true;
        goLeft=false;
        footChangeFlag=0;


    }

    else if (RemainingDSTime<=0.01 && goLeft==0  && footChangeFlag==1 ){
        //stand foot take the right foot y position
        stepCount++;
        ActualFootPositionY=DesiredStepLengthY/2;
        if(stepCount==0)
            NextFootPosition=DesiredStepLengthX;
        else
            NextFootPosition=DesiredStepLengthX;
        if(stepCount>0)
            //Para modificarse cuando se cambie el valor de ejecución de pisada
            ActualFootPositionX+=DesiredStepLengthX;
        goLeft=true;
        goRight=false;
        footChangeFlag=0;

    }
    //CRITICO
    if (RemainingDSTime>0.2)
        footChangeFlag=1;

}

void ZMPupdate::checkZMP(){
    ofstream in;
    in.open("ZMPX.txt",ios::app);
    for (int i=0;i<400;i++){ in<<this->ZMPX[i]<<" ";}
    in<<endl;
    in.close();

    in.open("ZMPY.txt",ios::app);
    for (int i=0;i<400;i++){ in<<this->ZMPY[i]<<" ";}
    in<<endl;
    in.close();


}
