#include"Manager.h"
#include <iostream>
#include "ListaUsuario.h"

Manager::Manager(string nom, int ced, string nomUs, string pass)
    :Usuario(nom,ced,nomUs,"Manager",pass){}
    

void Manager::imprimir(){
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Datos Persona: "<<"Puesto: Manager"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
    cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena<<endl;
}