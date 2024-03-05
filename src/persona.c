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

  // guardarEnArchivo(persona);
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

      printf("\n");
      
      if(actual->persona.experiencias != NULL) {
        Experiencias *experienciasActual = actual->persona.experiencias;
        while (experienciasActual != NULL) {
          printf("Experiencia: %s, %s\n", experienciasActual->experiencia.empresa, experienciasActual->experiencia.cargo);
          experienciasActual = experienciasActual->sig;
        }
      }
      
      actual = actual->sig;
    }
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

void buscarPorEmpresa(Agendas* cabeza, char empresa[]){
  Agendas *actual = cabeza;

  while(actual != NULL){
    Experiencias *experienciaActual = actual->persona.experiencias;
    while (experienciaActual != NULL) {
      // if(strcmp(experienciaActual->experiencia.empresa, empresa) == 0){
      //   agregarPersona(&profesiones, actual->persona);
      // }
      experienciaActual = experienciaActual->sig;
    }
    actual = actual->sig;
  }
}