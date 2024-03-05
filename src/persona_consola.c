#include <stdio.h>
#include "struct.h"
#include "persona.h"
#include "archivo.h"

Persona leerDatosConsola(){
  Persona nuevaPersona;
  printf("Ingrese la cédula: ");
  scanf("%s", nuevaPersona.cedula);
  
  printf("Ingrese el nombre: ");
  scanf("%s", nuevaPersona.nombre);
  
  printf("Ingrese el apellido: ");
  scanf("%s", nuevaPersona.apellido);
  
  printf("Ingrese la dirección: ");
  scanf("%s", nuevaPersona.direccion);
  
  printf("Ingrese el teléfono: ");
  scanf("%s", nuevaPersona.telefono);
  
  printf("Ingrese el email: ");
  scanf("%s", nuevaPersona.email);
  
  printf("Ingrese el tipo de sangre: ");
  scanf("%s", nuevaPersona.tipoSangre);
  
  printf("Ingrese la fecha de nacimiento: ");
  scanf("%s", nuevaPersona.fechaNacimiento);

  return nuevaPersona;
}