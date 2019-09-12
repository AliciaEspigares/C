#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int aux=1;

    //Si eleccionprograma no le devuelve un 1, para de ejecutarse el bucle, parando así el programa
    while (aux==1){
        aux = eleccionprograma();
    }

}

int eleccionprograma()
{
    /**< Muestra los programas disponibles, lee el número elegido y te redirige al programa correspondiente */
    int tammax = sizeof(char);
char b[tammax];
int a ;
long int n;
    printf("MENU PRINCIPAL\n1.- Programa 1\n2.- Programa 2\n3.- Programa 3\n4.- Programa 4\n5.- Programa 5\n6.- Programa 6\n0.- Salir\nElegir opcion:");
    int programa;
    scanf("%i",&programa);

    switch (programa){
    case 1:

        printf("Ha elegido el programa numero 1\n\n");
        printf("Este programa le devuelve el numero de digitos de un numero.\n\nCUIDADO: No introducir un numero de mas de 10 digitos\n\n");
        printf("Introduzca el numero:");
        scanf("%d", &n);
        a=NumDigitos(n);
        printf("Numero de digitos= %u\n", a);
        printf("___________________________________\n\n\n");
        return 1;
    case 2:
        printf("Ha elegido el programa numero 2\n\n");
        printf("Este programa convierte un numero de base 2 a base 10.\n\n");
        printf("Introduzca el numero:");
        int i;
        for(int i=0;b!='\n';i++){
            b[i]=getchar();
        }
        int dec=ConvierteBase10((int)b,i);
         if (dec==-1){printf("El numero introducido no es base 2. Por favor, intentelo de nuevo.\n");}
        else{
        printf("Numero en base 2= %u. Numero en base 10=%u.\n", n,dec);
        printf("___________________________________\n\n\n");
        }
        return 1;
    case 3:
        printf("Ha elegido el programa numero 3\n\n");
        return 1;
    case 4:
        printf("Ha elegido el programa numero 4\n\n");
        return 1;
    case 5:
        printf("Ha elegido el programa numero 5\n\n");
        return 1;
    case 6:
        printf("Has elegido el programa numero 6\n\n");
        return 1;
    case 0:
        printf("Ha elegido salir\n\n");
        return 0;
    default: //No funciona con letras
        printf("El numero de programa no es correcto. Por favor, intentelo de nuevo.\n\n");
        return 1;

    }

}

int NumDigitos(numero){
short int a=1;
int c=numero;
while(c>=10){
c=c/10;
a++;
}
return a;
}

int ConvierteBase10(n,total){
    int dec=0;
    int *p=NULL;
    p = (int *)malloc(sizeof(n));
    for(int i=0; i<total;i++){
            p=&n[i];
        if (p!=1||p!=0){
                printf("El numero introducido no es base 2. Por favor, intentelo de nuevo.\n");
        }
        else{
                dec=dec+(2^(total-i));
        }
    }
    return dec;

    /*int con=0;


    for(int i=0; i++; i<n){

        if (p[i]==0 || p[i]==1){
            printf("chi");
        return -1;
        }
    }
    else{
        int dig=NumDigitos(n)-1;
        while(dig>=0){
            if(n>=pow(10,dig)){
                con=con+pow(2,dig);
        printf("num=%ld,dig=%d, con=%d\n",n,dig,con);
            }
            n=n-pow(10,dig);
            dig--;
        }
        return con;
    }*/
}
