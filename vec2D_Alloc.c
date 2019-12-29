#include "vec2D_Alloc.h"

#include <stdlib.h>
#include <stdio.h>

double **vec2D_Alloc(int y_size,int x_size){

	static double **vec;

	vec=calloc(y_size,sizeof(double *));

	for(int j=0;j<y_size;j++){

		*(vec+j)=calloc(x_size,sizeof(double));

	}

	return vec;

}
