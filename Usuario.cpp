#include "Usuario.h"

Usuario::Usuario(string nom, string ced, string nomUs,string pues, string pass)
    :nombre(nom),cedula(ced), nomUsuario(nomUs),puesto(pues),contrasena(pass){}
    
Usuario::~Usuario(){}

string Usuario::obtenerInfo() const{
    return nombre + "," + cedula + "," + nomUsuario + "," + puesto + "," + contrasena;
}