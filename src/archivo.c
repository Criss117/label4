#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "archivo.h"

void guardarEnArchivo(Persona persona){
  FILE *fp = fopen(FILENAME, "w");
  if (fp == NULL) {
    printf("Error al abrir el archivo.\n");
    exit(1);
  }
  fprintf(fp, "%s\n", persona.cedula);
  fprintf(fp, "%s\n", persona.nombre);
  fprintf(fp, "%s\n", persona.apellido);
  fprintf(fp, "%s\n", persona.direccion);
  fprintf(fp, "%s\n", persona.telefono);
  fprintf(fp, "%s\n", persona.email);
  fprintf(fp, "%s\n", persona.tipoSangre);

  Pregrados *pregradoActual = persona.pregrados;
  while (pregradoActual != NULL) {
    fprintf(fp, "%s\n", pregradoActual->pregrado.titulo);
    pregradoActual = pregradoActual->sig;
  }

  Posgrados *posgradoActual = persona.posgrados;
  while (posgradoActual != NULL) {
    fprintf(fp, "%s\n", posgradoActual->posgrado.titulo);
    fprintf(fp, "%s\n", posgradoActual->posgrado.nivel);
    posgradoActual = posgradoActual->sig;
  }

  Experiencias *experienciasActual = persona.experiencias;
  while (experienciasActual != NULL) {
    fprintf(fp, "%s\n", experienciasActual->experiencia.empresa);
    fprintf(fp, "%s\n", experienciasActual->experiencia.cargo);
    fprintf(fp, "%s\n", experienciasActual->experiencia.fechaInicio);
    fprintf(fp, "%s\n", experienciasActual->experiencia.fechaFin);
    experienciasActual = experienciasActual->sig;
  }

  fclose(fp);
}