#include "Usuario.h"
int Usuario::contadorId = 0;

Usuario::Usuario(std::string nom, int ced, std::string nomUs,std::string pues, std::string pass)
    :nombre(nom),cedula(ced), nomUsuario(nomUs),puesto(pues),contrasena(pass){
        this->calendario = new Calendario();
        this->id = contadorId;
        ++contadorId;
}
    
Usuario::Usuario(std::string linea){

}

Usuario::~Usuario(){
    delete this->calendario;
}

std::string Usuario::obtenerInfo() const{
    return nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + puesto + "," + contrasena + "," + std::to_string(id);
}

Calendario* Usuario::getCalendario(){return this->calendario;}

std::string Usuario::getNomUs() const{return nomUsuario;}

std::string Usuario::getContra() const{return contrasena;}

int Usuario::getId() const{return id;}
std::string Usuario::getPuesto() const{return puesto;}
