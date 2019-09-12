#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h> 
#define TAMMAX 50

// Declaración de las estructuras a usar en la práctica
typedef struct direccion{
	char calle[TAMMAX];
	int c_postal;
	char ciudad[TAMMAX];
    char provincia[TAMMAX];
    char pais[TAMMAX];
}direccion;

typedef struct contacto{
	int telefono;
    char mail[TAMMAX];
 }contacto;

typedef struct amigo{
	char nombre[TAMMAX];
	int dni;
	direccion direcc;
	contacto contact;
	int dia, mes, anyo; // cumpleaños 	
}amigo;

// Declaración de la variable fpdatos de forma global para abrir y cerrar ficheros
FILE* fpdatos;
