#include "Calendario.h"

Calendario::Nodo::Nodo(Reservacion* _reservacion, Nodo* _nodo_siguiente) : reservacion(_reservacion), nodo_siguiente(_nodo_siguiente){}

Calendario::Nodo::~Nodo(){
    delete this->reservacion;
}

void Calendario::Nodo::setSiguiente(Nodo* _nodo_siguiente){this->nodo_siguiente = _nodo_siguiente;}

Calendario::Calendario(){
    this->segundos_actual = time(nullptr);      
    this->fecha_actual = *localtime(&segundos_actual);  
}

Calendario::~Calendario(){
    if(this->primera_reservacion){  //Si tenemos al menos una reservacion
        while(this->primera_reservacion){    //Mientras tengamos reservaciones activas
            Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
            this->primera_reservacion = this->primera_reservacion->nodo_siguiente;  //Movemos la reservación más próxima a la siguiente
            delete temp;    //Eliminamos la reservación auxiliar
        }
    }
}

int Calendario::getCantidadReservaciones(){return this->cantidad_reservaciones;}

bool Calendario::reservacion_incorrecta(struct tm fecha_inicio, struct tm fecha_fin, struct tm fecha_actual){//Revisa que la fecha de fin sea mayor a la fecha inicio
    bool reservacion_incorrecta {true};
    time_t segundos_inicio = mktime(&fecha_inicio);
    time_t segundos_fin = mktime(&fecha_fin);
    if(segundos_inicio<this->segundos_actual){
        cout<<"\033[31m"<<"\nLa fecha de inicio no puede estar en el pasado"<<"\033[0m"<<endl;
    }else if(segundos_fin<segundos_inicio){
        cout<<"\033[31m"<<"\nLa fecha de fin no puede ser previa a la fecha de inicio"<<"\033[0m"<<endl;
    }else if(segundos_fin==segundos_inicio){
        cout<<"\033[31m"<<"\nLa fecha de fin no puede igual a la fecha de inicio"<<"\033[0m"<<endl;
    }else{
        reservacion_incorrecta = false;
    }
    return reservacion_incorrecta;
}

bool Calendario::choque_con_calendario(struct tm fecha_inicio, struct tm fecha_fin){//Revisa que la reserva no choque con otra del calendario
    time_t segundos_inicio = mktime(&fecha_inicio);
    time_t segundos_fin = mktime(&fecha_fin);

    Nodo* aux = this->primera_reservacion;
    while(aux){
        if(aux->reservacion->fecha_choca(fecha_inicio)||aux->reservacion->fecha_choca(fecha_fin)){  //Si las fechas ingresadas chocan con cualquier evento del calendario
            cout<<"\033[31m"<<"\nLa reservacion NO pudo ser agregada ya que choca con otra fecha del calendario"<<"\033[0m"<<endl;
            return true;
        } 
        aux = aux->nodo_siguiente;
    }
    return false;
}

struct tm Calendario::preguntarDia(){
    cout<<"--------------Fecha del Evento Diario--------------"<<endl;

    std::string anno, mes, dia;    //Cadenas de texto
    int anno_i {0}, mes_i {0}, dia_i {1};    //Valores numericos

    while(true){//------------------------------------------------------------------------------------------
        int anno_actual = this->fecha_actual.tm_year+1900;
        cout<<"Ingrese el numero del anno ("<<anno_actual<<"<=): ";
        getline(cin, anno);

        if(numero_entero_dentro_de_rango(anno_actual, 3000, anno)){
            anno_i = stoi(anno)-1900;
            break;
        }
    }

    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese el numero del mes (1-12): ";
        getline(cin, mes);  //Convertimos a entero
        if(numero_entero_dentro_de_rango(1, 12, mes)){
            mes_i = stoi(mes)-1;
            break;
        }
    }

    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese el numero del dia (1-31): ";
        getline(cin, dia);
        if(numero_entero_dentro_de_rango(1, 31, dia)){
            dia_i = stoi(dia);  //Convertimos a entero
            break;
        }
    }

    struct tm fecha = {};   //Fecha con todos sus valores en cero
    fecha.tm_year = anno_i; //Modifico sus valores a los valores ingresados
    fecha.tm_mon = mes_i;     
    fecha.tm_mday = dia_i;

    return fecha;
}

