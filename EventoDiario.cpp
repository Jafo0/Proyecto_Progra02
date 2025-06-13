#include "EventoDiario.h"

EventoDiario::EventoDiario(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

EventoDiario::EventoDiario(struct tm _fecha_inicio, struct tm _fecha_fin, time_t _idReservacion) : Reservacion(_fecha_inicio, _fecha_fin, _idReservacion){}

EventoDiario::~EventoDiario(){}

void EventoDiario::imprimirReservacion(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;   //Encabezado
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)
        <<" | "<<"Evento Diario"<<endl;
}
void EventoDiario::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}
void EventoDiario::escribirReservacionArchivo(std::ofstream& archivo) {
    archivo<<"Evento Diario"<<endl;
    this->escribirIdYFechas(archivo);
}