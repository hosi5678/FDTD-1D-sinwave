#include "setgaussian.h"
#include "calc_param.h"
#include "fft.h"
#include "put_memo.h"
#include "get_peak.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setgaussian(double *J){

	char *file_name="gaussian.csv";
	FILE *fp;

	for(int i=0;i<timestep;i++){
		J[i]=I0*exp(-alpha*pow((i-t0),2.0));
	}

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("cannot open file(Gaussian).\n");
		exit(1);
	}

	put_memo(fp,file_name);

	for(int i=0;i<timestep;i++){
		fprintf(fp,"%d,%.5e\n",i,J[i]);
	}

	printf("gaussian wave setting finished.\n");

	double *J_fft;

	J_fft=calloc(fft_data_length,sizeof(double));

	for(int i=0;i<fft_data_length;i++){
		J_fft[i]=J[i];
	}
	
	fft(J_fft,fft_data_length,"fft_gaussian.csv");

	fclose(fp);

}
