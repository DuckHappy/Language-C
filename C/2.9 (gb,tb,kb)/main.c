#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kib,mib,gib,tib;

    //KIB
    printf("Numero Kib : ");
    scanf("%f",&kib);

    //MIB
    printf("\nMib : ");
    mib = kib/1024;
    printf("%f/1024=%f",kib,mib);

    //GIB
    printf("\n\nGib : ");
    gib = mib/1024;
    printf("%f/1024=%f",mib,gib);

    //TIB
    printf("\n\nTib : ");
    tib = gib/1024;
    printf("%f/1024=%f",gib,tib);

    return 0;
}
