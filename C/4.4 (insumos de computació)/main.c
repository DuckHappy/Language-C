/*Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE NOMBRE Y APELLIDO TOTAL FACTURADO
X XXXXX XXXXXXXX $ XXXXXXXXX,XX*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int NumeroCliente;
int NumeroVendedor;
float importe;
float TotalFacturado;
}venta;

typedef struct
{
int CodigoCliente;
char NombreApellido[51];
}cliente;

venta ventas[3];
cliente clientes[3];

int cargar_venta();
int CARGA_CLIENTE();
void ordenamiento();

int main()
{
    int acumA=0,acumB=0,x=0,tot_fac=0;

    acumA=cargar_venta();
    acumB=CARGA_CLIENTE();
    ordenamiento();

    printf("CANTIDAD DE VENTAS REALIZADA POR CLIENTE : %d \n", acumA); //a
    printf("CANTIDAD DE VENTAS REALIZADA POR VENDEDOR : %d \n", acumB); //b

    printf("CODIGO DE CLIENTES    NOMBRE Y APELLIDO  TOTAL FACTURADO");
    printf("\n");
    for(x+0;x<3;x++)
        {
        printf("%d                    %s            %.2f\n", clientes[x].CodigoCliente, clientes[x].NombreApellido, ventas[x].TotalFacturado);
        }
    return 0;
}

int cargar_venta()
{
    int x,acum=0;

     printf("ingrese numero de cliente : ");
    scanf("%d",&ventas[x].NumeroCliente);

    while(ventas[x].NumeroCliente!=999)
        {
            do{
                printf("ingrese importe : ");
                scanf("%f",&ventas[x].importe);
            }while(ventas[x].importe<0);

            do
            {
            printf("ingrese numero de vendedor : ");
            scanf("%d",&ventas[x].NumeroVendedor);
            }while(ventas[x].NumeroVendedor<0 || ventas[x].NumeroVendedor>10);

        getchar();

        ventas[x].TotalFacturado=ventas[x].importe;

        acum++;
        x++;

        printf("ingrese numero de cliente : ");
        scanf("%d",&ventas[x].NumeroCliente);


        }
return acum;

}

int CARGA_CLIENTE()
{
    int x=0, acum=0;

    while(x<3)
        {
        printf("ingrese codigo de cliente : ");
        scanf("%d",&clientes[x].CodigoCliente);

        getchar();

        acum++;

        printf("ingrese el nombre y apellido : ");
        fgets(clientes[x].NombreApellido,51,stdin);

        x++;

        }
return acum;
}

void ordenamiento()
{
    int x=0,y=0;
    float aux;

    for(x=0;x<3-1;x++)
        {
        for(y=0;y<3-1-x;y++)
            {
            if(ventas[y].TotalFacturado>=ventas[y+1].TotalFacturado)
                {
                aux=ventas[y].TotalFacturado;
                ventas[y].TotalFacturado=ventas[y+1].TotalFacturado;
                ventas[y+1].TotalFacturado=aux;
                }
            }
        }
}




