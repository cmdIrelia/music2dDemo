#-------------------------------------------------
#
# Project created by QtCreator 2019-02-14T19:36:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eigen
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    music2ducadoa.cpp

HEADERS += \
        mainwindow.h \
    Eigen/Cholesky \
    Eigen/CholmodSupport \
    Eigen/Core \
    Eigen/Dense \
    Eigen/Eigen \
    Eigen/Eigenvalues \
    Eigen/Geometry \
    Eigen/Householder \
    Eigen/IterativeLinearSolvers \
    Eigen/Jacobi \
    Eigen/KLUSupport \
    Eigen/LU \
    Eigen/MetisSupport \
    Eigen/OrderingMethods \
    Eigen/PardisoSupport \
    Eigen/PaStiXSupport \
    Eigen/QR \
    Eigen/QtAlignedMalloc \
    Eigen/Sparse \
    Eigen/SparseCholesky \
    Eigen/SparseCore \
    Eigen/SparseLU \
    Eigen/SparseQR \
    Eigen/SPQRSupport \
    Eigen/StdDeque \
    Eigen/StdList \
    Eigen/StdVector \
    Eigen/SuperLUSupport \
    Eigen/SVD \
    Eigen/UmfPackSupport \
    music2ducadoa.h

FORMS += \
        mainwindow.ui

unix:LIBS += -lqwtplot3d -L../../lib
linux-g++:QMAKE_CXXFLAGS += -fno-exceptions

win32{
  LIBS += ./lib/libqwtplot3d.a
  #TEMPLATE  = vcapp
  DEFINES  += QT_DLL QWT3D_DLL
  contains (CONFIG, debug)  {
    #QMAKE_LFLAGS += /NODEFAULTLIB:msvcrt
  }
}

QT += opengl
LIBS+= -lopengl32 -lglu32 -lglut

INCLUDEPATH += ./qwtplot3d
