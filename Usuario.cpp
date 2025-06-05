#include "Usuario.h"

Usuario::Usuario(string nom, int ced, string nomUs,string pues, string pass)
    :nombre(nom),cedula(ced), nomUsuario(nomUs),puesto(pues),contrasena(pass){
        this->calendario = Calendario();
    }
    
Usuario::~Usuario(){}

string Usuario::obtenerInfo() const{
    return nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + puesto + "," + contrasena;
}
string Usuario::getNomUs() const{return nomUsuario;}

string Usuario::getContra() const{return contrasena;}
