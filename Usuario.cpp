#include "Usuario.h"
int Usuario::contadorId = 0;

Usuario::Usuario(string nom, int ced, string nomUs,string pues, string pass)
    :nombre(nom),cedula(ced), nomUsuario(nomUs),puesto(pues),contrasena(pass){
        this->calendario = Calendario();
        this->id = contadorId;
        ++contadorId;}
    
Usuario::~Usuario(){}

string Usuario::obtenerInfo() const{
    return nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + puesto + "," + contrasena + "," + std::to_string(id);
}
string Usuario::getNomUs() const{return nomUsuario;}

string Usuario::getContra() const{return contrasena;}

int Usuario::getId() const{return id;}
string Usuario::getPuesto() const{return puesto;}