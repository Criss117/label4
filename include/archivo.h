#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "persona.h"

#define FILENAME "agenda.txt"
#define MAX_LINE_LENGTH 100

void leerArchivo();
void guardarEnArchivo(Agendas *cabeza);
void leerArchivoSinGuardar();
#endif