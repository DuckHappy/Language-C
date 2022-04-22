#include <stdio.h>
#include <stdlib.h>

int main()
{
    //tpint = tarros de pintura
    int tpint , litros, alitros, blitros, clitros;

    printf("\nintroduce tarros de pintura : ");
    scanf("%d", &tpint);

    //50%
    printf("\nLos de 1 litros son : ");
    alitros = tpint/2;
    printf("\n%d/2=%d",tpint, alitros);

    //30%
    printf("\n\nLos de 4 litros son : ");
    blitros = tpint*3/10;
    printf("\n%d*3/10=%d",tpint, blitros);

    //20%
    printf("\n\nLos de 20 litros son : ");
    clitros = tpint/5;
    printf("\n%d/5=%d",tpint, clitros);


    return 0;
}
