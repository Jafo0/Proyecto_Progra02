#include "Reunion.h"

Reunion::Reunion(struct tm _fechaInicio, struct tm _fechaFin, std::string _lugar) 
        : Reservacion(_fechaInicio, _fechaFin), lugar(_lugar){}

Reunion::~Reunion(){}

string Reunion::getLugar()  {return this->lugar;}

void Reunion::setLugar(string _lugar){this->lugar = _lugar;}

void Reunion::imprimirReservacion(int posicion)  {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;   //Encabezado
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)    //Obtengo las fechas
        <<" | "<<"Reunion"<<" | "<<this->lugar<<endl;
}

void Reunion::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;   //Encabezado
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}

void Reunion::escribirReservacionArchivo(std::ofstream& archivo) {
    archivo<<"Reunion"<<endl;
    this->escibirFechasReservacionArchivo(archivo);
    archivo<<lugar<<endl;
}
