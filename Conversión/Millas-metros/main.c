#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int unidad;
	float distancia;
	float resultado;
	char a;
	char b[7];
	
	printf("Escriba a continuacion la distancia: ");
	scanf("%f", & distancia);
	
	printf("\nEn que unidades ha escrito la distancia? 1=millas 2=metros\n;");
	scanf("%d", & unidad);
	
	if( unidad==1){
		resultado=distancia*1852;
		a=="metros";
		b=="millas";
	}
	
	else {resultado=distancia/1852 ;
	 a=='millas';
	  b=='metros';}
	  
	
	
	printf("%f %s son %f %s", distancia, b,resultado,a );
	
	
	
	
	
	
	return 0;
}
