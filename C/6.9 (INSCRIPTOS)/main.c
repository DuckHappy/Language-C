/*
6.9 Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la informaci�n de los inscriptos a un
curso de programaci�n. El archivo a�n no est� completo ya que la inscripci�n se realiza por partes. Por cada
inscripto se tiene la siguiente informaci�n:
� DNI (entero)
� Apellido y Nombres (texto de 20 caracteres m�ximo)
� Pagado (campo entero donde 1 indica que pag� y 0 que a�n adeuda la matr�cula)
Se desea realizar un programa que cumpla con dos funciones:
a. Registrar los pagos de los alumnos ya inscriptos.
b. SI hay cupo, agregar nuevos inscriptos (el cupo m�ximo es de 60 alumno).
El programa solicitar� el ingreso del DNI y lo buscar� entre los inscriptos, en caso de que lo encuentre dar�
la opci�n para registrar el pago (si es que no est� pago ya). En caso de que no lo encuentre dar� la opci�n
para inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega
un nuevo inscripto se le preguntar� si desea quedar registrado para un curso futuro, y en caso afirmativo
se le solicitar� el tel�fono y se guardar� el nombre, DNI y tel�fono en un archivo Interesados.dat.
El ingreso de datos finaliza con un DNI negativo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int dni;
    char apell_nom[21];
    int pagado;

}inscripto;

typedef struct
{
    int telefono;
    int dni;
    char apell_nom[21]


}interesado;

int buscar(FILE* ,int);
void registropago(FILE*,int);
void inscribirdni(FILE* ,int );
void interesadoadd(FILE*);

int main()
{
    FILE *pf;
    inscripto ins;
    int dni,enc,op,op2,pos;

    pf=fopen("INSCRIPTOS.dat","r+b");
    if(pf==NULL)
        {
        printf("error de lectura");
        getch();
        exit(1);
        }
    fread(&ins,sizeof(inscripto),1,pf);
    while(!feof(pf))
        {
        printf("%d  %s  %d\n",ins.dni, ins.apell_nom,ins.pagado);
        fread(&ins,sizeof(inscripto),1,pf);

        }


        printf("ingrese dni : ");
        scanf("%d",&dni);


        while(dni>0)
            {
             pos=buscar(pf, dni);
             if(pos!=-1)
                {
                fseek(pf,sizeof(inscripto)*pos,SEEK_CUR);
                fread(&ins,sizeof(inscripto),1,pf);

                if(ins.pagado==0)
                    {
                    printf("DESEA ABONAR MATRICULA? : 1(YES)....2(NO)\n");
                    scanf("%d",&op);
                    if(op==1)
                        {
                        registropago(pf,dni);
                        }
                    }

                }
            else
                {
                printf("NO SE ENCONTRO DNI, DESEA INSCRIBIR? : 1(YES).... 2(NO)\n");
                scanf("%d",&op2);
                if(op2==1)
                    {
                    inscribirdni(pf,dni);
                    }
                }
                do
                {
                    printf("ingrese dni : ");
                    scanf("%d",&dni);
                }while(dni>99999999);
            }

    fclose(pf);
    return 0;
}

int buscar(FILE *pf, int dni)
{
    inscripto ins;
    int pos=-1;

    rewind(pf);

    fread(&ins,sizeof(inscripto),1,pf);
    while(!feof(pf)&&pos==-1)
        {
        if(dni==ins.dni)
            {
             fseek(pf,-sizeof(inscripto),SEEK_CUR);
             pos=ftell(pf)/sizeof(inscripto);
            }
        else
            fread(&ins,sizeof(inscripto),1,pf);
        }
return pos;
}


void registropago(FILE* pf,int dni)
{
    inscripto ins;

    rewind(pf);

    fread(&ins,sizeof(inscripto),1,pf);
    while(!feof(pf))
        {
        if(ins.dni==dni)
            {
            ins.pagado=1;
            fseek(pf,-sizeof(inscripto),SEEK_CUR);
            fwrite(&ins,sizeof(inscripto),1,pf);
            fflush(pf);
            printf("PAGO REGISTRADO\n");
            return 0;
            }
        fread(&ins,sizeof(inscripto),1,pf);
        }
return 0;

}

void inscribirdni(FILE* pf,int dni)
{
    inscripto ins;
    int cant=0,op;

    rewind(pf);

    fread(&ins,sizeof(inscripto),1,pf);
    while(!feof(pf))
        {
        cant++;
        fread(&ins,sizeof(inscripto),1,pf);
        }
    if(cant>=60)
        {
        printf("SUPERO LIMITE DE CUPOS, DESEA QUEDAR REGISTRADO PARA UN CURSO FUTURO? : 1(YES).... 2(NO) : \n");
        scanf("%d",&op);
        if(op==1)
            {
            interesadoadd(pf);
            }
        else
            {
            printf("ingrese apellido y nombre : ");
            scanf("%s", ins.apell_nom);

            ins.dni=dni;
            ins.pagado=0;
            fseek(pf,0,SEEK_END);
            fwrite(&ins,sizeof(inscripto),1,pf);
            fflush(pf);
            printf("INSCRIPCION REALIZADA");


            }

        }
return 0;
}

void interesadoadd(FILE *pf)
{
    interesado inte;

    rewind(pf);
    pf=fopen("INTERESADOS.dat","wb");
    if(pf==NULL)
        {
        printf("error de lectura");
        getch();
        exit(1);
        }

    printf("ingrese telefono : ");
    scanf("%d",&inte.telefono);

    printf("ingrese dni : ");
    scanf("%d",&inte.dni);

    printf("ingrese apellido y nombre ");
    scanf("%s", inte.apell_nom);

    fwrite(&inte,sizeof(interesado),1,pf);

}










