#include "fft.h"
#include "calc_param.h"
#include "put_memo.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//       usage 
//       wave:array of wave source input
//       Nsample:length of data of wave
//       file_name:file name to create  
//       fft(wave,16384,"gaussian.csv")

void swap(double *a,double *b){

	double temp;

/*
	temp a b
	 a   a b
	 a   b b
	 a   b a
*/
	temp=*a;

	*a=*b;

	*b=temp;
}

void fft(double *wave,int Nsample,char *file_name){

	FILE *fp;

   int k1,num,nhalf,phi,phi0;
	int *rot;

   double s,sc,c,a0,b0;
	double *y;
	double *power;

	int check;

	check=Nsample;

	while(check>1){
		if(check%2==1){
			printf("fft data size error(not power of 2).\n");
			exit(1);
		}

		check>>=1;

	}

	fp=fopen(file_name,"w");

	if(fp==NULL){
		printf("file open error(fft).\n");
		exit(1);
	}
	
   put_memo(fp,file_name);

	power=calloc(Nsample,sizeof(double));

	rot=calloc(sizeof(int),Nsample);
	y=calloc(sizeof(double),Nsample);

   nhalf=Nsample/2; 
	num=Nsample/2; 

	sc=2.0*pi/Nsample;

   printf("  fft caluculation start.\n");

   while(num>=1){

      for(int j=0;j<Nsample;j+=2*num){

         phi=rot[j]/2;    
			phi0=phi+nhalf;  
         
			c=cos(sc*phi);   
			s=-sin(sc*phi);

         for(int k=j;k<j+num;k++){

            k1=k+num;

            a0=wave[k1]*c-y[k1]*s; 
				b0=wave[k1]*s+y[k1]*c;

            wave[k1]=wave[k]-a0;      
				y[k1]=y[k]-b0;

            wave[k]=wave[k]+a0;       
				y[k]=y[k]+b0;

            rot[k]=phi;           
				rot[k1]=phi0;

        }
      }

      num=num/2;
   }

   for(int i=0;i<Nsample-1;i++){
		int j;
      if((j=rot[i])>i){
			
			swap(&wave[i],&wave[j]);
			swap(&y[i],&y[j]);

      }
	
		wave[i]=sqrt(pow(wave[i],2.0)+pow(y[i],2.0))/Nsample;

   }

	for(int i=0;i<(Nsample/2);i++){
		fprintf(fp,"%d,%.5e\n",i,wave[i]);
	}

	fclose(fp);

   printf("  fft caluculation finished.\n");

	free(power);
	free(rot);
	free(y);

}

