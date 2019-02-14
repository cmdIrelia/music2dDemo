#include "music2ducadoa.h"

#include <math.h>
#include <cfloat>

#include <qDebug>

#define D_LAMBDA 0.4

#define Fc 18000000000

#define ARR_ELEMENTS (8)

Music2dUCADoa::Music2dUCADoa()
{
    qsrand(20);
    //TODO init a_theta, make the calc only once.
}

void Music2dUCADoa::argo_test(float shift)
{
    //float shift=0.5;
    MatrixXcf ant(ARR_ELEMENTS,1000);
    for(float i=0;i<1000;i++){
        for(int j=0;j<ARR_ELEMENTS;j++){
            shift = qrand()/100;
            ant(j,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i+shift)+qrand()/100,
                                              cos(1.f*M_PI/2.f*i+shift)+qrand()/100);
        }
        //ant(1,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i),cos(1.f*M_PI/2.f*i));
        //ant(2,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i+shift)+qrand()/100,cos(1.f*M_PI/2.f*i+shift)+qrand()/100);
        //ant(3,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i+shift),cos(1.f*M_PI/2.f*i+shift));
    }
    music_argo(ant);
}

void Music2dUCADoa::music_argo(MatrixXcf& ant)
{
    MatrixXcf R(ant*ant.adjoint());
    ComplexEigenSolver<MatrixXcf> es(R);
    //cout<<"D="<<endl<<es.eigenvalues()<<endl;
    //cout<<"V="<<endl<<es.eigenvectors()<<endl;

    MatrixXcf
        R_swap(MatrixXcf(es.eigenvectors()).rowwise().reverse().block(0,1,R.rows(),R.cols()-1));
    //cout<<"R_swap="<<endl<<R_swap<<endl;
    MatrixXcf R_R_H(R_swap*R_swap.adjoint());

    MatrixXcf a(ARR_ELEMENTS,1);

    //cout<<"\033[1;33m========GO P=========\033[0m"<<endl;
    float doa_azimuth,doa_elevation,p_min=FLT_MAX;
    //float Pmusic[361][91];
    int PmusicIndex[2]={0,0};
    for(float azimuth = 0;azimuth<=2.f*M_PI;azimuth += 2.f*M_PI/360.f){
        for(float elevation = 0;elevation<=M_PI/2.f;elevation += M_PI/2.f/90.f){
            a_theta(a,azimuth,elevation);
            //float p = (a.adjoint()*R_swap*R_swap.adjoint()*a)(0,0).real();
            //cout<<theta/M_PI*180<<"\t"<<(a_H*R_swap*R_swap.adjoint()*a).real()<<endl;
            float p = abs((a.adjoint()*R_R_H*a)(0,0).real());
            if (p<p_min){
                doa_azimuth=azimuth/M_PI*180;
                doa_elevation=elevation/M_PI*180;
                p_min = p;
            }
            //cout<<PmusicIndex[0],PmusicIndex[1]++;
            if(p>0.000000001){
                Pmusic[PmusicIndex[0]][PmusicIndex[1]]=1/p;
            }
            else{
                qDebug()<<"small p at "<<PmusicIndex[0]<<" "<<PmusicIndex[1]<<"= "<<p;
                Pmusic[PmusicIndex[0]][PmusicIndex[1]]=1000;
            }
            PmusicIndex[1]++;
        }
        PmusicIndex[1]=0;
        PmusicIndex[0]++;
    }
    //cout<<"\033[1;33m========DOA=========\033[0m"<<endl;
    //cout<<"DOA azi/ele= "<<doa_azimuth<<"  "<<doa_elevation<<"\tp_min="<<p_min<<endl;
    this->Azimuth = doa_azimuth;
    this->Elevation = doa_elevation;
}

void Music2dUCADoa::a_theta(MatrixXcf& a, float azimuth, float elevation)
{
    const int sensor_num = ARR_ELEMENTS;

    MatrixXf d_angle(ARR_ELEMENTS,1);
    for(int i=0;i<ARR_ELEMENTS;i++){
        d_angle(i,0)=i*2*M_PI/ARR_ELEMENTS;
    }

    const float c = 3e8;
    const float namda = c/Fc;
    const float R = namda/(2*sin(d_angle(1,0))*sin(0.5*d_angle(1,0)));  //偶数
    //cout<<"阵元工作半径 R="<<endl;
    //cout<<R<<endl;

    MatrixXf x(sensor_num,1);
    MatrixXf y(sensor_num,1);
    for(int i=0;i<sensor_num;i++){
        x(i,0)=R*cos(d_angle(i,0));
        y(i,0)=R*sin(d_angle(i,0));
    }

    MatrixXf a_tao(ARR_ELEMENTS,1);
    a_tao = sin(elevation)*(x*cos(azimuth)+y*sin(azimuth));
    for(int i=0;i<sensor_num;i++){
        a(i,0)=exp(std::complex<float>(0,-1.f*2*M_PI*a_tao(i,0)/namda));
    }
    //cout<<"a_theta at zimu = "<<azimuth<<"  elev="<<elevation<<endl;
    //cout<<a<<endl;
}
