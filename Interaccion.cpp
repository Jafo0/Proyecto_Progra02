#include <iostream>
#include <fstream>
#include "Interaccion.h"

Interaccion::Interaccion(){
    this->lista = new ListaUsuario();
}

int Interaccion::menu_entrada(){
    int respuesta{0};
    while (true){
        cout<<"--------------Bienvenido a CalendarPro--------------"<<endl;
        cout<<"1. Crear Usuario" <<endl;
        cout<<"2. Iniciar Sesion" <<endl;
        cout<<"3. Salir" <<endl;
        cout<<"4. Ver Usuarios existentes" <<endl;
        cout<<"Indique que accion desea realizar: ";
        cin>>respuesta;
        cout<<endl;
        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else if(respuesta<1 || 4<respuesta){
            cout << "\033[31m"<<"Ingrese un numero en el rango de 1-3"<<"\033[0m" << endl;
            continue; 
        }else{
            return respuesta;
        }
    }
}

bool Interaccion::iniciar_sesion(){
    string respuestaUs;
    string respuestaPass;
    cin.ignore();       //Elimino el \n del cin anterior
    cout<<"--------------Inicio de sesion--------------"<<endl;

    //Nombre de usuario (sin espacios):
    while(true){
        cout<< "Ingrese su nombre de usuario: ";
        getline(cin,respuestaUs); 
        if(respuestaUs.empty()){
            cout << "\033[31m"<<"Ingrese algun nombre de Usuario"<<"\033[0m" << endl;
        }else if(respuestaUs.find(' ') != std::string::npos){   //Si encontró un espacio vacío
            cout << "\033[31m"<<"Ingrese un nombre de Usuario sin espacios"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }

    //Contraseña (sin espacios):
    while(true){
        cout<< "Ingrese la contrasenna: ";
        getline(cin,respuestaPass); 
        if(respuestaPass.find(' ') != std::string::npos){   //Si encontró un espacio vacío
            cout << "\033[31m"<<"Ingrese una contrasenna sin espacios"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }

    try{
        Usuario* aux = lista->verificador(respuestaUs,respuestaPass);
        if(aux != nullptr){
            cout<<"Inicio de sesion exitoso"<<endl;
            usuarioActivo = aux;
            return true;
        }else{
            cout<< "\033[31m"<<"Los datos ingresados son incorrectos. Regresando al menu principal"<<"\033[0m" << endl;
        }
    }catch (const invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    return false;
}

int Interaccion::menu_accion_usuario(){
    cout<<"--------------Opciones de calendario--------------"<<endl;
    cout<<"1. Ver Calendario"<<endl;
    cout<<"2. Ver invitaciones pendientes"<<endl;
    cout<<"3. Crear nueva reservacion"<<endl;
    cout<<"4. Cancelar reservacion"<<endl;
    cout<<"5. Modificar reservacion"<<endl;
    cout<<"6. Ver Calendario de otros"<<endl;
    cout<<"7. Cerrar Sesion"<<endl;


    int respuesta{0};
    while (true){
        cout<<"Indique que accion desea realizar: ";
        cin>>respuesta;
        cout<<endl;

        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;  
        }else if(respuesta<1 || 7<respuesta){
            cout << "\033[31m"<<"Ingrese un numero en el rango de 1-7"<<"\033[0m" << endl;
            continue; 
        }else{
            return respuesta;
        }
    }
}

Usuario* Interaccion::crear_Usuario(){
    string nom,nomUs,puesto,pass;
    int ced, rol;

    string mensaje;     //Para desplegar en pantalla el progreso de nuestra creacion de usuario

    mensaje += "--------------Creacion de usuario--------------\n";

    cout<<mensaje;
    
    cin.ignore();       //Elimino el \n del cin anterior
    
    //Nombre (puede tener espacios):
    while(true){
        cout<<"Ingrese su nombre: ";    //Puede tener espacios
        getline(cin,nom);
        if(nom.empty()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese algun nombre"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }

    //Ya con nombre valido:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su nombre: " + nom + "\n");
    cout<<mensaje;

    //Cédula (solo número):
    while(true){
        cout<<"Ingrese su cedula: ";    //No puede tener letras. 
        cin>>ced;

        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese una cedula valida"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }        
    cin.ignore();       //Elimino el \n del cin anterior

    //Ya con cédula valida:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su cedula: " + std::to_string(ced) + "\n");
    cout<<mensaje;

    //Nombre de usuario (sin espacios):
    while(true){
        cout<<"Cree un nombre de usuario: ";
        getline(cin,nomUs); 
        if(nomUs.empty()){
            cout << "\033[31m"<<"Ingrese algun nombre de Usuario"<<"\033[0m" << endl;
        }else if(nomUs.find(' ') != std::string::npos){   //Si encontró un espacio vacío
            cout << "\033[31m"<<"Ingrese un nombre de Usuario sin espacios"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }

    //Ya con nombre de usuario válido:
    system("cls");  //Limpio pantalla
    mensaje += ("Cree un nombre de usuario: " + nomUs + "\n");
    cout<<mensaje;

    //Contraseña (sin espacios):
    while(true){
        cout<<"Escriba una contrasena: ";
        getline(cin,pass); 
        if(pass.find(' ') != std::string::npos){   //Si encontró un espacio vacío
            cout << "\033[31m"<<"Ingrese una contrasenna sin espacios"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else{
            break;  //Me salgo del while
        }
    }

    //Ya con contraseña valida:
    system("cls");  //Limpio pantalla
    mensaje += ("Escriba una contrasena: " + pass + "\n");
    cout<<mensaje;


    //Rol (Solo 1 o 2):
    while(true){
        cout<<"Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor: ";
        cin>>rol;

        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;
            continue; //Vuelve al inicio del while
        }else if(rol != 1 && rol != 2){
            cout << "\033[31m"<<"Ingrese una opcion correcta"<<"\033[0m" << endl;
            continue; 
        }else{
            break;  //Me salgo del while
        }
    }

    //Ya con rol válido:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor: " + std::to_string(rol) + "\n");
    cout<<mensaje;

    Usuario* usuario_nuevo;

    if(rol == 1){
        usuario_nuevo = new Manager(nom,ced,nomUs,pass);
    }else if(rol ==2){
        usuario_nuevo = new ContribuidorI(nom,ced,nomUs,pass);
    }   

    system("cls");
    return usuario_nuevo;
}

void Interaccion::ejecutar(){
    int respuesta{0};
    bool flag = true;
    while (flag){
        respuesta = this->menu_entrada();   //Aquí nos aseguramos de tener una entrada válida
        switch (respuesta){
            case 1:{//crear
                Usuario* usuario_nuevo = crear_Usuario();
                this->lista->agregarUsuario(usuario_nuevo);
                break;}
            case 2:{//iniciar sesion
                if(this->lista->vacia()){
                    cout << "\033[31m"<<"No puede iniciar sesion ya que no existen usuarios"<<"\033[0m" << endl;  
                }else{
                    if(this->iniciar_sesion()){
                        bool salir {false};
                        while(!salir){
                            int accion_usuario = menu_accion_usuario();
                            switch (accion_usuario) {
                                case 1:
                                    cout << "Opción 1 seleccionada" << endl;
                                    break;
                                case 2:
                                    cout << "Opción 2 seleccionada" << endl;
                                    break;
                                case 3:
                                    cout << "Opción 3 seleccionada" << endl;
                                    break;
                                case 4:
                                    cout << "Opción 4 seleccionada" << endl;
                                    break;
                                case 5:
                                    cout << "Opción 5 seleccionada" << endl;
                                    break;
                                case 6:
                                    cout << "Opción 6 seleccionada" << endl;
                                    break;
                                case 7:
                                    cout << "Opción 7 seleccionada" << endl;
                                    break;
                                default:
                                    salir = true;
                                    break;
                            }
                        }
                    }                   
                }
                break;}
            case 3:{ //salir
                cout<<"\033[33m"<<"Saliendo del Programa..."<<"\033[0m"<<endl;
                flag=false;
                break;}
            case 4:{ //imprimir usuarios
                this->lista->imprimirUsuarios();
                break;}
            default:
                cout << "\033[31m"<<"Opcion Invalida"<<"\033[0m" << endl;  
                break;
        }
    }
}