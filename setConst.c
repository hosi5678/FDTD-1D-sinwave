#include "setConst.h"

double *setConst(double *vec,int length,double value){

	for(int i=0;i<length;i++){
		vec[i]=value;
	}

	return vec;

}