/*
6.5 Se desea realizar un programa que permita actualizar la lista de precios de una empresa en forma individual
a cada uno de sus productos.
Los productos que están guardados en el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación
de precios finaliza con un código de producto igual a 0.
Al finalizar exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser
visualizada directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.



*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];

}producto;

int main()
{
    producto prod;
    FILE *pf;
    int cod;
    float prec;

    pf=fopen("PRODUCTOS.dat","a+b");
    //pf=fopen("listaprecios.csv","a+t");

    if(pf==NULL)
        {
        printf("error de apertura");
        getch();
        exit(1);
        }
    //fprintf(pf,"codigo;precio;descripcion\n");
    fread(&prod,sizeof(producto),1,pf);
    while(!feof(pf))
        {
        printf("%d  %f  %s \n", prod.codigo,prod.precio,prod.descripcion);
        fread(&prod,sizeof(producto),1,pf);
        }
    rewind(pf);

    printf("\n-----actualizar la lista de precios-----\n");

    printf("ingrese codigo : ");
    scanf("%d",&cod);
    while(cod!=0)
        {
        printf("ingrese precio : ");
        scanf("%f",&prec);

        fread(&prod,sizeof(producto),1,pf);
        while(!feof(pf))
            {
            if(prod.codigo==cod)
                {
                fseek(pf,-sizeof(producto),SEEK_CUR);
                prod.precio=prec;
                fwrite(&prod,sizeof(producto),1,pf);
                fseek(pf,0,SEEK_CUR);
                fread(&prod,sizeof(producto),1,pf);
                }fread(&prod,sizeof(producto),1,pf);
            }
        printf("ingrese codigo : ");
        scanf("%d",&cod);
        }
    system("cls");
    rewind(pf);




    fread(&prod,sizeof(producto),1,pf);
    while(!feof(pf))
        {
        printf("%d  %f  %s \n", prod.codigo,prod.precio,prod.descripcion);
        fread(&prod,sizeof(producto),1,pf);
        }
    fclose(pf);

    return 0;
}
