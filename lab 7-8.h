#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define t 2
typedef struct struct_nodoB{
    int claves[2*t-1];
    int hijos[2*t];
    int esHoja;
    int cantidadActual;
}nodoB;

nodoB *iniciarNodo();
nodoB *llenarNodo(nodoB *);
int guardarEnArchivo(nodoB *, char *);
nodoB *leerArchivo(nodoB *,char *);
void imprimirNodo(nodoB *);



void imprimirNodo(nodoB *unNodo){
    int i=0;
    printf("\nClaves: ");
    while(i<(2*t-1)){
        printf("\n%i",unNodo->claves[i]);
        i++;
    }
    printf("\nHijos: ");
    i=0;
    while(i<(2*t)){
      printf("\n%i",unNodo->hijos[i]);
      i++;
    }
    printf("\nes Hoja: %i",unNodo->esHoja);
    printf("\ncantidad actual: %i\n",unNodo->cantidadActual);
}



nodoB *leerArchivo(nodoB *unNodo,char *nombre){
    FILE *fp;
    nodoB *auxNodo;
    auxNodo=malloc(sizeof(nodoB));
    fp=fopen(nombre,"rb");
    fread(auxNodo,sizeof(nodoB),1,fp);
    return auxNodo;
    fclose(fp);
}

nodoB *iniciarNodo(){
  nodoB *unNodo;
  unNodo=malloc(sizeof(nodoB));
  int i=0;
  while(i<(2*t-1)){
    unNodo->claves[i]='\0';
    i++;
  }
  i=0;
  while(i<(2*t)){
    unNodo->hijos[i]='\0';
    i++;
  }
  unNodo->esHoja='\0';
  unNodo->cantidadActual=0;
  return unNodo;
}

nodoB *llenarNodo(nodoB *unNodo){
  int i=0;
  srand(time(NULL));
  while(i<(2*t-1)){
    unNodo->claves[i]=rand() % 1000;
    (unNodo->cantidadActual)++;
    i++;
  }
  i=0;
  while(i<(2*t)){
    unNodo->hijos[i]=i+1;
    i++;
  }
  return unNodo;
}

char *pedirNombre(char *nombre){
  int i=0;

  char aux[30];
  while(i<30){
    aux[i]='\0';
    i++;
  }
  fflush(stdin);
  scanf("%s",&aux);
  fflush(stdin);
  i=0;
  while(aux[i]!='\0'){
    i++;
  }
  int j=0;
  nombre=malloc(sizeof(char)*(i));
  strcpy(nombre,aux);

  return nombre;



}
int guardarEnArchivo(nodoB *unNodo,char *nombre){
  FILE *fp;
  fp=fopen(nombre,"wb");
  fwrite(unNodo,sizeof(nodoB),1,fp);
  fclose(fp);



}
