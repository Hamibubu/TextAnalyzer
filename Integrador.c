#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define menu printf("\n1)Introducir texto \n2)Desplegar estadisticas\n3)Desplegar pronombres encontrados\n4)Desplegar todas las palabras que comienzan con mayúsculas\n5)Desplegar los verbos en gerundio\n6)Buscar una palabra en el texto\n7)Intercambiar mayúsculas y minúsculas\n8)SALIR\n\nTecleé la opcion deseada: ")
#define tam 255

int Estadistica(char cadena[], int *vocales, int *parrafos, int *consonantes, int *espacio);
int Pronombres(char cadena[]);
int Mayusculas(char cadena[]);
int Gerundio(char cadena[]);
int Separa(char cadena[]);
int Busca(char cadena[]);
int Intercambia(char cadena[]);
int menuP();


int main(void){
  int MP, miParrafos, miVocales, miConsonantes, miEspacio;
  char texto [tam];
  
  do{
    MP = menuP();
    switch(MP){
      case 1:
        printf("\e[1;1H\e[2J");
        printf("Tecleé un texto (255 caracteres máximo): ");
        gets(texto);
        fgets(texto,tam,stdin);
        break;    
      case 2: ;
              printf("El número de caracteres de tu cadena es de %d \n", strlen(texto));
        Estadistica(texto, &miVocales, &miParrafos, &miConsonantes, &miEspacio);
              printf("El número de vocales que tiene la cadena %s es: %d\n",texto, miVocales);
              printf("El número de consonantes que tiene la cadena %s es: %d\n",texto, miConsonantes);
            printf("El número de palabras que tiene la cadena %s es: %d\n",texto, miEspacio);
              printf("El número de parrafos que tiene la cadena %s es: %d\n",texto, miParrafos);
              break;
      case 3:Pronombres(texto);
              break;
      case 4: Mayusculas(texto);
              break;   
      case 5: Separa(texto);
              break;
      case 6: printf("\e[1;1H\e[2J"); Busca(texto);
              break;
      case 7: Intercambia(texto);
              break;   
    }
    } while (MP!=8); 
  return 0;
  
}
int menuP(){
  int opcion;
  do{
    menu;
    scanf("%d", &opcion);
    if(opcion>8 || opcion<1) printf("Opción NO válida.\n");
    } while (opcion<1 || opcion>8);
      return opcion;
        }


//Estadisticas
//Contar vocales
int Estadistica(char cadena[], int *vocales, int *parrafos, int *consonantes, int *espacio){
	*parrafos=1;
  *vocales=0;
  *consonantes=0;
  *espacio=1;
  
	// Recorrer toda la cadena
	for (int indice = 0; cadena[indice] != '\0'; ++indice){

		// Obtener el char de la posición en donde está el índice
		// y por otro lado convertirla a minúscula

		// Así no importa si ponen 'A' o 'a', ambas letras serán convertidas a 'a'
		char letraActual = tolower(cadena[indice]);
		if (letraActual == 'a' || letraActual == 'e' || letraActual == 'i' || letraActual == 'o' || letraActual == 'u'){
			*vocales = *vocales + 1;
		}
    else if(letraActual == '.' ){
      *parrafos = *parrafos + 1;
      }else if(letraActual != 'a' & letraActual != 'e' & letraActual != 'i' & letraActual != 'o' & letraActual != 'u' & letraActual >='a' &&  letraActual<='z'){
			*consonantes = *consonantes + 1;
	}else if(letraActual == ' '){
			*espacio = *espacio + 1;
    }
    }
	return 0;
}

int Pronombres(char cadena[]){
  char cadenatmp[tam];
  memset(cadenatmp, 0, tam);
  int cont=0, indi, ca, cont2=0, lon, el=0, ella=0, yo=0, tu=0, nosotros=0, nosotras=0, vosotros=0, vosotras=0, ellos=0, ellas=0, ustedes=0;
  lon=strlen(cadena);
  for(cont=0;cont<lon;cont++){
    if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==','){
      
        ca = strlen(cadenatmp);
        for(cont2=0;cont2<ca;cont2++){
          cadenatmp[cont2]=0;
        }
        cont2=0;
    }else{
      char a = tolower(cadena[cont]);
      cadenatmp[cont2]=a;
      cont2=cont2+1;
    }
    if(strcmp("el",cadenatmp)==0){
      ++el;
    }else if(strcmp("ella",cadenatmp)==0){
      ++ella;
    }else if(strcmp("yo",cadenatmp)==0){
      ++yo;
    }else if(strcmp("nosotros",cadenatmp)==0){
      ++nosotros;
    }else if(strcmp("nosotras",cadenatmp)==0){
      ++nosotras;
    }else if(strcmp("tu",cadenatmp)==0){
      ++tu;
    }else if(strcmp("ellos",cadenatmp)==0){
      ++ellos;
    }else if(strcmp("ellas",cadenatmp)==0){
      ++ellas;
    }else if(strcmp("vosotros",cadenatmp)==0){
      ++vosotros;
    }else if(strcmp("vosotras",cadenatmp)==0){
      ++vosotras;
    }else if(strcmp("ustedes",cadenatmp)==0){
      ++ustedes;
    }
  }
  printf("En total existen \n%d yo, \n%d tú, \n%d él, \n%d ella, \n%d ellos, \n%d ellas, \n%d vosotros, \n%d nosotros, \n%d nosotras, \n%d vosotras y \n%d ustedes.\n", yo, tu, el, ella, ellos, ellas, vosotros, nosotros, nosotras, vosotras, ustedes);
  return 0;
}
int Mayusculas(char cadena[]){
  char cadenatmp[tam];
  memset(cadenatmp, 0, tam);
  int cont=0, cont2=0, log, ca, l=0;
  log=strlen(cadena);
  for(cont=0;cont<log+1;cont++){
    if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==','){
        ca = strlen(cadenatmp);
      if(cadenatmp[0]>='A' && cadenatmp[0]<='Z'){
          printf("Tu palabra %d %s empieza con mayúscula.\n", l, cadenatmp);
          l++;
        }
        for(cont2=0;cont2<ca;cont2++){
          cadenatmp[cont2]=0;
        }
        cont2=0;
      }else{
      char a = cadena[cont];
      cadenatmp[cont2]=a;
      cont2=cont2+1;
      } if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==',' || cadena[cont]=='\n'){
    if(cadenatmp[0]>='A' && cadenatmp[0]<='Z'){
          printf("Tu palabra %d %s empieza con mayúscula.\n", l, cadenatmp);
          l++;
        }
  }
    
    }
  if(l==0){
      printf("Ninguna palabra empieza con mayúscula.\n");
    }
  return 0;
}

