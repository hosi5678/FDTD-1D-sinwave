/********* FFTを行う関数  ************************************/
/* 入力:x[Nsample]:実数入力波形（振幅）,Nsample:データの数 ***/
/*************************************************************/

#include "fft.h"
#include "calc_param.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void fft(double *x,int Nsample){

   int i,j,k,k1,num,nhalf,phi,phi0;
	int *rot;

   double s,sc,c,a0,b0,tmp;
	double *y;

	rot=calloc(sizeof(int),Nsample);
	y=calloc(sizeof(double),Nsample);

   nhalf=Nsample/2; 
	num=Nsample/2; 

	sc=2.0*pi/Nsample;

   while(num>=1){

      for(j=0;j<Nsample;j+=2*num){

         phi=rot[j]/2;    
			phi0=phi+nhalf;  
         
			c=cos(sc*phi);   
			s=-sin(sc*phi);

         for(k=j; k<j+num; k++){

            k1=k+num;

            a0=x[k1]*c-y[k1]*s; 
				b0=x[k1]*s+y[k1]*c;

            x[k1]=x[k]-a0;      
				y[k1]=y[k]-b0;

            x[k]=x[k]+a0;       
				y[k]=y[k]+b0;

            rot[k]=phi;           
				rot[k1]=phi0;

        }
      }

      num=num/2;
   }

   for(i=0;i<Nsample-1;i++){
      if((j=rot[i])>i){
        tmp=x[i]; 
		  x[i]=x[j]; 
		  x[j]=tmp;
        tmp=y[i];
		  y[i]=y[j];
		  y[j]=tmp;
      }
   }

	FILE *fp;

	char *file_name="fft_w.csv";

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("file open error.\n");
		exit(1);
	}

	for(int i=0;i<(Nsample/2);i++){
		fprintf(fp,"%.20f\n",sqrt(pow(x[i],2.0)+pow(y[i],2.0)));
	}

	fclose(fp);

}

