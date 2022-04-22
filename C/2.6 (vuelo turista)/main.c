#include <stdio.h>
#include <stdlib.h>

int main()
{
    //apasaj=pasajeros clase turista bpasaj=primera clase  pa=precio a  pb=precios b rtv=recaudacion total vuelo
    int apasaj, bpasaj, pa, pb, rtv;

    //pasajeros
    printf("Ingresar pasajeros clases turista :  ");
    scanf("%d", &apasaj);
    printf("Ingresar pasajeros clases turista :  ");
    scanf("%d", &bpasaj);

    //calculos de pasajes
    pa=apasaj*8800;
    pb=bpasaj*11440;

    //presentacion de pasajes al cliente
    printf("\n\nRecaudacion total de vuelo : ");
    rtv=pa+pb;
    printf("\n%d+%d=%d", pa,pb,rtv);

    return 0;
}
