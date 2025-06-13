#include "Interaccion.h"
#include "Encabezados.h"

Interaccion::Interaccion(){this->usuariosRegistrados = new ListaUsuario();}

Interaccion::~Interaccion(){delete this->usuariosRegistrados;}

int Interaccion::menu_entrada(){
    string respuesta;   
    while (true){
        cout<<"--------------Bienvenido a CalendarPro--------------"<<endl;
        cout<<"1. Crear Usuario" <<endl;
        cout<<"2. Iniciar Sesion" <<endl;
        cout<<"3. Salir" <<endl;
        cout<<"4. Ver Usuarios existentes" <<endl;
        cout<<"Indique que accion desea realizar: ";

        getline(cin,respuesta);
        if(numero_entero_dentro_de_rango(1,4,respuesta)){
            return stoi(respuesta);
        }
    }
}

string Interaccion::pedirTexto(string encabezado){
    string texto;
    do{
        cout<< encabezado;
        getline(cin,texto); 
    }while(!texto_no_vacio_sin_espacios(texto));

    return texto;
}

int Interaccion::pedirCedula(){
    string cedula;
    do{
        cout<< "Ingrese su cedula: ";
        getline(cin,cedula); 
    }while(!numero_entero_sin_rango(cedula));

    return stoi(cedula);
}

int Interaccion::pedirPuesto(){
    string puesto;
    do{
        cout<<"Ingrese su tipo de rol:\n (1)Manager (2)Contribuidor: ";
        getline(cin,puesto); 
    }while(!numero_entero_dentro_de_rango(1,2,puesto));

    return stoi(puesto);
};

int Interaccion::menuAccionContribuidor(){
    cout<<"--------------Opciones de Contribuidor--------------"<<endl;
    cout<<"1. Ver Calendario"<<endl;
    cout<<"2. Ver invitaciones pendientes"<<endl;
    cout<<"3. Crear nueva reservacion"<<endl;
    cout<<"4. Cancelar reservacion"<<endl;
    cout<<"5. Modificar reservacion"<<endl;
    cout<<"6. Ver Calendario de otros"<<endl;
    cout<<"7. Cerrar Sesion"<<endl;

    string respuesta;
    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,7, respuesta));

    return stoi(respuesta);
}

int Interaccion::menuAccionManager(){
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

    string respuesta;
    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,9, respuesta));

    return stoi(respuesta);
}

Usuario* Interaccion::crear_Usuario(){
    cout<<"--------------Creacion de usuario--------------\n";
    
    string nombre = this->pedirTexto("Ingrese su nombre: ");

    int cedula = this->pedirCedula();

    string nombreUsuario = this->pedirTexto("Ingrese su nombre de usuario: ")
           , contrasenna = this->codificar(this->pedirTexto("Ingrese su contrasenna: "));

    int puesto = this->pedirPuesto();


    Usuario* usuario_nuevo;
    if(usuariosRegistrados->verificador2(cedula,nombreUsuario)){//si esto es falso
        if(puesto == 1){
            usuario_nuevo = new Manager(nombre,cedula,nombreUsuario,contrasenna, Usuario::contadorId);
        }else if(puesto ==2){
            usuario_nuevo = new Contribuidor(nombre,cedula,nombreUsuario,contrasenna, Usuario::contadorId);
        } 
        
        return usuario_nuevo;
    }else{
         //limpio
        cout<<"\033[31m"<<"Error, el nombre de usuario o cedula ya estan en uso"<<"\033[0m"<<endl;
        usuario_nuevo = nullptr;
        return usuario_nuevo;
    }
}

