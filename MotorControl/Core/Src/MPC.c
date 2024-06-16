#include "MPC.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void initMPC(struct MPCData* MPCData){

    MPCData->N1=N1_I;
    MPCData->N2=N2_I;
    MPCData->Nu=Nu_I;

    MPCData->sizeA=sizeA_I;
    MPCData->sizeB=sizeB_I;
    MPCData->sizeD=sizeC_I;
    MPCData->sizeC=sizeD_I;

    MPCData->dB[0]=0;
    MPCData->dB[1]=0.2175;
    MPCData->dA[0]=1;
    MPCData->dA[1]=-0.8187;
    MPCData->C[0]=0; MPCData->C[1]=1;
    MPCData->D[0]=1; MPCData->D[1]=1;
    for (int i=0;i<MPCData->N2+MPCData->sizeA;i++)
        MPCData->X[i]=0;

    for (int i=0;i<MPCData->N2+MPCData->sizeB;i++)
        MPCData->U[i]=0;

    for (int i=0;i<MPCData->N2+MPCData->sizeD;i++)
        MPCData->N[i]=0;

    for (int i=0;i<MPCData->N2+MPCData->sizeC;i++)
        MPCData->NF[i]=0;


    MPCData->G[0]=0.2175;  MPCData->G[1]=0.3956; MPCData->G[2]=0.5414; MPCData->G[3]= 0.6607; MPCData->G[4]=0.7584;
    //H=(G'*G+eye(Nu)*Ts);
    //invH=inv(H'*H)*H'

    MPCData->Ut=0;
    MPCData->Ts=0.01;
    MPCData->constrains=1;
    MPCData->n1=n1_I;
    MPCData->alpha=0.3;

    if (MPCData->alpha==0){
        for (int i=0; i<MPCData->N2; i++)
            MPCData->weight[i]=0;
    }
    else{
        for (int i=0; i<MPCData->N2; i++)
            MPCData->weight[i]=pow(MPCData->alpha,MPCData->N2-i-1);
    }

    MPCData->invG[0]=0.1442;  MPCData->invG[1]=0.2622; MPCData->invG[2]=0.3589; MPCData->invG[3]= 0.4380; MPCData->invG[4]=0.5027;
    MPCData->f[0]=0.2175;  MPCData->f[1]=0.3956; MPCData->f[2]=0.5414; MPCData->f[3]= 0.6607; MPCData->f[4]=0.7584;
    MPCData->invH[0]=0.6585;


}

