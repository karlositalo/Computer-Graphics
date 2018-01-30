#ifndef OBSERVERVER_H
#define OBSERVERVER_H

#include "Kvertex.h"
#include "ViewPort.h"
#include "Scene.h"

class Observer
{
public:
    Observer(Kvertex* observerPos, Kvertex* lookAt, Kvertex* viewUp, int d, int Nx, int Ny, float W, float H);

    void T_w_c(Scene* c);
    float Tc_m[4][4];
    float Tm_c[4][4];

    ViewPort* kwindow;

    Kvertex* observerPosition;
    Kvertex* lookAt;
    Kvertex* viewUp;
    Kvertex *Ic, *Jc, *Kc;

};

#endif // Observer_H
