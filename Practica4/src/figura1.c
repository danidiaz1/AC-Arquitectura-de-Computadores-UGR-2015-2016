#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct {
    	int a;
     	int b;
} s[5000];

main()
{
    int ii,i,X1,X2;
    int R[40000];

    struct timespec ini,fin;
    double transcurrido;
	
    clock_gettime(CLOCK_REALTIME,&ini);

    for (ii=0; ii<=40000;ii++) {
        for(i=0; i<5000;i++) X1=2*s[i].a+ii;
        for(i=0; i<5000;i++) X2=3*s[i].b-ii;
        if (X1<X2)  R[ii]=X1;  
        else  R[ii]=X2;
    }

    clock_gettime(CLOCK_REALTIME,&fin);
    transcurrido=(double) (fin.tv_sec-ini.tv_sec)+(double) ((fin.tv_nsec-ini.tv_nsec)/(1.e+9));

    printf("Tiempo(seg): %f\nR[0]=%d, R[39999]=%d \n",transcurrido,R[0],R[39999]);
}


