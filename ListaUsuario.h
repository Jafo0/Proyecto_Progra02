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
            //Constructores y Destructores
            Nodo(Usuario*, Nodo*); //usuario y el next
            ~Nodo();
            //Setters y getters
            Nodo* getNext() const;
            void setNext(Nodo*);
            Usuario* getUsuario() const;
            void setUsuario(Usuario*);
    };
    //Atributos
    Nodo* head{nullptr};
public:
    //Constructores y destructores
    ListaUsuario();
    ~ListaUsuario();

    //Getters
    void invitar(Reservacion*);

    //Métodos para comprobar cosas
    bool vacia();
    bool comprobarID(int);
    bool IdEsContribuidor(int);
    bool hayContribuidores();

    //Métodos para trabajar con Usuarios:
    void agregarUsuario(Usuario*);
    Usuario* UsuarioPorID(int); //Le doy un id y me devuelve un Usuario*
    void eliminarContribuidorPorID(int); //Esto es para eliminar contribuidores

    //Para visualizar la lista:
    void imprimir(string, string);
    void imprimirIDS();

    //Verificar si puedo agregar un usuario a mi lista:
    Usuario* verificador(const std::string&,const std::string&); 
    bool verificador2(const int&,const std::string&); //cedula y nombre usuario  son unicos

    //Otros métodos
    void escribirEnArchivo(std::ofstream&, ofstream&);
    void escribirIdsEnArchivo(std::ofstream&);
    void leerIds(std::ifstream&, ListaUsuario*);
};
#endif