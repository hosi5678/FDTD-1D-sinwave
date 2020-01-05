#include "calc_param.h"

// definition of calculation parameter

// circular constant(円周率)
const double pi=3.1415926535897932384626433832795;

// light speed(光速)
const double c=2.99792458e8;

// dielectric constant under a vacuum(真空の誘電率)
const double eps0=8.8541878128e-12;

// magnetic permeability under a vacuum(真空の透磁率)
const double u0=1.25663706212e-6;

// index of refraction of vacuum(真空の屈折率)
const double ref_index0=1.0;

// index of refraction of material(マテリアルの屈折率)
double ref_index1;

// gaussian current[A](ガウシアンパルスのピーク電流)
double I0;

// gaussian pulse width parameter(ガウシアンパルスの半値幅)
double alpha;

// length of time t=timestep*dt
int timestep;

// peak position of gaussian pulse center(ガウシアンパルスのパルス中心のポジション)
int t0;

// length of space x=x_cellsize*dx
int x_cellsize;
int y_cellsize;
int z_cellsize;

int Ex_length;
int Ey_length;
int Ez_length;

int Hx_length;
int Hy_length;
int Hz_length;

// descrete fragments of space(x)
double dx;

double dy;
double dz;

// to suppress divergence
double dt_margin;

// descrete fragments of time(t)
double dt;

// descrete fragments of angular frequency(w)
double dw;

// angular frequency w=k*dw
double w;

// angular frequency peak numer
int angular_frequency_num;

// wave selection 0:gaussian pulse 1:sinwave
int wave_selection;

// fft data size 2^fft_index(fftのデータの長さ,2のべき乗で指定)
int fft_index;

// gaussian pulse excitation point(gaussian pulseの励起点)
int excite_point_x;
int excite_point_y;
int excite_point_z;

// thickness of pml absorption layer(pml吸収層の厚さ)
int pml_layer;

// max value of pml absorption layer of electrical conductivity(pml吸収層の電気伝導率の最大値)
double sigma_max;

// start time point of fft calculation
int fft_t_start;

// data length of fft
int fft_data_length;
