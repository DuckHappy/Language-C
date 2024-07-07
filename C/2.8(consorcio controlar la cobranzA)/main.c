/*
2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO DPTO 1 DPTO2 … DPTO 15
PISO 1 X
PISO 2 X X
PISO 3 X
PISO 4 X X
PISO 5 X X
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m_edif[5][15]={{0}};
    int piso,depar,x,y;

    printf("ingrese piso : ");
    scanf("%d",&piso);

    while(piso!=99)
        {
        do{
        printf("ingrese el departamento : ");
        scanf("%d",&depar);
        }while(depar>15 || depar<0);


        m_edif[piso-1][depar-1]+=1000;

        printf("ingrese piso : ");
        scanf("%d",&piso);

        }

    printf("\t\tTOTAL RECAUDADO");

    printf("\t\t\nDEPARTAMENTOS DEUDORES\n");
    for (int x = 0; x <15; x++) {
        printf("\tDPTO %d ", x+1);
    }
    printf("PISO");
    printf("\n");

    for (int x = 0; x < 5; x++) {
        printf("PISO %d ", x + 1);
        for (int y = 0; y < 15; y++) {
            printf("\t%d",m_edif[x][y]);
        }
        printf("\n");
    }

    return 0;
}
