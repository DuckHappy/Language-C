/*
1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void IngresaCodigos(int [],int,int);
int buscar(int[],int,int);
int buscar2(int[],int,int);

int main ()
    {
        int cod, band, cant, ind,x, max, min, poscodmax, codmax, poscodmin, codmin;
        int vcod[10]={0}, vcant[10]={0};

        srand(time(NULL));
        cod=rand();
        IngresaCodigos(vcod,10,10000);

       do
        {
            printf("ingrese codigo de 4 cifras : ");
            scanf("%d",&cod);
            band=buscar(vcod,cod,10);
                if(band==-1)
                {
                    printf("no se encontro en la base de datos, intentelo nuevamente...\n");
                }
        }while(band==-1);

       while(cod!=0 && cod>0)
        {
            do
            {
                printf ("cantidad : ");
                scanf ("%d", &cant);
                if(cant<0)
                    {
                        printf("cantidad no puede ser menor a 0 >:( \n");
                    }
            }
            while (cant < 0);
            ind=buscar(vcod, cod, 10);
            vcant[ind]+=cant;
            do
            {
                printf("ingrese codigo de 4 cifras : ");
                scanf("%d",&cod);
                band=buscar(vcod,cod,10);
                    if(band==-1)
                    {
                        printf("no se encontro en la base de datos, intentelo nuevamente...\n");
                    }
            }while(band==-1);

        }

    for(x=0;x<10;x++)
        {
        printf("codigo %d      su cantidad es %d \n",vcod[x],vcant[x]);
        }

max=vcant[0];
min=vcant[0];

    for(x=0;x<10;x++)
        {
        if(max<vcant[x])
            {
            max=vcant[x];
            }

        }
    for(x=0;x<10;x++)
        {
        if(min>vcant[x])
            {
            min=vcant[x];
            }
        }

poscodmax=buscar(vcant, max, 10);
codmax=buscar2(vcod,poscodmax,10);

poscodmin=buscar(vcant, min, 10);
codmin=buscar2(vcod,poscodmin,10);

printf("la cantidad maxima es %d del codigo %d\n",max, codmax);
printf("la cantidad minima es %d del codigo %d",min, codmin);

    return 0;
    }

void IngresaCodigos(int v[],int a ,int b)
    {
    int x,codi,band;

    for(x=0;x<a;x++)
        {
        v[x]=rand()%b;
        printf("dato de servidor : %d \n",v[x]);
        codi=v[x];
        band=buscar(v,codi,10);
        v[x]=codi;
        }
    }




int buscar(int vec[], int dato, int lim)
    {
    int x=0, band=-1;

    while(band==-1 && x<lim)
        {
        if(vec[x]==dato || dato==0)
            {
            band=x;
            }
        else x++;
        }
        return band;
    }


int buscar2(int vec[], int dato, int lim)
    {
    int x=0, band=-1, codmax;

    while(band==-1 && x<lim)
        {
        if(x==dato)
            {
            band=x;
            codmax=vec[x];
            }
        else x++;
        }
        return codmax;
    }

