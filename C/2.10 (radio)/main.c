#include <stdio.h>
#include <stdlib.h>

int main()
{
    //r = radio, sup = superficie, per = perimetro , v = volumen
    float r,sup,per,vol;

    //ingreso de radio
    printf("Dale viejo ingresa radio bb :");
    scanf("%f", &r);

    //Superficie
    printf("\nSuperficie :");
    sup=3.141592*r*r;
    printf("%0.2f",sup);

    //perimetro
    printf("\nPerimetro :");
    per=2*3.141592*r;
    printf("%0.2f",per);

    //Volumen
    printf("\nSuperficie :");
    vol= (4*3.141592*r*r*r)/3;
    printf("%0.2f",vol);

    return 0;
}
