#include <iostream>
#include <fstream>
#include "Interaccion.h"

Interaccion::Interaccion(ListaUsuario* lista_n):lista(lista_n){}

void Interaccion::ejecutar(){
    int respuesta{0};
    bool flag = true;
    while (flag){
        cout<<"--------------Bienvenido a CalendarPro--------------"<<endl;
        cout<<"1. Crear Usuario" <<endl;
        cout<<"2. Iniciar Sesion" <<endl;
        cout<<"3. Salir" <<endl;
        cout<<"Indique que accion desea realizar: ";
        cin>>respuesta;
        cout<<endl;
        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }

        if(1>respuesta || 3<respuesta){
            cout << "\033[31m"<<"Ingrese un numero en el rango de 1-3"<<"\033[0m" << endl;
            continue; 
        }else{
            switch (respuesta){
            case 1:{//crear
                crear_Usuario();
                break;}
            case 2:{//iniciar sesion
                menu_general();
                menu_usuario();
                break;}
            case 3:{ //salir
                cout<<"\033[33m"<<"Saliendo del Programa..."<<"\033[0m"<<endl;
                flag=false;
                break;}
            default:
                cout << "\033[31m"<<"Opcion Invalida"<<"\033[0m" << endl;  
                break;
            }
        }
    }
}

void Interaccion::crear_Usuario(){
    string nom,ced,nomUs,puesto,pass;
    int rol;
    cout<<"--------------Creacion de usuario--------------"<<endl;
    while(true){
        cout<<"Ingrese su nombre: ";
        cin>>nom;
        cout<<"Ingrese su cedula: ";
        cin>>ced;
        cout<<"Cree un nombre de ususario: ";
        cin>>nomUs;
        cout<<"Escriba una contrasena: ";
        cin>>pass;
        cout<<"Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor";
        cin>>rol;

        if(rol == 1){
            Usuario* m = new Manager(nom,ced,nomUs,pass, lista);
            lista->agregarUsuario(m);
            lista->guardarEnArchivo(); //hacer las funciones de agregar lista y guardar en archivo
            break;

        }else if(rol ==2){
            Usuario* m = new ContribuidorI(nom,ced,nomUs,pass, lista);
            lista->agregarUsuario(m);
            lista->guardarEnArchivo();
            break;

        }else{
            if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;  
            }
        }
    }
}

void Interaccion::menu_general(){
    string respuestaUs;
    string respuestaPass;
    cout<<"--------------Inicio de sesion--------------"<<endl;
    while (true){
        try{
            cout<< "Ingrese su nombre de usuario: "<<endl;
            cin >>respuestaUs;
            cout<< "Ingrese la contrasena: "<<endl;
            cin>>respuestaPass;
            Usuario* aux = lista->verificador(respuestaUs,respuestaPass);
            if(aux != nullptr){
                cout<<"Inicio de sesion exitoso"<<endl;
                usuarioActivo = aux;
                break;                                  //me salgo del ciclo
            }else{
                cout<< "\033[31m"<<"Datos ingresados son incorrectos"<<"\033[0m" << endl;
            }
        }catch (const invalid_argument& e){
            cout << "Error: " << e.what() << endl;
        }
    }
}

void Interaccion::menu_usuario(){
    cout<<"--------------Opciones de calendario--------------"<<endl;
    cout<<"1. Ver Calendario"<<endl;
    cout<<"2. Ver invitaciones pendientes"<<endl;
    cout<<"3. Crear nueva reservacion"<<endl;
    cout<<"4. Cancelar reservacion"<<endl;
    cout<<"5. Modificar reservacion"<<endl;
    cout<<"6. Ver Calendario de otros"<<endl;

    int respuesta{0};
    while (true){
        cout<<"Indique que accion desea realizar: ";
        cin>>respuesta;
        cout<<endl;

        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;  
        }
    }
}
