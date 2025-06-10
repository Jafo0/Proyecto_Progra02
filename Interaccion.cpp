#include <iostream>
#include <fstream>
#include <sstream>
#include "Interaccion.h"

Interaccion::Interaccion(){
    this->usuarios_registrados = new ListaUsuario();
}

Interaccion::Interaccion(std::ifstream& archivo){
    this->usuarios_registrados = new ListaUsuario();
    std::string linea_temp;

    while (getline(archivo, linea_temp)) {  //Leemos cada línea a partir de la siguiente
        std::stringstream ss(linea_temp);   //Creo un stream de la línea
        std::string elemento;               //Cada elemento separado por coma (csv)
        std::string elementos_csv[6];       // mi array de elementos 
        int i = 0;
        while (getline(ss, elemento, ',')) {        //Mientras se pueda: Leemos ss hasta la coma y guardamos en elemento
                elementos_csv[i] = elemento;        //Guardamos en el array
                i++;                    
        }

        std::string puesto = elementos_csv[0];
        std::string nombre = elementos_csv[1];
        int cedula = stoi(elementos_csv[2]);
        std::string nom_usuario = elementos_csv[3];
        std::string contrasenna = elementos_csv[4];
        int id = stoi(elementos_csv[5]);

        Usuario* usuario_nuevo;
        if(puesto == "Contribuidor"){
            usuario_nuevo = new Contribuidor(nombre, cedula, nom_usuario, contrasenna, id);
        }else{  //Si estoy en un Manager, sé que lo siguiente es leer sus ids asociados
            ListaUsuario* lista_ids = new ListaUsuario();
            lista_ids->leer_id_de_archivo(archivo, this->usuarios_registrados);
            usuario_nuevo = new Manager(nombre, cedula, nom_usuario, contrasenna, id, lista_ids);
        } 
        this->usuarios_registrados->agregarUsuario(usuario_nuevo); //Lo agregamos a la lista
        
    }
    archivo.close();  // Cierra el archivo
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
        Usuario* aux = this->usuarios_registrados->verificador(respuestaUs,respuestaPass);
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

int Interaccion::escoger_accion_usuario_contribuidor(){
    cout<<"--------------Opciones de Contribuidor--------------"<<endl;
    cout<<"1. Ver Calendario"<<endl;
    cout<<"2. Ver invitaciones pendientes"<<endl;
    cout<<"3. Crear nueva reservacion"<<endl;
    cout<<"4. Cancelar reservacion"<<endl;
    cout<<"5. Modificar reservacion"<<endl;
    cout<<"6. Ver Calendario de otros"<<endl;
    cout<<"7. Cerrar Sesion"<<endl;

    std::string respuesta;

    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,7, respuesta));

    return stoi(respuesta);
}

void Interaccion::realizar_accion_contribuidor(){
    bool salir {false};
    while(!salir){
        int accion;

        accion= escoger_accion_usuario_contribuidor();

        switch (accion) {
            case 1:
                system("cls");
                this->usuarioActivo->getCalendario()->imprimirCalendario();
                break;
            case 2:
                system("cls");
                cout<<"2. Ver invitaciones pendientes"<<endl;
                break;
            case 3:
                system("cls");
                this->usuarioActivo->getCalendario()->crear_reservacion();
                system("cls");
                break;
            case 4:{
                system("cls");
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != -1){
                    std::string posicion;
                    do{
                        cout<<"Ingrese el numero de reservacion que desea eliminar (<"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"): ";
                        getline(cin,posicion);
                    }while(!numero_entero_dentro_de_rango(0,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion));
                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(posicion));
                }else{
                    cout << "\033[31m"<<"\nNo tiene reservaciones en su calendario\n"<<"\033[0m" << endl;
                }
                break;
            }case 5:{
                system("cls");
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
            system("cls");
                cout<<"6. Ver Calendario de otros"<<endl;
                break;
            case 7:
            system("cls");
                cout<<"\033[33m"<<"Cerrando sesion..."<<"\033[0m"<<endl;
                salir = true;   //Cerrar sesion
                this->usuarioActivo = nullptr;
                break;
            default:
                break;
        }
        this->guardar_en_archivo(); 
    }
}

