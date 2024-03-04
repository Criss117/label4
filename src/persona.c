#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"
#include "struct.h"
#include "archivo.h"

/**
 * @brief agrega una agenda a agendas
 * 
 * @param cabeza 
 * @param agenda 
 */
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

/**
 * @brief Agrega un pregrado a una persona
 * 
 * @param cabeza 
 * @param nombrePregrado 
 */
void agregarPregrado(Pregrados **cabeza, char *nombrePregrado) {
    Pregrados *nuevoPregrado = (Pregrados*)malloc(sizeof(Pregrados));
    if (nuevoPregrado == NULL) {
      printf("Error: No se pudo asignar memoria.\n");
      exit(1);
    }

    nuevoPregrado->pregrado.titulo = strdup(nombrePregrado);
    nuevoPregrado->sig = *cabeza;
    *cabeza = nuevoPregrado;
}

/**
 * @brief agrega un nuevo posgrado
 * 
 * @param cabeza 
 * @param posgradoInfo 
 */
void agregarPosgrado(Posgrados** cabeza, Posgrado posgradoInfo){
  Posgrados *nuevoPosgrado = (Posgrados*)malloc(sizeof(Posgrados));
  if(nuevoPosgrado == NULL){
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevoPosgrado->posgrado = posgradoInfo;
  nuevoPosgrado->sig = *cabeza;
  *cabeza = nuevoPosgrado;
}


/**
 * @brief agrega una nueva experiencia
 * 
 * @param cabeza 
 * @param experiencia 
 */
void agregarExperiencia(Experiencias** cabeza, Experiencia experiencia){
  Experiencias *nuevaExperiencia = (Experiencias*)malloc(sizeof(Experiencias));
  if(nuevaExperiencia == NULL){
    printf("Error: No se pudo asignar memoria.\n");
    exit(1);
  }

  nuevaExperiencia->experiencia = experiencia;
  nuevaExperiencia->sig = *cabeza;
  *cabeza = nuevaExperiencia;  
}

/**
 * @brief Imprime la lista de agendas
 * 
 * @param cabeza 
 */
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
      Pregrados *pregradoActual = actual->persona.pregrados;
      while (pregradoActual != NULL) {
          printf("Pregrado: %s\n", pregradoActual->pregrado.titulo);
          pregradoActual = pregradoActual->sig;
      }

      Posgrados *posgradoActual = actual->persona.posgrados;
      while (posgradoActual != NULL) {
          printf("Posgrado: %s, %s\n", posgradoActual->posgrado.titulo, posgradoActual->posgrado.nivel);
          posgradoActual = posgradoActual->sig;
      }
      printf("\n");

      Experiencias *experienciasActual = actual->persona.experiencias;
      while (experienciasActual != NULL) {
        printf("Experiencia: %s, %s\n", experienciasActual->experiencia.empresa, experienciasActual->experiencia.cargo);
        experienciasActual = experienciasActual->sig;
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