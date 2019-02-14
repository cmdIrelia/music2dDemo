#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "music2ducadoa.h"
#include <include/qwt3d_types.h>
#include <include/qwt3d_surfaceplot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void makePlot();
    void refreshPlot();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Music2dUCADoa music;

    Qwt3D::SurfacePlot *plot;
    Qwt3D::Triple **allocateData(int columns, int rows);
    Qwt3D::Triple **allocateData();
    void deleteData(Qwt3D::Triple **data, int columns);

};

#endif // MAINWINDOW_H
