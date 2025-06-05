#include"ContribuidorI.h"
#include <iostream>
#include "ListaUsuario.h"

ContribuidorI::ContribuidorI(string nom, int ced, string nomUs, string pass)
    :Usuario(nom,ced,nomUs,"Contribuidor",pass){}
    
void ContribuidorI::imprimir(){
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Datos Persona: "<<"Puesto: Contribuidor"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
    cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena<<endl;
}
