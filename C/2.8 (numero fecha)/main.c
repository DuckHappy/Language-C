#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anio,mes,dia;

    //ingreso de fecha
    printf("ingresa fecha dia,mes,anio  : ");
    scanf("%d %d %d", &dia, &mes, &anio);

    //cambio de formato
    printf("\nformato aa/mm/dd : ");
    printf("\n%d %d %d" ,anio,mes,dia);

    return 0;
}
