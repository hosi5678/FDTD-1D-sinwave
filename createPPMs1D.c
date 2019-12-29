#include "createPPMs1D.h"
#include "calc_param.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createPPMs1D(double **Eyt,int timestep,double ppm_gain){

	int r,g,b;
	int height;

	height=100;

	char str[100];
	FILE *fp;

	for(int t=0;t<timestep;t++){
		for(int x=0;x<Ey_length;x++){
			Eyt[t][x]=Eyt[t][x]*ppm_gain;
		}
	}

	for(int t=0;t<timestep;t++){

		sprintf(str,"./ppm/timestep%06d.ppm",t);

		fp=fopen(str,"w");

		if(fp==NULL){
			printf("file open error.\n");
			exit(1);
		}

		fprintf(fp,"P3\n");
		fprintf(fp,"%d %d\n",x_cellsize,height);
		fprintf(fp,"255\n");

		for(int y=0;y<height;y++){

			for(int x=0;x<Ey_length;x++){

				if(y==height/2){

					if(Eyt[t][x]>255.0){
						r=0;
						g=255;
						b=0;
					}else if(Eyt[t][x]<-255.0){
						r=255;
						g=0;
						b=0;
					}else if(abs(Eyt[t][x])<20.0){
						r=128;
						g=128;
						b=128;
					}else if(Eyt[t][x]<0.0){
						r=(int)(abs(Eyt[t][x]));
						g=0;
						b=0;
					}else{
						r=0;
						g=(int)(Eyt[t][x]);
						b=0;
					}

					fprintf(fp,"%d %d %d \n",r,g,b);

				}else{
					r=255;
					g=255;
					b=255;

					fprintf(fp,"%d %d %d \n",r,g,b);

				} // if (y) statement

			} // x loop statement
		} // y loop statement

			fclose(fp);

	} // t loop statement
	
}
