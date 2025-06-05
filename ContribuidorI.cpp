#include"ContribuidorI.h"
#include <iostream>
#include "ListaUsuario.h"

ContribuidorI::ContribuidorI(string nom, string ced, string nomUs, string pass,ListaUsuario* lista)
    :Usuario(nom,ced,nomUs,"Contribuidor",pass){}
    
//esto ya no es necesario
void ContribuidorI::registrar(ListaUsuario* lista){
    lista->agregarUsuario(this);
    lista->guardarEnArchivo();
}

void ContribuidorI::imprimir(){
    cout<<"Soy un Contribuidor"<< "\nMi nombre es: "<<nombre<<"  cedula: "<< cedula
    <<"\nNombre de usuario: "<<nomUsuario<<"  contrasenna: "<< contrasena<<endl;
}
