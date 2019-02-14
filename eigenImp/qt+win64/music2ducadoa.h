#ifndef MUSIC2DUCADOA_H
#define MUSIC2DUCADOA_H

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace Eigen;

class Music2dUCADoa
{
public:
    Music2dUCADoa();
    void music_argo(MatrixXcf &ant);
    void argo_test(float shift);

    float Azimuth,Elevation;
    float Pmusic[361][91];

private:
    void a_theta(MatrixXcf &a, float azimuth, float elevation);

};

#endif // MUSIC2DUCADOA_H
