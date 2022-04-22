#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota1, nota2, promedio;

    //se ingresa la primera nota
    printf("Nota de Pepe : ");
    scanf("%d", &nota1);

    //se ingresas la segunda nota
    printf("Nota de juancito : ");
    scanf("%d", &nota2);

    //se realiza promedio
    printf("\npromedio");
    promedio=(nota1+nota2)/2;

    //se lo presenta al cliente
    printf("\n\n(%d+%d)/2=%d", nota1, nota2,promedio);

    return 0;
}
