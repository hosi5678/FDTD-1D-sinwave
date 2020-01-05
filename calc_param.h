#pragma once

// declaration of calculation parameters

// these common parameters will be used within many files,so add extern.

// const parameter is read only(not writable)
extern const double pi;

extern const double eps0;
extern const double u0;
extern const double c;

extern const double ref_index0;
extern double ref_index1;

extern int timestep;
extern double dt;
extern double dw;
extern double w;
extern int angular_frequency_num;
extern int wave_selection;

extern int fft_t_start;
extern int fft_data_length; 

extern int fft_index;

extern double I0;
extern double alpha;
extern int t0;

extern int x_cellsize;
extern int y_cellsize;
extern int z_cellsize;

extern int Ex_length;
extern int Ey_length;
extern int Ez_length;

extern int Hx_length;
extern int Hy_length;
extern int Hz_length;

extern int excite_point_x;
extern int excite_point_y;
extern int excite_point_z;

extern double dx;
extern double dy;
extern double dz;

extern double dt;

extern double dt_margin;

extern int pml_layer;
extern double sigma_max;
