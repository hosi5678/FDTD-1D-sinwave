#include "calc_param.h"

#include <stdio.h>
#include <stdlib.h>

void set_calc_param(void){

	printf("input timestep(integer)=\n");
	
   if(scanf("%d",&timestep)==EOF){
		printf("input timestep error.\n");
		exit(1);
	}

	printf("input cellsize(interger)=\n");

	if(scanf("%d",&x_cellsize)==EOF){
		printf("input x_cellsize error.\n");
		exit(1);
	}

	y_cellsize=x_cellsize;
	z_cellsize=x_cellsize;

	printf("select wave(0:gaussian pulse / 1:sin wave)");

	if(EOF==scanf("%d",&wave_selection)){
		printf("input select_wave error.\n");
	   exit(1);
	}

	if(wave_selection==0){
		printf("input gaussian alpha parameter(around 0.01).\n");
		
		if(scanf("%lf",&alpha)==EOF){
			printf("input gaussian alpha error.\n");
			exit(1);
		}

		printf("input fft_index(integer)=\n");
		printf("ex. index=10:data_length=1024\n");
		printf("ex. index=11:data_length=2048\n");
		printf("ex. index=12:data_length=4096\n");
		printf("ex. index=13:data_length=8192\n");
		printf("ex. index=14:data_length=16384\n");
		printf("ex. index=15:data_length=32768\n");
		printf("ex. index=16:data_length=65536\n");
		printf("ex. index=17:data_length=131072\n");
		printf("ex. index=18:data_length=262144\n");
		printf("ex. index=19:data_length=524288\n");

		if(scanf("%d",&fft_index)==EOF){
			printf("input fft_index error.\n");
			exit(1);
		}

		fft_data_length=1;

		for(int i=0;i<fft_index;i++){
			fft_data_length<<=1; 
		}

		fft_t_start=timestep-fft_data_length+1;

		if(fft_t_start<0){
			printf("error.(fft_t_start<0)\n");
			exit(1);
		}

	}else if(wave_selection==1){

		printf("input index to be exponent of 2(used gaussian,integer)=\n");

		fft_data_length=1;

		if(scanf("%d",&fft_index)==EOF){
			printf("input fft_index error.\n");
			exit(1);
		}

		for(int i=0;i<fft_index;i++){
			fft_data_length<<=1; 
		}

		printf("input angular_frequency_num(integer)=\n");

			if(scanf("%d",&angular_frequency_num)==EOF){
				printf("input angular frequency num error.\n");
				exit(1);
			}

	}else{
		printf("wave_selection value error.\n");
		exit(1);
	}

	dx=25.0e-9;
	dt_margin=0.95;
	t0=200.0;
	I0=1.0e-3; 

	ref_index1=2.9;

	pml_layer=20;
	sigma_max=3.18744e6;

	excite_point_x=(int)(x_cellsize-1)/2;
	excite_point_y=(int)(y_cellsize-1)/2;
	excite_point_z=(int)(z_cellsize-1)/2;

	Ex_length=x_cellsize;
	Ey_length=y_cellsize;
	Ez_length=z_cellsize;

	Hx_length=x_cellsize-1;
	Hy_length=y_cellsize-1;
	Hz_length=z_cellsize-1;

	dy=dx;
	dz=dx;

// in case of 1D 
	dt=dt_margin*dx/c;
// in case of 2D

	dw=2.0*pi/(timestep*dt);

	printf("timestep=%d\n",timestep);

	printf("I0=%e\n",I0);
	printf("alpha=%e\n",alpha);
	printf("t0=%d\n",t0);

	printf("dx=%e\n",dx);
	printf("dt margin=%e\n",dt_margin);
	printf("dt=%e\n",dt);
	printf("dw=%e\n",dw);

	printf("\x1b[36m"); // cyan
	printf("\x1b[1m");  // highlight
	printf("  fft_index=%d\n",fft_index);
   printf("\x1b[39m"); // back to default(cyan->white)
   printf("\x1b[0m"); //  back to default(highlihgt->normal)

	printf("fft_data_length=%d\n",fft_data_length);
	printf("fft_time_start=%d\n",timestep-fft_data_length+1);

	printf("angular frequency num=%d\n",angular_frequency_num);

	printf("x cellsize=%d\n",x_cellsize);
	printf("y cellsize=%d\n",y_cellsize);
	printf("z cellsize=%d\n",z_cellsize);

	printf("excite point x=%d\n",excite_point_x);
	printf("excite point y=%d\n",excite_point_y);
	printf("excite point z=%d\n",excite_point_z);

	printf("Ex length=%d\n",Ex_length);
	printf("Ey length=%d\n",Ey_length);
	printf("Ez length=%d\n",Ez_length);

	printf("Hx length=%d\n",Hx_length);
	printf("Hy length=%d\n",Hy_length);
	printf("Hz length=%d\n",Hz_length);

}

