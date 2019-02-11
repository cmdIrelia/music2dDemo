//服务器上
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

#include <math.h>
#include <cfloat>

#define D_LAMBDA 0.4

#define Fc 18000000000

#define ARR_ELEMENTS (4)

//using Eigen::MatrixXcf;
using namespace Eigen;
using namespace std;

void a_theta(MatrixXcf& a, float azimuth, float elevation);

void music_argo(MatrixXcf& ant)
{
	MatrixXcf R(ant*ant.adjoint());
	ComplexEigenSolver<MatrixXcf> es(R);
	//cout<<"D="<<endl<<es.eigenvalues()<<endl;
	//cout<<"V="<<endl<<es.eigenvectors()<<endl;
	
	MatrixXcf 
		R_swap(MatrixXcf(es.eigenvectors()).rowwise().reverse().block(0,1,R.rows(),R.cols()-1));
	//cout<<"R_swap="<<endl<<R_swap<<endl;
	MatrixXcf R_R_H(R_swap*R_swap.adjoint());

	MatrixXcf a(4,1);

	//cout<<"\033[1;33m========GO P=========\033[0m"<<endl;
	float doa_azimuth,doa_elevation,p_min=FLT_MAX;
	MatrixXf Pmusic(361,91);int PmusicIndex[2]={0,0};
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
			Pmusic(PmusicIndex[0],PmusicIndex[1]++)=1/p;
		}
		PmusicIndex[1]=0;
		PmusicIndex[0]++;
	}
	cout<<"\033[1;33m========DOA=========\033[0m"<<endl;
	cout<<"DOA azi/ele= "<<doa_azimuth<<"  "<<doa_elevation<<"\tp_min="<<p_min<<endl;
	cout<<"Pmusic.block(0,0,10,10)="<<endl;
	cout<<Pmusic.block(0,0,10,10)<<endl;;
}

void a_theta(MatrixXcf& a, float azimuth, float elevation)
{
	const int sensor_num = 4;

	MatrixXf d_angle(4,1);
	d_angle<<0*2*M_PI/4,1*2*M_PI/4,2*2*M_PI/4,3*2*M_PI/4;


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

	MatrixXf a_tao(4,1);
	a_tao = sin(elevation)*(x*cos(azimuth)+y*sin(azimuth));
	for(int i=0;i<sensor_num;i++){
		a(i,0)=exp(std::complex<float>(0,-1.f*2*M_PI*a_tao(i,0)/namda));
	}
	//cout<<"a_theta at zimu = "<<azimuth<<"  elev="<<elevation<<endl;
	//cout<<a<<endl;
}

int main()
{
	float shift;// = 0.5;
	cout<<"input shift:"<<endl;
	cin>>shift;
	MatrixXcf ant(4,1000);
	for(float i=0;i<1000;i++){
		ant(0,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i),cos(1.f*M_PI/2.f*i));
		ant(1,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i),cos(1.f*M_PI/2.f*i));
		ant(2,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i+shift),cos(1.f*M_PI/2.f*i+shift));
		ant(3,int(i))=std::complex<float>(sin(1.f*M_PI/2.f*i+shift),cos(1.f*M_PI/2.f*i+shift));
	}

	// MatrixXi m(2,3);
	// m<<1,2,3,4,5,6;
	// cout<<"m="<<endl<<m<<endl;
	// cout<<"m wise reverse+block:"<<endl;
	// cout<<m.rowwise().reverse().block(0,1,m.rows(),m.cols()-1)<<endl;

	// MatrixXcf a(4,1);
	// a_theta(a,50,60);


	music_argo(ant);
	return 0;
}
