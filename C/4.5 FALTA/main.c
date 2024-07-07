/*4.6 La fórmula 1 está compuesta por 20 pilotos y en el año se corrieron 23 carreras.
a) Se desea ingresar la información de cada piloto (nombre, escudería) y la posición en la que llegó dicho
piloto en cada una de las 23 carreras (1 a 20).
b) Luego se debe poder elegir el número de carrera del año y mostrar el listado de los 10 primeros puestos
de dicha carrera. Repetir el proceso con distintos números de carreras hasta ingresar un 0 como número
de carrera.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
 char nombre[51],escuderia[51];
 float posicion[5];

}piloto;

piloto pilotos[3];

void cargar();
void seleccion();
void ordenar(int, int);

int main()
{
    cargar();
    seleccion();

    return 0;
}

void cargar()
{
    int x=0,y=0;

    printf("INGRESO A LA BASE DE DATOS\n");

    for(x=0;x<5;x++)
        {
        printf("ingresar nombre : ");
        fgets(pilotos[x].nombre,51,stdin);

        printf("ingresar la escuderia : ");
        fgets(pilotos[x].escuderia,51,stdin);

        for(y=0;y<5;y++)
            {
            printf("ingresar posicion del piloto %s de la carrera %d ",pilotos[x].nombre,y+1 );
            scanf("%d",&pilotos[x].posicion[y]);

            }
        }


}

void seleccion()
{
    int n_car,x=0;

    printf("INGRESO PARA SABER TOP 10 \n");

    do
     {
      printf("ingresar numero de carrera de 1-23: ");
      scanf("%d",&n_car);
     }while(n_car<0 || n_car>23);

   while(n_car!=0)
    {

    ordenar(n_car,23);

    do
     {
      printf("ingresar numero de carrera de 1-23: ");
      scanf("%d",&n_car);
     }while(pilotos[x].NumeroCarrera<0 || pilotos[x].NumeroCarrera>23);

    }


}

void ordenar(int carrera, int lim)
{
    int x=0,y=0,aux;

    for(x=0;x<lim-1;x++)
        {
        for(y=0;y<lim-1-x;y++)
            {
            if(carrera==pilotos[y].posicion[y])
                {


                }


            }


        }


}


