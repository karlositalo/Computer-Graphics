#include "Observer.h"
#include "Matrix.h"

Observer::Observer(Kvertex* observerPos, Kvertex* lookAt, Kvertex* viewUp, int d, int Nx, int Ny, float W, float H){
    observerPosition = observerPos;
    this->lookAt = lookAt;
    this->viewUp = viewUp;

    Kc = observerPosition->subtractVectors(lookAt);
    Kc->normalize();

    this->viewUp = this->viewUp->subtractVectors(observerPosition);

    Ic = this->viewUp->crossProduct(Kc);
    Ic->normalize();

    Jc = Kc->crossProduct(Ic);

    kwindow = new ViewPort(d, Nx, Ny, W, H);

    Tc_m[0][0] = Ic->x; Tc_m[0][1] = Jc->x; Tc_m[0][2] = Kc->x; Tc_m[0][3] = observerPosition->x;
    Tc_m[1][0] = Ic->y; Tc_m[1][1] = Jc->y; Tc_m[1][2] = Kc->y; Tc_m[1][3] = observerPosition->y;
    Tc_m[2][0] = Ic->z; Tc_m[2][1] = Jc->z; Tc_m[2][2] = Kc->z; Tc_m[2][3] = observerPosition->z;
    Tc_m[3][0] = 0;     Tc_m[3][1] = 0;     Tc_m[3][2] = 0;     Tc_m[3][3] = 1;

    Tm_c[0][0] = Ic->x; Tm_c[0][1] = Ic->y; Tm_c[0][2] = Ic->z; Tm_c[0][3] = -observerPosition->dotProduct(Ic);
    Tm_c[1][0] = Jc->x; Tm_c[1][1] = Jc->y; Tm_c[1][2] = Jc->z; Tm_c[1][3] = -observerPosition->dotProduct(Jc);
    Tm_c[2][0] = Kc->x; Tm_c[2][1] = Kc->y; Tm_c[2][2] = Kc->z; Tm_c[2][3] = -observerPosition->dotProduct(Kc);
    Tm_c[3][0] = 0;     Tm_c[3][1] = 0;     Tm_c[3][2] = 0;     Tm_c[3][3] = 1;
}

void Observer::T_w_c(Scene *c){
    float v[4];
    float* u;
    v[3] = 1;

    for( int i=0; i<18; i++ ){
        for( int j=0; j<8; j++ ){
            v[0] = c->ObjectList[i]->KvertexList[j]->x;
            v[1] = c->ObjectList[i]->KvertexList[j]->y;
            v[2] = c->ObjectList[i]->KvertexList[j]->z;
            u = vector_matrixMultiplicaton(Tm_c, v);

            c->ObjectList[i]->KvertexList[j]->x = u[0];
            c->ObjectList[i]->KvertexList[j]->y = u[1];
            c->ObjectList[i]->KvertexList[j]->z = u[2];
            delete u;
        }
    }

    v[0] = c->LS->position->x; v[1] = c->LS->position->y; v[2] = c->LS->position->z; v[3] = 1;
    u = vector_matrixMultiplicaton(Tm_c, v);

    c->LS->position->x = u[0]; c->LS->position->y = u[1]; c->LS->position->z = u[2];

    delete u;

    observerPosition->x = 0; observerPosition->y = 0; observerPosition->z = 0;
   /* v[0] = observerPosition->x; v[1] = observerPosition->y; v[2] = observerPosition->z; v[3] = 1;
    u = vector_matrixMultiplicaton(Tm_c,v);
    observerPosition->x = u[0]; observerPosition->y = u[1]; observerPosition->z = u[2];
    delete u;*/
}

