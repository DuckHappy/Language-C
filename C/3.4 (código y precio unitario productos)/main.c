/*
3.4 Se ingresan c�digo y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero s� se sabe que son menos de 50. El c�digo es alfanum�rico de 3 caracteres y la carga de
los datos de productos termina con un c�digo igual al �FIN�. Luego se registran las ventas del d�a y por cada
venta se ingresa el c�digo de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudaci�n total del d�a y el producto del cual se vendi� menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfab�tica por c�digo de producto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar(char[][4],char[],int);

int main()
{
    int x=0,ind,z=0;
    char v_cod[5][4],cod[4];
    float prec_prod[5],acum=0, v_rec[5]={0},cant;

    printf("ingrese codigo a la base de datos : ");
    fgets(v_cod[x],5, stdin);

        while(strcmpi(v_cod[x],"FIN\n")!=0)
            {
            printf("Ingrese precio de producto ");
            scanf("%f",&prec_prod[x]);
            getchar();
            x++;


            printf("ingrese codigo a la base de datos : ");
            fgets(v_cod[x],5, stdin);


            }

    printf("REGISTRO DE VENTAS \n");

    printf("Ingrese cantidad de unidades : ");
    scanf("%f",&cant);
    getchar();

    while(cant!=0)
        {
        printf("ingrese codigo de producto : ");
        fgets(cod,4,stdin);
        cod[strlen(cod)-1]="\n";
        getch();

        ind=buscar(v_cod,cod,5);

        v_rec[ind]+=cant*prec_prod[ind];


        printf("Ingrese cantidad : ");
        scanf("%f",&cant);

        }
for(z=0;z<5;z++)
    {
    printf("%f\n",v_rec);

    }




    return 0;
}

int buscar(char v[][4],char codigo[], int lim)
{
    int pos=-1,x=0;

    while(pos==-1 && x<lim)
        {
        if(strcmpi(v[x],codigo)==0)
            {
            pos=x;
            }else x++;
        }
return pos;
}






