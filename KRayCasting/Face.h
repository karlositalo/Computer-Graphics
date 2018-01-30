#ifndef FACE_H
#define FACE_H

#include "Kvertex.h"
#include "Material.h"

class Face{
    public:
        Face(Kvertex*, Kvertex*, Kvertex*, Material *mat);
        Kvertex* calculateNormal();
        float getIntesection(Kvertex* u);
        Material* propMat;
        Kvertex *v1, *v2, *v3;
};

#endif // FACE_H
