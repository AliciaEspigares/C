#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int cod =123;
    int cad=0;


    while(1){
    printf("Introduce el codigo: ");
    scanf("%d",&cad);
    if(cod==cad){
         printf( "El codigo es correcto.");
         break;
    }
    else{
    printf( "El codigo es incorrecto.\n");}

    }

    return 0;
}
