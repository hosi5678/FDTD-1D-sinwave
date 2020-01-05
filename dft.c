#include "calc_param.h"
#include "set_calc_param.h"
#include "dft.h"
#include "put_memo.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//       usage 
//       wave:array of wave source input
//       Nsample:length of data wave
//       file_name:file name to create  
//       dft(wave,5000,"gaussian.csv")

void dft(double *wave,int Nsample,char *file_name){

	FILE *fp;

	double *power;

	fp=fopen(file_name,"w");

	power=calloc(Nsample,sizeof(double));

	if(NULL==fp){
		printf("file open error.\n");
		exit(1);
	}

	fp=put_memo(fp,file_name);

    for(int t=0; t<Nsample; t++) {

        double real = 0.0;
        double imaginary = 0.0;

        for(int k=0; k<Nsample; k++) {
            real += wave[k]*cos(2*pi*k*t/Nsample);
            imaginary += -wave[k]*sin(2*pi*k*t/Nsample);

        }
		
			power[t]=sqrt(pow(real,2.0)+pow(imaginary,2.0))/Nsample;

		if(t<Nsample/2){
			fprintf(fp,"%d,%.5e\n",t,power[t]);
		}

    }

	fclose(fp);

}
