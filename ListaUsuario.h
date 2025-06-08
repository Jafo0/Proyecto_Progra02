#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H
#include "Usuario.h"
#include <fstream>

class ListaUsuario{
private:
    class Nodo{
        public:
            //Atributos
            Nodo* next{nullptr};
            Usuario* usuario;
            //Métodos:
            Nodo(Usuario*, Nodo*); //usuario y el next
            ~Nodo();
    };
    Nodo* head{nullptr};
public:
    ListaUsuario();
    ~ListaUsuario();
    bool vacia();
    void agregarUsuario(Usuario*);
    bool guardarEnArchivo();
    void imprimirUsuarios();
    Usuario* encontrarId(const int&);
    Usuario* verificador(const std::string&,const std::string&); 

//este metodo es exclusivo para interaccion, me indica si los valores 
//ingresados estan en la lista y me devuelve el ususario al que pertenecen

};
#endif