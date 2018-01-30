#include "Scene.h"
#include "Material.h"
#include <cmath>
using namespace std;

Scene::Scene(){
    float ka[3] = {1, 1, 0.0};
    Material* m = new Material(ka, ka, ka, 0.1);
    tampo = new Cube(m);

    ka[0] = 1.0; ka[1] = 0.0; ka[2] = 0.0;
    m = new Material(ka, ka, ka, 0.2);
    perna1 = new Cube(m);

    ka[0] = 0.0; ka[1] = 1.0; ka[2] = 0.0;
    m = new Material(ka, ka, ka, 0.3);
    perna2 = new Cube(m);

    ka[0] = 0.0; ka[1] = 0.0; ka[2] = 1.0;
    m = new Material(ka, ka, ka, 0.4);
    perna3 = new Cube(m);

    ka[0] = 0.0; ka[1] = 0.0; ka[2] = 1.0;
    m = new Material(ka, ka, ka, 0.5);
    perna4 = new Cube(m);

    //AVIAO
    ka[0] = 1.0; ka[1] = 0.0; ka[2] = 0.0;
    m = new Material(ka, ka, ka, 0.5);
    letra1 = new Cube(m);
    ka[0] = 0.0; ka[1] = 1.0; ka[2] = 1.0;
    m = new Material(ka, ka, ka, 0.5);
    letra2_1 = new Cube(m);
    letra2_2 = new Cube(m);
    ka[0] = 1.0; ka[1] = 0.0; ka[2] = 1.0;
    m = new Material(ka, ka, ka, 0.5);
    letra3_1 = new Cube(m);
    letra3_2 = new Cube(m);
    letra3_3 = new Cube(m);
    letra3_4 = new Cube(m);
    ka[0] = 0.0; ka[1] = 1.0; ka[2] = 0.0;
    m = new Material(ka, ka, ka, 0.5);
    letra4_1 = new Cube(m);
    letra4_2 = new Cube(m);
    ka[0] = 0.5; ka[1] = 0.0; ka[2] = 0.5;
    m = new Material(ka, ka, ka, 0.5);
    letra5_1 = new Cube(m);
    letra5_2 = new Cube(m);
    letra5_3 = new Cube(m);
    letra5_4 = new Cube(m);

    //AVIAO

    ka[0] = 0.3; ka[1] = 0.3; ka[2] = 0.3;
    float ks[3] = {0.8, 0.8, 0.8};
    LS = new LightSource(ka, ks, ks, new Kvertex(500, 350, 250));

    ObjectList[0] = tampo;
    ObjectList[1] = perna1;
    ObjectList[2] = perna2;
    ObjectList[3] = perna3;
    ObjectList[4] = perna4;
    ObjectList[5] = letra1;
    ObjectList[6] = letra2_1;
    ObjectList[7] = letra2_2;
    ObjectList[8] =  letra3_1;
    ObjectList[9] =  letra3_2;
    ObjectList[10] =  letra3_3;
    ObjectList[11] =  letra3_4;
    ObjectList[12] =  letra4_1;
    ObjectList[13] =  letra4_2;
    ObjectList[14] =  letra5_1;
    ObjectList[15] =  letra5_2;
    ObjectList[16] = letra5_3;
    ObjectList[17] =  letra5_4;

}

void Scene::modeling(){

    tampo->scale(110, 1.5, 60);
    perna1->scale(2.5, 36, 1.5);
    perna2->scale(2.5, 36, 1.5);
    perna3->scale(2.5, 36, 1.5);
    perna4->scale(2.5, 36, 1.5);
    //letra1->rotateX(1.57);
    //aviao
        for(int i = 5 ; i <18 ; i++)
            ObjectList[i]->scale(2.5, 20, 5);
        letra4_2->scale(2,1,1);
    //aviao

    tampo->translate(0, 73.5, 0);
    perna1->translate(-107.5, 36, -58.5);
    perna2->translate(-107.5, 36, 58.5);
    perna3->translate(107.5, 36, -58.5);
    perna4->translate(107.5, 36, 58.5);

    //aviao
        letra1->translate(-105,94,0);

        letra2_1->translate(-75,94,0);
        letra2_2->rotateZ(1.57);
        letra2_2->translate(-75,114,0);

        letra3_1->translate(-45,94,0);
        letra3_2->translate(-10,94,0);
        letra3_3->rotateZ(1.57);
        letra3_3->translate(-27.5,104,0);
        letra3_4->rotateZ(1.57);
        letra3_4->translate(-27.5,114,0);

        letra4_1->translate(12.5,94,0);
        letra4_2->rotateZ(1.57);
        letra4_2->translate(27.5,81,0);

        letra5_1->translate(60,94,0);
        letra5_2->translate(90,94,0);
        letra5_3->rotateZ(1.57);
        letra5_3->translate(75,79,0);
        letra5_4->rotateZ(1.57);
        letra5_4->translate(75,115,0);

    //aviao
    float theta = acos(10.0/11.18033);
    theta = -theta;
   /* for(int i = 0 ; i < 18 ; i++){
        ObjectList[i]->rotateY(theta);
    }*/
    /*
    tampo->rotateY(theta);
    perna1->rotateY(theta);
    perna2->rotateY(theta);
    perna3->rotateY(theta);
    perna4->rotateY(theta);
    letra1->rotateY(theta);
    letra2_1->rotateY(theta);
    letra2_2->rotateY(theta);
    letra3_1->rotateY(theta);
    letra3_2->rotateY(theta);
    letra3_3->rotateY(theta);
    letra3_4->rotateY(theta);
    letra4_1->rotateY(theta);
    letra4_2->rotateY(theta);
    letra5_1->rotateY(theta);
    letra5_2->rotateY(theta);
    letra5_3->rotateY(theta);
    letra5_4->rotateY(theta);
*/
    /*for(int i = 0; i < 18 ; i++){
        ObjectList[i]->translate(500, 0, 250);
    }*/
    /*
    tampo->translate(500, 0, 250);
    perna1->translate(500, 0, 250);
    perna2->translate(500, 0, 250);
    perna3->translate(500, 0, 250);
    perna4->translate(500, 0, 250);

    //aviao

        letra1->translate(500, 0, 250);
        letra2_1->translate(500, 0, 250);
        letra2_2->translate(500, 0, 250);
        letra3_1->translate(500, 0, 250);
        letra3_2->translate(500, 0, 250);
        letra3_3->translate(500, 0, 250);
        letra3_4->translate(500, 0, 250);
        letra4_1->translate(500, 0, 250);
        letra4_2->translate(500, 0, 250);
        letra5_1->translate(500, 0, 250);
        letra5_2->translate(500, 0, 250);
        letra5_3->translate(500, 0, 250);
        letra5_4->translate(500, 0, 250);
    //aviao*/
}
