#ifndef SPECTRUM3D_H
#define SPECTRUM3D_H

#include <cstdlib>

#include <math.h>
#include <QApplication>
#include <QWidget>

#include <qwtplot3d/qwt3d_surfaceplot.h>
#include <qwtplot3d/qwt3d_function.h>

class MeshPlot3D: public Qwt3D::SurfacePlot
{
	Q_OBJECT
public slots:
	void slot_refreshPlot();

public:
    explicit MeshPlot3D();	//init
	void initData(int column, int row);
	bool destroyData();
	bool setData( int column, int row, double value);
	void testFunc_sin();

private:
	int column;
	int row;

	double **data;
};

#endif //SPECTRUM3d_H
