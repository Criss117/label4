#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"
#include "struct.h"
#include "archivo.h"
#include "persona_consola.h"

void menu(){
  Agendas* cabezaAgendas = NULL;
  int opcion;

  Pregrados *pregradosPersona1 = NULL;
  Pregrado pregradoInfo = {"Arquitectura"};
  agregarPregrado(&pregradosPersona1, pregradoInfo);

  Posgrados *posgradosPersona1 = NULL;
  Posgrado posgradoInfo = {"Lic. en Negocios", "Especializacion"};
  Posgrado posgradoInfo2 = {"Lic. en Negocios 2", "Maestria"};
  agregarPosgrado(&posgradosPersona1, posgradoInfo);
  agregarPosgrado(&posgradosPersona1, posgradoInfo2);

  Experiencias *experienciasPersona1 = NULL;
  Experiencia exp1 = {"empresa 1", "cargo 1", "2022-01-01", "2022-01-01"};
  Experiencia exp2 = {"empresa 2", "cargo 2", "2022-01-01", "2022-01-01"};
  agregarExperiencia(&experienciasPersona1, exp1);
  agregarExperiencia(&experienciasPersona1, exp2);

  Persona persona1 = {"123456789", "Juan", "Perez", "Calle 123", "123456789", "juan@example.com", "AB", "24/08/21", pregradosPersona1, posgradosPersona1, experienciasPersona1};
  agregarPersona(&cabezaAgendas, persona1);

  do {
    printf("\nMenú:\n");
    printf("1. Leer archivo\n");
    printf("2. Guardar archivo\n");
    printf("3. Agregar persona\n");
    printf("4. Eliminar persona\n");
    printf("5. Hacer consultas\n");
    printf("6. Mostrar información del archivo\n");
    printf("7. Ordenar datos\n");
    printf("8. Salir\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        leerArchivoSinGuardar();
        break;
      case 2:
        guardarEnArchivo(cabezaAgendas); // Guardar solo una persona por ahora
        break;
      case 3:
        Persona nuevaPersona = leerDatosConsola(&cabezaAgendas);
        agregarPersona(&cabezaAgendas, nuevaPersona);
        imprimirLista(cabezaAgendas);
        break;
      case 4:
        eliminarPersona(&cabezaAgendas);
        imprimirLista(cabezaAgendas);
        break;
      case 5:
        printf("Por Arquitectura\n");
        Pregrado pre = {"Arquitectura"};
        buscarProfesion(cabezaAgendas, pre);
        printf("\nEn Empresa 1 \n");
        buscarPorEmpresa(cabezaAgendas, "empresa 1");
        contarPosgrados(cabezaAgendas);
        break;
      case 6:
        leerArchivoSinGuardar(); // Mostrar información de todas las personas en la lista
        break;
      case 7:
        imprimirLista(cabezaAgendas);
        break;
      case 8:
        printf("Saliendo del programa.\n");
        break;
      default:
        printf("Opción no válida. Por favor, ingrese un número del 1 al 8.\n");
    }
  } while (opcion != 8);
}