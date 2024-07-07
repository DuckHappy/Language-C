/*
1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definir un array para almacenar las cantidades de cada producto
    int cantidades[10] = {0}; // Inicializamos todas las cantidades a cero

    int codigoProducto, cantidad;

    // Entrada de pedidos
    printf("Ingrese el codigo del producto (0 para finalizar): ");
    scanf("%d", &codigoProducto);

    while (codigoProducto != 0) {
        if (codigoProducto < 1 || codigoProducto > 10) {
            printf("Codigo de producto invalido. Debe estar entre 1 y 10.\n");
        } else {
            printf("Ingrese la cantidad de unidades solicitadas: ");
            scanf("%d", &cantidad);
            cantidades[codigoProducto - 1] += cantidad; // Restamos 1 para que el índice comience desde 0
        }

        printf("Ingrese el codigo del producto (0 para finalizar): ");
        scanf("%d", &codigoProducto);
    }

    // Emitir listado de pedidos
    printf("\nListado de pedidos recibidos:\n");
    printf("Codigo\tCantidad\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\t%d\n", i + 1, cantidades[i]); // Sumamos 1 al índice para obtener el código del producto
    }

    return 0;
}
