#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class ListaUsuario;

class Usuario{
protected:
    string nombre;
    string cedula;
    string nomUsuario;
    string puesto;
    string contrasena;
public:
    Usuario(string,string,string,string,string);
    virtual ~Usuario();
    virtual void imprimir()=0;
    virtual void registrar(ListaUsuario*)=0;
    string obtenerInfo() const;
    string getNomUs() const;
    string getContra() const;
    
};
#endif