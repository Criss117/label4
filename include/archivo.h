#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "persona.h"

#define FILENAME "agenda.txt"
#define MAX_LINE_LENGTH 300

void leerArchivo();
void guardarEnArchivo(Persona persona);

#endif