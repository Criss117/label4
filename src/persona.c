#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"
#include "struct.h"
#include "archivo.h"

void agregarPersona(Agendas** cabeza, Persona persona){
  Agendas* nuevaAgenda = (Agendas*)malloc(sizeof(Agendas));
  if(nuevaAgenda == NULL){
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevaAgenda->persona = persona;
  nuevaAgenda->sig = NULL;

  nuevaAgenda->persona = persona;
  nuevaAgenda->sig = *cabeza;
  *cabeza = nuevaAgenda;

  guardarEnArchivo(persona);
}

void agregarPregrado(Pregrados **cabeza, Pregrado pregrado) {
  Pregrados *nuevosPregrados = (Pregrados*)malloc(sizeof(Pregrados));
  if (nuevosPregrados == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevosPregrados->pregrado = pregrado;
  nuevosPregrados->sig = *cabeza;
  *cabeza = nuevosPregrados;
}

void agregarPosgrado(Posgrados** cabeza, Posgrado posgrado){
  Posgrados *nuevosPosgrados = (Posgrados*)malloc(sizeof(Posgrados));
  if(nuevosPosgrados == NULL){
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevosPosgrados->posgrado = posgrado;
  nuevosPosgrados->sig = *cabeza;
  *cabeza = nuevosPosgrados;
}

void agregarExperiencia(Experiencias** cabeza, Experiencia experiencia){
  Experiencias *nuevasExperiencias = (Experiencias*)malloc(sizeof(Experiencias));
  if(nuevasExperiencias == NULL){
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevasExperiencias->experiencia = experiencia;
  nuevasExperiencias->sig = *cabeza;
  *cabeza = nuevasExperiencias;  
}

void imprimirLista(Agendas* cabeza){
  Agendas *actual = cabeza;

  if (actual == NULL) {
    printf("La agenda esta vacia.\n");
    return;
  }

  printf("\n-----------Agenda:--------------\n");

  while (actual != NULL) {
    printf("Cedula: %s\n", actual->persona.cedula);
    printf("Nombre: %s\n", actual->persona.nombre);
    printf("Apellido: %s\n", actual->persona.apellido);
    printf("Dirección: %s\n", actual->persona.direccion);
    printf("Teléfono: %s\n", actual->persona.telefono);
    printf("Email: %s\n", actual->persona.email);
    printf("Tipo de Sangre: %s\n", actual->persona.tipoSangre);
    
    // Imprimir los pregrados de la persona
    if(actual->persona.pregrados != NULL) {
      Pregrados *pregradoActual = actual->persona.pregrados;
      while (pregradoActual != NULL) {
        printf("Pregrado: %s\n", pregradoActual->pregrado.titulo);
        pregradoActual = pregradoActual->sig;
      }
    }

    if(actual->persona.posgrados != NULL) {
      Posgrados *posgradoActual = actual->persona.posgrados;
      while (posgradoActual != NULL) {
        printf("Posgrado: %s, %s\n", posgradoActual->posgrado.titulo, posgradoActual->posgrado.nivel);
        posgradoActual = posgradoActual->sig;
      }
    }
    
    if(actual->persona.experiencias != NULL) {
      Experiencias *experienciasActual = actual->persona.experiencias;
      while (experienciasActual != NULL) {
        printf("Experiencia: %s, %s\n", experienciasActual->experiencia.empresa, experienciasActual->experiencia.cargo);
        experienciasActual = experienciasActual->sig;
      }
    }
    
    actual = actual->sig;
    printf("\n-------------------------\n");
  }
  printf("\n-----------Agenda:--------------\n");
}

void liberarMemoria(Agendas* cabeza ){
  Agendas* actual = cabeza;
  Agendas* siguiente;
  while (actual != NULL) {
      siguiente = actual->sig;
      free(actual);
      actual = siguiente;
  }
}

void buscarProfesion(Agendas* cabeza, Pregrado pregrado){
  Agendas *actual = cabeza;
  Agendas *profesiones;


  while(actual != NULL){
    Pregrados *pregradoActual = actual->persona.pregrados;
    while (pregradoActual != NULL) {
      if(strcmp(pregradoActual->pregrado.titulo, pregrado.titulo) == 0){
        agregarPersona(&profesiones, actual->persona);
      }
      pregradoActual = pregradoActual->sig;
    }
    actual = actual->sig;
  }

  imprimirLista(profesiones);
}

void buscarPorEmpresa(Agendas* cabeza, const char *empresa){
  Agendas *actual = cabeza;

  while(actual != NULL){
    Experiencias *experienciaActual = actual->persona.experiencias;
    while (experienciaActual != NULL) {
      printf("Cedula: %s\n", actual->persona.cedula);
      if (strcmp(experienciaActual->experiencia.empresa, empresa) == 0) {
        printf("Nombre: %s %s\n", actual->persona.nombre, actual->persona.apellido);
        printf("Cedula: %s\n", actual->persona.cedula);
        printf("Empresa: %s\n", experienciaActual->experiencia.empresa);
        printf("Cargo: %s\n", experienciaActual->experiencia.cargo);
        printf("\n");
        break;
      }
      experienciaActual = experienciaActual->sig;
    }
    actual = actual->sig;
  }
}

void eliminarPersona(Agendas **cabeza){
  char cedula[100];
  printf("Ingrese la cédula de la persona a eliminar: ");
  scanf("%s", cedula);

  Agendas *actual = *cabeza;
  Agendas *anterior = NULL;
  if(actual != NULL && strcmp(actual->persona.cedula, cedula) == 0){
    *cabeza = actual->sig;
    free(actual);
    return;
  }

  while(actual != NULL && strcmp(actual->persona.cedula, cedula) != 0){
    anterior = actual;
    actual = actual->sig;
  }

  if(actual == NULL){
    printf("No se encontro la persona.\n");
    return;
  }

  anterior->sig = actual->sig;
  free(actual);
}

void contarPosgrados(Agendas *agenda) {
  int especializacion = 0;
  int maestria = 0;
  int doctorado = 0;

  Agendas *actual = agenda;
  while (actual != NULL) {
    Posgrados *posgradoActual = actual->persona.posgrados;
    while (posgradoActual != NULL) {
      if (strcmp(posgradoActual->posgrado.nivel, "Especializacion") == 0) {
        (especializacion)++;
      } else if (strcmp(posgradoActual->posgrado.nivel, "Maestria") == 0) {
        (maestria)++;
      } else if (strcmp(posgradoActual->posgrado.nivel, "Doctorado") == 0) {
        (doctorado)++;
      }
      posgradoActual = posgradoActual->sig;
    }
    actual = actual->sig;
  }

  printf("Especialización: %d\n", especializacion);
  printf("Maestría: %d\n", maestria);
  printf("Doctorado: %d\n", doctorado);
}