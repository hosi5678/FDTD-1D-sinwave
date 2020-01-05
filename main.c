#include "calc_param.h"
#include "set_calc_param.h"
#include "vec2D_Alloc.h"
#include "setgaussian.h"
#include "setsinwave.h"
#include "get1DEHVec.h"
#include "put_memo.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

	double *Ey;
	double *Hz;

	double *J; 

	clock_t start,end;

	start=clock();

	// set calculation point
	set_calc_param();

	// 1D_Alloc();
	Ey=calloc((unsigned int)Ey_length,sizeof(double));
	Hz=calloc((unsigned int)Hz_length,sizeof(double));

	J=calloc((unsigned int)timestep,sizeof(double));

	if(NULL==Ey){
		printf("Ey memory allocation error.\n");
		exit(1);
	}

	if(NULL==Hz){
		printf("Hz memory allocation error.\n");
		exit(1);
	}

	if(NULL==J){
		printf("J memory allocation error.\n");
		exit(1);
	}

	if(wave_selection==0){
		setgaussian(J);
	}else if(wave_selection==1){
		setsinwave(J);
	}else{
		printf("select wave value error.(0 or 1).\n");
		exit(1);
	}

   get1DEHVec(Ey,Hz,J);

	FILE *fp;

	fp=fopen("memo.csv","w");

	if(fp==NULL){
		printf("file open error.\n");
		exit(1);
	}

	fp=put_memo(fp,"memo.csv");

	fclose(fp);

	free(Ey);
	free(Hz);

	free(J);

	end=clock();

	printf("required time:%.2f(sec)\n",(double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}
