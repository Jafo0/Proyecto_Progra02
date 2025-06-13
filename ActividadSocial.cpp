#include "ActividadSocial.h"

ActividadSocial::ActividadSocial(struct tm _fechaInicio, struct tm _fecha_fin) : Reservacion(_fechaInicio, _fecha_fin){}

ActividadSocial::~ActividadSocial(){}

void ActividadSocial::imprimirReservacion(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)
        <<" | "<<"Actividad Social"<<" | "<<"Sala de uso comun"<<endl;
}

void ActividadSocial::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}

void ActividadSocial::escribirReservacionArchivo(std::ofstream& archivo) {
    archivo<< "Actividad Social"<<endl;
    this->escibirFechasReservacionArchivo(archivo);
    archivo<<lugar<<endl;
}