#ifndef PERSONA_H
#define PERSONA_H

#include "struct.h"

#define DECREMENT "DEC"
#define INCREMENT "INC"


void agregarPersona(Agendas** cabeza, Persona persona);
void agregarPregrado(Pregrados **cabeza, char *nombrePregrado);
void agregarPosgrado(Posgrados **cabeza, Posgrado posgradoInfo);
void agregarExperiencia(Experiencias **cabeza, Experiencia experiencia);
void imprimirLista(Agendas* cabeza);
void liberarMemoria(Agendas* cabeza);

#endif