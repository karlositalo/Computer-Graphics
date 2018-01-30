#include "Matrix.h"
#include <iostream>
using namespace std;

float** matrixMultiplication(float A[][4], float B[][4]){
    float** C = new float*[4];

    int i,j,k;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            C[i] = new float[4];
            C[i][j] = 0;
            for(k=0;k<4;k++)
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
        }
    }

    return C;
}

float* vector_matrixMultiplicaton(float A[][4], float v[]){
    float* u = new float[4];

    int i,j;

    for(i=0;i<4;i++){
        u[i] = 0;
        for(j=0;j<4;j++)
            u[i] = u[i] + A[i][j]*v[j];
    }

    return u;
}

