#include "ViewPort.h"
#include "Face.h"
#include <cstddef>
#include <math.h>
#include <iostream>
using namespace std;

ViewPort::ViewPort(float d, int nx, int ny, float w, float h)
{
    distance = d;
    Nx = nx;
    Ny = ny;
    W = w;
    H = h;

    pixColors = new Kvertex**[Nx];
    for( int i=0; i<Nx; i++ )
        pixColors[i] = new Kvertex*[Ny];

    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ )
            pixColors[i][j] = new Kvertex(1, 1, 1);
    }
}

void ViewPort::rayCasting(Scene *c){
    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ ){
            Kvertex* pix = new Kvertex( (-W/2 + (W/Ny)/2 + j*(W/Ny)) , (H/2 - (H/Nx)/2 - i*(H/Nx)) , -distance );
            //cout << pix->x << " " << pix->y << " " << pix->z << endl;
            Face* f = NULL;
            float t = 99999;

            //pix->normalize();
            for( int k=0; k<18; k++ ){
                for( int l=0; l<12; l++ ){
                    Kvertex* n = c->ObjectList[k]->FaceList[l]->calculateNormal();
                    n->normalize();

                    if( n->dotProduct( pix ) < 0.0 ){
                        //cout << cont++ << endl;
                        float tt = c->ObjectList[k]->FaceList[l]->getIntesection( pix );
                        //cout << tt << endl;
                        if( tt < t ){
                          //  cout << "interseção" << endl;
                            f = c->ObjectList[k]->FaceList[l];
                            t = tt;
                        }
                    }
                }
            }

            if( f != NULL ){
                getPixColor(f, pix->scalarVectorProduct( t ), c->LS, i, j);
            }
            else{
                pixColors[i][j]->x=1.0;
                pixColors[i][j]->y=1.0;
                pixColors[i][j]->z=1.0;
            }
            delete pix;
        }
    }

    normalizeColors();
}

void ViewPort::getPixColor(Face *f, Kvertex* IP, LightSource *ls, int i, int j){
    Kvertex* n = f->calculateNormal();
    n->normalize();

    //cout << "normal: " << n->x << " " << n->y << " " << n->z << endl;

    Kvertex* l = ls->position->subtractVectors( IP );
    l->normalize();
    //cout << "l: " << l->x << " " << l->y << " " << l->z << endl;
    IP->changeDirection();
    Kvertex* v = IP;
    v->normalize();
    //cout << "v: " << v->x << " " << v->y << " " << v->z << endl;

    float t = 2*l->dotProduct( n );
    Kvertex* r = n->scalarVectorProduct(t);
    r = r->subtractVectors(l);
    //cout << "r: " << r->x << " " << r->y << " " << r->z << endl;

    Kvertex* compAmb = ls->Iamb->corrProduct( f->propMat->Kamb );
    //cout << "compAmb: " << compAmb->x << " " << compAmb->y << " " << compAmb->z << endl;

    Kvertex* compDif = ls->Idif->corrProduct( f->propMat->Kdif );
    compDif = compDif->scalarVectorProduct( n->dotProduct( l ) );
    if( n->dotProduct( l ) < 0 ){
        compDif->x = 0;
        compDif->y = 0;
        compDif->z = 0;
    }
    //cout << "compDif: " << compDif->x << " " << compDif->y << " " << compDif->z << endl;

    t = r->dotProduct( v );
    //cout << "t: " << t << endl;
    t = pow( t, f->propMat->m );
    //cout << f->propMat->m << endl;
    //cout << "t: " << t << endl;
    Kvertex* compEsp = new Kvertex(0, 0, 0);
    if( t>0 ){
        compEsp = ls->Ispec->corrProduct( f->propMat->Kspec );
        //cout << "compEsp: " << compEsp->x << " " << compEsp->y << " " << compEsp->z << endl;
        compEsp = compEsp->scalarVectorProduct( t );
        //cout << "compEsp: " << compEsp->x << " " << compEsp->y << " " << compEsp->z << endl;
    }

    Kvertex* intLuz = compAmb->sumVectors( compDif );
    intLuz = intLuz->sumVectors( compEsp );

    pixColors[i][j]->x = intLuz->x;
    pixColors[i][j]->y= intLuz->y;
    pixColors[i][j]->z= intLuz->z;

    delete intLuz;
    delete compEsp;
    delete compAmb;
    delete compDif;
    delete n;
    delete l;
    //delete v;
    delete r;
    //cout << pixColors[i][j]->x << " " << pixColors[i][j]->y << " " << pixColors[i][j]->z << endl;
}

void ViewPort::normalizeColors(){
    float t = pixColors[0][0]->x;

    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ ){
            //cout << t << endl;
            float t1 = pixColors[i][j]->x;
            float t2 = pixColors[i][j]->y;
            float t3 = pixColors[i][j]->z;

            if( t1 > t2 && t1 > t3 && t1 > t )
                t = t1;
            if( t2 > t1 && t2 > t3 && t2 > t )
                   t = t2;
            if( t3 > t2 && t3 > t1 && t3 > t )
                t = t3;
        }
    }
    cout << t << endl;
    if( t > 1 ){

        for( int i=0; i<Nx; i++ ){
            for( int j=0; j<Ny; j++ ){
                pixColors[i][j]->x /= t;
                pixColors[i][j]->y /= t;
                pixColors[i][j]->z /= t;
            }
        }
    }
}
