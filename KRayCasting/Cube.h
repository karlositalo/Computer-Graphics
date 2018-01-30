#ifndef CUBE_H
#define CUBE_H

#include "Kvertex.h"
#include "Face.h"
#include "Material.h"

class Cube
{
public:
    Cube(Material *mat);
    Kvertex *KvertexList[8];
    Face* FaceList[12];
    void translate(float, float, float);
    void scale(float, float, float);
    void rotateX(float);
    void rotateY(float);
    void rotateZ(float);
};

#endif // Cube_H
