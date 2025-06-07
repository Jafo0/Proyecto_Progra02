#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include "Usuario.h"

class ListaEmpleados{
    private:
        class Nodo{
            public:
                //atributos
                Nodo* next{nullptr};
                int id;
                //metodos
                Nodo(int,Nodo*);     //getId
                ~Nodo();
        };
    Nodo* head;
    public:
        ~ListaEmpleados();
        bool agregarId(Usuario*);   //Nodo guarda id con getId() metodo de 
        //void popId(int);          //esta puede ser opcional para quitar a un empleado de la lista
        void imprimir();
        bool comprobarLista(int);      //comprobar que el id no este en la lista
};
#endif