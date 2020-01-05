#include "put_memo.h"
#include "calc_param.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

FILE *put_memo(FILE *fp,char *file_name){

	time_t timer=time(NULL);
	struct tm *timeptr;

	char *str_time;

	str_time=calloc(256,sizeof(char));

	if(NULL==str_time){
		printf("allocation error.(srt_time)\n");
		exit(1);
	}
	
	str_time[255]='\0';

	timeptr=localtime(&timer);

	strftime(str_time,256,"%Y/%m/%d(%a) %H:%M:%S\n",timeptr);	

	fprintf(fp,"memo,datetime:%s",str_time);

	if(wave_selection==0){
		fprintf(fp,"memo,wave type=Gaussian\n");
	}else if(wave_selection==1){
		fprintf(fp,"memo,wave type=sin wave\n");
	}

	fprintf(fp,"memo,I0:%.5e\n",I0);
	fprintf(fp,"memo,alpha:%.5e\n",alpha);
	fprintf(fp,"memo,cellsize:%d\n",x_cellsize);
	fprintf(fp,"memo,timestep:%d\n",timestep);
	fprintf(fp,"memo,fft_index:%d\n",fft_index);
	fprintf(fp,"memo,data_length:%d\n",fft_data_length);
   fprintf(fp,"memo,dt_margin:%.5e\n",dt_margin);
	fprintf(fp,"memo,t0:%d\n",t0);
   fprintf(fp,"memo,dx:%.5e\n",dx);
	fprintf(fp,"memo,dt:%.5e\n",dt);
	fprintf(fp,"memo,dw:%.5e\n",dw);
	fprintf(fp,"memo,angular frequency num:%d\n",angular_frequency_num);

	return fp;

}
