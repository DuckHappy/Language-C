/*
6.6 Dado el archivo productos.dat con la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
Realizar un programa que permita eliminar productos dado su código
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
    FILE *pf, *pf2;
    int cod;

    pf=fopen("PRODUCTOS.dat","rb");
    pf2=fopen("PRODUCTOS2.dat","w+b");

    if(pf==NULL || pf2==NULL)
        {
        printf("error de lectura ");
        getch();
        exit(1);
        }
    fread(&prod,sizeof(producto),1,pf);
    while(!feof(pf))
        {
        printf("%d  %f  %s \n", prod.codigo,prod.precio,prod.descripcion);
        fread(&prod,sizeof(producto),1,pf);
        }
    system("pause");
    rewind(pf);

    printf("\n-------- eliminar productos dado su código --------\n");
    printf("ingrese numero de codigo : ");
    scanf("%d",&cod);
    while(cod!=0)
        {
        fread(&prod,sizeof(producto),1,pf);
        while(!feof(pf))
            {
            if(prod.codigo==cod)
                {
                fwrite(&prod,sizeof(producto),1,pf2);
                }
                fread(&prod,sizeof(producto),1,pf);
            }
        printf("ingrese numero de codigo : ");
        scanf("%d",&cod);
        }
    system("cls");
    rewind(pf2);
    fread(&prod,sizeof(producto),1,pf2);
    while(!feof(pf2))
        {
        printf("%d  %f  %s \n", prod.codigo,prod.precio,prod.descripcion);
        fread(&prod,sizeof(producto),1,pf2);

        }

    fclose(pf);
    fclose(pf2);



    return 0;
}
