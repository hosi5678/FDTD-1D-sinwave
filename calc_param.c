#include "calc_param.h"

const double pi=3.14159265358979;;

const double c=2.99792458e8;
const double eps0=8.8541878128e-12;
const double u0=1.25663706212e-6;

double ref_index0;
double ref_index1;

double I0;
double alpha;

int timestep;
double t0;

int x_cellsize;
int y_cellsize;
int z_cellsize;

int Ex_length;
int Ey_length;
int Ez_length;

int Hx_length;
int Hy_length;
int Hz_length;

double dx;
double dt_margin;

double dt;
double dw;
double w;

double dy;
double dz;

int excite_point_x;
int excite_point_y;
int excite_point_z;

int pml_layer;
double sigma_max;

