#include "calc_param.h"
#include "set_calc_param.h"
#include "vec2D_Alloc.h"
#include "setGaussian.h"
#include "setsinwave.h"
#include "get1DEHVec.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

	double *Ex,*Ey,*Ez;
	double *Hx,*Hy,*Hz;

	double *J; // J=I0*exp(-alpha(t-t0)^2);

	// set calculation point
	set_calc_param();

	// 1D_Alloc();
	Ex=calloc(Ex_length,sizeof(double));
	Ey=calloc(Ey_length,sizeof(double));
	Ez=calloc(Ez_length,sizeof(double));

	Hx=calloc(Hx_length,sizeof(double));
	Hy=calloc(Hy_length,sizeof(double));
	Hz=calloc(Hz_length,sizeof(double));

	J=calloc(timestep,sizeof(double));

//	setGaussian(J);
	setsinwave(J);

	Ey=get1DEHVec(Ey,Hz,J);

	free(Ex);
	free(Ey);
	free(Ez);

	free(Hx);
	free(Hy);
	free(Hz);

	free(J);

	return 0;
}
