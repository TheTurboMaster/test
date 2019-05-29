#include "lab 7-8.h"
#include <stdio.h>
#include <stdlib.h>
void main (){
  nodoB *unNodo;
  unNodo=malloc(sizeof(nodoB));
  unNodo=iniciarNodo(unNodo);
  unNodo=llenarNodo(unNodo);
  imprimirNodo(unNodo);
  char *nombre;
  nombre=pedirNombre(nombre);
  guardarEnArchivo(unNodo,nombre);
  printf("\nlo que se guardo en el archivo: ");
  unNodo=leerArchivo(unNodo,nombre);
  imprimirNodo(unNodo);
  printf("\nfuera string: %s",nombre);
}
