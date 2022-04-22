#include <stdio.h>
#include <stdlib.h>

int main()
{
    //pi=precio inicial   des=descuento  cod=codigo  pf=precio final
    float pi,des,pf;
    int cod;

        //primero ingresa precio de producto
        printf("Precio de producto : ");
        scanf("%f", &pi);

        //el codigo 1 o 0
        printf("Codigo :");
        scanf("%d", &cod);

            //que sucede en las dos situaciones (1 , 0)

                //que sucede con 1
            if (cod==1)

            {
                printf ("\nProducto Con Descuento :");
                des=(pi*20)/100;
                pf=pi-des;
                printf("%0.2f",pf);

            } else {

                //que sucede con 0
                printf ("\nSin descuento :");
                pf=pi;
                printf("%0.2f",pf);

                   }

return 0;
}
