/*
6.3 El archivo ventas.dat contiene información histórica de las ventas realizadas por una empresa desde el año
2014 al 2023. El formato de registro es el siguiente:
• Mes (entero)
• Año (entero)
• Dia (entero)
• Código de Producto (entero)
• Importe de la venta (real)
Se pide ingresar un rango de años y mostrar un cuadro ventas realizadas en cada mes de cada año. Por ejemplo,
si se ingresa desde 2020 a 2022 debe mostrar lo siguiente:
Mes 1 Mes 2 Mes 3 ……. Mes 12
2020 xxx xxx xxx xxx
2021 xxx xxx xxx xxx
2022 xxx xxx xxx xxx
Una vez configurados los años debe poder cambiarse la vista para en lugar de visualizar cantidad de ventas, ver el
detalle de importe por mes/año. El usuario podrá alternar las vistas las veces que quiera. Agregar una opción
para finalizar el programa.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int mes;
  int anio;
  int dia;
  int cod_prod;
  float imp;
}ventas;

int main()
{
    ventas venta;
    FILE *ven;
    int cant_vent=0,m_cant[10][12]={{0}},x,y, sel,a;
    float m_imp[10][12]={{0}};

    ven=fopen("VENTAS.dat","wb");
    if(ven==NULL)
        {
        printf("error");
        getch();
        exit(1);
        }
    a=venta.dia;

    do
        {
            printf("ingrese mes : ");
            scanf("%d",&venta.mes);
        }while(venta.mes<0 || venta.mes>12);

    while(venta.mes!=0)
        {

        do
        {
            printf("ingrese anio : ");
            scanf("%d",&venta.anio);
        }while(venta.anio<2014 || venta.anio>2023);



            printf("ingrese dia : ");
            scanf("%d",&venta.dia);



    do
        {
            printf("ingrese codigo de producto : ");
            scanf("%d",&venta.cod_prod);
        }while(venta.cod_prod<0);

    do
        {
            printf("ingrese impuesto : ");
            scanf("%f",&venta.imp);
            if(venta.imp>0)
                {
                cant_vent++;
                }
        }while(venta.imp<0);



    fwrite(&venta,sizeof(ventas),1,ven);

    m_cant[venta.anio-2014][venta.mes-1]+=cant_vent;
    m_imp[venta.anio-2014][venta.mes-1]+=venta.imp;

    do
        {
            printf("ingrese mes : ");
            scanf("%d",&venta.mes);
        }while(venta.mes<0 || venta.mes>12);

        }

    printf("aca esta : %d",venta.dia);

    fclose(ven);

    system("cls");

    do
        {
        printf("----------------SELECCION--------------------\n");
    printf("1-cantidad de ventas  .... 2-cantidad de importe.... 3-exit\n");
    scanf("%d",&sel);

    if(sel==1)
        {
        system("cls");
        printf("\t\t");
        for(x=0;x<12;x++)
            {
            printf("mes %d\t",x+1);
            }

                printf("\n");

            for(x=0;x<10;x++)
                {
                printf("anio %d\t",x+2014);
                for(y=0;y<12;y++)
                    {
                    printf("%d\t", m_cant[x][y]);
                    }
                    printf("\n");
                }



                }else
                    if(sel==2)
                    {
                    system("cls");
                    printf("\t\t");
                    for(x=0;x<12;x++)
                        {
                        printf("mes %d\t",x+1);
                        }

                    printf("\n");

                    for(x=0;x<10;x++)
                        {
                        printf("anio %d\t",x+2014);
                            for(y=0;y<12;y++)
                            {
                                printf("%.2f\t", m_imp[x][y]);
                            }
                    printf("\n");
                        }

                    }else exit(1);


        }while(sel!=3);








    return 0;
}


