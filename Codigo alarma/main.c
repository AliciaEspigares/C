#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
 	int pin=1234;
    int comprobante;
	int n;
	char nombre='Alicia';
	printf("Introduce el pin: ");
	scanf("%d", & comprobante);
	if(pin==comprobante){
	
printf("\nPIN CORRECTO\n\nBienvenido/a %s. ¿Que desea realizar?\n 1 Ajustes\n 2 Salir", nombre);
	scanf("%d", &n);
	
	switch(n){
		case 1:
			printf("\n\nAJUSTES\n\n ¿Que deseas realizar?\n 1 Cambiar pin\n 2 Comprobar pin\n 3 Cambiar nombre\n 4 Salir" );
			
				switch(n){
			case 1:
				printf("Introduzca el nuevo pin");
				scanf("%s", & pin);
				break;
			case 2:
				printf("Su pin es %s", pin);
				break;
			case 3:
				printf("Introduzca su nombre");
				scanf("%s",&nombre);
				break;
			case 4:
				system("Pause");
				return 0;
			default:
			 	printf("Numero equivocado. Por favor introduzca de nuevo el número. ");
			 		printf("\n ¿Que deseas realizar?\n 1 Cambiar pin\n 2 Comprobar pin\n 3 Cambiar nombre\n 4 Salir" );
			
					switch(n){
				case 1:
					printf("Introduzca el nuevo pin");
					scanf("%s", & pin);
					break;
				case 2:
					printf("Su pin es %s", pin);
					break;
				case 3:
					printf("Introduzca su nombre");
					scanf("%s",&nombre);
					break;
				case 4:
					system("Pause");
					return 0;
				default:
			 		printf("Numero equivocado. Por favor introduzca de nuevo el número. ");
			 	}
			}
		break;
	
		case 2: 
		return 0;
		system("Pause");
		break;
		
		default :
			printf("Numero equivocado. Por favor marque otra vez el numero.");
				printf("\n ¿Que desea realizar?\n 1 Ajustes\n 2 Salir", nombre);
				scanf("%d", &n);
	
				switch(n){
					case 1:
						printf("\n\nAJUSTES\n\n ¿Que deseas realizar?\n 1 Cambiar pin\n 2 Comprobar pin\n 3 Cambiar nombre\n 4 Salir" );
			
					switch(n){
						case 1:
							printf("Introduzca el nuevo pin");
							scanf("%s", & pin);
							break;
						case 2:
							printf("Su pin es %s", pin);
							break;
						case 3:
							printf("Introduzca su nombre");
							scanf("%s",&nombre);
							break;
						case 4:
							system("Pause");
							return 0;
						default:
			 				printf("Numero equivocado. Por favor introduzca de nuevo el número. ");
			 				printf("\n\nAJUSTES\n\n ¿Que deseas realizar?\n 1 Cambiar pin\n 2 Comprobar pin\n 3 Cambiar nombre\n 4 Salir" );
							switch(n){
								case 1:
									printf("Introduzca el nuevo pin");
									scanf("%s", & pin);
									break;
								case 2:
									printf("Su pin es %s", pin);
									break;
								case 3:
									printf("Introduzca su nombre");
									scanf("%s",&nombre);
									break;
								case 4:
									system("Pause");
									return 0;
								default:
			 						printf("Numero equivocado. Por favor introduzca de nuevo el número. ");
							 	}
						}
					break;
	
					case 2: 
						return 0;
						system("Pause");
						break;
		
					default :
						printf("Numero equivocado. Por favor marque otra vez el numero.");
	}
	
	
}
	
	
}
	
	else printf("\nPIN ERRONEO");
	
	
	
	
	
	
	return 0;
}
