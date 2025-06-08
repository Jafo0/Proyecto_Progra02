#include <iostream>
#include <fstream>
#include "Interaccion.h"

Interaccion::Interaccion(){
    this->lista = new ListaUsuario();
}

int Interaccion::menu_entrada(){
    std::string respuesta;   //Respuesta en std::string
    int respuesta_i{};    //Respuesta en int
    while (true){
        cout<<"--------------Bienvenido a CalendarPro--------------"<<endl;
        cout<<"1. Crear Usuario" <<endl;
        cout<<"2. Iniciar Sesion" <<endl;
        cout<<"3. Salir" <<endl;
        cout<<"4. Ver Usuarios existentes" <<endl;
        cout<<"Indique que accion desea realizar: ";

        getline(cin,respuesta);
        if(numero_entero_dentro_de_rango(1,4,respuesta)){
            respuesta_i = stoi(respuesta);
            return respuesta_i;
        }
    }
}

bool Interaccion::iniciar_sesion(){
    std::string respuestaUs;
    std::string respuestaPass;
    system("cls");
    cout<<"--------------Inicio de sesion--------------"<<endl;

    //Nombre de usuario:---------------------------------------------------------------------------------------------------
    while(true){
        cout<< "Ingrese su nombre de usuario: ";
        getline(cin,respuestaUs); 
        if(texto_no_vacio_sin_espacios(respuestaUs)){break;}
    }

    //Contraseña:---------------------------------------------------------------------------------------------------------
    while(true){
        cout<< "Ingrese la contrasenna: ";
        getline(cin,respuestaPass); 
        if(texto_no_vacio_sin_espacios(respuestaPass)){break;}
    }

    try{
        Usuario* aux = lista->verificador(respuestaUs,respuestaPass);
        if(aux != nullptr){
            system("cls");
            cout<< "\033[32m"<<"\nInicio de sesion exitoso\n"<<"\033[0m" << endl;
            this->usuarioActivo = aux; 
            if(aux->getPuesto() == "Manager"){
                this->manActivo = static_cast<Manager*>(aux); //comprobacion si el inicio de sesion fue un usuario manager
            }else{manActivo=nullptr;}                   //casteo para que sea valido
            return true;
        }else{
            cout<< "\033[31m"<<"\nLos datos ingresados son incorrectos. Regresando al menu principal\n"<<"\033[0m" << endl;
        }
    }catch (const std::invalid_argument& e){
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

    //opciones solo visibles para los manager
    if (usuarioActivo->getPuesto()=="Manager"){ 
        cout<<"8. Modificar empleados / subalternos"<<endl;
        cout<<"9. Ver lista de empleados / subalternos"<<endl;
    }

    std::string respuesta;
    while (true){
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
        if(usuarioActivo->getPuesto()=="Manager"){//opcion solo para los manager, tienen 1 a 9 opciones
            if(numero_entero_dentro_de_rango(1,9, respuesta)){
                return stoi(respuesta);
            }
        }else{
            if(numero_entero_dentro_de_rango(1,7, respuesta)){
                return stoi(respuesta);
            }
        }
    }
}

Usuario* Interaccion::crear_Usuario(){
    system("cls");
    std::string nom, nomUs, puesto, pass, ced, rol;
    int ced_i, rol_i;

    std::string mensaje;     //Para desplegar en pantalla el progreso de nuestra creacion de usuario

    mensaje += "--------------Creacion de usuario--------------\n";

    cout<<mensaje;
    
    
    //Nombre:------------------------------------------------------------------------------------------------
    while(true){
        cout<<"Ingrese su nombre: ";    //Puede tener espacios
        getline(cin,nom);  
        if(texto_no_vacio_sin_espacios(nom)){break;}
    }

    //Ya con nombre valido:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su nombre: " + nom + "\n");
    cout<<mensaje;

    //Cédula:------------------------------------------------------------------------------------------------
    while(true){
        cout<<"Ingrese su cedula: ";    //No puede tener letras. 
        getline(cin, ced);
        if(numero_entero_sin_rango(ced)){
            ced_i = stoi(ced);
            break;  //Me salgo del while
        }
    }        

    //Ya con cédula valida:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su cedula: " + std::to_string(ced_i) + "\n");
    cout<<mensaje;

    //Nombre de usuario:---------------------------------------------------------------------------------------
    while(true){
        cout<<"Cree un nombre de usuario: ";
        getline(cin,nomUs); 
        if(texto_no_vacio_sin_espacios(nomUs)){break;}
    }

    //Ya con nombre de usuario válido:
    system("cls");  //Limpio pantalla
    mensaje += ("Cree un nombre de usuario: " + nomUs + "\n");
    cout<<mensaje;

    //Contraseña:---------------------------------------------------------------------------------------------------
    while(true){
        cout<<"Escriba una contrasena: ";
        getline(cin,pass); 
        if(texto_no_vacio_sin_espacios(pass)){break;}
    }

    //Ya con contraseña valida:
    system("cls");  //Limpio pantalla
    mensaje += ("Escriba una contrasena: " + pass + "\n");
    cout<<mensaje;


    //Rol (Solo 1 o 2):-------------------------------------------------------------------------------------------
    while(true){
        cout<<"Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor: ";
        getline(cin,rol); 

        if(numero_entero_dentro_de_rango(1,2,rol)){
            rol_i = stoi(rol);
            break;
        }
    }

    //Ya con rol válido:
    system("cls");  //Limpio pantalla
    mensaje += ("Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor: " + std::to_string(rol_i) + "\n");
    cout<<mensaje;

    Usuario* usuario_nuevo;

    if(rol_i == 1){
        usuario_nuevo = new Manager(nom,ced_i,nomUs,pass);
    }else if(rol_i ==2){
        usuario_nuevo = new ContribuidorI(nom,ced_i,nomUs,pass);
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
                    cout << "\033[31m"<<"\nNo puede iniciar sesion ya que no existen usuarios\n"<<"\033[0m" << endl;  
                }else{
                    if(this->iniciar_sesion()){
                        bool salir {false};
                        while(!salir){
                            int accion_usuario = menu_accion_usuario();
                            switch (accion_usuario) {
                                case 1:
                                // system("cls");
                                    this->usuarioActivo->getCalendario()->imprimirCalendario();
                                    break;
                                case 2:
                                    cout<<"2. Ver invitaciones pendientes"<<endl;
                                    break;
                                case 3:
                                    // system("cls");
                                    this->usuarioActivo->getCalendario()->crear_reservacion();
                                    break;
                                case 4:{
                                    std::string posicion;
                                    while(true){
                                        cout<<"Ingrese el numero de reservacion que desea eliminar (<"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"): ";
                                        getline(cin,posicion);
                                        if(numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion)){
                                            this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(posicion));
                                            break;
                                        }
                                    }
                                    break;
                                }case 5:{
                                    std::string posicion;
                                    while(true){
                                        cout<<"Ingrese el numero de reservacion que desea modificar (<"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"): ";
                                        getline(cin,posicion);
                                        if(numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion)){
                                            this->usuarioActivo->getCalendario()->modificarReservacion(stoi(posicion));
                                            break;
                                        }
                                    }
                                    break;
                                }case 6:
                                    cout<<"6. Ver Calendario de otros"<<endl;
                                    break;
                                case 7:
                                    cout<<"\033[33m"<<"Cerrando sesion..."<<"\033[0m"<<endl;
                                    salir = true;   //Cerrar sesion
                                    break;
                                case 8:
                                    cout<< "Opción 8 seleccionada" << endl;
                                    modificar_empleados();
                                    break;
                                case 9:
                                    cout<< "Opción 9 seleccionada" << endl;
                                    manActivo->listaEmp.imprimir();
                                    break;
                                default:
                                    break;
                            }
                        }
                    }                   
                }
                break;}
            case 3:{ //salir
                system("cls");
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

bool Interaccion::modificar_empleados(){
    int idEntrada;

    while (true){
        cout<<"Ingrese el Id de la persona que desea agregar: ";
        cin>>idEntrada;
        if(cin.fail()){
            cin.clear();              
            cin.ignore(1000, '\n');
            cout << "\033[31m"<<"Ingrese un numero"<<"\033[0m" << endl;
            continue;
        }else{break;} //si la entrada es valida
    }
    try{
        Usuario* aux = lista->encontrarId(idEntrada);
        if(aux != nullptr){
            bool flag = manActivo->listaEmp.agregarId(aux);
            if(flag){
                cout<<"Usuario agregado a su lista de empleados exitosamente"<<endl;
            }else{cout<<"\033[31m"<<"Usuario que desea agregar ya estaba en su lista"<<"\033[0m"<<endl;}
            
            //como ListaEmpleados esta declarado como atributo publico, 
            //entonces puedo acceder a el directamente
            return true;
        }else{
            cout<< "\033[31m"<<"ID no reponden a ningun usuario o es el de un manager. Regresando al menu principal"<<"\033[0m" << endl;
        }
    }catch (const std::invalid_argument& e){
        cout << "Error: " << e.what() << endl;
    }
    return false;
}

