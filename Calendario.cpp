#include "Calendario.h"

Calendario::Nodo::Nodo(Reservacion* _reservacion, Nodo* _nodo_siguiente) : reservacion(_reservacion), nodo_siguiente(_nodo_siguiente){}

Calendario::Nodo::~Nodo(){
    delete this->reservacion;
}

void Calendario::Nodo::setSiguiente(Nodo* _nodo_siguiente){this->nodo_siguiente = _nodo_siguiente;}

Calendario::~Calendario(){
    if(this->primera_reservacion){  //Si tenemos al menos una reservacion
        while(this->primera_reservacion){    //Mientras tengamos reservaciones activas
            Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
            this->primera_reservacion = this->primera_reservacion->nodo_siguiente;  //Movemos la reservación más próxima a la siguiente
            delete temp;    //Eliminamos la reservación auxiliar
        }
    }
}

bool Calendario::choqueFechas(struct tm fecha_inicio_otra, struct tm fecha_fin_otra){
    if(this->primera_reservacion){  //Si tenemos al menos una reservacion
        Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        while(temp){    //Mientras tengamos reservaciones activas
            struct tm fecha_inicio_uno = temp->reservacion->get_fecha_inicio();
            struct tm fecha_fin_uno = temp->reservacion->get_fecha_fin();
            if(mktime(&fecha_fin_uno) == mktime(&fecha_inicio_otra)){
                cout<<"La fecha de inicio es la misma"<<endl;
                return true;
            }else if(mktime(&fecha_fin_uno) == mktime(&fecha_fin_otra)){
                cout<<"La fecha de fin es la misma"<<endl;
                return true;
            }else{
                temp = temp->nodo_siguiente;
            }
        }
        return false;
    }
    return false;   //Tenemos nuestro calendario vacío
}

struct tm Calendario::preguntarDia(){
    cout<<"--------------Fecha del Evento Diario--------------"<<endl;

    int mes {0}, dia {1};

    while(true){
        cout<<"Ingrese el numero del mes (0-11): ";
        cin>>mes;
        cout<<endl;
        if(mes<0 || 11<mes){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    while(true){
        cout<<"Ingrese el numero del dia (1-31): ";
        cin>>dia;
        cout<<endl;
        if(dia<1 || 31<dia){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    system("cls");

    time_t t = time(NULL);  //Obtengo tiempo actual
    struct tm fecha = *localtime(&t);   //La convierto en fecha
        fecha.tm_mon = mes;     //Modifico sus valores a los valores ingresados
        fecha.tm_mday = dia;
        fecha.tm_hour = 0;
        fecha.tm_min = 0;
        fecha.tm_sec = 0;

    return fecha;
}

struct tm Calendario::preguntarFecha(std::string mensaje){
    cout<<mensaje<<endl;

    int mes {0}, dia {1}, hora {0}, min {0};

    while(true){
        cout<<"Ingrese el numero del mes (0-11): ";
        cin>>mes;
        cout<<endl;
        if(mes<0 || 11<mes){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    while(true){
        cout<<"Ingrese el numero del dia (1-31): ";
        cin>>dia;
        cout<<endl;
        if(dia<1 || 31<dia){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    while(true){
        cout<<"Ingrese la hora (0-23): ";
        cin>>hora;
        cout<<endl;
        if(hora<0 || 23<hora){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    while(true){
        cout<<"Ingrese el minuto (0-59): ";
        cin>>min;
        cout<<endl;
        if(min<0 || 59<min){
            cout<<"\033[31m"<<"Por favor ingrese un valor dentro del rango indicado"<<"\033[0m"<<endl;
        }else{
            break;
        }
    }

    system("cls");

    time_t t = time(NULL);  //Obtengo tiempo actual
    struct tm fecha = *localtime(&t);   //La convierto en fecha
        fecha.tm_mon = mes;     //Modifico sus valores a los valores ingresados
        fecha.tm_mday = dia;
        fecha.tm_hour = hora;
        fecha.tm_min = min;
        fecha.tm_sec = 0;

    return fecha;
}

char Calendario::menu_reservaciones(){
    cout<<"--------------Opciones de reservacion--------------"<<endl;
    cout<<"1. Reunion"<<endl;
    cout<<"2. Cita personal"<<endl;
    cout<<"3. Actividad social"<<endl;
    cout<<"4. Evento diario"<<endl;
    
    int reserva {0};
    while(true){
        cout<<"Indique que tipo de reservacion desea crear: ";
        cin>>reserva;
        cout<<endl;
        if(cin.fail()){     //Ingresa un string
            cin.clear();              // Limpia el estado de error
            cin.ignore(1000, '\n');   // Descarta la línea incorrecta
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;
        }else if(1<=reserva&&reserva<=4){   //Ingresa un número válido
            return (reserva + '0'); //Convierto int a char
        }else{  //Ingresa un número fuera del rango
            cout << "\033[31m"<<"Ingrese un numero valido"<<"\033[0m" << endl;
        }
    }   
}


Reservacion* Calendario::crearReservacion(){
    Reservacion* reservacion {nullptr};
    char tipo_reservacion = this->menu_reservaciones(); //Indico qué reservación quiero

    struct tm fecha_inicio, fecha_fin; 

    //Pregunto las fechas:
    if(tipo_reservacion == '4'){  //Si la reservación es evento diario
        fecha_inicio = this->preguntarDia();
        fecha_fin = fecha_inicio;
            fecha_fin.tm_mday+=1;
    }else{  //La reservación no es un evento diario
        fecha_inicio = this->preguntarFecha("--------------Datos para la fecha de inicio de la reservacion--------------");
        fecha_fin = this->preguntarFecha("--------------Datos para la fecha de final de la reservacion--------------");
    }
    
    //Si hay choque de fechas con otro evento:
    if(this->choqueFechas(fecha_inicio, fecha_fin)){   
        cout<<"\033[31m"<<"Las fechas ingresadas chocan con otro evento del calendario"<<"\033[0m"<<endl;
    }else{ //Si no hay choque de fechas:
        switch (tipo_reservacion){  //Creo la reservación que quiera el usuario
            case '1':{
                std::string lugar;
                cout<<"Por favor ingrese el lugar de la Reunion: ";
                cin>>lugar;
                cout<<endl;
                reservacion = new Reunion(fecha_inicio, fecha_fin, lugar);
                break;}
            case '2':
                reservacion = new CitaPersonal(fecha_inicio, fecha_fin);
                break;
            case '3':
                reservacion = new ActividadSocial(fecha_inicio, fecha_fin);
                break;
            case '4':
                reservacion = new EventoDiario(fecha_inicio, fecha_fin);
                break;
            default:
                break;
        }
    }
    return reservacion;
}


void Calendario::agregarReservacion(){
    Reservacion* nueva_reservacion = crearReservacion();
    
    if(nueva_reservacion){
        if(!this->primera_reservacion){     //Si no tenemos reservaciones
        this->primera_reservacion = new Nodo(nueva_reservacion, nullptr);
        }else{  //Tenemos por lo menos una reservacion
            Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
            while(temp->nodo_siguiente){    //Mientras tengamos una reservación siguiente 
                temp = temp->nodo_siguiente;
            }
            temp->setSiguiente(new Nodo(nueva_reservacion, nullptr));
        }
    }    
}

void Calendario::imprimirCalendario(){
    if(this->primera_reservacion){  //Si tenemos al menos una reservacion
        Nodo* temp = this->primera_reservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        while(temp){    //Mientras tengamos reservaciones activas
            temp->reservacion->imprimir();
            temp = temp->nodo_siguiente;
        }
    }
}