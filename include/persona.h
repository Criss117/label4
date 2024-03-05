#ifndef PERSONA_H
#define PERSONA_H

#include "struct.h"

#define DECREMENT "DEC"
#define INCREMENT "INC"


void agregarPersona(Agendas** cabeza, Persona persona);
void agregarPregrado(Pregrados **cabeza, Pregrado pregrado);
void agregarPosgrado(Posgrados **cabeza, Posgrado posgrado);
void agregarExperiencia(Experiencias **cabeza, Experiencia experiencia);
void imprimirLista(Agendas* cabeza);
void liberarMemoria(Agendas* cabeza);
void buscarProfesion(Agendas* cabeza, Pregrado pregrado);
void buscarPorEmpresa(Agendas* cabeza, char empresa[]);

#endif