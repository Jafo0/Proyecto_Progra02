#ifndef COMPROBACION_H
#define COMPROBACION_H

#include <string>
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

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


#endif // COMPROBACION_H
