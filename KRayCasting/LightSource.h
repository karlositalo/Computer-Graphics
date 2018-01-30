#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "Kvertex.h"

class LightSource
{
public:
    LightSource(float* ia, float* id, float* is, Kvertex* v);
    Kvertex *Iamb, *Idif, *Ispec;
    Kvertex* position;
};

#endif // LightSource_H
