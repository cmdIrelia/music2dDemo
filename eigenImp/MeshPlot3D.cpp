#include "MeshPlot3D.h"
#include <QDebug>

using namespace Qwt3D;

MeshPlot3D::MeshPlot3D() : column(0), row(0), data(nullptr)
{
    setTitle("A Simple SurfacePlot Demonstration");

	this->initData( 100, 100);

    setRotation(30,0,15);
    setScale(1,1,1);
    setShift(0.15,0,0);
    setZoom(0.9);

    for (unsigned i=0; i!=coordinates()->axes.size(); ++i)
    {
        coordinates()->axes[i].setMajors(7);
        coordinates()->axes[i].setMinors(4);
    }

    coordinates()->axes[X1].setLabelString("x-axis");
    coordinates()->axes[Y1].setLabelString("y-axis");
    coordinates()->axes[Z1].setLabelString("z-level");

    setCoordinateStyle(BOX);

    updateData();
    updateGL();
}

void MeshPlot3D::initData(int column, int row)
{
	if( this->data != nullptr )
		this->destroyData();

	this->column = column;
	this->row = row;

	this->data = new double*[column];
	for(int i = 0; i < column; ++i)
		*(data + i) = new double[row];
}

bool MeshPlot3D::destroyData()
{
	if( this->data == nullptr)
		return false;
	else
	{
		for(int i = 0; i < column; ++i)
			delete *(data + i);
		delete data;
		this->data = nullptr;

		return true;
	}
}

bool MeshPlot3D::setData( int column, int row, double value)
{
	if( this->data == nullptr || (column < 0) || (column >= this->column) || (row < 0) || (row >= this->column))
		return false;
	else
	{
		*(*(this->data + column) + row) = value;	
		return true;	
	}
}


// slots:
void MeshPlot3D::slot_refreshPlot()
{
	this->loadFromData( this->data, column, row, 0, column, 0, row);

	updateData();
	updateGL();
}

void MeshPlot3D::testFunc_sin()
{
	static double ph = 0;
	ph += 0.01;
	if( ph > 1e5)
		ph = 0;
	
	for(int i = 0; i < this->column; ++i)
		for(int j = 0; j < this->row; ++j)
			*(*(this->data + i) + j) = (rand() % 10) / 20.0 - 10 * (sin(j / 10.0 + ph));

}
