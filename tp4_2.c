#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LONGITUD 150

typedef struct Nodo Nodo;
typedef struct Tarea Tarea;

struct Tarea {
  int TareaID; // Numérico autoincremental comenzando en 1000
  char *Descripcion; //
  int Duracion; // entre 10 – 100
};

struct Nodo {
  Tarea T; // dato
  Nodo *Siguiente; // siguiente
};

Nodo *CrearNodo(Tarea T);
Nodo *insertarAlFinal(Nodo *lista, Tarea nuevaTarea);

int main() {
    char buffer[MAX_LONGITUD];
    int continuar;
  Nodo *listaTareas = NULL; // inicializar lista vacia
  do {
    struct Tarea nuevaTarea; // le coloco nombre struct
    nuevaTarea.TareaID = 1000;

    printf("Ingrese descripcion de la tarea:\n");
    fflush(stdin);
    gets(buffer);
    nuevaTarea.Descripcion = malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(nuevaTarea.Descripcion, buffer);

    printf("Ingrese la duracion de la tarea (entre 10 y 100): ");
    scanf("%d", &nuevaTarea.Duracion); // Leer la duración antes de inicializar

    printf("Desea ingresar otra tarea? (0=no /1=si): ");
    scanf("%d", &continuar);

    listaTareas = insertarAlFinal(listaTareas, nuevaTarea);
  } while (continuar == 1);
  return 0;
}

Nodo *CrearNodo(Tarea T) {
  Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
  nodo->T = T;
  nodo->Siguiente = NULL;
  return nodo;
}

Nodo *insertarAlFinal(Nodo *lista, Tarea nuevaTarea) {
  Nodo *nuevoNodo = CrearNodo(nuevaTarea);
  if (lista == NULL) {
    return nuevoNodo;
  } else {
    Nodo *aux = lista;
    while (aux->Siguiente) {
      aux = aux->Siguiente;
    }
    aux->Siguiente = nuevoNodo;
    return lista;
  }
}
