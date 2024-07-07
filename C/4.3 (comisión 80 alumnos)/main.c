/*Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO*/


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    int nota1;
    int nota2;
    char apellnombre[81];
    float notapromedio;

}alumno;

alumno alumnos[3];

void INGRESO();
void RESULTADO();
void INFORME_PROMO();

int main()
{
    INGRESO();
    RESULTADO();
    INFORME_PROMO();

    return 0;
}

void INGRESO()
{
    int x=0;

    for(x=0;x<3;x++)
        {
        do
            {
            printf("Ingrese dni sin puntos : ");
            scanf("%d",&alumnos[x].dni);

            }while(alumnos[x].dni>99999999 || alumnos[x].dni<9999999);

            getchar();

        printf("Ingrese apellido y nombre :");
        fgets(alumnos[x].apellnombre,81,stdin);
        alumnos[x].apellnombre[strcspn(alumnos[x].apellnombre, "\n")] = '\0';


        do
            {
            printf("ingrese la nota 1 : ");
            scanf("%d",&alumnos[x].nota1);

            }while(alumnos[x].nota1<0 || alumnos[x].nota1>10);

        do
            {
            printf("ingrese la nota 2 : ");
            scanf("%d",&alumnos[x].nota2);

            }while(alumnos[x].nota2<0 || alumnos[x].nota2>10);

        alumnos[x].notapromedio=(alumnos[x].nota1+alumnos[x].nota2)/2.0;


        }

}

void RESULTADO()
{
    int x=0;

    printf("RESULTADOS : \n");
    for(x=0;x<3;x++)
        {
        if(alumnos[x].nota1>4 && alumnos[x].nota2>4)
            {
            printf("El alumno %s aprobo la materia \n",alumnos[x].apellnombre);
            }else
            printf("El alumno %s desaprobo la materia la materia \n",alumnos[x].apellnombre);
        }
}

void INFORME_PROMO()
{
    int x=0;

    printf("PROMOCIONADOS : \n");

    for(x=0;x<3;x++)
        {
        if(alumnos[x].nota1 >=7 && alumnos[x].nota2 >=7)
            {
            printf("DNI : %d-APELLIDO Y NOMBRE : %s- PROMEDIO : %.2f \n",alumnos[x].dni,alumnos[x].apellnombre,alumnos[x].notapromedio);
            }

        }


}

















