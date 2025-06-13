#include "Usuario.h"
int Usuario::contadorId = 0;

Usuario::Usuario(std::string nom, int ced, std::string nomUs,std::string pues, std::string pass, int id)
    :nombre(nom),cedula(ced), nomUsuario(nomUs),puesto(pues),contrasena(pass), id(id){
        this->calendario = new Calendario();
        ++contadorId;
}

std::string Usuario::getNombre() const{return this->nombre;}
void Usuario::setNombre(const std::string& nuevoNombre){this->nombre = nuevoNombre;}

int Usuario::getCedula() const{return this->cedula;}
void Usuario::setCedula(int nuevaCedula){this->cedula = nuevaCedula;}

std::string Usuario::getNomUsuario() const{return this->nomUsuario;}
void Usuario::setNomUsuario(const std::string& nuevoNomUsuario){this->nomUsuario = nuevoNomUsuario;}

std::string Usuario::getPuesto() const{return this->puesto;}
void Usuario::setPuesto(const std::string& nuevoPuesto){this->puesto = nuevoPuesto;}

std::string Usuario::getContrasena() const{return this->contrasena;}
void Usuario::setContrasena(const std::string& nuevaContrasena){this->contrasena = nuevaContrasena;}

Calendario*& Usuario::getCalendario() {return this->calendario;}

void Usuario::setCalendario(Calendario* nuevoCalendario){this->calendario = nuevoCalendario;}

int Usuario::getID() const{return this->id;}

void Usuario::setID(int _id){this->id = _id;}

std::string Usuario::infoUsuario() const{
    return puesto + "," + nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + contrasena + "," + std::to_string(id);
}
