#include "Calendario.h"

Calendario::Nodo::Nodo(Reservacion* _reservacion, Nodo* _nodoSiguiente) : reservacion(_reservacion), nodoSiguiente(_nodoSiguiente){}

Calendario::Nodo::~Nodo(){delete this->reservacion;}

Reservacion* Calendario::Nodo::getReservacion() const {return this->reservacion;}

void Calendario::Nodo::setReservacion(Reservacion* _reservacion){this->reservacion = _reservacion;}

Calendario::Nodo* Calendario::Nodo::getNodoSiguiente() const{return this->nodoSiguiente;}

void Calendario::Nodo::setNodoSiguiente(Nodo* _nodoSiguiente){this->nodoSiguiente = _nodoSiguiente;}

Calendario::Calendario(){
    this->segundosActual = time(nullptr);      
    this->fechaActual = *localtime(&segundosActual);  
}

Calendario::~Calendario(){
    if(this->primeraReservacion){  //Si tenemos al menos una reservacion
        while(this->primeraReservacion){    //Mientras tengamos reservaciones activas
            Nodo* temp = this->primeraReservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
            this->primeraReservacion = this->primeraReservacion->nodoSiguiente;  //Movemos la reservación más próxima a la siguiente
            delete temp;    //Eliminamos la reservación auxiliar
        }
    }
}

time_t Calendario::getSegundosActual() const{return this->segundosActual;}

struct tm Calendario::getFechaActual() const {return this->fechaActual;}

int Calendario::getCantidadReservaciones() const {return this->cantidadReservaciones;}

bool Calendario::nuevaReservacionLogica(struct tm fechaInicio, struct tm fechaFin) const{
    time_t segundosInicio = mktime(&fechaInicio);
    time_t segundosFin = mktime(&fechaFin);

    if(segundosInicio<=this->segundosActual){//Empezamos en el pasado
        cout<<"\033[31m"<<"\nLa reservacion inicia en el pasado"<<"\033[0m"<<endl;
        return false;
    }else if(segundosFin<segundosInicio){   //Terminamos antes de empezar
        cout<<"\033[31m"<<"\nLa reservacion termina antes de empezar"<<"\033[0m"<<endl;
        return false;
    }else if(segundosFin==segundosInicio){  //La reservación dura 0 segundos
        cout<<"\033[31m"<<"\nLa reservacion dura 0 segundos"<<"\033[0m"<<endl;
        return false;
    }        
    return true;    //Reservacion lógica
}

bool Calendario::choqueConCalendario(struct tm fechaInicio, struct tm fechaFin) const{//Revisa que la reserva no choque con otra del calendario
    Nodo* aux = this->primeraReservacion;
    while(aux){
        if(aux->getReservacion()->choqueFechas(fechaInicio, fechaFin)){
            cout<<"\033[31m"<<"\nLa reservacion NO pudo ser agregada ya que choca con otra fecha del calendario"<<"\033[0m"<<endl;
            return true;}    //Si hay choque
        aux = aux->nodoSiguiente;   //Pasamos al siguiente nodo
    }
    return false;
}

int Calendario::preguntarAnno() const{
    string anno;
    while(true){
        int anno_actual = this->fechaActual.tm_year+1900;
        cout<<"Ingrese el numero del anno ("<<anno_actual<<"<=): ";
        getline(cin, anno);
        if(numero_entero_sin_rango(anno)){
            if(anno_actual<=stoi(anno)){
                return stoi(anno);
            }
        }
    }
}

int Calendario::preguntarMes() const{
    string mes;
    while(true){
        cout<<"Ingrese el numero del mes (1-12): ";
        getline(cin, mes);  
        if(numero_entero_dentro_de_rango(1, 12, mes)){
            return stoi(mes);
        }
    }
}

int Calendario::preguntarDia() const{
    string dia;
    while(true){
        cout<<"Ingrese el numero del dia (1-31): ";
        getline(cin, dia);
        if(numero_entero_dentro_de_rango(1, 31, dia)){
            return stoi(dia);
        }
    }
}

