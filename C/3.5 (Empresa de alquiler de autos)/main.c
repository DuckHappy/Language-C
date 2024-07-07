/*
3.5 Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número de
patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el procesamiento de
los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación, se ingresan los
siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
a. El porcentaje de autos alquilados durante el día.
b. Realizar el informe con el formato siguiente:
ALQUILER DE AUTOS DEL DÍA: DD-MM-AAAA
COTIZACION DEL DÓLAR: $ XX,XX
NRO. DE AUTO DIAS DE ALQUILER PRECIO DEL ALQUILER
EN PESOS
FECHA DE DEVOLUCION
DEL AUTO
XXXXX XX XXXX,XX XX/XX/XXXX
XXXXX XX XXXX,XX XX/XX/XXXX
TOTAL RECAUDADO X ALQUILER (EN PESOS) $ XXXXX,
TOTAL RECAUDADO X ALQUILER (EN DÓLARES) $ XXXXX,XX
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(char[][7],int);
int buscar(char[],char[][7],int);

int main()
{
    char autos[3][7]={{0}};
    char dia[11],pat[7];
    float cot_dol,p_dol,porcen;
    int band=0,c_dias,v_con[30]= {0},a,ind,c_dol,v_cont[2]={0},x,vp_pes[3],tot_dol=0,tot_pes=0,v_dias[3];

    cargar(autos,3);

    printf("ingrese dia en este formato dd-mm-aaaa : ");
    scanf("%s",dia);

    printf("ingrese la cotizacion del dolar actual : ");
    scanf("%f",&cot_dol);

    do
    {
        printf("ingrese el auto a alquilar : ");
        scanf("%s",pat);

        ind=buscar(pat,autos,2);
        a=strlen(pat);

        if(strcmpi(pat,"FINDIA")==0)
        {
            ind=1;
        }
    }
    while(a != 6 || ind==-1);

    while(strcmpi(pat,"FINDIA")!=0)
    {
        do
        {

            printf("ingrese dias de alquilar : ");
            scanf("%d",&c_dias);
            v_dias[ind-1]+=c_dias;

        }
        while(c_dias<0);

        do
        {
            printf("ingrese el precio dolar : ");
            scanf("%d",&c_dol);
        }while(c_dol<0);

        v_cont[ind-1]++;

        vp_pes[ind-1]=cot_dol*c_dol;

        tot_dol+=c_dol*c_dias;

        do
        {
            printf("ingrese el auto a alquilar : ");
            scanf("%s",pat);

            ind=buscar(pat,autos,3);
            a=strlen(pat);

            if(strcmpi(pat,"FINDIA")==0)
            {
                ind=1;
            }
        }
        while(a>6 || a<6 || ind==-1);
    }
    printf("porcentajes : \n");
    for(x=0;x<3;x++)
        {
        porcen=(100*v_cont[x])/30;
        printf("%f\n",porcen);
        }

    printf("\t\tALQUILER DE AUTOS DEL DIA: %s",dia);
    printf("\t\t\n\t\tcotizacion del dolar : %f \n",cot_dol);

    printf("numero de auto : ");
    for(x=0;x<3;x++)
        {


        }
    printf("TOTAL RECAUDADO POR ALQUILER (EN PESOS): $%.2f\n", tot_pes);
    printf("TOTAL RECAUDADO POR ALQUILER (EN DÓLARES): $%.2f\n", tot_dol);






    return 0;
}

void cargar(char vn[][7],int lim)
{
    int x;

    for(x=0; x<lim; x++)
    {
        printf("ingrese patente a la base de datos de 6 caracteres : ");
        scanf("%s",vn[x]);
    }
}

int buscar(char vn[], char va[][7], int lim) {
    int x;

    for (x = 0; x < lim; x++) {
        if (strcmp(va[x], vn) == 0) {
            return x; // Se encontró la patente
        }
    }

    return -1; // No se encontró la patente
}

