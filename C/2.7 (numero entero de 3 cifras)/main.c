#include <stdio.h>
#include <stdlib.h>

int main()
{
    //n3c = numero 3 cifras
    int n3c,cen,dec,uni;

    //pedido de numero de tres cifras
    printf("Numero de 3 cifras :");
    scanf("%d", &n3c);

    //centecimo
    cen=n3c/100;
    printf("\n%d/100=%d", n3c,cen);

    //decimo
    dec=n3c/10;
    printf("\n%d/10=%d", n3c,dec);

    //unidad
    uni=n3c/1;
    printf("\n%d/1=%d", n3c,uni);


    return 0;
}
