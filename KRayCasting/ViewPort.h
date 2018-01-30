#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Kvertex.h"
#include "Scene.h"

class ViewPort{
public:
    ViewPort(float d, int nx, int ny, float w, float h);
    Kvertex*** pixColors;
    float distance;
    int Nx, Ny;
    float W, H;
    void rayCasting(Scene *c);
    void getPixColor(Face*f, Kvertex *IP, LightSource *ls, int i, int j);
    void normalizeColors();
};

#endif // ViewPort_H
