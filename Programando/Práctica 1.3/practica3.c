#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include "practica3.h"

// Prototipos de las funciones
void MostrarDatos(amigo a);
void LeerAmigoFichero(amigo *a);
void EscribirAmigoFichero(amigo a);
int ComprobarLista(amigo* lista_amigos, amigo nuevo_amigo, int n_amigos);
int ComparaFechas(amigo am, int margendias);
int BorrarDatos(amigo* lista_amigos, int n_amigos, char *campo, char *valor);
void AgruparAmigos(amigo* lista_amigos, int n_amigos);

// ************************ MAIN **********************
// ****************************************************
int main(int argc, char *argv[])
{
    // Declaraci�n de variables
    int n_amigos;
	int i, res;
    amigo *pamigos;
    amigo nuevo_amigo;
    char temp[TAMMAX];
    setlocale(LC_CTYPE, "Spanish");

    //Leer los amigos de la base de datos y cargarlos en memoria
    fpdatos = fopen("basedatos.txt","r");
        if (fpdatos == NULL)
        {
        printf("No ha sido posible abrir la base de datos\n");
        return -1;
        }
   	fscanf(fpdatos,"%d", &n_amigos); // Lee el n�mero de amigos del fichero

   	/////////////////////////////////////
   //	LeerAmigoFichero(&nuevo_amigo);
   //	return(-1);
   	////////////////////////////////////


    if(n_amigos==0){
         printf("\nNo hay amigos en la base de datos");
         pamigos=NULL;
    }
    else{
         printf("\nLeyendo %d amigos de la base de datos.\n", n_amigos);
         // Reserva din�mica de memoria para almacenar al n�mero de amigos que contenga la base de datos
         pamigos = (amigo*)malloc(n_amigos*sizeof(amigo));
         for(i=0; i < n_amigos; i++)
                  LeerAmigoFichero(&pamigos[i]); // Esta funci�n leer� un �nico amigo cada vez
    }
    fclose(fpdatos);

    // Una vez leida la base de datos comenzaremos a comprobar el comando introducido para ejecutar la opci�n deseada
    if(argc < 2)
    {
      printf("\nOpcion incorrecta:\nUso:\npractica3.exe [opcion] [parametro]\n");
      return -1;
    }
    else if(strcmp(argv[1],"add")==0)
    {
         //Abrimos fichero de entrada con el nuevo amigo
         fpdatos = fopen(argv[2],"r");
            if (fpdatos == NULL)
            {
            printf("No ha sido posible abrir el fichero indicado\n");
            return -1;
            }
         LeerAmigoFichero(&nuevo_amigo); // Leemos al nuevo amigo
         fclose(fpdatos);
         res=ComprobarLista(pamigos, nuevo_amigo, n_amigos); //comprobar si est� en la lista, 1 si esta, 0 si no est�
         if(!res) // En caso de no estar lo a�ade
         {
                 n_amigos++; //un nuevo amigo
                 pamigos =(amigo*)realloc(pamigos, n_amigos*sizeof(amigo));
                 pamigos[n_amigos-1]=nuevo_amigo;
                 printf("\nNueva entrada a�adida con exito\n");
         }
         else
         {
             printf("La persona ya se encuentra en la base de datos\n");
            }
    }
    else if(strcmp(argv[1],"del")==0)
    {
        // Se llama a la funci�n borrar para comprobar si alg�n amigo
        // de la base de datos coincide con el telefono introducido
        // El amigo se eliminar� de la variable pamigos dentro de la funci�n
        // La funci�n devolver� el nuevo n�mero de amigos
        n_amigos=BorrarDatos(pamigos, n_amigos,argv[2],argv[3]);
    }
    else if(strcmp(argv[1],"show")==0)
    {
         for(i=0; i < n_amigos; i++)
              MostrarDatos(pamigos[i]); // Muestra los amigo uno a uno

         // En este caso, puesto que s�lo se ha mostrado la base de datos sin hacer modificaciones,
         // no ser� necesario escribirla de nuevo, por lo tanto, se finaliza la ejecuci�n
         return 0;
    }
    else if(strcmp(argv[1],"check")==0)
    {
        // Comprueba si el cumplea�os de algun amigo ser� en los pr�ximos 7 d�as
         for(i=0; i < n_amigos; i++)
         {
           res = ComparaFechas(pamigos[i], 7);
           if(res)
                   MostrarDatos(pamigos[i]); // En caso afirmativo muestra su informaci�n
         }
         // En este caso, puesto que s�lo se muestra informaci�n de la base de datos sin hacer modificaciones,
         // no ser� necesario escribirla de nuevo, por lo tanto, se finaliza la ejecuci�n
         return 0;
    }
    else if(strcmp(argv[1],"group")==0)
    {
        AgruparAmigos(pamigos,n_amigos);
         // En este caso, puesto que s�lo se muestra informaci�n de la base de datos sin hacer modificaciones,
         // no ser� necesario escribirla de nuevo, por lo tanto, se finaliza la ejecuci�n
         return 0;
        }
    else
    {
        printf("La opcion introducida (%s) no est� contemplada\n",argv[1]);
        return -1;
        }

    // Una vez finalicen las acciones, en algunos de los casos ser� necesario volver a escribir la base de datos
    // Escribir los datos ya procesados en el fichero sustituyendo la base de datos anterior
    fpdatos = fopen("basedatos.txt","w");
        if (fpdatos == NULL)
        {
        printf("No ha sido posible abrir la base de datos\n");
        return -1;
        }
   	fprintf(fpdatos,"%d", n_amigos); // Escribe el n�mero actualizado de amigos
    for(i=0; i < n_amigos; i++)
               EscribirAmigoFichero(pamigos[i]); // Va escribiendo la informaci�n de cada amigo uno a uno
    fclose(fpdatos);


	free(pamigos); //Liberamos memoria
}



