#include"Manager.h"
#include <iostream>
#include "ListaUsuario.h"

Manager::Manager(string nom, string ced, string nomUs, string pass,ListaUsuario* lista)
    :Usuario(nom,ced,nomUs,"Manager",pass){
        if(lista) {
        registrar(lista);
    }
}

void Manager::registrar(ListaUsuario* lista){
    if(!lista) return;
    lista->agregarUsuario(this);
    lista->guardarEnArchivo();
}

void Manager::imprimir(){
    cout<<"Soy un Manager"<< "\nMi nombre es: "<<nombre<<"  cedula: "<< cedula
    <<"\nNombre de usuario: "<<nomUsuario<<"  contrasenna: "<< contrasena<<endl;
}