float runController(double measure, double reference, struct MPCData* MPCData){

    double Uopt[MPCData->Nu];
    // 1= shift EPSAC database and store base input
    double Ut=MPCData->U[MPCData->N2];
    for (int k = (MPCData->sizeB+MPCData->N2); k >=1 ; k--) {
        MPCData->U[k] = MPCData->U[k-1];      // [Corrimiento a la derecha]
    }
    for (int k = (MPCData->sizeA+MPCData->N2); k >=1 ; k--) {
        MPCData->X[k] = MPCData->X[k-1];      // [Corrimiento a la derecha]
    }
    for (int k = (MPCData->sizeD+MPCData->N2); k >=1 ; k--) {
        MPCData->N[k] = MPCData->N[k-1];      // [Corrimiento a la derecha]
    }
    for (int k = (MPCData->sizeC+MPCData->N2); k >=1 ; k--) {
        MPCData->NF[k] = MPCData->NF[k-1];     // [Corrimiento a la derecha]
    }
    for (int k=0; k<=MPCData->N2; k++){
        MPCData->U[k]=Ut;       // Store Control Action
    }
    // 2= compute EPSAC base-response x(t+k/t), k=0..N2
    // Model Output
    double numValues=0, denValues=0;

    for (int k=MPCData->N2;k>=0;k--){
        numValues=0;
        for(int j_b=0;j_b<=(MPCData->sizeB-1);j_b++){
            numValues=MPCData->dB[j_b]*MPCData->U[k+j_b]+numValues;
        }
        denValues=0;
        for(int j_a=1;j_a<=(MPCData->sizeA-1);j_a++){
            denValues=MPCData->dA[j_a]*MPCData->X[k+j_a]+denValues;
        }
        MPCData->X[k]=numValues-denValues;
    }
    // 3= compute n(t)=y(t)-x(call) with x(call) the model output
    MPCData->N[MPCData->N2]=measure-MPCData->X[MPCData->N2];
    // 4= compute nf(t)=D/C*n(call) and put nf(t+k/t)=0, k=1..N2
    double NF_d=0,NF_c=0;



    NF_d=0;
    for(int j_d=0;j_d<=(MPCData->sizeD-1);j_d++){
        NF_d=MPCData->D[j_d]*MPCData->N[MPCData->N2+j_d]+NF_d;
    }
    NF_c=0;
    int aux_en;
    if(MPCData->sizeC>=1){
        aux_en=0;
    }
    else{
        aux_en=1;
    }
    for(int j_c=aux_en;j_c<=(MPCData->sizeC-1);j_c++){
        NF_c=MPCData->C[j_c]*MPCData->NF[MPCData->N2+j_c]+NF_c;
    }
    MPCData->NF[MPCData->N2]=NF_d-NF_c;
    for(int k=0;k<MPCData->N2;k++){
        MPCData->NF[k]=0;
    }
    // 5= compute n(t+k/t)=C/D*nf(t+k/t), k=1..N2
    double N_d=0,N_c=0;
    for (int k=MPCData->N2-1;k>=0;k--){
        N_c=0;
        int aux_en;
        if(MPCData->sizeC>=1){
            aux_en=0;
        }
        else{
            aux_en=1;
        }
        for(int j_c=aux_en;j_c<=(MPCData->sizeC-1);j_c++){
            N_c=MPCData->C[j_c]*MPCData->NF[k+j_c+1]+N_c;
        }
        N_d=0;
        for(int j_d=1;j_d<=(MPCData->sizeD-1);j_d++){
            N_d=MPCData->D[j_d]*MPCData->N[k+j_d]+N_d;
        }
        MPCData->N[k]=N_c-N_d;
    }

    // 6= calcula Ybase=X(N2-N1+1:-1:1)+N(N2-N1+1:-1:1); k=N1....N2
    for(int k=MPCData->N2-1;k>=0;k--){
        MPCData->Ybase[MPCData->N2-1-k]=MPCData->N[k]+MPCData->X[k];
    }
    MPCData->X[MPCData->N2]=measure; // SERIE-PARALELO
    // 7= New control input U=U+ inv(G'*G)*G'*Err
//In case we want it as vector
/*
   double Ref[MPCData->N2];
   for (int i=0; i<MPCData->N2; i++)
        Ref[i]=measure;
 */

   double Ref=measure;
   for (int i=0;i<MPCData->N2;i++){
        MPCData->SetP[i]=reference-MPCData->weight[i]*(reference-Ref);
    }

    for (int i=0;i<MPCData->N2;i++){
        MPCData->Err[i]=MPCData->SetP[i]-MPCData->Ybase[i];
    }

    if (MPCData->constrains==0){
        for(int k=0;k<MPCData->Nu;k++){
            Uopt[k]=0;
        }

        for (int k=0;k<MPCData->N2;k++){
            Uopt[0] += MPCData->invG[k]*MPCData->Err[k];

        }
        MPCData->U[MPCData->N2]=MPCData->U[MPCData->N2]+Uopt[0];
    }
    else{ // I/O constraints

        float maxy=105.0; // Velocidad máxima que puede alcanzar, en nuestro caso es 100.
        float miny=-105.0;
        float deltaY=100.01000; //delta de velocidad

        float Umin=-200.500;
        float Umax=200.500; // PWM máxima que puede alcanzar, en nuestro caso es 100.
        float delta_U=2; //delta de la PWM cada 10 ms

        float dmaxy=MPCData->Ybase[0]+deltaY;
        float dminy=MPCData->Ybase[0]-deltaY;


        //construct b matrix;
        //b=[maxy-Ybase;Ybase-miny;dmaxy-Ybase;Ybase-dminy; Umax-U(N2+1:-1:N2+1-Nu+1);U(N2+1:-1:N2+1-Nu+1)-Umin;ones(Nu,1)*(delta_U);ones(Nu,1)*(delta_U)];

        for (int i=0; i<MPCData->N2; i++){
            MPCData->bmaxy[i]=maxy-MPCData->Ybase[i];
            MPCData->bminy[i]=MPCData->Ybase[i]-miny;
            MPCData->bdmaxy[i]=dmaxy-MPCData->Ybase[i];
            MPCData->bdminy[i]=MPCData->Ybase[i]-dminy;
        }

        for (int i=0; i<MPCData->Nu; i++){
            MPCData->bmaxU[i]=Umax-MPCData->U[MPCData->N2-i];
            MPCData->bminU[i]=MPCData->U[MPCData->N2-i]-Umin;
            MPCData->bdmaxU[i]=delta_U;
            MPCData->bdminU[i]=delta_U;
        }

        //Construct A
        //A=[G;-G;G;-G;eye(Nu);-eye(Nu);eye(Nu);-eye(Nu)];

        for (int i=0; i<MPCData->N2; i++){
            MPCData->Amaxy[i]=MPCData->G[i];
            MPCData->Aminy[i]=-MPCData->G[i];
            MPCData->Admaxy[i]=MPCData->G[i];
            MPCData->Adminy[i]=-MPCData->G[i];
        }
        for (int i=0; i<MPCData->Nu; i++){
            MPCData->AmaxU[i]=1;
            MPCData->AminU[i]=-1;
            MPCData->AdmaxU[i]=1;
            MPCData->AdminU[i]=-1;
        }
        float fullb[MPCData->N2*4+MPCData->Nu*4];
        float fullA[MPCData->Nu*4+MPCData->N2*4];

        for (int i=0;i<MPCData->N2;i++){
            fullb[i]=              MPCData->bmaxy[i] ;
            fullb[MPCData->N2+i]=  MPCData->bminy[i] ;
            fullb[MPCData->N2*2+i]=MPCData->bdmaxy[i] ;
            fullb[MPCData->N2*3+i]=MPCData->bdminy[i] ;
        }

        for (int i=0;i<MPCData->Nu;i++){
            fullb[MPCData->N2*4+i]=              MPCData->bmaxU[i];
            fullb[MPCData->N2*4+MPCData->Nu+i]=  MPCData->bminU[i];
            fullb[MPCData->N2*4+MPCData->Nu*2+i]=MPCData->bdmaxU[i] ;
            fullb[MPCData->N2*4+MPCData->Nu*3+i]=MPCData->bdminU[i] ;

        }


        for (int i=0;i<MPCData->N2;i++){
            fullA[i]=              MPCData->Amaxy[i]  ;
            fullA[MPCData->N2+i]=  MPCData->Aminy[i]  ;
            fullA[MPCData->N2*2+i]=MPCData->Admaxy[i] ;
            fullA[MPCData->N2*3+i]=MPCData->Adminy[i] ;

        }

        for (int i=0;i<MPCData->Nu;i++){
            fullA[MPCData->N2*4+i]=              MPCData->AmaxU[i] ;
            fullA[MPCData->N2*4+MPCData->Nu+i]=  MPCData->AminU[i] ;
            fullA[MPCData->N2*4+MPCData->Nu*2+i]=MPCData->AdmaxU[i];
            fullA[MPCData->N2*4+MPCData->Nu*3+i]=MPCData->AdminU[i];

        }


        float F1;
        F1=0;
        for (int i=0;i<MPCData->N2;i++){
            F1=F1+MPCData->f[i]*(MPCData->Ybase[i]-MPCData->SetP[i]);

        }

        Uopt[0]=QPhild( MPCData->invH,&F1,fullA,fullb,MPCData->n1,1,MPCData);



        MPCData->U[MPCData->N2]=MPCData->U[MPCData->N2]+Uopt[0];
    }

    return MPCData->U[MPCData->N2];
}
double QPhild(float *invH, float *f, float *A, float *bn, int n1, int m1,struct MPCData* MPCData){



    double eta=-invH[0] * f[0];

    float kk=0;

    for (int i=0;i<n1;i++){
        if(A[i]*eta>bn[i]){
            kk=kk+1;
            break;
        }

    }
    if(kk==0){
        return 0;
    }

    for (int j=0;j<n1;j++){
        for (int i=0;i<n1;i++){
            MPCData->P[n1*j+i]=A[j] * invH[0] * A[i];

        }

    }

    for (int i=0;i<n1;i++){
        MPCData->d[i]=A[i]*invH[0]*f[0]+bn[i];
    }

    for(int k=0;k<n1;k++){
        MPCData->lambda[k]=0;
    }
    float presition=10;
    int maxIterations=20;
    for (int i=0;i<maxIterations;i++){

        for(int k=0;k<n1;k++){
            MPCData->lambda_p[k]=MPCData->lambda[k];
        }
        for (int j=0;j<n1;j++){
            float temp=0;
            for(int k=0;k<n1;k++){
                temp=temp+MPCData->P[n1*j+k]*MPCData->lambda[k];

            }

            temp=temp-MPCData->P[n1*j+j]*MPCData->lambda[j]+MPCData->d[j];
            float temp2=-temp/MPCData->P[n1*j+j];
            MPCData->lambda[j]=fmax(0,temp2);


        }

        presition=0;
        for(int i=0;i<n1;i++){
            presition+=pow(MPCData->lambda[i]-MPCData->lambda_p[i],2);
        }
        if (presition<0.001)
            break;
    }
    double temp=0;
    for(int i=0;i<n1;i++){
        temp+=invH[0]*A[i]*MPCData->lambda[i];
    }
    eta=-invH[0]*f[0]-temp;



    return eta;
}
