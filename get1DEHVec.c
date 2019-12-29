#include "get1DEHVec.h"
#include "vec2D_Alloc.h"
#include "calc_param.h"
#include "set_calc_param.h"
#include "setConst.h"
#include "dft.h"
#include "fft.h"
#include "createPPMs1D.h"

#include <stdio.h>
#include <stdlib.h>

double *get1DEHVec(double *Ey,double *Hz,double *J){

	// algorighm

	// Ey[i]=((2*eps[i]-sigma[i]*dt)/(2*eps[i]+sigma[i]*dt))*Ey[i]
   //      -((2*dt)/(2*eps[i]+sigma[i]*dt))*(Hz[i]-Hz[i-1])
	//      -((2*dt)/(2*eps[i]+sigma[i]*dt))*J[t][i]

   // i=1,2,.....,x_cellsize-1
	// Ey[0]=0,Ey[x_cellsize]=0

	// Hz[i]=Hz[i]-(dt/(u0*dx))*(Ey[i+1]-Ey[i]);

	// i=0,1,2,,,,,,x_cellsize-1

	static double *sigma;
	static double *eps;

	// double ppm_gain;
   //	ppm_gain=3.0e10;

	double **Eyt;
	double *Et;

	sigma=calloc(Ey_length,sizeof(double));
	setConst(sigma,Ey_length,0.0);

	eps=calloc(Ey_length,sizeof(double));
	setConst(eps,Ey_length,eps0);
	
	double J_excite=0.0;

	Eyt=vec2D_Alloc(timestep,Ey_length);

	Et=calloc(timestep,sizeof(double));

	for(int t=0;t<timestep;t++){

		for(int x=1;x<Ey_length-1;x++){
		
			if(x==excite_point_x){
				J_excite=J[t];
			}else{
				J_excite=0.0;
			}

		 Ey[x]=((2*eps[x]-sigma[x]*dt)/(2*eps[x]+sigma[x]*dt))*Ey[x] \
            -((2*dt)/((2*eps[x]+sigma[x]*dt)*dx))*(Hz[x]-Hz[x-1]) \
		      -((2*dt)/(2*eps[x]+sigma[x]*dt))*J_excite;

				Eyt[t][x]=Ey[x];
				Et[t]=Eyt[t][excite_point_x];

		}

		for(int x=0;x<Hy_length;x++){
			Hz[x]=Hz[x]-(dt/(u0*dx))*(Ey[x+1]-Ey[x]);
		}
		
	}

	FILE *fp;

	fp=fopen("Eyt_plane.csv","w");

	if(fp==NULL){
		printf("file open error(Ey(t)(plane).csv).\n");
		exit(1);
	}

	for(int t=0;t<timestep;t++){
		for(int x=0;x<Ey_length;x++){
			fprintf(fp,"%.50f,",Eyt[t][x]);
		}
			fprintf(fp,"\n");
	}

	fclose(fp);

	fp=fopen("Eyt_x.csv","w");

	if(fp==NULL){
		printf("file open error(Ey(t)(excitation point).csv).\n");
		exit(1);
	}

	for(int t=0;t<timestep;t++){
		fprintf(fp,"%.50f\n",Eyt[t][excite_point_x]);
	}

/*	createPPMs1D(Eyt,timestep,ppm_gain); */

	dft(Et,timestep);

	fclose(fp);

	free(Eyt);
	free(Et);

	return Ey;

}
