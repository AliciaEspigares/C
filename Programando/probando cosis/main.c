#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    x=1;
    while(x>0){
    printf("\nEscribe un numero: ");
    scanf("%d",&x);
    if(x<0){break;}
    printf("\nLos divisores son: ");
    for(y = x-1;y>0;y--){
        if(x%y==0){
            printf("%d ",y);
        }
    }
    }
    printf("El numero introducido era negativo");

    return 0;
}
