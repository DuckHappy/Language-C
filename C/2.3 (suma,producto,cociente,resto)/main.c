#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,suma,producto,cociente,res;

        //primer numero
        printf("first number : ");
        scanf("%d", &num1);

        //segundo numero
        printf("second number :");
        scanf("%d", &num2);

        //suma
        printf("\nsuma");
        suma=num1+num2;
        printf("\n%d+%d=%d", num1,num2,suma);

        //producto
        printf("\n\nproducto");
        producto=num1*num2;
        printf("\n%d*%d=%d", num1, num2, producto);

        //cociente
        printf("\n\ncociente");
        cociente=num1/num2;
        printf("\n%d/%d=%d", num1,num2,cociente);

        //resto
        printf("\n\nres");
        res=num1%cociente;
        printf("\n %d", res);



    return 0;
}
