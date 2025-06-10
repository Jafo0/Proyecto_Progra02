#include"Contribuidor.h"
#include <iostream>
#include "ListaUsuario.h"

    Contribuidor::Contribuidor(std::string nom, int ced, std::string nomUs, std::string pass, int id)
        :Usuario(nom,ced,nomUs,"Contribuidor",pass, id){}
        
    void Contribuidor::imprimir(std::string encabezado){
        cout<<"-------------------------------------------";
        cout<<encabezado;
        cout<<"-------------------------------------------"<<endl;
        cout<<"Datos Persona: "<<"Puesto: Contribuidor"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
        cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena<<"\t|"<<"Id: "<<id<<endl;
    }
