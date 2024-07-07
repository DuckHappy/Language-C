/*
6.7 Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad.

falta

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int codigo;
    char descripcion[51];
    int stock;

}stock;

typedef struct
{
    int codigo;
    int cantidad;

}faltante;

void actualizar_stock(FILE*,int,int);
void registrar_falt(int ,int);

int main()
{
    stock sto;
    FILE *pf;

    int cod,cant;

    pf=fopen("STOCK.dat","r+b");
    if(pf==NULL)
        {
        printf("error de lectura ");
        getch();
        exit(1);
        }
    fread(&sto,sizeof(stock),1,pf);
    while(!feof(pf))
        {
        printf("%d  %s  %d\n",sto.codigo,sto.descripcion,sto.stock);
        fread(&sto,sizeof(stock),1,pf);
        }
    rewind(pf);


    do
        {
        printf("ingrese codigo a modificar : ");
        scanf("%d",&cod);

        }while(cod<0);

    while(cod!=0)
        {
        do
            {
            printf("ingrese cantidad : ");
            scanf("%d",&cant);
            }while(cant<0);

            actualizar_stock(pf,cod,cant);
                }
        do
        {
            printf("ingrese codigo a modificar : ");
            scanf("%d",&cod);
        }while(cod<0);

    fclose(pf);

return 0;
        }

void actualizar_stock(FILE *pf,int cod, int cant)
{
    stock sto;
    int cant_falt;
    rewind(pf);

    fread(&sto,sizeof(stock),1,pf);
    while(!feof(pf))
        {
        if(sto.stock>=cant)
            {
            sto.stock-=cant;
            fseek(pf,-sizeof(stock),SEEK_CUR);
            fwrite(&sto,sizeof(stock),1,pf);
            fflush(pf);
            }else
            {
            cant_falt=cant-sto.stock;
            registrar_falt(cod,cant_falt);
            sto.stock=0;
            fseek(pf,-sizeof(stock),SEEK_CUR);
            fwrite(&sto,sizeof(stock),1,pf);
            fflush(pf);
            }
        fread(&sto,sizeof(stock),1,pf);
        }
fclose(pf);
}

void registrar_falt(int cod, int falta)
{
    FILE *pf;
    faltante falt;
    rewind(pf);

    pf=fopen("FALTANTES.dat","w+b");
    if(pf==NULL)
        {
        printf("error de lectura");
        getch();
        exit(1);
        }
    rewind(pf);

    fread(&falt,sizeof(faltante),1,pf);
    while(!feof(pf))
        {
        if(falt.codigo==cod)
            {
            falt.cantidad+=falta;
            falt.codigo=cod;
            fseek(pf,-sizeof(faltante),SEEK_CUR);
            fwrite(&falt,sizeof(faltante),1,pf);
            fflush(pf);
            }
        fread(&falt,sizeof(faltante),1,pf);
        }
fclose(pf);
rewind(pf);

}
