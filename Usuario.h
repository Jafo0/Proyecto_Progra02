#ifndef USUARIO_H
#define USUARIO_H

#include "Calendario.h"
#include <string>
#include <fstream>
using std::cout;
using std::endl;

class Usuario{
protected:
    std::string nombre;
    int cedula;
    std::string nomUsuario;
    std::string puesto;
    std::string contrasena;
    Calendario* calendario;
    int id;
    

public:
    static int contadorId; //esto es estatico por tanto es el que se aumenta o
    Usuario(std::string,int,std::string,std::string,std::string, int);
    virtual ~Usuario();
    virtual void imprimir(std::string)=0;
    virtual void guardar_en_archivo(std::ofstream&)=0;
    std::string obtenerInfo() const;
    Calendario* getCalendario();
    std::string getNomUs() const;
    std::string getContra() const;

    int getCedula() const;

    int getId() const;
    std::string getPuesto() const; //si su puesto es manager puede ver su lista de empleados
    
};
#endif