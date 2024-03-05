/**
 * @file main.c
 * @authors Cristian Camilo Viveros Castillo <crviveros@unicuaca.edu.co>
            Edinson Oviedo Martinez <eoviedo@unicuaca.edu.co>
 * @brief 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include "struct.h"
#include "persona.h"
#include "archivo.h"

int main(){
  // leerArchivo();

  Agendas* cabezaAgendas = NULL;

  Pregrados *pregradosPersona1 = NULL;
  Pregrado pregradoInfo = {"Arquitectura"};
  agregarPregrado(&pregradosPersona1, pregradoInfo);

  Posgrados *posgradosPersona1 = NULL;
  Posgrado posgradoInfo = {"Lic. en Negocios", "Licenciatura"};
  Posgrado posgradoInfo2 = {"Lic. en Negocios 2", "Licenciatura"};
  agregarPosgrado(&posgradosPersona1, posgradoInfo);
  agregarPosgrado(&posgradosPersona1, posgradoInfo2);

  Experiencias *experienciasPersona1 = NULL;
  Experiencia exp1 = {"empresa 1", "cargo 1", "2022-01-01", "2022-01-01"};
  Experiencia exp2 = {"empresa 2", "cargo 2", "2022-01-01", "2022-01-01"};
  agregarExperiencia(&experienciasPersona1, exp1);
  agregarExperiencia(&experienciasPersona1, exp2);

  Persona persona1 = {"123456789", "Juan", "Perez", "Calle 123", "123456789", "juan@example.com", "AB", "24/08/21", pregradosPersona1, posgradosPersona1};
  agregarPersona(&cabezaAgendas, persona1);

  Persona persona2 = {"123456789", "Juan2", "Perez2", "Calle 123", "123456789", "juan@example.com", "AB", "24/08/21", pregradosPersona1, posgradosPersona1};
  agregarPersona(&cabezaAgendas, persona2);

  // Pregrado pre = {"Ingenieria"};
  // buscarProfesion(cabezaAgendas, pre);

  // buscarPorEmpresa(cabezaAgendas, "empresa 1");

  imprimirLista(cabezaAgendas);
  guardarEnArchivo(cabezaAgendas);
  return 0;
}