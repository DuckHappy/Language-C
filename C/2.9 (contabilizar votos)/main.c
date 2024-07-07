/*
2.9 Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol. Existen 10 candidatos cada
uno representado por un número de lista diferente (número de 3 cifras no correlativo). La votación se realiza
en 15 sedes distintas codificadas del 1 al 15. Se ingresan los votos registrados en cada una de las sedes
registrando:
• Número de lista
• Número de sede
• Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
LISTA SEDE1 SEDE2 SEDE3… SEDE15
873 36 78 99… XX
735 XX XX XXX… XX
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
TOTAL DE VOTOS PORCENTAJE LISTA
800 80% 873
200 20% 735
c. Candidatos que NO recibieron votos en la sede 5.
*/
#include <stdio.h>
#include <stdlib.h>

int buscarind(int[],int,int);
void cargarvec(int[],int,int);


int main()
{
    int n_list,n_sed,c_vot,res,x=0,y,ind;
    int cand_sed[10][15]={{0}},v_sed[10]={0},v_list[10]={0};

    do
        {
        printf("ingrese cantidad de voto [positivo] : ");
        scanf("%d",&c_vot);

        }while(c_vot<0);
    while(c_vot!=0)
        {
        do
            {
            printf("numero de lista de candidato [de 3 digitos] ");
            scanf("%d",&n_list);

            res=n_list/100;

            }while(res<0 || n_list<0 || n_list>1000);

        do
            {
            printf("numero de numero de sede [de 1 a 15] ");
            scanf("%d",&n_sed);

            }while(n_sed<0 || n_sed>15);

            v_list[x]==n_list;
            x++;


            ind=buscarind(v_list,n_list,10);
            cand_sed[x][n_sed-1]+=c_vot;

            if(n_sed==5)
                {
                v_sed[ind-1]+=c_vot;
                }

        do
        {
        printf("ingrese cantidad de voto [positivo] : ");
        scanf("%d",&c_vot);

        }while(c_vot<0);

        }

        for(x=0;x<10;x++)
            {
            printf("%d\n",v_list[x]);

            }

        for(x=0;x<10;x++)
            {
            printf("%d\n",v_list[x]);
            for(y=0;y<15;y++)
                {
                printf("sede %d \t",y);
                printf("%d",cand_sed[x][y]);
                }
            }
        for(x=0;x<10;x++)
            {
            if(v_sed[x]==0)
                {
                printf("\ncandidato que no recibio votos de la sede 5 : %d\n",v_sed[x]);
                }

            }


    return 0;
}

int buscarind(int v[], int dato, int lim)
{
    int x,ind=-1;

    while(x<lim && ind==-1)
        {
        if(v[x]==dato || dato==0)
            {
            ind=x;
            }else x++;
        }
return ind;
}


