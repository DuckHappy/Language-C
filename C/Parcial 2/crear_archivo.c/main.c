#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cod[4];
    char nom[31];
    char cat;
    float imp;
    float cob; // Este valor será calculado en el programa principal
} sueldo;

int main() {
    FILE *pf;
    sueldo s[5] = {
        {"001", "Juan Perez", 'a', 15.50, 200.0},
        {"002", "Maria Lopez", 't', 20.00, 400.0},
        {"003", "Carlos Ruiz", 'd', 10.00, 98.0},
        {"004", "Ana Torres", 'e', 25.00, 456.0},
        {"005", "Luis Gomez", 'a', 18.00, 567.0}
    };

    pf = fopen("personal.dat", "wb"); // Abrir el archivo en modo escritura binaria
    if (pf == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    // Escribir los registros en el archivo
    fwrite(s, sizeof(sueldo), 5, pf);

    fclose(pf); // Cerrar el archivo
    printf("Archivo personal.dat creado con éxito.\n");

    return 0;
}
