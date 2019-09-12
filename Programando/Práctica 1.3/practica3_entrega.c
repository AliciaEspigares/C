// Alicia Espigares Erades 74443776-K
#include "practica3.h"

//Lee todos los datos de un amigo
void LeerAmigoFichero(amigo* a)
{
  char temp[TAMMAX];
//Leemos la primera línea que contiene el número de personas que contiene la lista
    fgets(temp, TAMMAX, fpdatos);
//Leemos el nombre
    fgets(a->nombre, TAMMAX, fpdatos); //Leemos el nombre que hay escrito en basedatos.txt
    a->nombre[strlen(a->nombre)-1]='\0'; //Para que al leer el nombre no nos coja el \n
//Leemos el DNI
    fgets(temp, TAMMAX, fpdatos);//Leemos el dni que hay escrito en basedatos.txt
    a->dni=atoi(temp);//Convierte el dato en int
//Leemos la dirección
    //CALLE
    fgets(a->direcc.calle, TAMMAX, fpdatos); //Leemos la calle que hay escrita en basedatos.txt
    a->direcc.calle[strlen(a->direcc.calle)-1]='\0'; //Para que al leer la calle no nos coja el \n
    //CÓDIGO POSTAL
    fscanf(fpdatos,"%d\n",&a->direcc.c_postal); //Leemos el código postal
    //CIUDAD
    fgets(a->direcc.ciudad, TAMMAX, fpdatos);
    a->direcc.ciudad[strlen(a->direcc.ciudad)-1]='\0';
    //PROVINCIA
    fgets(a->direcc.provincia, TAMMAX, fpdatos);
    a->direcc.provincia[strlen(a->direcc.provincia)-1]='\0';
    //PAIS
    fgets(a->direcc.pais, TAMMAX, fpdatos);
    a->direcc.pais[strlen(a->direcc.pais)-1]='\0';
//Leemos el contacto
    //TELEFONO
    fgets(temp, TAMMAX, fpdatos);
    a->contact.telefono=atoi(temp);
    //CORREO
    fgets(a->contact.mail, TAMMAX, fpdatos);
    a->contact.mail[strlen(a->contact.mail)-1]='\0';
//Leemos la fecha de nacimiento
	fscanf(fpdatos,"%d %d %d",&a->dia, &a->mes, &a->anyo);
    fgets(temp, TAMMAX, fpdatos);
//Imprimimos por pantalla todos los datos
	printf("\nNombre: %s\n",a->nombre);
	printf("DNI: %d\n",a->dni);
	printf("Direccion-> %s, %d %s (%s), %s\n",a->direcc.calle,a->direcc.c_postal,a->direcc.ciudad, a->direcc.provincia, a->direcc.pais);
	printf("Contacto-> Teléfono: %d - email: %s\n",a->contact.telefono,a->contact.mail);
    printf("Fecha de nacimiento: %d/%d/%d\n",a->dia, a->mes, a->anyo);


}


// Devuelve 1 si nuevo_amigo se encuentra en la lista (se usan los dnis para comprobarlo)
int ComprobarLista(amigo* lista_amigos, amigo nuevo_amigo, int n_amigos)
{
    char temp[TAMMAX];
     fgets(temp, TAMMAX, fpdatos);
     fgets(temp, TAMMAX, fpdatos);
     fscanf(fpdatos,"%d\n",&nuevo_amigo.dni); //Leemos el código postal
     printf("DNIamigui: %d\n",nuevo_amigo.dni);
     return 1;

}

// Elimina a aquel amigo de la base de datos cuyo campo indicado (dni, email o año de nacimiento)
// coincida con el introducido como siguiente parámetro
// La función devolverá el nuevo número de amigos
int BorrarDatos(amigo* lista_amigos, int n_amigos, char *campo, char *valor)
{
    //***************************************************************************
    //CÓDIGO A ESCRIBIR POR EL ALUMNO


        //***************************************************************************
}

// Esta función mostrará agrupará los amigos por pais y año de nacimiento
// mostrará el nombre de cada amigo que pertenece a cada país y dentro de este por año de nacimiento
void AgruparAmigos(amigo* lista_amigos, int n_amigos)
{
    //***************************************************************************
    //CÓDIGO A ESCRIBIR POR EL ALUMNO

    //***************************************************************************
}
