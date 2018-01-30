#include "Face.h"
#include "LinearSystems.h"
#include <iostream>
using namespace std;

Face::Face(Kvertex* u, Kvertex* v, Kvertex* w, Material* mat){
    v1 = u;
    v2 = v;
    v3 = w;
    propMat = mat;
}

Kvertex* Face::calculateNormal(){
    Kvertex* w1 = v2->subtractVectors(v1);
    Kvertex* w2 = v3->subtractVectors(v1);
    Kvertex* N = w1->crossProduct(w2);
    N->normalize();

    delete w1;
    delete w2;
    return N;
}

float Face::getIntesection(Kvertex* u){
    Kvertex* w1 = v2->subtractVectors(v1);
    Kvertex* w2 = v3->subtractVectors(v1);
    w1->changeDirection();
    w2->changeDirection();
    float A[3][3] = {{u->x, w1->x, w2->x}, {u->y, w1->y, w2->y}, {u->z, w1->z, w2->z}};
    float b[3] = {v1->x, v1->y, v1->z};
    float* x = gaussMethod(A, b, 3);
    float c = 1 - x[1] - x[2];

    //cout << x[0] << x[1] << x[2] <<endl;

    if( ( x[1] > 0 ) && ( x[2] > 0 ) && ( c > 0 ) ){
        return x[0];
    }

    /*if((u->x > v1->x && u->x > v2->x && u->x > v3->x) || (u->x < v1->x && u->x < v2->x && u->x < v3->x) ||
            (u->y > v1->y && u->y > v2->y && u->y > v3->y) || (u->y < v1->y && u->y < v2->y && u->y < v3->y) ||
            (u->z > v1->z && u->z > v2->z && u->z > v3->z) || (u->z < v1->z && u->z < v2->z && u->x < v3->z)){
        return 99999;
    }
    //cout << u->norma() <<endl;
    return u->norma();*/
    delete w1;
    delete w2;
    return 99999;
}
