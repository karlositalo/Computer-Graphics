#include "Kvertex.h"
#include "Matrix.h"
#include <cmath>
#include <iostream>
using namespace std;

Kvertex::Kvertex()
{
    x = 1;
    y = 1;
    z = 1;
}

Kvertex::Kvertex(float nx, float ny, float nz){
    x = nx;
    y = ny;
    z = nz;
}

Kvertex* Kvertex::sumVectors(Kvertex* u){
    Kvertex* v = new Kvertex(x + u->x, y + u->y, z + u->z);

    return v;
}

Kvertex* Kvertex::subtractVectors(Kvertex* u){
    Kvertex* v = new Kvertex(x - u->x, y - u->y, z - u->z);

    return v;
}

void Kvertex::changeDirection(){
    this->x=-x;
    this->y=-y;
    this->z=-z;
}

Kvertex* Kvertex::crossProduct(Kvertex* u){
    Kvertex* v = new Kvertex(y*u->z - z*u->y, z*u->x - x*u->z, x*u->y - y*u->x);

    return v;
}

float Kvertex::dotProduct(Kvertex* u){
    return x*u->x + y*u->y + z*u->z;
}

Kvertex* Kvertex::scalarVectorProduct(float k){
    Kvertex* v = new Kvertex(x*k, y*k, z*k);

    return v;
}

Kvertex* Kvertex::corrProduct(Kvertex* u){
    Kvertex* v = new Kvertex(x*u->x, y*u->y, z*u->z);

    return v;
}

float Kvertex::norm(){
    return sqrt(x*x + y*y + z*z);
}

void Kvertex::normalize(){
    float n = norm();

    x = x/n;
    y = y/n;
    z = z/n;
}

void Kvertex::translate(float tx, float ty, float tz){
    x = x + tx;
    y = y + ty;
    z = z + tz;
}

void Kvertex::scale(float sx, float sy, float sz){
    x = x*sx;
    y = y*sy;
    z = z*sz;
}

void Kvertex::rotateX(float ang){
    float R[4][4] = {{1,0,0,0}, {0,cos(ang),-sin(ang),0}, {0,sin(ang),cos(ang),0}, {0,0,0,1}};
    float v[4] = {x,y,z,1};
    float* u;

    u = vector_matrixMultiplicaton(R, v);

    x = u[0];
    y = u[1];
    z = u[2];
}

void Kvertex::rotateY(float ang){
    cout << "seno" << sin(ang) << "cos" << cos(ang) << endl;
    float R[4][4] = {{cos(ang),0,sin(ang),0}, {0,1,0,0}, {-sin(ang),0,cos(ang),0}, {0,0,0,1}};
    float v[4] = {x,y,z,1};
    float* u;

    u = vector_matrixMultiplicaton(R, v);

    x = u[0];
    y = u[1];
    z = u[2];
}

void Kvertex::rotateZ(float ang){
    float R[4][4] = {{cos(ang),-sin(ang),0,0}, {sin(ang),cos(ang),0,0}, {0,0,1,0}, {0,0,0,1}};
    float v[4] = {x,y,z,1};
    float* u;

    u = vector_matrixMultiplicaton(R, v);

    x = u[0];
    y = u[1];
    z = u[2];
}
