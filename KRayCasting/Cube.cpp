#include "Cube.h"

Cube::Cube(Material *mat){
    KvertexList[0] = new Kvertex(1, -1, 1);
    KvertexList[1] = new Kvertex(1, -1, -1);
    KvertexList[2] = new Kvertex(-1, -1, -1);
    KvertexList[3] = new Kvertex(-1, -1, 1);
    KvertexList[4] = new Kvertex(1, 1, 1);
    KvertexList[5] = new Kvertex(1, 1, -1);
    KvertexList[6] = new Kvertex(-1, 1, -1);
    KvertexList[7] = new Kvertex(-1, 1, 1);

    FaceList[0] = new Face(KvertexList[3], KvertexList[0], KvertexList[7], mat);
    FaceList[1] = new Face(KvertexList[0], KvertexList[4], KvertexList[7], mat);
    FaceList[2] = new Face(KvertexList[0], KvertexList[5], KvertexList[4], mat);
    FaceList[3] = new Face(KvertexList[0], KvertexList[1], KvertexList[5], mat);
    FaceList[4] = new Face(KvertexList[2], KvertexList[3], KvertexList[6], mat);
    FaceList[5] = new Face(KvertexList[3], KvertexList[7], KvertexList[6], mat);
    FaceList[6] = new Face(KvertexList[1], KvertexList[2], KvertexList[5], mat);
    FaceList[7] = new Face(KvertexList[2], KvertexList[6], KvertexList[5], mat);
    FaceList[8] = new Face(KvertexList[0], KvertexList[3], KvertexList[1], mat);
    FaceList[9] = new Face(KvertexList[3], KvertexList[2], KvertexList[1], mat);
    FaceList[10] = new Face(KvertexList[7], KvertexList[4], KvertexList[6], mat);
    FaceList[11] = new Face(KvertexList[4], KvertexList[5], KvertexList[6], mat);
}

void Cube::translate(float tx, float ty, float tz){
    int i;

    for( i=0; i<8; i++ )
        KvertexList[i]->translate(tx, ty, tz);
}

void Cube::scale(float sx, float sy, float sz){
    int i;

    for( i=0; i<8; i++ )
        KvertexList[i]->scale(sx, sy, sz);
}

void Cube::rotateX(float ang){
    int i;

    for( i=0; i<8; i++ )
        KvertexList[i]->rotateX(ang);
}

void Cube::rotateY(float ang){
    int i;

    for( i=0; i<8; i++ )
        KvertexList[i]->rotateY(ang);
}

void Cube::rotateZ(float ang){
    int i;

    for( i=0; i<8; i++ )
        KvertexList[i]->rotateZ(ang);
}
