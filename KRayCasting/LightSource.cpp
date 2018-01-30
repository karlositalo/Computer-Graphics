#include "LightSource.h"

LightSource::LightSource(float *ia, float *id, float *is, Kvertex *v){
    Iamb = new Kvertex( ia[0], ia[1], ia[2] );
    Idif = new Kvertex( id[0], id[1], id[2] );
    Ispec = new Kvertex( is[0], is[1], is[2] );
    position = v;
}
