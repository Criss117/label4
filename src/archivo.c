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

  fprintf(fp, "cedula: %s\n", persona.cedula);
  fprintf(fp, "nombre: %s\n", persona.nombre);
  fprintf(fp, "apellido: %s\n", persona.apellido);
  fprintf(fp, "direccion: %s\n", persona.direccion);
  fprintf(fp, "telefono: %s\n", persona.telefono);
  fprintf(fp, "persona: %s\n", persona.email);
  fprintf(fp, "tipoSangre: %s\n", persona.tipoSangre);

  fprintf(fp, "01\n");

  Pregrados *pregradoActual = persona.pregrados;
  while (pregradoActual != NULL) {
    fprintf(fp, "titulo: %s\n", pregradoActual->pregrado.titulo);
    pregradoActual = pregradoActual->sig;
  }

  fprintf(fp, "02\n");

  Posgrados *posgradoActual = persona.posgrados;
  while (posgradoActual != NULL) {
    fprintf(fp, "titulo: %s\n", posgradoActual->posgrado.titulo);
    fprintf(fp, "nivel: %s\n", posgradoActual->posgrado.nivel);
    posgradoActual = posgradoActual->sig;
  }

  fprintf(fp, "03\n");

  Experiencias *experienciasActual = persona.experiencias;
  while (experienciasActual != NULL) {
    fprintf(fp, "empresa: %s\n", experienciasActual->experiencia.empresa);
    fprintf(fp, "cargo: %s\n", experienciasActual->experiencia.cargo);
    fprintf(fp, "fechaIncio: %s\n", experienciasActual->experiencia.fechaInicio);
    fprintf(fp, "fechaFin: %s\n", experienciasActual->experiencia.fechaFin);
    experienciasActual = experienciasActual->sig;
  }
  fclose(fp);

  printf("Guardado exitosamente.\n");
}

void leerArchivo(){
  FILE *fp = fopen(FILENAME, "r");
  char linea[MAX_LINE_LENGTH];

  if(fp == NULL){
    printf("Error al abrir el archivo.\n");
    exit(1);
  }

  while(fgets(linea, MAX_LINE_LENGTH, fp) != NULL){
    linea[strcspn(linea, "\n")] = 0;

    if(strcmp(linea, "00") == 0){
      printf("Cedula: ");
      fgets(linea, MAX_LINE_LENGTH, fp);
      linea[strcspn(linea, "\n")] = 0;
      printf("%s\n", linea);
      printf("Nombre: ");
      fgets(linea, MAX_LINE_LENGTH, fp);
      linea[strcspn(linea, "\n")] = 0;
      printf("%s\n", linea);
      printf("Apellido: ");
      fgets(linea, MAX_LINE_LENGTH, fp);
      linea[strcspn(linea, "\n")] = 0;
      printf("%s\n", linea);
      printf("Dirección: ");
      fgets(linea, MAX_LINE_LENGTH, fp);
      linea[strcspn(linea, "\n")] = 0;
      printf("%s\n", linea);
    }
    // if(strcmp(linea, "01") == 0){
    //   printf("Pregrados: \n");
    //   fgets(linea, MAX_LINE_LENGTH, fp);
    //   linea[strcspn(linea, "\n")] = 0;
    //   while(strcmp(linea, "02") != 0){
    //     printf("%s\n", linea);
    //     fgets(linea, MAX_LINE_LENGTH, fp);
    //     linea[strcspn(linea, "\n")] = 0;
    //   }
    // }
  }
  fclose(fp);

}