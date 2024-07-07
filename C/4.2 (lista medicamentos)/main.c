/*
4.2 Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    float precio;
    int stock;

}medicamento;

medicamento medicamentos[3]; //vector estructura

void INGRESO(); //funciones
void BUSQUEDA_MEDI();
void INFORME();

int main()

{

    INGRESO();
    BUSQUEDA_MEDI();
    INFORME();

    return 0;
}

void INGRESO()
{
    int x=0;

    for(x=0;x<3;x++)
        {
        printf("ingrese el codigo : ");
        scanf("%d",&medicamentos[x].codigo);

        printf("ingrese precio : ");
        scanf("%f",&medicamentos[x].precio);

        printf("ingrese el stock : ");
        scanf("%d",&medicamentos[x].stock);
        }

}

void BUSQUEDA_MEDI()
{
    int cod,x=0;

    printf("BUSCAR PRECIO DE MEDICAMENTO : ");
    for(x=0;x<3;x++)
        {
        printf("ingrese el codigo : ");
        scanf("%d",&cod);

        if(medicamentos[x].codigo==cod)
            {
            printf("este es el precio de ese medicamento : %.2f",medicamentos[x].precio);
            }else printf("NO EXISTE ESE CODIGO");

        }

}

void INFORME()
{

    int x=0;

    printf("INFORME DE AQUELLOS MENORES A 10 STOCK : \n");
    for(x=0;x<3;x++)
        {
        if(medicamentos[x].stock<10)
            {
            printf("este medicamento es menor 10 stock : %d \n",medicamentos[x].codigo);
            }

}
}

