#ifndef KVERTEX_H
#define KVERTEX_H

class Kvertex{
    public:
        float x, y, z;

        void scale(float, float, float);
        void translate(float, float, float);
        void normalize();
        void rotateX(float);
        void rotateY(float);
        void rotateZ(float);
        void changeDirection();

        float dotProduct(Kvertex*);
        float norm();

        Kvertex();
        Kvertex(float, float, float);
        Kvertex* sumVectors(Kvertex*);
        Kvertex* subtractVectors(Kvertex*);
        Kvertex* crossProduct(Kvertex*);
        Kvertex* corrProduct(Kvertex*);
        Kvertex* scalarVectorProduct(float);
};

#endif // Kvertex_H
