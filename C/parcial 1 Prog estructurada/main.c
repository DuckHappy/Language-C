#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int num;
    char nom[26];
    char sec;
    int porc;
    float com;
} vendedor;

// Funciones
void carga1(vendedor v[]);
int buscar(vendedor v[], int dato, int lim);
void carga2(vendedor v[], float m[][49]);
void mostrar(float m[][49], vendedor v[]);
void menor(vendedor v[]);
void punto3(vendedor v[]);

int main() {
    vendedor ven[50];
    float m[20][49] = {{0}}; // Declaración de matriz

    carga1(ven);
    carga2(ven, m);

    return 0;
}

void mostrar(float m[][49], vendedor v[]) {
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 49; y++)
        {
            printf("En el dia %d el vendedor %s su comision fue %f\n", x + 1, v[y].nom, m[x][y]);
        }
    }
}

void menor(vendedor v[])
{
    int ind = 0;
    float min = v[0].com;

    for (int x = 1; x < 49; x++)
    {
        if (min > v[x].com)
            {
            min = v[x].com;
            ind = x;
            }
    }
    printf("%s\n", v[ind].nom);
}

int buscar(vendedor v[], int dato, int lim)
{
    int x,ind=-1;

    for (int x = 0; x < lim; x++) {
        if (dato == v[x].num)
            {
            ind=x;
            x++;
            }else x++;
    }
    return ind;
}

void carga2(vendedor v[], float m[][49])
{
    int n_ven, ind=-1,x=0;
    float com;

    do {
        printf("Ingrese numero: ");
        scanf("%d", &n_ven);
        ind = buscar(v, n_ven, 50);
    } while (n_ven < 0 || n_ven > 99 || ind == -1);

    while (n_ven != 0)
        {
        do {
            printf("Ingrese comision a actualizar: ");
            scanf("%f", &com);
            } while (com < 0);

        v[ind].com = com;
        m[x][ind] += com;

        do {
            printf("Ingrese numero: ");
            scanf("%d", &n_ven);
            ind = buscar(v, n_ven, 50);
            } while (n_ven < 0 || n_ven > 99 || ind == -1);
    }
    mostrar(m, v);
    menor(v);
    punto3(v);
}

void carga1(vendedor v[]) {
    int n_ven, x = 0;

    do {
        printf("Ingrese numero: ");
        scanf("%d", &n_ven);
    } while (n_ven < 0 || n_ven > 99);

    while (n_ven != 0)
    {
        v[x].num=n_ven;
        getchar(); // Para limpiar el buffer
        printf("Ingrese nombre: ");
        fgets(v[x].nom, 26, stdin);
        v[x].nom[strcspn(v[x].nom, "\n")] = 0; // Elimina el salto de línea

        do {
            printf("Ingrese sector (e/m/v/t): ");
            scanf(" %c", &v[x].sec); // Espacio antes de %c para limpiar el buffer
        } while (v[x].sec != 'e' && v[x].sec != 'm' && v[x].sec != 'v' && v[x].sec != 't');

        do {
            printf("Ingrese porcentaje: ");
            scanf("%d", &v[x].porc);
        } while (v[x].porc < 5 || v[x].porc > 15);

        do {
            printf("Ingrese comision: ");
            scanf("%f", &v[x].com);
        } while (v[x].com < 0);

        x++;

        do {
            printf("Ingrese numero: ");
            scanf("%d", &n_ven);
        } while (n_ven < 0 || n_ven > 99);
    }
}

void punto3(vendedor v[]) {
    float impE = 0, impM = 0, impV = 0, impT = 0;

    for (int x = 0; x < 50; x++) {
        if (v[x].sec == 'e') {
            impE += v[x].com; // Sumar la comisión
        } else if (v[x].sec == 'm') {
            impM += v[x].com;
        } else if (v[x].sec == 'v') {
            impV += v[x].com;
        } else if (v[x].sec == 't') {
            impT += v[x].com;
        }
    }

    printf("Para el sector e: %f\n", impE);
    printf("Para el sector m: %f\n", impM);
    printf("Para el sector v: %f\n", impV);
    printf("Para el sector t: %f\n", impT);
}
