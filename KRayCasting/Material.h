#ifndef MATERIAL_H
#define MATERIAL_H

#include "Kvertex.h"

class Material
{
public:
    Material();
    Material(float* ka, float* kd, float* ks, float mm);
    Kvertex *Kamb, *Kdif, *Kspec;
    float m;
};

#endif // MATERIAL_H
