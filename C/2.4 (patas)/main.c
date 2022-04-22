#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pies,pulgadas,yardas,cms,mts;

    //Medida pie
    printf("pies:");
    scanf("%f", &pies);

    //convertir a pulgadas
    printf("\npulgadas");
    pulgadas= pies*12;
    printf("\n%0.2f*12=%0.2f", pies, pulgadas);

    //convertir a yardas
    printf("\n\nyardas");
    yardas=pies/3;
    printf("\n%0.2f/3=%0.2f", pies, yardas);

    //convertir a centimetros
    printf("\n\ncms");
    cms= pulgadas*2.54;
    printf("\n%0.2f*2.54=%0.2f", pulgadas, cms);

    //convertir a metros
    printf("\n\nmts");
    mts= cms/100;
    printf("\n%0.2f/100=%0.2f",cms, mts);

    return 0;
}
