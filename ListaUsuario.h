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
    void agregar_usuario_por_id(ListaUsuario*, int);
    bool comprobar_ID(int);
    void guardarEnArchivo(std::ofstream&);
    void imprimir();
    void imprimir_id();
    Usuario* encontrarId(const int&);
    Usuario* verificador(const std::string&,const std::string&); 

//este metodo es exclusivo para interaccion, me indica si los valores 
//ingresados estan en la lista y me devuelve el ususario al que pertenecen

};
#endif