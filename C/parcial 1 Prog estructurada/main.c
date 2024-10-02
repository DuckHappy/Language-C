#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de la estructura vendedor
typedef struct {
    int num;      // Número del vendedor
    char nom[26]; // Nombre del vendedor (máximo 25 caracteres)
    char sec;     // Sector al que pertenece (e, m, v, t)
    int porc;     // Porcentaje de comisión
    float com;    // Comisión total del vendedor
} vendedor;

// Declaración de funciones
void carga1(vendedor v[]);
int buscar(vendedor v[], int dato, int lim);
void carga2(vendedor v[], float m[][49]);
void mostrar(float m[][49], vendedor v[]);
void menor(vendedor v[]);
void punto3(vendedor v[]);

int main() {
    vendedor ven[50] = {0}; // Array de 50 vendedores
    float m[20][49] = {{0}}; // Matriz de comisiones para 20 días y 49 vendedores

    // Llamada a la función para cargar los vendedores
    carga1(ven);

    // Llamada a la función para cargar las ventas y actualizar comisiones
    carga2(ven, m);

    return 0;
}

// Función para mostrar las comisiones de los vendedores por día
void mostrar(float m[][49], vendedor v[]) {
    for (int x = 0; x < 20; x++) { // Recorrer los 20 días
        for (int y = 0; y < 49; y++) { // Recorrer los 49 vendedores
            printf("En el dia %d el vendedor %s su comision fue %f\n", x + 1, v[y].nom, m[x][y]);
        }
    }
}

// Función para encontrar el vendedor con la menor comisión
void menor(vendedor v[]) {
    int ind = 0; // Índice del vendedor con la menor comisión
    float min = v[0].com; // Asignar la comisión del primer vendedor como mínimo inicial

    // Comparar la comisión de cada vendedor
    for (int x = 1; x < 49; x++) {
        if (min > v[x].com) { // Si encuentra una comisión menor, actualiza el mínimo
            min = v[x].com;
            ind = x; // Guardar el índice del vendedor con la menor comisión
        }
    }
    printf("Vendedor con menor comision: %s\n", v[ind].nom);
}

// Función para buscar un vendedor por su número
int buscar(vendedor v[], int dato, int lim) {
    int x, ind = -1;

    // Recorrer todos los vendedores hasta encontrar el número
    for (int x = 0; x < lim; x++) {
        if (dato == v[x].num) { // Si el número coincide, devuelve el índice
            ind = x;
            x++;
        } else {
            x++;
        }
    }
    return ind; // Devuelve el índice o -1 si no se encontró
}

// Función para cargar las ventas y actualizar las comisiones
void carga2(vendedor v[], float m[][49]) {
    int n_ven, ind = -1, x = 0;
    float com;

    // Ingreso del número del vendedor
    do {
        printf("Ingrese numero de vendedor: ");
        scanf("%d", &n_ven);
        ind = buscar(v, n_ven, 50); // Busca el número de vendedor en la lista
    } while (n_ven < 0 || n_ven > 99 || ind == -1); // Valida que sea correcto

    // Repetir hasta que se ingrese el número 0 (fin de ingreso de ventas)
    while (n_ven != 0) {
        // Ingresar la comisión para actualizar
        do {
            printf("Ingrese comision a actualizar: ");
            scanf("%f", &com);
        } while (com < 0); // Validar que la comisión sea positiva

        v[ind].com = com; // Actualiza la comisión del vendedor
        m[x][ind] += com; // Almacena la comisión en la matriz por día y vendedor

        // Volver a pedir el número de vendedor
        do {
            printf("Ingrese numero: ");
            scanf("%d", &n_ven);
            ind = buscar(v, n_ven, 50);
        } while (n_ven < 0 || n_ven > 99 || ind == -1); // Validar el número de vendedor
    }

    // Mostrar las comisiones y los resultados
    mostrar(m, v);
    menor(v);
    punto3(v);
}

// Función para cargar los datos de los vendedores (número, nombre, sector, porcentaje y comisión)
void carga1(vendedor v[]) {
    int n_ven, x = 0, ind, band = 0;

    // Ingreso del número de vendedor
    do {
        band = 0;
        printf("Ingrese numero: ");
        scanf("%d", &n_ven);
        ind = buscar(v, n_ven, 49); // Busca si ya existe el número de vendedor

        if (ind != -1) {
            x = ind; // Si ya existe, usa ese índice
        }

        // Verificar si el número es correlativo al anterior
        if (v[x - 1].num - 1 == n_ven || v[x - 1].num + 1 == n_ven) {
            band = 1;
            printf("No cargado por ser correlativo con el anterior\n");
        }

    } while (n_ven < 0 || n_ven > 99 || band == 1); // Validar el número ingresado

    // Repetir hasta que se ingrese el número 0 (fin de carga)
    while (n_ven != 0) {
        v[x].num = n_ven; // Asignar el número al vendedor
        getchar(); // Limpiar el buffer de entrada

        // Ingresar el nombre del vendedor
        printf("Ingrese nombre: ");
        fgets(v[x].nom, 26, stdin);
        v[x].nom[strcspn(v[x].nom, "\n")] = 0; // Elimina el salto de línea del nombre

        // Ingresar el sector del vendedor, validando que sea una opción válida
        do {
            printf("Ingrese sector (e/m/v/t): ");
            scanf(" %c", &v[x].sec); // Espacio antes de %c para limpiar el buffer
        } while (v[x].sec != 'e' && v[x].sec != 'm' && v[x].sec != 'v' && v[x].sec != 't');

        // Ingresar el porcentaje de comisión, validando que esté entre 5 y 15
        do {
            printf("Ingrese porcentaje: ");
            scanf("%d", &v[x].porc);
        } while (v[x].porc < 5 || v[x].porc > 15);

        // Ingresar la comisión, validando que sea positiva
        do {
            printf("Ingrese comision: ");
            scanf("%f", &v[x].com);
        } while (v[x].com < 0);

        x++; // Avanza al siguiente vendedor

        // Repetir la verificación para el próximo vendedor
        do {
            band = 0;
            printf("Ingrese numero: ");
            scanf("%d", &n_ven);
            ind = buscar(v, n_ven, 49);

            if (ind != -1) {
                x = ind; // Si ya existe, usa ese índice
            }

            // Verificar si el número es correlativo al anterior
            if (v[x - 1].num - 1 == n_ven || v[x - 1].num + 1 == n_ven) {
                band = 1;
                printf("No cargado por ser correlativo con el anterior\n");
            }

        } while (n_ven < 0 || n_ven > 99 || band == 1);
    }
}

// Función para calcular el importe total por sector
void punto3(vendedor v[]) {
    float impE = 0, impM = 0, impV = 0, impT = 0;

    // Recorrer todos los vendedores y sumar las comisiones por sector
    for (int x = 0; x < 50; x++) {
        if (v[x].sec == 'e') {
            impE += v[x].com; // Sumar la comisión para sector electrodomésticos
        } else if (v[x].sec == 'm') {
            impM += v[x].com; // Sumar la comisión para sector muebles
        } else if (v[x].sec == 'v') {
            impV += v[x].com; // Sumar la comisión para sector vajillas
        } else if (v[x].sec == 't') {
            impT += v[x].com; // Sumar la comisión para sector telefonía
        }
    }

    // Imprimir los resultados por sector
    printf("Para el sector e: %f\n", impE);
    printf("Para el sector m: %f\n", impM);
    printf("Para el sector v: %f\n", impV);
    printf("Para el sector t: %f\n", impT);
}
