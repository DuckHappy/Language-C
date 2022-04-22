#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,a,b,c,d,num2,num3,e,f,sum;

    //numero de 4 ciffras
    printf("Numero de 4 cifras : ");
    scanf("%d", &num);

    //proceso que no ve el cliente

    //se divide con el objetivo de defragmentar numero

    a=num/1000;

    b=(num%1000)/100;

    c=(num%1000)%100/10;

    d=(num%1000)%100%10/1;

    //se suma para quedar 2 cifras
    num3=a+b+c+d;

    //volvemos a defragmentar con division
    e=num3/10;

    f=(num3%10)/1;

    //printf a la suma dada luego de la division
    printf("\nSuma de las cifras hacia una cifra :");
    sum=e+f;
    printf("\t%d",sum);

    return 0;
}
