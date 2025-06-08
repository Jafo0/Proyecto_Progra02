#include"Manager.h"
#include <iostream>
#include "ListaUsuario.h"

Manager::Manager(std::string nom, int ced, std::string nomUs, std::string pass)
    :Usuario(nom,ced,nomUs,"Manager",pass){
        this->listaEmp = ListaEmpleados(); //atributo de lista empleado de manager
}

void Manager::imprimir(){
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Datos Persona: "<<"Puesto: Manager"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
    cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena <<"\t|"<<"Id: "<<id<<endl;
}