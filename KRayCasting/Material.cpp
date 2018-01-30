#include "Material.h"

Material::Material()
{
    Kamb = new Kvertex( 0.5, 0.5, 0.5 );
    Kdif = new Kvertex( 0.5, 0.5, 0.5 );
    Kspec = new Kvertex( 0.5, 0.5, 0.5 );
    m = 1;
}

Material::Material(float *ka, float *kd, float *ks, float mm)
{
    Kamb = new Kvertex( ka[0], ka[1], ka[2] );
    Kdif = new Kvertex( kd[0], kd[1], kd[2] );
    Kspec = new Kvertex( ks[0], ks[1], ks[2] );
    m = mm;
}
