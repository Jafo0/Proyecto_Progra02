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
    int id;
    static int contadorId; //esto es estatico por tanto es el que se aumenta o

public:
    Usuario(string,int,string,string,string);
    virtual ~Usuario();
    virtual void imprimir()=0;
    string obtenerInfo() const;
    string getNomUs() const;
    string getContra() const;

    int getId() const;
    string getPuesto() const; //si su puesto es manager puede ver su lista de empleados
};
#endif