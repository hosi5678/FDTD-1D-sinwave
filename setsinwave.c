#include "setsinwave.h"
#include "calc_param.h"
#include "put_memo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setsinwave(double *J){

	char *file_name="sinwave.csv";
	FILE *fp;

	for(int i=0;i<timestep;i++){
		J[i]=I0*sin(2.0*pi*i*angular_frequency_num/fft_data_length);
	}

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("cannot open file(sin wave).\n");
		exit(1);
	}

	fp=put_memo(fp,file_name);

	for(int i=0;i<timestep;i++){
		fprintf(fp,"%d,%.5e\n",i,J[i]);
	}

	fclose(fp);

}
