#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
    {
        char cod[4];
        char nom[31];
        char cat;
        float imp;
        float cob;
    }sueldo;

typedef struct
    {
        char cod[4];
        int hrs;
    }errores;

//funciones
int buscar(char[],FILE *);
void actualizar(char[],int,FILE*);
void error(char[],int);
void mayor(FILE*);
void tot(FILE*);

int main()
{
    sueldo suel;
    FILE *pf;
    char cod[4];
    int hrs, enc=0,b,c;

    pf=fopen("personal.dat","r+b");
    if(pf==NULL)
    {
        printf("error");
        getchar();
        exit(1);
    }

    fread(&suel,sizeof(sueldo),1,pf);
    while(!feof(pf))
    {
        printf("%s %s %c %f %f \n",suel.cod,suel.nom,suel.cat,suel.imp,suel.cob);
        fread(&suel,sizeof(sueldo),1,pf);
    }
    rewind(pf);

    printf("ingrese codigo FIN para terminar: ");
    fgets(cod,4,stdin);
    cod[strcspn(cod, "\n")] = 0;
    enc=buscar(cod,pf);

    while(strcmp(cod,"FIN")!=0)
    {
        do
        {
            printf("ingrese horas: ");
            scanf("%d",&hrs);
        }while(hrs<0 || hrs>168);

        if(enc==0)
        {
            error(cod,hrs);
        }

        actualizar(cod,hrs,pf);

        getchar();
         printf("ingrese codigo : ");
        fgets(cod,4,stdin);
        cod[strcspn(cod, "\n")] = 0;
        enc=buscar(cod,pf);

    }

    mayor(pf);
    tot(pf);
    fclose(pf);

    return 0;
}
void error(char c[4],int h)
{
    FILE *pf;
    errores er;

    er.hrs=h;
    strcpy(er.cod,c);

    pf=fopen("errores.dat", "a+b");
    if(pf==NULL)
    {
        printf("error de creacion");
    }

    fwrite(&er,sizeof(er),1,pf);

    rewind(pf);

    printf("Contenido de errores.dat:\n");
    while (fread(&er, sizeof(er), 1, pf) == 1)
    {
        printf("Codigo: %s, Horas: %d\n", er.cod, er.hrs);
    }
    fclose(pf);
}


void actualizar(char cod[4], int h, FILE *pf)
{
    sueldo s;

    rewind(pf);
    fread(&s,sizeof(s),1,pf);
    while(!feof(pf))
    {
        if(strcmp(cod,s.cod)==0)
        {
            s.cob=s.imp*h;
            fseek(pf,sizeof(sueldo)*-1,SEEK_CUR);
            fwrite(&s,sizeof(s),1,pf);
            fflush(pf);
            fseek(pf,0,SEEK_CUR);
        }
        fread(&s,sizeof(s),1,pf);
    }
    rewind(pf);
}

void mayor(FILE *pf)
{
    sueldo s;
    int x;
    float max_s=0;
    char nom_max[31];

    rewind(pf);

    fread(&s,sizeof(s),1,pf);
    while(!feof(pf))
    {

        if(s.cob>max_s)
        {
            max_s=s.cob;
            strcpy(nom_max,s.nom);
        }
        fread(&s,sizeof(s),1,pf);
    }
    printf("el nombre del maximo es %s  con una cantidad de %f \n", nom_max, max_s);
}

int buscar(char dato[4], FILE *pf)
{
    int enc=0;
    rewind(pf);
    sueldo s;

    fread(&s,sizeof(s),1,pf);
    while(!feof(pf))
    {
        if(strcmp(dato,s.cod)==0)
        {
            enc=1;
        }
        fread(&s,sizeof(s),1,pf);
    }
    return enc;
}

void tot(FILE* pf)
{
    sueldo s;
    float c_a=0,c_t=0,c_d=0,c_e=0;
    int x;

    rewind(pf);

    fread(&s,sizeof(s),1,pf);
    while(!feof(pf))
    {
        if(s.cat=='a')
        {
          c_a+=s.cob;
        }
        if(s.cat=='t')
        {
          c_t+=s.cob;
        }
        if(s.cat=='d')
        {
          c_d+=s.cob;
        }
        if(s.cat=='e')
        {
          c_e+=s.cob;
        }
        fread(&s,sizeof(s),1,pf);
    }
    printf("cantidad total por catalogo... \nA:%f  \nT:%f  \nD:%f  \nE:%f\n",c_a,c_t,c_d,c_e);
}
