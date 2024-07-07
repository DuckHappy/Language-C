/*
Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior se desea desarrollar un
programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no
promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre del archivo
a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para mostrar todos los
archivos generados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre_apellido[81];
    int not1;
    int not2;
    float not_prom;

} datos;

void lectura(FILE *arch);

int main()
{
    datos dato;
    FILE *pf, *prom, *des, *cur;

    pf = fopen("ALUMNO.dat", "rb");
    prom = fopen("PROMOCION.dat", "wb");
    des = fopen("DESAPROBADOS.dat", "wb");
    cur = fopen("CURSANDO.dat", "wb");

    if (pf == NULL || prom == NULL || des == NULL || cur == NULL)
    {
        printf("error");
        exit(1);
    }

    while (fread(&dato, sizeof(datos), 1, pf) == 1)
    {
        if (dato.not1 >= 7 && dato.not2 >= 7)
        {
            fwrite(&dato, sizeof(datos), 1, prom);
        }
        else if (dato.not1 <= 3 || dato.not2 <= 3)
        {
            fwrite(&dato, sizeof(datos), 1, des);
        }
        else
        {
            fwrite(&dato, sizeof(datos), 1, cur);
        }
    }

    fclose(pf);
    fclose(prom);
    fclose(cur);
    fclose(des);

    system("cls");

    prom = fopen("PROMOCION.dat", "rb");
    if (prom == NULL)
    {
        printf("error");
        exit(1);
    }
    lectura(prom);
    fclose(prom);

    system("pause");
    system("cls");

    des = fopen("DESAPROBADOS.dat", "rb");
    if (des == NULL)
    {
        printf("error");
        exit(1);
    }
    lectura(des);
    fclose(des);
    system("pause");
    system("cls");

    cur = fopen("CURSANDO.dat", "rb");
    if (cur == NULL)
    {
        printf("error");
        exit(1);
    }
    lectura(cur);
    fclose(cur);
    system("pause");
    system("cls");

    return 0;
}

void lectura(FILE* arch)
{
    datos dato;

    while (fread(&dato, sizeof(datos), 1, arch) == 1)
    {
        printf("\n\nDNI: %d", dato.dni);
        printf("\nNombre y Apellido: %s", dato.nombre_apellido);
        printf("\nNota 1: %d", dato.not1);
        printf("\nNota 2: %d", dato.not2);
        printf("\nPromedio: %.2f\n", dato.not_prom);
    }
}
