/********* DFTを行う関数 *************************************/
/* 入力:x[Nsample]:実数入力波形（振幅）,Nsample:データの数 ***/
/*************************************************************/

#include "calc_param.h"
#include "dft.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void dft(double *x,int Nsample){

	char *file_name="dft_w.csv";

	FILE *fp;

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("file open error.\n");
		exit(1);
	}

    for(int t=0; t<Nsample; t++) {

        double real = 0.0;
        double imaginary = 0.0;

        for(int k=0; k<Nsample; k++) {
            real += x[k]*cos(2*pi*k*t/Nsample);
            imaginary += -x[k]*sin(2*pi*k*t/Nsample);
        }

		if(t<Nsample/2){
        fprintf(fp,"%.50f\n",sqrt(pow(real,2.0)+pow(imaginary,2.0))/Nsample);
		}

    }

	fclose(fp);

}
