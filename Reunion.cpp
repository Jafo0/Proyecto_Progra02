#include "Reunion.h"
#include "ListaUsuario.h"
#include "Usuario.h"

Reunion::Reunion(struct tm _fechaInicio, struct tm _fechaFin, std::string _lugar) 
        : Reservacion(_fechaInicio, _fechaFin), lugar(_lugar){}

Reunion::Reunion(struct tm _fechaInicio, struct tm _fechaFin, std::string _lugar, time_t _idReservacion) 
        : Reservacion(_fechaInicio, _fechaFin, _idReservacion), lugar(_lugar){}

Reunion::Reunion(struct tm _fechaInicio, struct tm _fechaFin, std::string _lugar,Usuario* user) 
        : Reservacion(_fechaInicio, _fechaFin), lugar(_lugar), organizador(user){}
        //aun no se imprime este puntero a usuario

Reunion::~Reunion(){}

string Reunion::getLugar()  {return this->lugar;}

Usuario* Reunion::getOrganizador(){return this->organizador;}

void Reunion::setLugar(string _lugar){this->lugar = _lugar;}

void Reunion::setListaInvitados(ListaUsuario* _invitados){ this->lista_invitados = _invitados;}

void Reunion::imprimirReservacion(int posicion)  {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;   //Encabezado
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)    //Obtengo las fechas
        <<" | "<<"Reunion"<<" | "<<this->lugar<<" | "
        << "Organizador: "<<endl;
        
        if(this->organizador != nullptr){
            
            cout<<this->getOrganizador()->getID();
        }else{
            cout<<"--";
        }
        cout<<endl;
}

void Reunion::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;   //Encabezado
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}

void Reunion::imprimirListaInvitados(){
    this->lista_invitados->imprimirIDS();
}

void Reunion::escribirReservacionArchivo(std::ofstream& archivo, ofstream& archivoOtro) {
    archivo<<"Reunion"<<endl;
    this->escribirIdYFechas(archivo);
    archivo<<lugar<<endl;


    //Escribo en mi otro archivo
    archivoOtro<<"Reunion"<<endl;
    this->escribirIdYFechas(archivoOtro);
    archivoOtro<<lugar<<endl;
    archivoOtro<<"IdOrganizador, "<<"<Hace falta agregarlo en Reunion.cpp>"<<endl;
    archivoOtro<<"Ids invitados, "<<"<Hace falta agregarlo en Reunion.cpp>"<<endl; 
}
