#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#include <omp.h>

double **M1, **M2, **M3;

int main(int argc, char** argv){ 
	int i, j, f, c, inner;
	double t1, t2, total;
	srand(time(NULL)); 

	//Leer argumento de entrada (no de componentes del vector) 
	if (argc<2){ 
		printf("Falta tamaño de matrices\n"); 
		exit(-1); 
	} 

	unsigned int N = atoi(argv[1]); // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B) 
	
	M1 = (double**) malloc(N*sizeof(double *));// malloc necesita el tamaño en bytes 
	M2 = (double**) malloc(N*sizeof(double *)); //si no hay espacio suficiente malloc devuelve NULL 
	M3 = (double**) malloc(N*sizeof(double *)); 
	if ( (M1==NULL) || (M2==NULL) || (M3==NULL) ){ 
		printf("Error en la reserva de espacio para los vectores\n"); 
		exit(-2); 
	}

 	for (i=0; i<N; i++){
		M1[i] = (double*) malloc(N*sizeof(double));
		M2[i] = (double*) malloc(N*sizeof(double));
		M3[i] = (double*) malloc(N*sizeof(double));

		if ( M1[i]==NULL || M2[i]==NULL || M3[i]==NULL ){
			printf("Error en la reserva de espacio para los vectores\n");
			exit(-2);
		}
	}
	//Inicializar matrices

	for (f=0; f<N; f++)
	{
		for (c=0; c<N; c++)
		{
			M1[f][c] = rand()%(1-10 + 1) + 1;
			M2[f][c] = rand()%(1-10 + 1) + 1;
		}
	}

	printf("Matriz 1: \n");
	for (f=0; f<N; f++)
	{
		printf("\n");
		for (c=0; c<N; c++)
			printf("%.0lf ", M1[f][c]);
		
	}
	
	printf("\n\nMatriz 2: \n");
	for (f=0; f<N; f++)
	{
		printf("\n");
		for (c=0; c<N; c++)
			printf("%.0lf ", M2[f][c]);
		
	}	

	//Medida de tiempo
	t1 = omp_get_wtime();

	//Calcular producto de matriz por matriz M1 · M2 = M3
	for (f = 0; f < N; f++) 
        	for (c = 0; c < N; c++)
			for (inner = 0; inner < N; inner++) 
		        	M3[f][c] += M1[f][inner] * M2[inner][c];
		 
	//Medida de tiempo
	t2 = omp_get_wtime();
	total = t2 - t1;
   
        //Imprimir el resultado y el tiempo de ejecución
	printf("Tiempo(seg.):%11.9f\t / Tamaño:%u\t", total,N);

	printf("\n\nMatriz 3: \n");
	for (f=0; f<N; f++)
	{
		printf("\n");
		for (c=0; c<N; c++)
			printf("%.0lf ", M3[f][c]);
		
	}	
	printf("\n");
	for (i=0; i<N; i++)
	{
		free(M1[i]);
		free(M2[i]);
		free(M3[i]);  
	}

	free(M1);
	free(M2);
	free(M3);

	return 0; 
}