bool Interaccion::iniciar_sesion(){
    
    cout<<"--------------Inicio de sesion--------------"<<endl;
    string nombreUsuario = this->pedirTexto("Ingrese el nombre de usuario: ")
           , contrasenna = this->codificar(this->pedirTexto("Ingrese la contrasenna: "));
    
    try{
        Usuario* aux = this->usuariosRegistrados->verificador(nombreUsuario,contrasenna);
        if(aux != nullptr){
            
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

void Interaccion::realizarAccionContribuidor(){
    bool salir {false};
    while(!salir){
        switch (menuAccionContribuidor()) {
            case 1:              
                this->usuarioActivo->getCalendario()->imprimirCalendarioCompleto();
                break;
            case 2:
                
                cout<<"2. Ver invitaciones pendientes"<<endl;
                break;
            case 3:

                this->usuarioActivo->getCalendario()->crearReservacion(this->usuarioActivo);
                break;
            case 4:{ 
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != 0){
                    string posicion;
                    do{
                        cout<<"\033[33m"<<"Ingrese el numero de reservacion que desea eliminar [1,"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"]: "<<"\033[0m";
                        getline(cin,posicion);
                    }while(!numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion));
                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(posicion));
                    cout<< "\033[32m"<<"\nReservacion eliminada exitosamente\n"<<"\033[0m" << endl;
                }else{
                    cout << "\033[31m"<<"\nNo tiene reservaciones en su calendario\n"<<"\033[0m" << endl;
                }
                break;
            }case 5:{
                string i;
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != 0){  //Calendario no vacío
                    this->usuarioActivo->getCalendario()->imprimirCalendarioCompleto();
                    do{
                        cout<<"\033[33m"<<"Ingrese el numero de reservacion que desea modificar [1,"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"]: "<<"\033[0m";
                        getline(cin, i);
                    }while(!numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), i));

                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(i));
                    this->usuarioActivo->getCalendario()->crearReservacion(usuarioActivo);
                }
                break;
            }case 6:{
                string id;
                do{
                    cout<<"Ingrese el id de la persona que desea ver: ";
                    getline(cin, id);
                }while(!numero_entero_sin_rango(id));

                if(usuarioActivo->getID() == stoi(id)){
                    cout << "\033[33m"<<"Si desea ver su propio id vaya a opcion (1)\n"<<"\033[0m" << endl;
                    break;
                }
                if(this->usuariosRegistrados->comprobarID(stoi(id))){
                    this->usuariosRegistrados->UsuarioPorID(stoi(id))->getCalendario()->imprimirCalendarioOculto();
                }else{
                    cout << "\033[33m"<<"El id ingresado no corresponde a ningun usuario\n"<<"\033[0m" << endl;
                }
                break;
            }case 7:
            
                cout<<"\033[33m"<<"Cerrando sesion..."<<"\033[0m"<<endl;
                salir = true;   //Cerrar sesion
                this->usuarioActivo = nullptr;
                break;
            default:
                break;
        }
        this->escribirEnArchivo();
    }
}

void Interaccion::realizarAccionManager(){
    bool salir {false};
    while(!salir){
        switch (menuAccionManager()) {
            case 1:
                this->usuarioActivo->getCalendario()->imprimirCalendarioCompleto();
                break;
            case 2:
                
                cout<<"2. Ver invitaciones pendientes"<<endl;
                break;
            case 3:
                this->usuarioActivo->getCalendario()->crearReservacion(this->usuarioActivo);
                break;
            case 4:{
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != 0){
                    string posicion;
                    do{
                        cout<<"\033[33m"<<"Ingrese el numero de reservacion que desea eliminar [1,"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"]: "<<"\033[0m";
                        getline(cin,posicion);
                    }while(!numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), posicion));
                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(posicion));
                    cout<< "\033[32m"<<"\nReservacion eliminada exitosamente\n"<<"\033[0m" << endl;
                }else{
                    cout << "\033[31m"<<"\nNo tiene reservaciones en su calendario\n"<<"\033[0m" << endl;
                }
                break;
            }case 5:{
                string i;
                if(this->usuarioActivo->getCalendario()->getCantidadReservaciones() != 0){  //Calendario no vacío
                    this->usuarioActivo->getCalendario()->imprimirCalendarioCompleto();
                    do{
                        cout<<"\033[33m"<<"Ingrese el numero de reservacion que desea eliminar [1,"<<this->usuarioActivo->getCalendario()->getCantidadReservaciones()<<"]: "<<"\033[0m";
                        getline(cin, i);
                    }while(!numero_entero_dentro_de_rango(1,this->usuarioActivo->getCalendario()->getCantidadReservaciones(), i));

                    this->usuarioActivo->getCalendario()->eliminarReservacion(stoi(i));
                    this->usuarioActivo->getCalendario()->crearReservacion(this->usuarioActivo);
                }
                break;
            }case 6:{
                string id;
                do{
                    cout<<"Ingrese el id de la persona que desea ver: ";
                    getline(cin, id);
                }while(!numero_entero_sin_rango(id));
                if(usuarioActivo->getID() == stoi(id)){
                    cout << "\033[33m"<<"Si desea ver su propio id vaya a opcion (1)\n"<<"\033[0m" << endl;
                    break;
                }
                if(this->usuariosRegistrados->comprobarID(stoi(id))){
                    this->usuariosRegistrados->UsuarioPorID(stoi(id))->getCalendario()->imprimirCalendarioOculto();
                }else{
                    cout << "\033[33m"<<"El id ingresado no corresponde a ningun usuario\n"<<"\033[0m" << endl;
                }
                break;}
            case 7:
                
                this->manActivo->modificarSubordinados(this->usuariosRegistrados);
                break;
            case 8:
                
                manActivo->imprimirSubordinados();
                break;
            case 9:
                
                cout<<"\033[33m"<<"Cerrando sesion..."<<"\033[0m"<<endl;
                salir = true;   //Cerrar sesion
                this->usuarioActivo = nullptr;
                this->manActivo = nullptr;
                break;
            default:
                break;
        }
        this->escribirEnArchivo(); 
    }
}

void Interaccion::escribirEnArchivo() {
    ofstream archivo("../ArchivoUsuarios.txt");   
    ofstream archivoOtro("../ActividadesColaborativas.txt");
    if (archivo.is_open()) {
        this->usuariosRegistrados->escribirEnArchivo(archivo, archivoOtro);
    }
}

