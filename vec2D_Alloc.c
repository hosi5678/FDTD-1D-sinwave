#include "vec2D_alloc.h"

#include <stdlib.h>
#include <stdio.h>

double **vec2d_alloc(int y_size,int x_size){

	static double **vec;

	vec=calloc((unsigned int)y_size,sizeof(double *));

	if(NULL==vec){
		printf("vec2d alloc memory error.\n");
		exit(1);
	}

	for(int j=0;j<y_size;j++){

		*(vec+j)=calloc((unsigned int)x_size,sizeof(double));

	}

	return vec;

}
