/*
4.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES
VENDIDAS
IMPORTE TOTAL
VENDIDO
XXXXXXX XXXX $XXXXX,XX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codigo[6];
    char descripcion[31];
    float precio;
    float importe_total;
    int cant_vendida;

}producto;

producto cargar(producto[],int);
void mostrar(producto[], int);

int main()
{
    producto v_prod[50];
    char cod[6];
    int cant_ped,x=0,i=0;

    cargar(v_prod,3);

    printf("ingrese la cantidad pedida : ");
    scanf("%d",&cant_ped);
    fflush(stdin);

    while(x<50 && cant_ped!=0)
        {
        printf("ingrese el codigo : ");
        fgets(cod,6,stdin);

        for(i=0;i<50;i++)
            {
            if(strcmp(v_prod[i].codigo,cod)==0)
                {
                v_prod[x].cant_vendida+=cant_ped;
                v_prod[x].importe_total+=cant_ped*v_prod[x].precio;
                }

            }
        while (getchar() != '\n');


        printf("ingrese la cantidad pedida : ");
        scanf("%d",&cant_ped);
        fflush(stdin);

        }

        mostrar(v_prod,3);

    return 0;
}


producto cargar(producto prod[],int lim)
{
    int x=0;

    printf("ingrese la descripcion : ");
    fgets(prod[x].descripcion, 31, stdin);
    prod[x].descripcion[strcspn(prod[x].descripcion, "\n")] = '\0'; // Eliminar el salto de línea del final

    while(x<lim && strcmpi(prod[x].descripcion,"FIN")!=0)
        {
        printf("ingrese el codigo de 5 caracteres : ");
        fgets(prod[x].codigo, 6, stdin);
        prod[x].codigo[strcspn(prod[x].codigo, "\n")] = '\0';

        do
         {
           printf("ingrese el precio : ");
           scanf("%f",&prod[x].precio);
           fflush(stdin);
         }while(prod[x].precio<0);

         while (getchar() != '\n');

        do
         {
            printf("ingrese la cantidad de unidades : ");
            scanf("%d",&prod[x].cant_vendida);
            getchar();
         }while(prod[x].cant_vendida<0);

         do
         {
            printf("ingrese total vendido : ");
            scanf("%f",&prod[x].importe_total);
            fflush(stdin);
         }while(prod[x].importe_total<0);

         x++;

        printf("ingrese la descripcion : ");
        fgets(prod[x].descripcion, 31, stdin);
        prod[x].descripcion[strcspn(prod[x].descripcion, "\n")] = '\0';
        fflush(stdin);
        }
};

void mostrar(producto prod[], int lim )
{
    int x=0;

    printf ("\n%6s%21s%15s%21s%12s", "CODIGO", "DESCRIPCION", "Precio", "Unidades vendidas","IMPORTE TOTAL VENDIDO ");
    for(x=0;x<lim;x++)
        {

        printf ("\n%6s%21s%15.2f%21d%12.2f", prod[x].codigo, prod[x].descripcion, prod[x].precio,prod[x].cant_vendida,prod[x].importe_total);

        }
}
