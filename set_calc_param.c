#include "calc_param.h"
#include <stdio.h>

void set_calc_param(void){

	x_cellsize=55;
	y_cellsize=55;
	z_cellsize=55;

	dx=20.0e-9;
	timestep=1000;

	dt_margin=0.95;
	t0=10.0;

	I0=10e-4;
	alpha=0.05; // gaussian parameter
	

	ref_index0=1.0;
	ref_index1=2.9;

	pml_layer=20;
	sigma_max=3.18744e10;

	excite_point_x=(int)(x_cellsize-1)/2;
	excite_point_y=(int)(y_cellsize-1)/2;
	excite_point_z=(int)(z_cellsize-1)/2;

	Ex_length=x_cellsize;
	Ey_length=y_cellsize;
	Ez_length=z_cellsize;

	Hx_length=x_cellsize-1;
	Hy_length=y_cellsize-1;
	Hz_length=z_cellsize-1;

	dy=dx;
	dz=dx;

// in case of 1D 
	dt=dt_margin*dx/c;
// in case of 2D

	dw=2.0*pi/(timestep*dt);
	w=8*dw;

	printf("timestep=%d\n",timestep);
	printf("eps0=%.15le\n",eps0);
	printf("u0=%.15le\n",u0);
	printf("c=%.15le\n",c);

	printf("I0=%e\n",I0);
	printf("alpha=%e\n",alpha);
	printf("t0=%f\n",t0);

	printf("dx=%e\n",dx);
	printf("dt margin=%e\n",dt_margin);
	printf("dt=%e\n",dt);
	printf("dw=%e\n",dw);

	printf("x cellsize=%d\n",x_cellsize);
	printf("y cellsize=%d\n",y_cellsize);
	printf("z cellsize=%d\n",z_cellsize);

	printf("excite point x=%d\n",excite_point_x);
	printf("excite point y=%d\n",excite_point_y);
	printf("excite point z=%d\n",excite_point_z);

	printf("Ex length=%d\n",Ex_length);
	printf("Ey length=%d\n",Ey_length);
	printf("Ez length=%d\n",Ez_length);

	printf("Hx length=%d\n",Hx_length);
	printf("Hy length=%d\n",Hy_length);
	printf("Hz length=%d\n",Hz_length);

}

