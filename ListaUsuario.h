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

};
#endif