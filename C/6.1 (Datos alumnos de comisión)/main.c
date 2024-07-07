/*
6.1 Los datos de los alumnos de una comisión de Computación Transversal son
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA

*/
#include <stdio.h>
#include <string.h>
typedef struct
{
    int dni;
    char nApellido[81];
    int notas[2];
    float promedio;
}ALUMNO;
void Lectura (FILE*);

int main ()
{
    FILE *archivo;
    ALUMNO dAlumno;
    int i=0,dni,nota1,nota2;
    float promedio;

    archivo = fopen("DatosAlumnos.dat","ab");
    if(archivo==NULL)
    {
        printf("Error, no se pudo abrir el archivo.");
        getchar();
        exit(1);
    }

    printf("***Ingrese datos de alumnos (DNI=0 para terminar)***\n");

    printf("Ingrese DNI alumno %d: ",i+1);
    do{
        scanf("%d",&dni);
        if(dni<0)
            printf("Error, ingrese nuevamente: ");
    }while(dni<0);

    while(dni!=0)
    {
        dAlumno.dni=dni;

        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        gets(dAlumno.nApellido);

        printf("Ingrese nota 1: ");
        do{
            scanf("%d",&nota1);
            if(nota1<0 || nota1>10)
                printf("Error, ingrese nuevamente: ");
        }while(nota1<0 || nota1>10);
        dAlumno.notas[0]=nota1;

        printf("Ingrese nota 2: ");
        do{
            scanf("%d",&nota2);
            if(nota2<0 || nota2>10)
                printf("Error, ingrese nuevamente: ");
        }while(nota2<0 || nota2>10);
        dAlumno.notas[1]=nota2;

        dAlumno.promedio=(nota1+nota2)/2;

        fwrite(&dAlumno,sizeof(ALUMNO),1,archivo);
        i++;

        printf("Ingrese DNI alumno %d: ",i+1);
        do{
            scanf("%d",&dni);
            if(dni<0)
                printf("Error, ingrese nuevamente: ");
        }while(dni<0);
    }
    fclose(archivo);

    archivo=fopen("DatosAlumnos.dat","rb");

    Lectura(archivo);

    fclose(archivo);

    return 0;
}

void Lectura (FILE *archivo)
{
    ALUMNO dAlumno;
    int i=0;

    printf("\n****Datos Guardados****\n");

    fread(&dAlumno,sizeof(ALUMNO),1,archivo);
    while(!feof(archivo))
    {
        printf("DNI: %d\n",dAlumno.dni);
        printf("Nombre y Apellido: %s\n",dAlumno.nApellido);
        printf("Nota 1: %d\nNota 2: %d\nPromedio: %.2f\n\n",dAlumno.notas[0],dAlumno.notas[1],dAlumno.promedio);

        fread(&dAlumno,sizeof(ALUMNO),1,archivo);
    }
}
