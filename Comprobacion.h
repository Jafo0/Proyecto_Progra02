#ifndef COMPROBACION_H
#define COMPROBACION_H

#include "Encabezados.h"

//Comprobaciones unitarias:
bool cadena_vacia(std::string);
bool cadena_con_punto(std::string);
bool cadena_con_espacio(std::string);
bool de_string_a_int(std::string);
bool numero_fuera_de_rango(int, int, int);

//Comprobaciones compuestas:
bool texto_no_vacio_sin_espacios(std::string);
bool numero_entero_dentro_de_rango(int, int, std::string);
bool numero_entero_sin_rango(std::string);

//Comprobaciones de fehcas:

bool annoValido(int);
bool mesValido(int);
bool diaValido(int);
bool horaValida(int);
bool minutoValido(int);


#endif // COMPROBACION_H
