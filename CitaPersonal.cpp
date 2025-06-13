#include "CitaPersonal.h"

CitaPersonal::CitaPersonal(struct tm _fechaInicio, struct tm _fechaFin) : Reservacion(_fechaInicio, _fechaFin){}

CitaPersonal::~CitaPersonal(){}

void CitaPersonal::imprimirReservacion(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)
        <<" | "<<"Cita Personal"<<endl;
}
void CitaPersonal::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}
void CitaPersonal::escribirReservacionArchivo(std::ofstream& archivo) {
    archivo<<"Cita Personal"<<endl;
    this->escibirFechasReservacionArchivo(archivo);
}