#include "get_peak.h"
#include "put_memo.h"

#include <stdio.h>
#include <stdlib.h>

void get_peak(double *wave,int data_length,char *file_name){

	FILE *fp;

	fp=fopen(file_name,"w");

	if(NULL==fp){
		printf("file open error(%s)\n",file_name);
		exit(1);
	}

	put_memo(fp,file_name);

	int count=0;

	for(int i=0;i<data_length/2-2;i++){
		if(wave[i+1]>wave[i] && wave[i+2]<wave[i+1]){
			fprintf(fp,"  peak position:%d,fft power:%.5e\n",i+1,wave[i+1]);

			if(count<10){
				printf("  peak position:%d,fft power:%.5e\n",i+1,wave[i+1]);
				count++;
			}
		}
	}

	fclose(fp);

}
