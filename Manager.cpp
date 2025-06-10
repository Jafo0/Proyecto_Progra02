#include"Manager.h"
#include <iostream>
#include "ListaUsuario.h"

Manager::Manager(std::string nom, int ced, std::string nomUs, std::string pass, int id)
    :Usuario(nom,ced,nomUs,"Manager",pass, id){
        this->listaEmp = new ListaUsuario(); //atributo de lista empleado de manager
}

void Manager::imprimirEmpleados(){
    this->listaEmp->imprimir_id();
}

void Manager::imprimir(std::string encabezado){
    cout<<"-------------------------------------------";
    cout<<encabezado;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Datos Persona: "<<"Puesto: Manager"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
    cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena <<"\t|"<<"Id: "<<id<<endl;
}


void Manager::agregar_empleado(ListaUsuario* usuarios_registrados){
    std::string respuesta;
    do{
        cout<<"Ingrese el id del empleado que desea agregar como subordinado: ";
        getline(cin, respuesta);
    }while(!de_string_a_int(respuesta));

    if(usuarios_registrados->comprobar_ID(stoi(respuesta))){    //Si el id existe
        this->listaEmp->agregar_usuario_por_id(usuarios_registrados, stoi(respuesta));
    }else{
        cout<<"\033[33m"<<"El id ingresado no corresponde a ningun empleado..."<<"\033[0m"<<endl;
    }

    

}

void Manager::eliminar_empleado(){

}

void Manager::modificar_listaEmp(ListaUsuario* usuarios_registrados){
    cout<<"--------------Opciones para los subalternos--------------"<<endl;
    cout<<"1. Agregar"<<endl;
    cout<<"2. Eliminar"<<endl;
    cout<<"3. Regresar"<<endl;

    std::string respuesta;
    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,3, respuesta));

    switch (stoi(respuesta)){
        case 1:
            this->agregar_empleado(usuarios_registrados);
            break;
        case 2:
            cout<<"\033[33m"<<"Estoy eliminando un empleado..."<<"\033[0m"<<endl;
            break;
        case 3:
            cout<<"\033[33m"<<"Estoy regresando..."<<"\033[0m"<<endl;
            break;
        default:
            break;

    }


}