int Calendario::preguntarHora() const{
    string hora;
    while(true){
        cout<<"Ingrese la hora (0-23): ";
        getline(cin, hora);
        if(numero_entero_dentro_de_rango(0, 23, hora)){
            return stoi(hora);
        }
    }
}

int Calendario::preguntarMinuto() const{
    string min;
    while(true){
        cout<<"Ingrese el minuto (0-59): ";
        getline(cin, min);
        if(numero_entero_dentro_de_rango(0, 59, min)){
            return stoi(min);
        }
    }
}

struct tm Calendario::preguntarFechaGeneral() const{
    cout<<"--------------Fecha del Evento Diario--------------"<<endl;
    
    struct tm fecha = {};   //Fecha con todos sus valores en cero
    //Modifico los valores que quiero:
    fecha.tm_year = this->preguntarAnno()-1900; 
    fecha.tm_mon = this->preguntarMes()-1;     
    fecha.tm_mday = this->preguntarDia();

    return fecha;
}

struct tm Calendario::preguntarFechaEspecifica(std::string mensaje) const{
    cout<<mensaje<<endl;

    struct tm fecha = {};   //Fecha con todos sus valores en cero
    //Modifico los valores que quiero:
    fecha.tm_year = this->preguntarAnno()-1900; 
    fecha.tm_mon = this->preguntarMes()-1;     
    fecha.tm_mday = this->preguntarDia();
    fecha.tm_hour = this->preguntarHora();
    fecha.tm_min = this->preguntarMinuto();

    return fecha;
}

void Calendario::imprimirCalendarioCompleto(){ 
    if(this->primeraReservacion){                  //Si tenemos al menos una reservacion
        Nodo* temp = this->primeraReservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        int contador = 0;
        while(temp){    //Mientras tengamos reservaciones activas
                temp->getReservacion()->imprimirReservacion(contador);
                contador++;
                temp = temp->nodoSiguiente;                
        }
    }else{
        cout<<"\033[33m"<<"Su calendario esta vacio..."<<"\033[0m"<<endl;
    }
}

void Calendario::imprimirCalendarioOculto(){ 
    if(this->primeraReservacion){                  //Si tenemos al menos una reservacion
        Nodo* temp = this->primeraReservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        int contador = 0;
        while(temp){    //Mientras tengamos reservaciones activas
                temp->getReservacion()->imprimirReservacionOculta(contador);
                contador++;
                temp = temp->nodoSiguiente;                
        }
    }else{
        cout<<"\033[33m"<<"Su calendario esta vacio..."<<"\033[0m"<<endl;
    }
}

int Calendario::menuReservaciones() const{
    cout<<"--------------Opciones de reservacion--------------"<<endl;
    cout<<"1. Reunion"<<endl;
    cout<<"2. Cita personal"<<endl;
    cout<<"3. Actividad social"<<endl;
    cout<<"4. Evento diario"<<endl;
    
    std::string reserva;
    while(true){
        cout<<"Indique que tipo de reservacion desea crear: ";
        getline(cin, reserva);
        if(numero_entero_dentro_de_rango(1,4,reserva)){
            return stoi(reserva);
        }
    }   
}

