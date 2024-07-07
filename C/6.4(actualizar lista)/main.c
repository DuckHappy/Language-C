/*
6.4 Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int codigo;
    float precio;
    char descripcion[51];

}precios;

int main()
{
    precios pre;
    FILE* pf;
    float porc;

    pf=fopen("PRECIOS.dat","r+b");
    if(pf==NULL)
    {
    printf("error de archivo");
    exit(1);
    }
    rewind(pf);

    fread(&pre,sizeof(precios),1,pf);
    while(!feof(pf))
        {
        printf("%d %f %s\n",pre.codigo, pre.precio, pre.descripcion);
        fread(&pre,sizeof(precios),1,pf);
        }
    system("pause");

    rewind(pf);

    printf("ingrese el porcentaje de incremento ");
    scanf("%f",&porc);

    fread(&pre,sizeof(precios),1,pf);

    while(!feof(pf))
        {
        fseek(pf,-sizeof(precios),SEEK_CUR);
        pre.precio += (pre.precio * porc) / 100;
        fwrite(&pre,sizeof(precios),1,pf);
        fseek(pf,0,SEEK_CUR);
        fread(&pre,sizeof(precios),1,pf);
        }

    rewind(pf);

    fread(&pre,sizeof(precios),1,pf);
    while(!feof(pf))
        {
        printf("%d %f %s\n",pre.codigo, pre.precio, pre.descripcion);
        fread(&pre,sizeof(precios),1,pf);
        }
    system("pause");




    return 0;
}
