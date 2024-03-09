#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "persona.h"
#include "archivo.h"

void guardarEnArchivo(Persona persona){
  FILE *fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    printf("Error al abrir el archivo.\n");
    exit(1);
  }
  fprintf(fp, "00\n");

  fprintf(fp, "%s\n", persona.cedula);
  fprintf(fp, "%s\n", persona.nombre);
  fprintf(fp, "%s\n", persona.apellido);
  fprintf(fp, "%s\n", persona.direccion);
  fprintf(fp, "%s\n", persona.telefono);
  fprintf(fp, "%s\n", persona.email);
  fprintf(fp, "%s\n", persona.tipoSangre);

  if(persona.pregrados != NULL){
    fprintf(fp, "01\n");

    Pregrados *pregradoActual = persona.pregrados;
    while (pregradoActual != NULL) {
      fprintf(fp, "%s\n", pregradoActual->pregrado.titulo);
      pregradoActual = pregradoActual->sig;
    }
  }

  if(persona.posgrados != NULL){
    fprintf(fp, "02\n");

    Posgrados *posgradoActual = persona.posgrados;
    while (posgradoActual != NULL) {
      fprintf(fp, "%s\n", posgradoActual->posgrado.titulo);
      fprintf(fp, "%s\n", posgradoActual->posgrado.nivel);
      posgradoActual = posgradoActual->sig;
    }
  }

  if(persona.experiencias != NULL){
    fprintf(fp, "03\n");

    Experiencias *experienciasActual = persona.experiencias;
    while (experienciasActual != NULL) {
      fprintf(fp, "%s\n", experienciasActual->experiencia.empresa);
      fprintf(fp, "%s\n", experienciasActual->experiencia.cargo);
      fprintf(fp, "%s\n", experienciasActual->experiencia.fechaInicio);
      fprintf(fp, "%s\n", experienciasActual->experiencia.fechaFin);
      experienciasActual = experienciasActual->sig;
    }
  }

  fclose(fp);
  printf("Guardado exitosamente.\n");
}

void leerArchivo(){
  Agendas* cabezaAgendas = NULL;

  FILE *file = fopen(FILENAME, "r");
  char linea[MAX_LINE_LENGTH];

  if(file == NULL){
    printf("Error al abrir el archivo.\n");
    exit(1);
  }


  while(fgets(linea, MAX_LINE_LENGTH, file)){
    linea[strcspn(linea, "\n")] = 0;
    Persona nuevaPersona;  

    if(strcmp(linea, "00") == 0){

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.cedula, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.nombre, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.apellido, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.direccion, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.telefono, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.email, linea);

      fgets(linea, MAX_LINE_LENGTH, file);
      linea[strcspn(linea, "\n")] = 0;
      strcpy(nuevaPersona.tipoSangre, linea);
    }

    if(strcmp(linea, "01") == 0){
      Pregrados *pregrados;

      while(strcmp(linea, "02") != 0 || strcmp(linea, "03") != 0 || feof(file) != 0){
        fgets(linea, MAX_LINE_LENGTH, file);
        linea[strcspn(linea, "\n")] = 0;

        if(strcmp(linea, "02") == 0 || strcmp(linea, "03") == 0){
          break;
        }

        printf("pregrado %s\n", linea);
        Pregrado nuevoPregrado;
        strcpy(nuevoPregrado.titulo, linea);
        agregarPregrado(&pregrados, nuevoPregrado);
      }

      if(pregrados != NULL){
        nuevaPersona.pregrados = pregrados;
      }
    }

    if(strcmp(linea, "02") == 0){
      Posgrados *posgrados;

      while(strcmp(linea, "01") != 0 || strcmp(linea, "03") != 0 || feof(file) != 0){
        fgets(linea, MAX_LINE_LENGTH, file);
        linea[strcspn(linea, "\n")] = 0;

        if(strcmp(linea, "01") == 0 || strcmp(linea, "03") == 0){
          break;
        }
        printf("pregrado %s\n", linea);
        Posgrado nuevoPosgrado;
        strcpy(nuevoPosgrado.titulo, linea);
        fgets(linea, MAX_LINE_LENGTH, file);
        strcpy(nuevoPosgrado.nivel, linea);
        agregarPosgrado(&posgrados, nuevoPosgrado);
      }

      if(posgrados != NULL){
        nuevaPersona.posgrados = posgrados;
        agregarPersona(&cabezaAgendas, nuevaPersona);
        printf("-------------------\n");
        imprimirLista(cabezaAgendas);
      }
    }
    // agregarPersona(&cabezaAgendas, nuevaPersona);
    // printf("-------------------\n");
    // imprimirLista(cabezaAgendas);
  }
  fclose(file);

}

void leerArchivoSinGuardar(){
  FILE *file = fopen(FILENAME, "r");
  char linea[MAX_LINE_LENGTH];

  if(file == NULL){
    printf("Error al abrir el archivo.\n");
    exit(1);
  }

  while(fgets(linea, MAX_LINE_LENGTH, file)){
    linea[strcspn(linea, "\n")] = 0;
    printf("%s\n", linea);
  }
  fclose(file);
}