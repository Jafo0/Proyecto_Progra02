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
            }else{cout<< "\033[31m"<<"\nIngrese un anno correcto\n"<<"\033[0m" << endl;}
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
        int contador = 1;
        while(temp){    //Mientras tengamos reservaciones activas
                temp->getReservacion()->imprimirReservacion(contador);
                contador++;
                temp = temp->nodoSiguiente;                
        }
        cout<<endl;
    }else{
        cout<<"\033[33m"<<"Su calendario esta vacio...\n"<<"\033[0m"<<endl;
    }
}

void Calendario::imprimirCalendarioOculto(){ 
    if(this->primeraReservacion){                  //Si tenemos al menos una reservacion
        Nodo* temp = this->primeraReservacion;     //Guardamos la reservacion más próxima en nodo auxiliar
        int contador = 1;
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
            this->ordenarReservacion(reservacion);  //La ordenamos en nuestro calendario
        }
    }
}

void Calendario::printParaAgregarId(){//podria retornar ListaUsuarios*,
    //que esta sea la lista que entra como parametro para la reunion / actividad
    string id;
    string cantidad;
    
    while(true){
        cout<<"Cuantos asistentes desea agregar?"<<endl;
        getline(cin,cantidad);
        if(numero_entero_sin_rango(cantidad)){
            int numAsistente = stoi(cantidad);
            if(numAsistente == 0){
                cout<<"\033[31m"<<"\nnumero invalido\n"<<"\033[0m"<<endl;
                break;
            }
            for(int i=0;i<stoi(cantidad);i++){
                cout<<"Ingrese Id de los asistentes / organizadores, #id"<< (i+1) <<endl;
                getline(cin,id);
                //implementar estructura de datos donde se vaya guardando, 
                //podria calendario tener otro atributo de lista usuario
                if(numero_entero_sin_rango(id)){
                    //buscar si id esta en la listausuarios
                }

            }
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
    this->cantidadReservaciones++;   
}

void Calendario::eliminarReservacion(int posicion){
    if(this->primeraReservacion){  //Tenemos al menos una reservación
        if(posicion == 1){          //Quiero eliminar mi primera reservacion
            Nodo* cabeza_antigua = this->primeraReservacion;
            this->primeraReservacion = this->primeraReservacion->getNodoSiguiente();
            delete cabeza_antigua;
        }else{
            Nodo* temp = this->primeraReservacion;     //Guardamos la primera reservacion en nodo temporal.
            int i = 1;
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

void Calendario::escribirEnArchivo(std::ofstream& archivo) const{
    Nodo* aux = primeraReservacion; //este es mi head
    while (aux!=nullptr){
        aux->getReservacion()->escribirReservacionArchivo(archivo);
        aux = aux->nodoSiguiente;
    }
    archivo<<"Fin de calendario"<<endl;
}

struct tm* Calendario::leerIdYFechasDeArchivo(std::ifstream& archivo){
    string linea_temp;

    getline(archivo, linea_temp);
    std::stringstream ss(linea_temp);   //Creo un stream de la línea
    string dato;               //Cada elemento separado por coma (csv)
    string datos_csv[11];       // mi array de elementos 
    int i = 0;
    while (getline(ss, dato, ',')) {        //Mientras se pueda: Leemos ss hasta la coma y guardamos en elemento
            datos_csv[i] = dato;        //Guardamos en el array
            i++;                    
    }

    struct tm fechaInicio = {}, fechaFin = {};

    fechaInicio.tm_mday = stoi(datos_csv[0]);
    fechaInicio.tm_mon  = stoi(datos_csv[1])-1;
    fechaInicio.tm_year = stoi(datos_csv[2]) - 1900;  
    fechaInicio.tm_hour = stoi(datos_csv[3]);
    fechaInicio.tm_min  = stoi(datos_csv[4]);

    fechaFin.tm_mday = stoi(datos_csv[5]);
    fechaFin.tm_mon  = stoi(datos_csv[6])-1;
    fechaFin.tm_year = stoi(datos_csv[7]) - 1900; 
    fechaFin.tm_hour = stoi(datos_csv[8]);
    fechaFin.tm_min  = stoi(datos_csv[9]);

    time_t idReservacion = static_cast<time_t>(stoll(datos_csv[10]));   //Para evitar perder información

    struct tm* fechas =  new struct tm[3];
    fechas[0] = fechaInicio;
    fechas[1] = fechaFin;
    fechas[2] = *localtime(&idReservacion);

    return fechas;
}
 
Reservacion* Calendario::leerReunionDeArchivo(std::ifstream& archivo){  
    struct tm* fechas = this->leerIdYFechasDeArchivo(archivo);

    string lugar;
    getline(archivo, lugar);

    Reservacion* nuevaReservacion = new Reunion(fechas[0], fechas[1], lugar, mktime(&fechas[2]));
    return nuevaReservacion;
}

Reservacion* Calendario::leerActividadSocialDeArchivo(std::ifstream& archivo){
    struct tm* fechas = this->leerIdYFechasDeArchivo(archivo);
    Reservacion* nuevaReservacion = new ActividadSocial(fechas[0], fechas[1], mktime(&fechas[2]));
    return nuevaReservacion;
}

Reservacion* Calendario::leerEventoDiarioDeArchivo(std::ifstream& archivo){
    struct tm* fechas = this->leerIdYFechasDeArchivo(archivo);
    Reservacion* nuevaReservacion = new EventoDiario(fechas[0], fechas[1], mktime(&fechas[2]));
    return nuevaReservacion;
}

Reservacion* Calendario::leerCitaPersonalDeArchivo(std::ifstream& archivo){
    struct tm* fechas = this->leerIdYFechasDeArchivo(archivo);
    Reservacion* nuevaReservacion = new CitaPersonal(fechas[0], fechas[1], mktime(&fechas[2]));
    return nuevaReservacion;
}

void Calendario::leerDeArchivo(std::ifstream& archivo){
    string linea_temp;
    Reservacion* nuevaReservacion;
    getline(archivo, linea_temp);   //Me deshago del encabezado "Calendario:"
    
    while(true){
        getline(archivo, linea_temp);
        if(linea_temp == "Fin de calendario"){   //No tenemos reservaciones
            break;
        }else{
            if(linea_temp == "Reunion"){
                nuevaReservacion = this->leerReunionDeArchivo(archivo); 
            }else if(linea_temp == "Evento Diario"){
                nuevaReservacion = this->leerEventoDiarioDeArchivo(archivo); 
            }else if(linea_temp == "Actividad Social"){
                nuevaReservacion = this->leerActividadSocialDeArchivo(archivo); 
            }else if(linea_temp == "Cita Personal"){
                nuevaReservacion = this->leerCitaPersonalDeArchivo(archivo); 
            }
            this->ordenarReservacion(nuevaReservacion);  //La ordenamos en nuestro calendario
        }
    } 
}