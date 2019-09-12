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
	//printf("\nNombre: %s\n",a->nombre);
	//printf("DNI: %d\n",a->dni);
	//printf("Direccion-> %s, %d %s (%s), %s\n",a->direcc.calle,a->direcc.c_postal,a->direcc.ciudad, a->direcc.provincia, a->direcc.pais);
	//printf("Contacto-> Teléfono: %d - email: %s\n",a->contact.telefono,a->contact.mail);
   // printf("Fecha de nacimiento: %d/%d/%d\n",a->dia, a->mes, a->anyo);
   // printf("termina la clase");


}

// Devuelve 1 si nuevo_amigo se encuentra en la lista (se usan los dnis para comprobarlo)
int ComprobarLista(amigo* lista_amigos, amigo nuevo_amigo, int n_amigos)
{
  int i;
  amigo lista_dos;

    for(i=0; i < n_amigos; i++){
       lista_dos = lista_amigos[i];
       if(lista_dos.dni==nuevo_amigo.dni){
        return 1;
       }
    }
         return 0;

}

int LongitudCadena (char *cadena)
{
    int j=0;
    while (cadena[j] != '\0') {j++;}
    return j;
}
// Elimina a aquel amigo de la base de datos cuyo campo indicado (dni, email o año de nacimiento)
// coincida con el introducido como siguiente parámetro
// La función devolverá el nuevo número de amigos
int BorrarDatos(amigo* lista_amigos, int n_amigos, char *campo, char *valor)
{
  int i;
  amigo lista_dos;
  int amigosborrados=0;
  ///////////SI EL CAMPO ES DNI

  if (strcmp(campo, "dni")==0){
    if(LongitudCadena(valor)== 8){ //Comprobamos que el dni está bien introducido

    //////////Convierte cadena de carácteres a int
    int numero=valor[0]-'0'; //Convierte el primer carácter a int
    for(int i =0; i<7; i++){
       numero= numero*10+(valor[i+1]-'0'); //convierte la cadena de carácteres a int
    }
    /////////Lee los amigos uno por uno y comprueba si su dni es igual al introducido
    for(i=0; i < n_amigos; i++){
       lista_dos = lista_amigos[i];
       if(lista_dos.dni==numero){ //Comprueba si el dni es igual
            amigosborrados++;
            for(int x=0; x<(n_amigos-i);x++){ //Borra el amigo
                   lista_amigos[i+x]=lista_amigos[i+1+x];
            }
            printf("\nAmigo %s eliminado con exito mediante el campo %s con valor %s.",lista_dos.nombre,campo, valor);
       }
    }
    if(amigosborrados==0){
        printf("Ningun amigo ha sido eliminado de la base de datos.\n");
        return n_amigos;
    }
    else{
    printf("\nHan sido eliminados %d amigos de la base de datos.\n",amigosborrados);
    return n_amigos-amigosborrados;
    }
  }
  else {
    printf("\nERROR: No ha escrito el dni correctamente. Escriba los 8 dígitos del dni sin letra.\n");
    return n_amigos;
  }
  }

///////////SI EL CAMPO ES EMAIL
    if (strcmp(campo, "email")==0){
    for(i=0; i < n_amigos; i++){
       lista_dos = lista_amigos[i];
       if(strcmp(lista_dos.contact.mail,valor)==0){
            amigosborrados++;
            for(int x=0; x<(n_amigos-i);x++){
                   lista_amigos[i+x]=lista_amigos[i+1+x];
            }
            printf("\nAmigo %s eliminado con exito mediante el campo %s con valor %s.\n",lista_dos.nombre,campo, valor);
       }
    }
    if(amigosborrados==0){
        printf("\nNingun amigo ha sido eliminado de la base de datos.\n");
        return n_amigos;
    }
    else{
    printf("\nHan sido eliminados %d amigos de la base de datos.\n",amigosborrados);
    return n_amigos-amigosborrados;
    }

  }
///////////SI EL CAMPO ES YEAR
  if (strcmp(campo, "year")==0){
  ///////////Convierte cadena de carácteres a int
  if(LongitudCadena(valor)== 4){
    int numero=valor[0]-'0'; //Convierte el primer carácter a int
    for(int i =0; i<3; i++){
       numero= numero*10+(valor[i+1]-'0'); //convierte la cadena de carácteres a int
    }

    for(i=0; i < n_amigos; i++){;
       lista_dos = lista_amigos[i];


       if(lista_dos.anyo==numero){
            amigosborrados++;
            for(int x=0; x<(n_amigos-i);x++){
                   lista_amigos[i+x]=lista_amigos[i+1+x];
            }
            printf("\nAmigo %s eliminado con exito mediante el campo %s con valor %s.\n",lista_dos.nombre,campo, valor);
       }
    }
    if(amigosborrados==0){
        printf("Ningun amigo ha sido eliminado de la base de datos.\n");
        return n_amigos;
    }
    else{
     printf("Han sido eliminados %d amigos de la base de datos.\n",amigosborrados);
     return n_amigos-amigosborrados;
    }
  }
  else {printf("\nERROR: No ha escrito el año correctamente. Escriba los 4 dígitos del año sin añadir ningún otro carácter.\n");}
  }
}



// Esta función mostrará agrupará los amigos por país y código postal
// mostrará el nombre de cada amigo que pertenece a cada país y dentro de este por código postal
void AgruparAmigos(amigo* lista_amigos, int n_amigos)
{
char pais[TAMMAX];
char cadena[n_amigos-1];

int res=0;
amigo lista_nueva;
amigo lista_nueva2;
amigo lista_nueva3;
//////Hacemos un array de 1
for(int p=0; p<n_amigos;p++){
    cadena[p]='1';
}

for(int i=0; i<n_amigos; i++){
    lista_nueva=lista_amigos[i];
    int t=0;
    int q=0;
    printf("\n%s",lista_nueva.direcc.pais);
    pais[(i-res)]=lista_nueva.direcc.pais[i];
    while(t<(i-res)){
        if(strcmp(lista_nueva.direcc.pais,pais[t])==0){
            res++;
            q=1;
            pais[i]=pais[i+1];
            break;
        }
        else{
            t++;
        }
    }

    if(q==0){
        for(int a=0; a<n_amigos; a++){
            lista_nueva2=lista_amigos[a];
            if(strcmp(lista_nueva2.direcc.pais,lista_nueva.direcc.pais)==0 && cadena[a]=='1'){
                cadena[a]='0';
                printf("\n                    %d",lista_nueva2.direcc.c_postal);
                printf("\n                                        %s",lista_nueva2.nombre);
                for(int m=a+1; m<n_amigos; m++){
                    //printf("entro en el 3er bucle");
                    lista_nueva3=lista_amigos[m];
                    if(strcmp(lista_nueva3.direcc.pais,lista_nueva.direcc.pais)==0 && cadena[m]=='1'){
                        //printf("Pais es igual ");

                        if(lista_nueva3.direcc.c_postal==lista_nueva2.direcc.c_postal){
                            //printf("Codigo postal es igual");
                            cadena[m]='0';
                            printf("\n                                        %s",lista_nueva3.nombre);

                        }
                    }
                }
            }
        }
    }
}
}
