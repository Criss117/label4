#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct Posgrado{
  char titulo[100];
  char nivel[100];
} Posgrado;

typedef struct Posgrados{
  Posgrado posgrado;
  struct Posgrados* sig;
} Posgrados;

typedef struct Pregrado{
  char titulo[100];
} Pregrado;

typedef struct Pregrados{
  Pregrado pregrado;
  struct Pregrados *sig;
} Pregrados;

typedef struct Experiencia {
  char empresa[100];
  char cargo[100];
  char fechaInicio[100];
  char fechaFin[100];
} Experiencia;

typedef struct Experiencias{
  Experiencia experiencia;
  struct Experiencias* sig;
} Experiencias;

typedef struct Persona {
  char cedula[100];
  char nombre[100];
  char apellido[100];
  char direccion[100];
  char telefono[100];
  char email[100];
  char tipoSangre[3];
  char fechaNacimiento[100];
  Pregrados *pregrados;
  Posgrados *posgrados;
  Experiencias *experiencias;
} Persona;

typedef struct Agendas{
  Persona persona;
  struct Agendas *sig;
} Agendas;

#endif