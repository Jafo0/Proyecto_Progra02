#include"Manager.h"
#include <iostream>
#include "ListaUsuario.h"

Manager::Manager(std::string nom, int ced, std::string nomUs, std::string pass, int id)
    :Usuario(nom,ced,nomUs,"Manager",pass, id){
        this->listaEmp = new ListaUsuario(); //atributo de lista empleado de manager
}

Manager::Manager(std::string nom, int ced, std::string nomUs, std::string pass, int id, ListaUsuario* lista_ids)
    :Usuario(nom,ced,nomUs,"Manager",pass, id){
        this->listaEmp = lista_ids;
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

void Manager::agregar_empleado(ListaUsuario* usuarios_registrados){ //Aquí ya hay contribuidores
    std::string respuesta;
    do{
        usuarios_registrados->imprimir_contribuidores();
        cout<<"\nIngrese el id del empleado que desea agregar como subordinado (-1 para salir): ";
        getline(cin, respuesta);
    }while(!de_string_a_int(respuesta));
    if(stoi(respuesta) == -1){
        system("cls");
        cout<<"\033[33m"<<"Saliendo..."<<"\033[0m"<<endl;
    }else{
        if(usuarios_registrados->comprobar_ID(stoi(respuesta))){    //Si el id existe
            this->listaEmp->agregar_contribuidor_por_id(usuarios_registrados, stoi(respuesta));
        }else{
            system("cls");
            cout<<"\033[33m"<<"El id ingresado no corresponde a ningun empleado..."<<"\033[0m"<<endl;
        }  
    }
}

void Manager::eliminar_empleado(){ //Aquí ya hay contribuidores
    std::string respuesta;
    do{
        this->listaEmp->imprimir_contribuidores();
        cout<<"\nIngrese el id del empleado que desea eliminar (-1 para salir): ";
        getline(cin, respuesta);
    }while(!de_string_a_int(respuesta));
    if(stoi(respuesta) == -1){
        system("cls");
        cout<<"\033[33m"<<"Saliendo..."<<"\033[0m"<<endl;
    }else{
        if(this->listaEmp->comprobar_ID(stoi(respuesta))){    //Si el id existe
            this->listaEmp->eliminar_contribuidor_por_id(stoi(respuesta));
            system("cls");
            cout<<"\033[32m"<<"El id ingresado ha sido eliminado con exito..."<<"\033[0m"<<endl;
        }else{
            system("cls");
            cout<<"\033[33m"<<"El id ingresado no corresponde a ningun empleado..."<<"\033[0m"<<endl;
        }  
    }
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
            system("cls");
            if(usuarios_registrados->hay_contribuidores()){ //Si en los usuarios generales hay contribuidores
                this->agregar_empleado(usuarios_registrados);
            }
            break;
        case 2:
            system("cls");
            if(this->listaEmp->hay_contribuidores()){   //Si tengo agregado algún contribuidor
                this->eliminar_empleado();
            }
            break;
        case 3:
            system("cls");
            cout<<"\033[33m"<<"Estoy regresando..."<<"\033[0m"<<endl;
            break;
        default:
            break;

    }
}

void Manager::guardar_en_archivo(std::ofstream& archivo){
    archivo << this->obtenerInfo()<<endl;
    this->listaEmp->guardar_id_en_archivo(archivo);
}