void Calendario::crearReservacion(){
    int tipo_reservacion = this->menuReservaciones(); //Indico qué reservación quiero
    struct tm fechaInicio {}, fechaFin {}; 

    //Pregunto las fechas:
    if(tipo_reservacion == 4){  //Si la reservación es evento diario
        fechaInicio = this->preguntarFechaGeneral();
        fechaFin = fechaInicio;
        fechaFin.tm_mday+=1;
    }else{  //La reservación no es un evento diario
        fechaInicio = this->preguntarFechaEspecifica("--------------Datos para la fecha de inicio de la reservacion--------------");
        fechaFin = this->preguntarFechaEspecifica("--------------Datos para la fecha de final de la reservacion--------------");
    }

    Reservacion* reservacion {nullptr};

    //Fecha correcta y no choca
    if(this->nuevaReservacionLogica(fechaInicio, fechaFin) && !this->choqueConCalendario(fechaInicio, fechaFin)){ 
        switch (tipo_reservacion){  //Creo la reservación que quiera el usuario
            case 1:{
                std::string lugar;
                while(true){
                    cout<<"Por favor ingrese el lugar de la Reunion: ";
                    getline(cin, lugar);
                    if(texto_no_vacio_sin_espacios(lugar)){break;}
                }
                reservacion = new Reunion(fechaInicio, fechaFin, lugar); 
                break;
            }case 2:
                reservacion = new CitaPersonal(fechaInicio, fechaFin);
                break;
            case 3:
                reservacion = new ActividadSocial(fechaInicio, fechaFin);
                break;
            case 4:
                reservacion = new EventoDiario(fechaInicio, fechaFin);
                break;
            default:
                break;
        }
        
        if(reservacion){
            cout<<"\033[32m"<<"\nLa reservacion ha sido creada correctamente"<<"\033[0m"<<endl;   
            this->cantidadReservaciones++;
            this->ordenarReservacion(reservacion);  //La ordenamos en nuestro calendario
        }
    }
}
    
void Calendario::ordenarReservacion(Reservacion* nueva_reservacion){
    if(!this->primeraReservacion){     //Si no tenemos reservaciones
    this->primeraReservacion = new Nodo(nueva_reservacion, nullptr);
    }else{  //Tenemos por lo menos una reservacion
        Nodo* temp = this->primeraReservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        time_t segundosNuevaReservacion = mktime(&nueva_reservacion->getFechaInicio()); 
        time_t segundosReservacionTemp = mktime(&(temp->getReservacion()->getFechaInicio()));   

        if(!temp->nodoSiguiente){  //Solo hay una reservacion
            if(segundosNuevaReservacion<segundosReservacionTemp){   //Si la nueva reservacion es previa a la existente
                this->primeraReservacion = new Nodo(nueva_reservacion, this->primeraReservacion);
            }else{
                this->primeraReservacion->setNodoSiguiente(new Nodo(nueva_reservacion, nullptr));
            }
        }else{  //Tenemos más de una reservación
            if(segundosNuevaReservacion<=segundosReservacionTemp){   //Si la nueva reservacion es previa a la primera reservacion
                this->primeraReservacion = new Nodo(nueva_reservacion, this->primeraReservacion);
            }else{
                while(temp->nodoSiguiente){    //Mientras tengamos una reservación siguiente 
                    time_t segundosReservacionSiguiente = mktime(&(temp->getNodoSiguiente()->getReservacion()->getFechaInicio()));
                    if(segundosNuevaReservacion<=segundosReservacionSiguiente){   //Si la nueva reservacion es previa a la siguiente
                        temp->setNodoSiguiente(new Nodo(nueva_reservacion, temp->nodoSiguiente));
                        return;
                    }
                    temp = temp->nodoSiguiente;
                }
                temp->setNodoSiguiente(new Nodo(nueva_reservacion, nullptr));   //Llegamos al final
            }
        }
    }     
}

void Calendario::eliminarReservacion(int posicion){
    if(this->primeraReservacion){  //Tenemos al menos una reservación
        if(posicion == 0){          //Quiero eliminar mi primera reservacion
            Nodo* cabeza_antigua = this->primeraReservacion;
            this->primeraReservacion = this->primeraReservacion->getNodoSiguiente();
            delete cabeza_antigua;
        }else{
            Nodo* temp = this->primeraReservacion;     //Guardamos la primera reservacion en nodo temporal.
            int i = 0;
            while(i < posicion-1){
                temp = temp->getNodoSiguiente();
                i++;
            }
            Nodo* aux = temp->getNodoSiguiente();   //El nodo auxiliar es el que queremos borrar
            temp->setNodoSiguiente(temp->getNodoSiguiente()->getNodoSiguiente());
            delete aux;
        }
        this->cantidadReservaciones--; 
    }
}

void Calendario::escribirEnArchivo(std::ofstream& archivo2) const{
    Nodo* aux = primeraReservacion; //este es mi head
    while (aux!=nullptr){
        aux->getReservacion()->escribirReservacionArchivo(archivo2);
        aux = aux->nodoSiguiente;
    }
}