void Interaccion::leerArchivo(std::ifstream& archivo){
    string linea_temp;

    while (getline(archivo, linea_temp)) {  //Leemos cada línea a partir de la siguiente
        if(linea_temp == "Contribuidor"){
            this->leerContribuidor(archivo);
        }else{
            this->leerManager(archivo);
        }
    }
    archivo.close();  // Cierra el archivo
}

void Interaccion::leerManager(std::ifstream& archivo){
    /*
    Para info general del manager
    */
    string linea_temp;
    getline(archivo, linea_temp);
    std::stringstream ss(linea_temp);   //Creo un stream de la línea
    string dato;               //Cada elemento separado por coma (csv)
    string datos_csv[5];       // mi array de elementos 
    int i = 0;
    while (getline(ss, dato, ',')) {        //Mientras se pueda: Leemos ss hasta la coma y guardamos en elemento
            datos_csv[i] = dato;        //Guardamos en el array
            i++;                    
    }
    //Defino los datos
    string nombre = datos_csv[0];
    int cedula = stoi(datos_csv[1]);
    string nom_usuario = datos_csv[2];
    string contrasenna = datos_csv[3];
    int id = stoi(datos_csv[4]);

    Usuario* usuario_nuevo = new Manager(nombre, cedula, nom_usuario, contrasenna, id); //Creo manager con calendario vacio

    this->manActivo = static_cast<Manager*>(usuario_nuevo); 
    
    this->manActivo->listaSubordinados->leerIds(archivo, this->usuariosRegistrados);    //Leo los subordinados

    this->manActivo->leerCalendarioDeArchivo(archivo);   //Leo su calendario

    this->usuariosRegistrados->agregarUsuario(usuario_nuevo); //Lo agregamos a la lista

    this->manActivo == nullptr;
}

void Interaccion::leerContribuidor(std::ifstream& archivo){
    /*
    Para info general del contribuidor
    */

    string linea_temp;
    getline(archivo, linea_temp);
    std::stringstream ss(linea_temp);   //Creo un stream de la línea
    string dato;               //Cada elemento separado por coma (csv)
    string datos_csv[5];       // mi array de elementos 
    int i = 0;
    while (getline(ss, dato, ',')) {        //Mientras se pueda: Leemos ss hasta la coma y guardamos en elemento
            datos_csv[i] = dato;        //Guardamos en el array
            i++;                    
    }
    //Defino los datos
    string nombre = datos_csv[0];
    int cedula = stoi(datos_csv[1]);
    string nom_usuario = datos_csv[2];
    string contrasenna = datos_csv[3];
    int id = stoi(datos_csv[4]);

    Usuario* usuario_nuevo = new Contribuidor(nombre, cedula, nom_usuario, contrasenna, id); //Creo contribuidor con calendario vacio

    usuario_nuevo->leerCalendarioDeArchivo(archivo);   //Leo su calendario

    this->usuariosRegistrados->agregarUsuario(usuario_nuevo); //Lo agregamos a la lista
}

string Interaccion::codificar(string contrasenna){
    int longitud = contrasenna.length();    //Longitud de la contraseña
    const char* arreglo_original = contrasenna.c_str(); //Función vista en clase
    string contrasenna_codificada; //Contraseña codificada
    for(int i = 0; i < longitud; i++){
        contrasenna_codificada += arreglo_original[i] + '5'; //Hago el mapeo para que la contraseña no se vea como la ingresada por el usuario
    }
    return contrasenna_codificada;
}

void Interaccion::ejecutar(){
    this->escribirEnArchivo(); 
    int respuesta{0};
    bool flag = true;
    while (flag){
        respuesta = this->menu_entrada();   //Aquí nos aseguramos de tener una entrada válida
        switch (respuesta){
            case 1:{//crear
                Usuario* usuario_nuevo = crear_Usuario();
                if(usuario_nuevo != nullptr){
                    this->usuariosRegistrados->agregarUsuario(usuario_nuevo);
                    break;}
                }
                break;
            case 2:{//iniciar sesion
                if(this->usuariosRegistrados->vacia()){
                    cout << "\033[31m"<<"\nNo puede iniciar sesion ya que no existen usuarios\n"<<"\033[0m" << endl;  
                }else{
                    if(this->iniciar_sesion()){
                        if(this->usuarioActivo->getPuesto() == "Contribuidor"){
                            this->realizarAccionContribuidor();
                        }else{
                            this->realizarAccionManager();
                        }
                    }                   
                }
                break;}
            case 3:{ //salir
                
                cout<<"\033[33m"<<"Saliendo del Programa..."<<"\033[0m"<<endl;
                flag=false;
                break;}
            case 4:{ //imprimir usuarios
                
                this->usuariosRegistrados->imprimir("No hay usuarios registrados", "Usuarios registrados: ");
                break;}
            default:
                cout << "\033[31m"<<"Opcion Invalida"<<"\033[0m" << endl;  
                break;
        }
        this->escribirEnArchivo(); //Después de cualquier accion, guardamos en archivo
    }
}