int Separa(char cadena[]){
  char palabras[tam];
  memset(palabras, 0, tam);
  int cont=0, cont2=0, log, ca, l=0, lul=0;
  log=strlen(cadena);
  for(cont=0;cont<log+1;cont++){
    if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==',' || cadena[cont]=='\n'){
      lul=lul+Gerundio(palabras);
        ca = strlen(palabras);
        for(cont2=0;cont2<ca;cont2++){
          palabras[cont2]=0;
        }
        cont2=0;
      }else{
      char a = tolower(cadena[cont]);
      palabras[cont2]=a;
      cont2=cont2+1;
      } 
    }
  if(lul==0){
    printf("No se encontraron palabras en gerundio. %d\n", lul);
  }
  return 0;
}
int Gerundio(char cadena[]){
  char cadenatmp[tam];
  memset(cadenatmp, 0, tam);
  int cont=0, cont2=0, log, ca, l=0;
  log=strlen(cadena);
  for(cont=0;cont<log+1;cont++){
    if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==',' || cadena[cont+1]=='a' || cadena[cont+1]=='e'|| cadena[cont]=='\n'){
        ca = strlen(cadenatmp);
      if(strcmp("ando", cadenatmp)==0){
          printf("Tu palabra '%s' es gerundio\n", cadena);
          l++;
        }else if(strcmp("endo", cadenatmp)==0){
          printf("Tu palabra '%s' es gerundio\n", cadena);
          l++;
        }
        for(cont2=0;cont2<ca;cont2++){
          cadenatmp[cont2]=0;
        }
        cont2=0;
      }else{
      
      char a = cadena[cont];
      cadenatmp[cont2]=a;
      cont2=cont2+1;
      }if(cadena[cont]=='\0'){
        if(strcmp("ando", cadenatmp)==0){
          printf("Tu palabra '%s' es gerundio\n", cadena);
          l++;
        }else if(strcmp("endo", cadenatmp)==0){
          printf("Tu palabra '%s' es gerundio\n", cadena);
          l++;
        }
      }
    }
  return l;
}
int Busca(char cadena[]){
   char palabras[tam];
  char palabra[tam]; 
  memset(palabras, 0, tam);
  memset(palabra, 0, tam);
  int cont=0, cont2=0, log, ca, l=0, cnt=1;
  printf("¿Qué palabra deseas buscar? (Ponla en minúsculas) : ");
  scanf("%s", palabra);
  log=strlen(cadena);
  for(cont=0;cont<log+1;cont++){
    if(cadena[cont]==' ' || cadena[cont]=='.' || cadena[cont]==',' || cadena[cont]=='\n'){
        ca = strlen(palabras);
        if (strcmp(palabra,palabras)==0){
          printf("Se encontró tu palabra %d veces\n", cnt);
          ++cnt;
        }
        for(cont2=0;cont2<ca;cont2++){
          palabras[cont2]=0;
        }
        cont2=0;
      }else{
      char a = tolower(cadena[cont]);
      palabras[cont2]=a;
      cont2=cont2+1;
      } 
      }if(cnt==1){
    printf("No se encontró tu palabra :(\n");
      }
  return 0; 
}
int Intercambia(char cadena[]){
  char cadena2[tam]="";
  int i, r;
  i = 0;

  while(cadena[i]!=0){
    if(cadena[i]>='a' && cadena[i]<='z'){
      cadena2[i] = cadena[i]-32;
    }
    else{
      if(cadena[i]>='A' && cadena[i]<='Z'){
      cadena2[i] = cadena[i]+32;
        }else{
        cadena2[i] = cadena[i];
        }
    }
    printf("%c", cadena2[i]);
    i = i+1;
  }
  return 0;
}