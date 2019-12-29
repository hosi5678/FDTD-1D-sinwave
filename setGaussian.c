#include "setGaussian.h"
#include "calc_param.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setGaussian(double *Iz){

	char *file_name="gaussian.csv";
	FILE *fp;

	for(int i=0;i<timestep;i++){
		Iz[i]=I0*exp(-alpha*pow((i-t0),2.0));
	}

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("cannot open file(Gaussian).\n");
		exit(1);
	}

	for(int i=0;i<timestep;i++){
		fprintf(fp,"%d,%.20f\n",i,Iz[i]);
	}

	fclose(fp);

}
