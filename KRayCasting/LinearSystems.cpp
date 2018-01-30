#include "LinearSystems.h"
#include <cmath>
using namespace std;

float* gaussMethod(float A[][3], float b[], int n){
    gaussElimination(A, b, n);
    return backSubstituition(A, b, n);
}


void gaussElimination(float A[][3], float b[], int n){
    float m;
    int i, j, k;

    for(k=0; k<n-1; k++){
        for(i=k+1; i<n; i++){
            partialPivotion(A, b, k, n);
            m = - A[i][k]/A[k][k];
            A[i][k] = 0;
            for(j=k+1; j<n; j++)
                A[i][j] = A[i][j] + m*A[k][j];
            b[i] = b[i] + m*b[k];
        }
    }
}

float* backSubstituition(float A[][3], float b[], int n){
    float* x = new float[n];
    float s;
    int k, j;

    x[n-1] = b[n-1]/A[n-1][n-1];
    for(k=n-2; k>-1; k--){
        s = 0;
        for(j=k+1; j<n; j++)
            s = s + A[k][j]*x[j];
        x[k] = (b[k] - s)/A[k][k];
    }

    return x;
}
float partialPivotion(float A[][3], float b[], int k, int n){
    int i, j;
    float m;

    j = k;
    m = abs( A[k][k] );

    for( i=k+1; i<n; i++){
        if( m < abs( A[i][k] ) ){
            m = abs( A[i][k] );
            j = i;
        }
    }

    if( j != k )
        switchLines(A, b, j, k, n);

    return A[j][k];
}
void switchLines(float A[][3], float b[], int j, int k, int n){
    int i;
    float t;

    for( i=0; i<n; i++){
        t = A[j][i];
        A[j][i] = A[k][i];
        A[k][i] = t;
    }

    t = b[j];
    b[j] = b[k];
    b[k] = t;
}


/*float* metodoDeGauss(float A[][3], float b[], int n){
    eliminacaoDeGauss(A, b, n);
    return backSubstituition(A, b, n);
}

float* backSubstituition(float A[][3], float b[], int n){
    float* x = new float[n];
    float s;
    int k, j;

    x[n-1] = b[n-1]/A[n-1][n-1];
    for(k=n-2; k>-1; k--){
        s = 0;
        for(j=k+1; j<n; j++)
            s = s + A[k][j]*x[j];
        x[k] = (b[k] - s)/A[k][k];
    }

    return x;
}

void eliminacaoDeGauss(float A[][3], float b[], int n){
    float m;
    int i, j, k;

    for(k=0; k<n-1; k++){
        for(i=k+1; i<n; i++){
            m = - A[i][k]/partialPivotion(A, b, k, n);
            A[i][k] = 0;
            for(j=k+1; j<n; j++)
                A[i][j] = A[i][j] + m*A[k][j];
            b[i] = b[i] + m*b[k];
        }
    }
}

float partialPivotion(float A[][3], float b[], int k, int n){
    int i, j;
    float m;

    j = k;
    m = abs( A[k][k] );
    for( i=k+1; i<n; i++ ){
        if( m < abs( A[i][k] ) ){
            m = abs( A[i][k] );
            j = i;
        }
    }

    if( j != k )
        switchLines(A, b, j, k, n);

    return A[k][j];
}

void switchLines(float A[][3], float b[], int j, int k, int n){
    int i;
    float t;

    for( i=0; i<n; i++ ){
        t = A[j][i];
        A[j][i] = A[k][i];
        A[k][i] = t;
    }
    t = b[j];
    b[j] = b[k];
    b[k] = t;
}
*/