struct tm Calendario::preguntarFecha(std::string mensaje){
    cout<<mensaje<<endl;

    std::string anno, mes, dia, hora, min;    //Cadenas de texto
    int anno_i {0}, mes_i {0}, dia_i {1}, hora_i {0}, min_i {0};    //Valores numericos

    while(true){//------------------------------------------------------------------------------------------
        int anno_actual = this->fecha_actual.tm_year+1900;
        cout<<"Ingrese el numero del anno ("<<anno_actual<<"<=): ";
        getline(cin, anno);

        if(numero_entero_dentro_de_rango(anno_actual, 3000, anno)){
            anno_i = stoi(anno)-1900;
            break;
        }
    }
    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese el numero del mes (1-12): ";
        getline(cin, mes);

        if(numero_entero_dentro_de_rango(1, 12, mes)){
            mes_i = stoi(mes)-1;
            break;
        }
    }

    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese el numero del dia (1-31): ";
        getline(cin, dia);

        if(numero_entero_dentro_de_rango(1, 31, dia)){
            dia_i = stoi(dia);
            break;
        }
    }

    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese la hora (0-23): ";
        getline(cin, hora);
        if(numero_entero_dentro_de_rango(0, 23, hora)){
            hora_i = stoi(hora);
            break;
        }
    }

    while(true){//------------------------------------------------------------------------------------------
        cout<<"Ingrese el minuto (0-59): ";
        getline(cin, min);
        if(numero_entero_dentro_de_rango(0, 59, min)){
            min_i = stoi(min);
            break;
        }
    }

    struct tm fecha = {};   //Fecha con todos sus valores en cero
    fecha.tm_year = anno_i; //Modifico sus valores a los valores ingresados
    fecha.tm_mon = mes_i;     
    fecha.tm_mday = dia_i;
    fecha.tm_hour = hora_i;
    fecha.tm_min = min_i;

    return fecha;
}

int Calendario::menu_reservaciones(){
    cout<<"--------------Opciones de reservacion--------------"<<endl;
    cout<<"1. Reunion"<<endl;
    cout<<"2. Cita personal"<<endl;
    cout<<"3. Actividad social"<<endl;
    cout<<"4. Evento diario"<<endl;
    
    std::string reserva;
    int reserva_i;
    while(true){
        cout<<"Indique que tipo de reservacion desea crear: ";
        getline(cin, reserva);
        if(numero_entero_dentro_de_rango(1,4,reserva)){
            reserva_i = stoi(reserva);
            return reserva_i;
        }
    }   
}

void Calendario::crear_reservacion(int id_organizador){
    Reservacion* reservacion {nullptr};
    int tipo_reservacion = this->menu_reservaciones(); //Indico qué reservación quiero
    system("cls");

    struct tm fecha_inicio {}, fecha_fin {}; 

    //Pregunto las fechas:
    if(tipo_reservacion == 4){  //Si la reservación es evento diario
        fecha_inicio = this->preguntarDia();
        fecha_fin = fecha_inicio;
        fecha_fin.tm_mday+=1;
    }else{  //La reservación no es un evento diario
        fecha_inicio = this->preguntarFecha("--------------Datos para la fecha de inicio de la reservacion--------------");
        fecha_fin = this->preguntarFecha("--------------Datos para la fecha de final de la reservacion--------------");
    }

    system("cls");
    //Este condicional es: La fecha tiene sentido (fin posterior al inicio) y no choca con ninguna otra
    if(!this->reservacion_incorrecta(fecha_inicio, fecha_fin, this->fecha_actual) && !this->choque_con_calendario(fecha_inicio, fecha_fin)){   // Reservacion correcta
        switch (tipo_reservacion){  //Creo la reservación que quiera el usuario
            case 1:{
                std::string lugar;
                while(true){
                    cout<<"Por favor ingrese el lugar de la Reunion: ";
                    getline(cin, lugar);
                    if(texto_no_vacio_sin_espacios(lugar)){
                        reservacion = new Reunion(fecha_inicio, fecha_fin, lugar, id_organizador);
                        break;
                    }
                }
                break;}
            case 2:
                reservacion = new CitaPersonal(fecha_inicio, fecha_fin);
                break;
            case 3:
                reservacion = new ActividadSocial(fecha_inicio, fecha_fin);
                break;
            case 4:
                reservacion = new EventoDiario(fecha_inicio, fecha_fin);
                break;
            default:
                break;
        }
        system("cls");
        cout<<"\033[32m"<<"\nLa reservacion ha sido agregada correctamente"<<"\033[0m"<<endl;     
        this->acomodarReservacion(reservacion);
    }
}
    
