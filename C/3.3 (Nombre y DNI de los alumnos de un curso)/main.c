/*
3.3 Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar(char[][20],char[],int);
void ordenar(char[][20], int);

int main()
{
    char v_nom[3][20], nom[20];
    int v_dni[3],dev_dni,x=0, a;




        printf("ingrese nombre a la base de datos : ");
        fgets(v_nom[x],20, stdin);


        while(x<3 && strcmpi(v_nom[x],"fin\n")!=0 )
            {
            printf("ingrese el DNI : ");
            scanf("%d",&v_dni[x]);
            getchar();
            x++;

            if(x!=3){
                printf("ingrese nombre a la base de datos ");
                fgets(v_nom[x], 50, stdin);
                }


            }









        printf("\ningrese nombre a buscar : ");
        fgets(nom, 20, stdin);
        getchar();

        while(strcmpi(nom,"nobuscarmas\n")!=0)
            {
            dev_dni=buscar(v_nom,nom,3);
            if(dev_dni==-1)
                {
                printf("no esta el dni buscado \n");
                }
            else printf("%d",v_dni[dev_dni]);

            printf("ingrese nombre a buscar \n: ");
            fgets(nom, 20, stdin);
            getchar();

            }
ordenar(v_nom,3);




return 0;
            }




int buscar(char v[][20],char nombre[] ,int lim)
{
    int x, devolver=-1;

    for(x=0;x<lim;x++)
        {
        if(strcmpi(v[x], nombre)==0)
            {
            return x;
            }

        }
return -1;

}

void ordenar(char v[][20], int lim)
{
    int x,y,z;
    char aux[20];

    for(x=0;x<lim-1;x++)
        {
        for(y=0;y<lim-1-x;y++)
            {
            if(strcmpi(v[y],v[y+1])>0)
                {
                strcpy(aux,v[y]);
                strcpy(v[y],v[y+1]);
                strcpy(v[y+1],aux);
                }
            }


        }
printf("nombres ordenados \n\n");

for(z=0;z<lim;z++)
    {
    printf("%s\n",v[z]);
    }
}



