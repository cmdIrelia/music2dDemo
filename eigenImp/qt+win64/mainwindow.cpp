#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

using namespace Qwt3D;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    music.argo_test(0.5);

    qDebug()<<"test result = "<<music.Azimuth<<" "<<music.Elevation;

    makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Triple** MainWindow::allocateData(int columns, int rows)
{
    Triple** data  = new Triple* [columns] ;
    for ( int i = 0; i < columns; ++i)
    {
        data[i]  = new Triple [rows];
        for(int j=0;j<rows;j++)
        {
            data[i][j].x=i*0.1-2;
            data[i][j].y=j*0.1-2;
            data[i][j].z=1.0 / ((data[i][j].x+1)*(data[i][j].x+1)+data[i][j].y*data[i][j].y+0.3);
            data[i][j].z+=1.0 / ((data[i][j].x-1)*(data[i][j].x-1)+data[i][j].y*data[i][j].y+0.3);
        }
    }
    return data;
}

Triple** MainWindow::allocateData()
{
    const int colums = 361;
    const int rows = 91;
    Triple** data  = new Triple* [colums] ;
    for ( int i = 0; i < colums; ++i)
    {
        data[i]  = new Triple [rows];
        for(int j=0;j<rows;j++)
        {
            data[i][j].x=i;
            data[i][j].y=j;
            //qDebug("%d %d %f\t",i,j,music.Pmusic[i][j]);
            if(music.Pmusic[i][j]>100){
                data[i][j].z=100;
            }
            else if(music.Pmusic[i][j]<0){
                qDebug()<<music.Pmusic[i][j];
                data[i][j].z=0;
            }
            else{
                data[i][j].z=music.Pmusic[i][j];
            }
        }
    }
    return data;
}

void MainWindow::refreshPlot()
{
    int x=361,y=91;
    Triple **tr = allocateData();
    plot->loadFromData(tr, x, y);
    deleteData(tr, x);

    for (unsigned i=0; i!=plot->coordinates()->axes.size(); ++i)
    {
        plot->coordinates()->axes[i].setMajors(5);
        plot->coordinates()->axes[i].setMinors(4);
        plot->coordinates()->axes[i].setLabelColor(RGBA(0,0,0.4));
    }

    plot->makeCurrent();
    plot->updateData();
    plot->updateGL();
}

void MainWindow::makePlot()
{
    plot = new SurfacePlot(ui->frame);

    plot->setTitle("DOA");

    QGridLayout *grid = new QGridLayout( ui->frame);
    grid->addWidget(plot,0,0);

    plot->setZoom(0.8);
    plot->setRotation(30,0,145);

    plot->coordinates()->setGridLines(true,true);

    plot->setCoordinateStyle(BOX);

    int x=361,y=91;
    Triple **tr = allocateData();
    plot->loadFromData(tr, x, y);
    deleteData(tr, x);

    for (unsigned i=0; i!=plot->coordinates()->axes.size(); ++i)
    {
        plot->coordinates()->axes[i].setMajors(5);
        plot->coordinates()->axes[i].setMinors(4);
        plot->coordinates()->axes[i].setLabelColor(RGBA(0,0,0.4));
    }

    plot->setMeshLineWidth(1);
    plot->coordinates()->setGridLinesColor(RGBA(0,0,0.5));
    plot->coordinates()->setLineWidth(1);
    plot->coordinates()->setNumberColor(RGBA(0,0.5,0));
    plot->coordinates()->setNumberFont("Courier",10);
    plot->setTitleFont("Courier",11);
    plot->coordinates()->setLabelFont("Courier",12, QFont::Bold);

    plot->coordinates()->axes[X1].setLabelString("Azimuth");
    plot->coordinates()->axes[X4].setLabelString("Azimuth");

    plot->coordinates()->axes[Y1].setLabelString("Elevation");
    plot->coordinates()->axes[Y2].setLabelString("Elevation");

    plot->coordinates()->axes[Z1].setLabelString("Pmusic");
    plot->coordinates()->axes[Z2].setLabelString("Pmusic");
    plot->coordinates()->axes[Z3].setLabelString("Pmusic");
    plot->coordinates()->axes[Z4].setLabelString("Pmusic");

    plot->coordinates()->setLineSmooth(true);

    plot->setRotation(35,0,-135);
    plot->setScale(1,1,1);
    plot->setShift(0,0,0);
    plot->setZoom(0.9);
    plot->setBackgroundColor(RGBA(1,1, 157./255));

    plot->makeCurrent();
    plot->updateData();
    plot->updateGL();
}

void MainWindow::deleteData(Triple** data, int columns)
{
    for ( int i = 0; i < columns; i++)
    {         delete [] data[i];     }
    delete [] data;
}

void MainWindow::on_pushButton_clicked()
{
    music.argo_test(ui->doubleSpinBox->value());
    qDebug()<<"test result = "<<music.Azimuth<<" "<<music.Elevation;
    refreshPlot();
    qDebug()<<"void refreshPlot()";
}