int Interaccion::escoger_accion_usuario_manager(){
    cout<<"--------------Opciones de Manager--------------"<<endl;
    cout<<"1. Ver Calendario"<<endl;
    cout<<"2. Ver invitaciones pendientes"<<endl;
    cout<<"3. Crear nueva reservacion"<<endl;
    cout<<"4. Cancelar reservacion"<<endl;
    cout<<"5. Modificar reservacion"<<endl;
    cout<<"6. Ver Calendario de otros"<<endl;
    cout<<"7. Modificar empleados / subalternos"<<endl;
    cout<<"8. Ver lista de empleados / subalternos"<<endl;
    cout<<"9. Cerrar Sesion"<<endl;

    std::string respuesta;
    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,9, respuesta));

    return stoi(respuesta);
}

void Interaccion::realizar_accion_manager(){
    bool salir {false};
    while(!salir){
        int accion_usuario;

        accion_usuario = escoger_accion_usuario_manager();
        
        switch (accion_usuario) {
            case 1:
                system("cls");
                this->usuarioActivo->getCalendario()->imprimirCalendario();
                break;
            case 2:
                system("cls");
                cout<<"2. Ver invitaciones pendientes"<<endl;
                break;
            case 3:
                system("cls");
                this->usuarioActivo->getCalendario()->crear_reservacion();
                system("cls");
                break;
            case 4:{
                system("cls");
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != -1){
                    std::string posicion;
                    do{
                        cout<<"Ingrese el numero de reservacion que desea eliminar (<"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"): ";
                        getline(cin,posicion);
                    }while(!numero_entero_dentro_de_rango(0,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion));
                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(posicion));
                }else{
                    cout << "\033[31m"<<"\nNo tiene reservaciones en su calendario\n"<<"\033[0m" << endl;
                }
                break;
            }case 5:{
                system("cls");
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
                system("cls");
                cout<<"6. Ver Calendario de otros"<<endl;
                break;
            case 7:
                system("cls");
                this->manActivo->modificar_listaEmp(this->usuarios_registrados);
                break;
            case 8:
                system("cls");
                manActivo->imprimirEmpleados();
                break;
            case 9:
                system("cls");
                cout<<"\033[33m"<<"Cerrando sesion..."<<"\033[0m"<<endl;
                salir = true;   //Cerrar sesion
                this->usuarioActivo = nullptr;
                this->manActivo = nullptr;
                break;
            default:
                break;
        }
        this->guardar_en_archivo(); 
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
        usuario_nuevo = new Manager(nom,ced_i,nomUs,pass, Usuario::contadorId);
    }else if(rol_i ==2){
        usuario_nuevo = new Contribuidor(nom,ced_i,nomUs,pass, Usuario::contadorId);
    }   

    system("cls");
    return usuario_nuevo;
}

void Interaccion::ejecutar(){
    this->guardar_en_archivo(); 
    int respuesta{0};
    bool flag = true;
    while (flag){
        respuesta = this->menu_entrada();   //Aquí nos aseguramos de tener una entrada válida
        switch (respuesta){
            case 1:{//crear
                Usuario* usuario_nuevo = crear_Usuario();
                this->usuarios_registrados->agregarUsuario(usuario_nuevo);
                break;}
            case 2:{//iniciar sesion
                if(this->usuarios_registrados->vacia()){
                    cout << "\033[31m"<<"\nNo puede iniciar sesion ya que no existen usuarios\n"<<"\033[0m" << endl;  
                }else{
                    if(this->iniciar_sesion()){
                        if(this->usuarioActivo->getPuesto() == "Contribuidor"){
                            this->realizar_accion_contribuidor();
                        }else{
                            this->realizar_accion_manager();
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
                system("cls");
                this->usuarios_registrados->imprimir();
                break;}
            default:
                cout << "\033[31m"<<"Opcion Invalida"<<"\033[0m" << endl;  
                break;
        }
        this->guardar_en_archivo(); //Después de cualquier accion, guardamos en archivo
    }
}

bool Interaccion::guardar_en_archivo() {
    std::ofstream archivo("../ArchivoUsuarios.txt"); //Para no borrar lo que ya existe
    if (archivo.is_open()) {
        this->usuarios_registrados->guardarEnArchivo(archivo);
        archivo.close();
        return true;
    }
    return false;

}