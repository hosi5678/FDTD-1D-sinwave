#include "get1DEHVec.h"
#include "vec2d_Alloc.h"
#include "calc_param.h"
#include "set_calc_param.h"
#include "setConst.h"
#include "dft.h"
#include "fft.h"
#include "put_memo.h"
#include "get_peak.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get1DEHVec(double *Ey,double *Hz,double *J){

	// algorighm

	// Ey[i]=((2*eps[i]-sigma[i]*dt)/(2*eps[i]+sigma[i]*dt))*Ey[i]
   //      -((2*dt)/(2*eps[i]+sigma[i]*dt))*(Hz[i]-Hz[i-1])
	//      -((2*dt)/(2*eps[i]+sigma[i]*dt))*J[t][i]

   // i=1,2,.....,x_cellsize-1
	// termination condition Ey[0]=0.0, Ey[x_cellsize]=0.0

	// Hz[i]=Hz[i]-(dt/(u0*dx))*(Ey[i+1]-Ey[i]);

	// i=0,1,2,,,,,,x_cellsize-1

	double *sigma;
	double *eps;

	double **eyt_plane;
	double *eyt_x;

	FILE *fp;

	char *eyt_plane_file_name="eyt_plane.csv";
	char *eyt_x_wave_file_name="eyt_x.csv";

	sigma=calloc((unsigned int)Ey_length,sizeof(double));
	setConst(sigma,Ey_length,0.0);

	eps=calloc((unsigned int)Ey_length,sizeof(double));
	setConst(eps,Ey_length,eps0);
	
	double J_excite=0.0;

	eyt_plane=vec2d_alloc(timestep,Ey_length);

	if(NULL==eyt_plane){
		printf("eyt plane memory allocation failed.\n");
		exit(1);
	}

	eyt_x=calloc((unsigned int)timestep,sizeof(double));

	if(NULL==eyt_x){
		printf("eyt(x) memory allocation failed.\n");
		exit(1);
	}

 	 printf("fdtd caluculation start.\n");

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

				eyt_plane[t][x]=Ey[x];
				eyt_x[t]=Ey[excite_point_x];

		}

		for(int x=0;x<Hy_length;x++){
			Hz[x]=Hz[x]-(dt/(u0*dx))*(Ey[x+1]-Ey[x]);
		}
		
	}

   printf("all fdtd caluculations were finished.\n");

	free(eps);
	free(sigma);

	fp=fopen(eyt_plane_file_name,"w");

	if(NULL==fp){
		printf("file open error (%s).\n",eyt_plane_file_name);
		exit(1);
	}

	put_memo(fp,eyt_plane_file_name);

	for(int t=0;t<timestep;t++){
		for(int x=0;x<Ey_length;x++){

			if(x==Ey_length-1){
				fprintf(fp,"%.5e",eyt_plane[t][x]);	
			}else{
				fprintf(fp,"%.5e,",eyt_plane[t][x]);
			}

		}
			fprintf(fp,"\n");
	}

	fclose(fp);

	printf("%s was created.\n",eyt_plane_file_name);

	free(eyt_plane);

	fp=fopen(eyt_x_wave_file_name,"w");

	put_memo(fp,eyt_x_wave_file_name);

	if(NULL==fp){
		printf("file open error(%s).\n",eyt_x_wave_file_name);
		exit(1);
	}

	for(int t=0;t<timestep;t++){
		fprintf(fp,"%d,%.5e\n",t,eyt_x[t]);
	}

	fclose(fp);

	printf("%s was created.\n",eyt_x_wave_file_name);

	if(wave_selection==0){

		char fft_file_name[50];
		char diff_fft_file_name[50];

		double *fft_wave;

		sprintf(fft_file_name,"fft_%s",eyt_x_wave_file_name);
	
		fft_wave=calloc((unsigned int)fft_data_length,sizeof(double));

		if(NULL==fft_wave){
			printf("fft wave memory error.\n");
			exit(1);
		}

		for(int i=0;i<fft_data_length;i++){
			fft_wave[i]=eyt_x[i+fft_t_start];
		}
	
		fft(fft_wave,fft_data_length,fft_file_name);

		printf("fft_file_name(%s) was created.\n",fft_file_name);

		sprintf(diff_fft_file_name,"diff_fft_%s",eyt_x_wave_file_name);

		get_peak(fft_wave,fft_data_length,diff_fft_file_name);

		printf("peak file(%s)was created.\n",diff_fft_file_name);

		free(fft_wave);

	}

	free(eyt_x);
   fclose(fp);

}
