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

void Contribuidor::escribirEnArchivo(std::ofstream& archivo){
    archivo<<"Contribuidor"<<endl;
    archivo<<nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + contrasena + "," + std::to_string(id)<<endl;
    archivo<<"Calendario: "<<endl;
    this->calendario->escribirEnArchivo(archivo);
}

void Contribuidor::leerCalendarioDeArchivo(std::ifstream& archivo){
    this->calendario->leerDeArchivo(archivo);
} 
