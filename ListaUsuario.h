#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H
#include "Usuario.h"
#include <fstream>

class ListaUsuario{
private:
    class Nodo{
    private:
        Nodo* next{nullptr};
        Usuario* usuario;
    public:
        Nodo(Usuario*, Nodo*); //usuario y el next
        Nodo* getNext();
        Usuario* getUsuario();
        ~Nodo();
    };
    Nodo* head{nullptr};
public:
    ListaUsuario()=default;
    ~ListaUsuario();
    void agregarUsuario(Usuario*);
    bool guardarEnArchivo();
    void imprimirUsuarios();
    Usuario* verificador(const string&,const string&); 
//este metodo es exclusivo para interaccion, me indica si los valores 
//ingresados estan en la lista y me devuelve el ususario al que pertenecen

};
#endif