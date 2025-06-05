#ifndef USUARIO_H
#define USUARIO_H

#include "Calendario.h"
#include <string>
using namespace std;

class Usuario{
protected:
    string nombre;
    int cedula;
    string nomUsuario;
    string puesto;
    string contrasena;
    Calendario calendario;

public:
    Usuario(string,int,string,string,string);
    virtual ~Usuario();
    virtual void imprimir()=0;
    string obtenerInfo() const;
    string getNomUs() const;
    string getContra() const;
    
};
#endif