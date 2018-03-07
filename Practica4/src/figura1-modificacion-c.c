// Modificacion C): Sacar multiplicacion del interior de un bucle

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
    int tmpX1_0,tmpX1_1,tmpX1_2,tmpX1_3,tmpX1_4;
    int tmpX2_0,tmpX2_1,tmpX2_2,tmpX2_3,tmpX2_4;
    int R[40000];

    struct timespec ini,fin;
    double transcurrido;
	
    clock_gettime(CLOCK_REALTIME,&ini);

    for (ii=1; ii<=40000;ii++) {
        // iniciar temporales
        tmpX1_0=tmpX1_1=tmpX1_2=tmpX1_3=tmpX1_4=0.0;
        tmpX2_0=tmpX2_1=tmpX2_2=tmpX2_3=tmpX2_4=0.0;
        // calcular en temporales
        for(i=0; i<5000;i+=5) {
            tmpX1_0+=s[i].a+ii;
            tmpX1_1+=s[i+1].a+ii;
            tmpX1_2+=s[i+2].a+ii;
            tmpX1_3+=s[i+3].a+ii;
            tmpX1_4+=s[i+4].a+ii;

            tmpX2_0+=s[i].b-ii;
            tmpX2_1+=s[i+1].b-ii;
            tmpX2_2+=s[i+2].b-ii;
            tmpX2_3+=s[i+3].b-ii;
            tmpX2_4+=s[i+4].b-ii;
        }
        // sumar temporales
        X1=(tmpX1_0+tmpX1_1+tmpX1_2+tmpX1_3+tmpX1_4)*2;
        X2=(tmpX2_0+tmpX2_1+tmpX2_2+tmpX2_3+tmpX2_4)*3;
        // comprobacion
        if (X1<X2)  R[ii]=X1;  
        else  R[ii]=X2;
    }

    clock_gettime(CLOCK_REALTIME,&fin);
    transcurrido=(double) (fin.tv_sec-ini.tv_sec)+(double) ((fin.tv_nsec-ini.tv_nsec)/(1.e+9));

    printf("Tiempo(seg): %f\nR[0]=%d, R[39999]=%d \n",transcurrido,R[0],R[39999]);
}