//Compara la fecha actual con el cumplea�os del amigo
//devuelve 1 si faltan menos de margendias para la fecha
int ComparaFechas(amigo am, int margendias)
{
   int dia, mes;
   time_t rawtime;
   struct tm * timeinfo;
   int dias1, dias2;

   dia = am.dia;
   mes = am.mes;


  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  //Obtenemos el dia del a�o de hoy de la estructura
  dias1 =   timeinfo->tm_yday;

  //Cambiamos los datos para el mes del amigo
  timeinfo->tm_mon = mes - 1;
  timeinfo->tm_mday = dia;

  mktime(timeinfo); //tm_yday se

   //Obtenemos el dia del a�o de la fecha del amigo
  dias2 = timeinfo->tm_yday;

  // Si faltan menos de margend�as y la fecha no es pasada
  if((dias2-dias1 < margendias)&&(dias2-dias1 >= 0))
                 return 1;

  return 0;
}

// Escribe una amigo en la base de datos
void EscribirAmigoFichero(amigo a)
{
    //***************************************************************************
    fprintf(fpdatos,"\n%s\n",a.nombre);
	fprintf(fpdatos,"%d\n",a.dni);
	fprintf(fpdatos,"%s\n",a.direcc.calle);
	fprintf(fpdatos,"%d\n",a.direcc.c_postal);
	fprintf(fpdatos,"%s\n",a.direcc.ciudad);
	fprintf(fpdatos,"%s\n",a.direcc.provincia);
	fprintf(fpdatos,"%s\n",a.direcc.pais);
	fprintf(fpdatos,"%d\n",a.contact.telefono);
	fprintf(fpdatos,"%s\n",a.contact.mail);
	fprintf(fpdatos,"%d %d %d\n",a.dia, a.mes, a.anyo);
    //***************************************************************************
}

//Muestra todos los datos de un amigo
void MostrarDatos(amigo a)
{
	printf("\nNombre: %s\n",a.nombre);
	printf("DNI: %d\n",a.dni);
	printf("Direccion-> %s, %d %s (%s), %s\n",a.direcc.calle,a.direcc.c_postal,a.direcc.ciudad, a.direcc.provincia, a.direcc.pais);
	printf("Contacto-> Tel�fono: %d - email: %s\n",a.contact.telefono,a.contact.mail);
    printf("Fecha de nacimiento: %d/%d/%d\n",a.dia, a.mes, a.anyo);
}
