/*
6.1 Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre_apellido[81];
    int not1, not2;
    float not_prom;

}datos;

void lectura(FILE*);

int main()
{
    int dni;
    datos dato;

    FILE *arch;
    arch = fopen("ALUMNO.dat","ab");

    if(arch==NULL)
        {
        printf("error ");
        getch();

        exit(1);
        }

    do
        {
        printf("ingrese numero dni :");
        scanf("%d",&dni);

        }while(dni>99999999 || dni<9999999 && dni!=0);

        while(dni!=0)
            {

            dato.dni=dni;

            printf("ingrese nombre y apellido :  ");
            fflush(stdin);
            gets(dato.nombre_apellido);

            printf("ingrese nota 1 : ");
            scanf("%d",&dato.not1);


            printf("ingrese nota 2 : ");
            scanf("%d",&dato.not2);


            dato.not_prom=(dato.not1+dato.not2)/2;


            fwrite(&dato,sizeof(datos),1,arch);

       do
        {
        printf("ingrese numero dni :");
        scanf("%d",&dni);

        }while(dni>99999999 || dni<9999999  && dni!=0);


            }

        fclose(arch);

        arch=fopen("ALUMNO.dat","rb");

        lectura(arch);

        fclose(arch);




    return 0;
}

void lectura(FILE *arch)
{
    datos dato;

    fread(&dato,sizeof(datos),1,arch);

    while(!feof(arch))
        {
        printf("DATOS :    ");
        printf("DNI : %d\n",dato.dni);
        printf("nombre y apellido : %s\n",dato.nombre_apellido);
        printf("nota 1 : %d\n",dato.not1);
        printf("nota 2 : %d\n",dato.not2);
        printf("promedio : %2.f\n",dato.not_prom);

         fread(&dato,sizeof(datos),1,arch);

        }


}
