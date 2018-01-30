#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Observer.h"
#include "Scene.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int Nx = 500;
    int Ny = 500;
    float H = 150;
    float W = 150;
    float dist = 50;

    //Observer* ob = new Observer( new Kvertex(900, 130, 100), new Kvertex(600, 75, 250), new Kvertex(600, 175, 250), dist, Nx, Ny, W, H );
    Observer* ob = new Observer( new Kvertex(0, 72, 500), new Kvertex(0, 75, 0), new Kvertex(0, 175, 0), dist, Nx, Ny, W, H );
    Scene* cena = new Scene();

    cena->modeling();

    ob->T_w_c(cena);

    ob->kwindow->rayCasting(cena);

    //initialize random seed
    srand (time(NULL));

    QImage image = QImage( Nx, Ny, QImage::Format_RGB32 );

    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ ){
            //NORMALIZANDO BURRAMENTE
            if(ob->kwindow->pixColors[i][j]->x >1)
               ob->kwindow->pixColors[i][j]->x=1;


            if(ob->kwindow->pixColors[i][j]->y >1)
               ob->kwindow->pixColors[i][j]->y=1;


            if(ob->kwindow->pixColors[i][j]->z >1)
               ob->kwindow->pixColors[i][j]->z=1;
            //NORMALIZANDO BURRAMENTE
            //cout << ob->kwindow->pixColors[i][j]->x << " " << ob->kwindow->pixColors[i][j]->y << " " << ob->kwindow->pixColors[i][j]->z << endl;
            image.setPixel(j, i, qRgb( ob->kwindow->pixColors[i][j]->x*255.0, ob->kwindow->pixColors[i][j]->y*255.0, ob->kwindow->pixColors[i][j]->z*255.0 ));
            delete ob->kwindow->pixColors[i][j];
        }
    }

    //image.setPixel( l, c, qRgb(100, 150, 200) );

    QGraphicsScene * graphic = new QGraphicsScene( this );

    graphic->addPixmap( QPixmap::fromImage( image ) );

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}
