/*
6.8 Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
Luego se dispone de un segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes
para la aerolínea con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizaron los viajes. Tenga en cuenta que los números de vuelo se
repiten entre las distintas aerolíneas. Al finalizar dar la opción para exportar los datos de vuelo de Aero1 en
formato csv.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
 char cod_aerolinea[11];
 int dia;
 int num_vuelo;
 float cot_pasaje;
 int pasajeros;

}vuelos;

typedef struct
{
    int dni;
    int num_vuelos;

}pasajeros;

void exportar(FILE *pf);

int main()
{
    vuelos vuel;
    pasajeros pasaj;
    FILE *pf, *pf2;
    char op;

    pf=fopen("VUELOS.dat","r+b");
    if(pf==NULL)
        {
        printf("error de lectura ");
        exit(1);
        }
    pf2=fopen("PASAJEROS.dat","rb");
    if(pf2==NULL)
        {
        printf("error de lectura ");
        exit(1);
        }

    printf("-------DATA INICIAL--------\n");
    fread(&vuel,sizeof(vuelos),1,pf);
    while(!feof(pf))
        {
        printf("%s  %d  %d  %2.f  %d\n", vuel.cod_aerolinea, vuel.dia, vuel.num_vuelo, vuel.cot_pasaje, vuel.pasajeros);
        fread(&vuel,sizeof(vuelos),1,pf);
        }

    rewind(pf);

    fread(&pasaj,sizeof(pasajeros),1,pf2);
    rewind(pf2);
    while(!feof(pf2))
        {
        fread(&vuel,sizeof(vuelos),1,pf);
        while(!feof(pf))
            {
            if(strcmp(vuel.cod_aerolinea,"AERO1")==0 && vuel.num_vuelo == pasaj.num_vuelos)
            {
                vuel.pasajeros++;
                fseek(pf,-sizeof(vuelos),SEEK_CUR);
                fwrite(&vuel,sizeof(vuelos),1,pf);
                fflush(pf2);
            }
        fread(&vuel,sizeof(vuelos),1,pf);
        }
        fread(&pasaj,sizeof(pasajeros),1,pf2);
        }

    rewind(pf);

    printf("\n------ACTUALIZADO------\n");
    fread(&vuel, sizeof(vuelos),1,pf);
    while(!feof(pf))
        {
        printf("%s  %d  %d  %2.f  %d\n", vuel.cod_aerolinea, vuel.dia, vuel.num_vuelo, vuel.cot_pasaje, vuel.pasajeros);
        fread(&vuel,sizeof(vuelos),1,pf);
        }
    system("pause");
    printf("------DESEA EXPORTAR EN FORMATO CSV?-----\n");
    printf("Y(YES).... N(NO)\n");
    scanf("%c",&op);
    if(op=='Y' || op=='y')
        {
        void exportar(pf);
        }

    fclose(pf);
    return 0;
}

void exportar(FILE *pf)
{
    vuelos vuel;

    rewind(pf);

    pf-fopen("AERO1","w+t");
    if(pf==NULL)
        {
        printf("error de lectura");
        getch();
        exit(1);
        }
    fprintf(pf,"cod_aerolinea;dia;num_vuelo;cot_pasaje;pasajeros\n");
    fread(&vuel,sizeof(vuelos),1,pf);
    while(!feof(pf))
        {
        fprintf(pf,"%s%d%d%f%d\n",vuel.cod_aerolinea,vuel.dia,vuel.num_vuelo,vuel.cot_pasaje,vuel.pasajeros );
        fread(&vuel,sizeof(vuelos),1,pf);
        }
    fclose(pf);
    printf("archivo exportado");

}
















