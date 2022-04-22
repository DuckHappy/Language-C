#include <stdio.h>
#include <stdlib.h>

int main()
{
    //emp = empanadas , tabon = total a abonar , uni = unidad , doce = docena
    int emp,uni,doce,tabon;

    //empanadas
    printf("ingresa cantidad de empanaduchas : ");
    scanf("%d", &emp);

    //Docena
    doce=(emp/12)*300;
    scanf("(%d/12)300",emp);

    //unidad
    uni= emp%12*30;
    scanf("emp%12*30");

    //Total que abonar
    printf("\nTotal que abonar papi : ");
    tabon=doce+uni;
    printf("%d",tabon);


    return 0;
}
