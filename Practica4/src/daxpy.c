#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(int argc, char **argv)
{
    // 1. Lectura valores de entrada
    if(argc < 2) {
        fprintf(stderr,"Falta num\n");
        exit(-1);
    }
    int N = atoi(argv[1]);

    struct timespec ini,fin;
    double transcurrido;

    // 2. Creación e inicialización de vector y matriz
    // 2.1. Creación
    int i,a=47;
    int x[N], y[N];

    // 2.2. Inicialización
    for (i=1; i<=N;i++) {
        x[i]=i;
        y[i]=i;
    }
	
    // 3. Cálculo resultado
    clock_gettime(CLOCK_REALTIME,&ini);

    for (i=1; i<=N;i++) {
        y[i]=a*x[i]+y[i];
    }

    clock_gettime(CLOCK_REALTIME,&fin);
    transcurrido=(double) (fin.tv_sec-ini.tv_sec)+(double) ((fin.tv_nsec-ini.tv_nsec)/(1.e+9));

    // 4. Impresión de vector resultado
    printf("Tiempo(seg): %f\ny[0]=%d, y[N-1]=%d \n",transcurrido,y[0],y[N-1]);
}
