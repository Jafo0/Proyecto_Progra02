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
            void set_siguiente(Nodo*);
    };
    Nodo* head{nullptr};
public:
    ListaUsuario();
    ~ListaUsuario();
    bool vacia();
    void agregarUsuario(Usuario*);
    void agregar_contribuidor_por_id(ListaUsuario*, int);
    void eliminar_contribuidor_por_id(int);
    bool comprobar_ID(int);
    void guardarManager(std::ofstream&);
    void guardarContribuidor(std::ofstream&);
    void guardarEnArchivo(std::ofstream&);
    void imprimir();
    void imprimir_contribuidores();
    bool hay_contribuidores();
    void imprimir_id();
    Usuario* encontrarId(const int&);
    Usuario* verificador(const std::string&,const std::string&); 
    void guardar_id_en_archivo(std::ofstream&);
    void leer_id_de_archivo(std::ifstream&, ListaUsuario*);

//este metodo es exclusivo para interaccion, me indica si los valores 
//ingresados estan en la lista y me devuelve el ususario al que pertenecen

};
#endif