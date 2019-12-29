#include "setsinwave.h"
#include "calc_param.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setsinwave(double *Iz){

	char *file_name="sinwave.csv";
	FILE *fp;

	for(int i=0;i<timestep;i++){
		Iz[i]=I0*sin(2.0*pi*i*26/timestep);
	}

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("cannot open file(sin wave).\n");
		exit(1);
	}

	for(int i=0;i<timestep;i++){
		fprintf(fp,"%d,%.30f\n",i,Iz[i]);
	}

	fclose(fp);

}
