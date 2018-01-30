#ifndef SCENE_H
#define SCENE_H

#include "LightSource.h"
#include "Cube.h"

class Scene{
public:
    Scene();
    void modeling();
    Cube *tampo, *perna1, *perna2, *perna3, *perna4,*letra1,*letra2_1,*letra2_2,*letra3_1,*letra3_2,*letra3_3,*letra3_4;
    Cube *letra4_1,*letra4_2,*letra5_1,*letra5_2,*letra5_3,*letra5_4,*cauda_3;
    Cube* ObjectList[18];
    LightSource* LS;
};

#endif // Scene_H
