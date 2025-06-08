#include"ContribuidorI.h"
#include <iostream>
#include "ListaUsuario.h"

    ContribuidorI::ContribuidorI(std::string nom, int ced, std::string nomUs, std::string pass)
        :Usuario(nom,ced,nomUs,"Contribuidor",pass){}
        
    void ContribuidorI::imprimir(){
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Datos Persona: "<<"Puesto: Contribuidor"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
        cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena<<"\t|"<<"Id: "<<id<<endl;
    }
