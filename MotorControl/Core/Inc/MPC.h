#ifndef MPC_H
#define MPC_H


/*
 * MPCVelControl.h
 *
 *  Created on: May 28, 2024
 *      Author: juan Alejandro Castaño
 *      Not optim code, non generalized for Nu nor N1;
 */

#ifndef INC_MPCVELCONTROL_H_
#define INC_MPCVELCONTROL_H_
#include <stdint.h>
#define N1_I 1
#define N2_I 5
#define Nu_I 1
#define n1_I 24
#define sizeA_I 2
#define sizeB_I 2
#define sizeC_I 2
#define sizeD_I 2
struct MPCData{
    int8_t N1;
    int8_t N2;
    int8_t Nu;
    int8_t sizeA;
    int8_t sizeB;
    int8_t sizeD;
    int8_t sizeC;


    int8_t constrains;

    float dA[2];
    float dB[2];

    float C[2];
    float D[2];
    float X[N2_I+sizeA_I];


    float U[N2_I+sizeB_I];
    float N[N2_I+sizeD_I];
    float NF[N2_I+sizeC_I];
    float G[Nu_I*N2_I];
    float invH[Nu_I*Nu_I];
    float invG[Nu_I*N2_I];
    float f[N2_I*Nu_I];

    float Ut;
    float Ts;
    float alpha;

    //INTERNAL
    float Ybase[N2_I];
    float Err[N2_I];
    float SetP[N2_I];
    float weight[N2_I];

    //CONSTRAINTS
    int n1;
    float bmaxy[N2_I];
    float bminy[N2_I];
    float bdmaxy[N2_I];
    float bdminy[N2_I];

    float bmaxU[Nu_I];
    float bminU[Nu_I];
    float bdmaxU[Nu_I];
    float bdminU[Nu_I];

    float Amaxy[N2_I];
    float Aminy[N2_I];
    float Admaxy[N2_I];;
    float Adminy[N2_I];;

    float AmaxU[Nu_I];
    float AminU[Nu_I];
    float AdmaxU[Nu_I];;
    float AdminU[Nu_I];;

    float lambda[n1_I];
    float lambda_p[n1_I];
    float P[n1_I*n1_I];
    float d[n1_I];


};

void initMPC(struct MPCData* MPCData);

float runController(double measure, double reference, struct MPCData* MPCData);

float evalConstraints(struct MPCData* MPCData);

void overControl(struct MPCData* MPCData);
double QPhild(float *invH, float *f, float *A, float *b, int n1, int m1,struct MPCData* MPCData);

#endif /* INC_MPCVELCONTROL_H_ */


#endif // MPC_H