void Calendario::acomodarReservacion(Reservacion* nueva_reservacion){
    this->cantidad_reservaciones++;

    if(nueva_reservacion){
        if(!this->primera_reservacion){     //Si no tenemos reservaciones
        this->primera_reservacion = new Nodo(nueva_reservacion, nullptr);
        }else{  //Tenemos por lo menos una reservacion
            Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
            time_t segundos_nueva_reservacion = mktime(&nueva_reservacion->get_fecha_inicio()); //Segundos de nueva reservacion
            time_t segundos_reservacion_primera_reservacion = mktime(&(this->primera_reservacion->reservacion->get_fecha_inicio()));
                
            if(!temp->nodo_siguiente){  //Solo hay una reservacion
                if(segundos_nueva_reservacion<=segundos_reservacion_primera_reservacion){   //Si la nueva reservacion es previa a la existente
                    this->primera_reservacion = new Nodo(nueva_reservacion, this->primera_reservacion);
                }else{
                    this->primera_reservacion->setSiguiente(new Nodo(nueva_reservacion, nullptr));
                }
            }else{  //Tenemos más de una reservación
                if(segundos_nueva_reservacion<=segundos_reservacion_primera_reservacion){   //Si la nueva reservacion es previa a la primera reservacion
                    this->primera_reservacion = new Nodo(nueva_reservacion, this->primera_reservacion);
                }else{
                    while(temp->nodo_siguiente){    //Mientras tengamos una reservación siguiente 
                        time_t segundos_reservacion_siguiente = mktime(&(temp->nodo_siguiente->reservacion->get_fecha_inicio()));
                        if(segundos_nueva_reservacion<=segundos_reservacion_siguiente){   //Si la nueva reservacion es previa a la siguiente
                            temp->setSiguiente(new Nodo(nueva_reservacion, temp->nodo_siguiente));
                            return;
                        }
                        temp = temp->nodo_siguiente;
                    }
                    temp->setSiguiente(new Nodo(nueva_reservacion, nullptr));
                }
            }
        }
    }    
}

void Calendario::eliminarReservacion(int posicion){
    if(this->primera_reservacion){  //Tenemos al menos una reservación
        if(posicion == 0){  //Quiero eliminar mi primera reservacion
            Nodo* cabeza_antigua = this->primera_reservacion;
            this->primera_reservacion = this->primera_reservacion->nodo_siguiente;
            delete cabeza_antigua;
        }else{
            Nodo* temp = this->primera_reservacion;     //Guardamos la primera reservacion en nodo temporal.
            int i = 0;
            while(i < posicion-1){
                temp = temp->nodo_siguiente;
                i++;
            }
            Nodo* aux = temp->nodo_siguiente;   //El nodo auxiliar es el que queremos borrar
            temp->setSiguiente(temp->nodo_siguiente->nodo_siguiente);
            delete aux;
        }
        this->cantidad_reservaciones--; 
    }
}

void Calendario::modificarReservacion(int posicion, int id_organizador){
    if(this->primera_reservacion && posicion <= this->cantidad_reservaciones){  //Tenemos al menos una reservación y la posición es posible
        this->eliminarReservacion(posicion);
        this->crear_reservacion(id_organizador);  //Se crea y se agrega en el orden que le corresponde
    }
}

void Calendario::imprimirCalendario(){
    if(this->primera_reservacion){  //Si tenemos al menos una reservacion
        Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        int contador = 0;
        while(temp){    //Mientras tengamos reservaciones activas
            temp->reservacion->imprimir(contador);
            temp = temp->nodo_siguiente;
            contador++;
        }
    }else{
        cout<<"\033[33m"<<"Su calendario esta vacio..."<<"\033[0m"<<endl;
    }
}

