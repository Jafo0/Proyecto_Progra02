#include "Reservacion.h"

Reservacion::Reservacion (struct tm _fechaInicio, struct tm _fechaFin) 
        : fechaInicio(_fechaInicio), fechaFin(_fechaFin) {this->idReservacion = time(nullptr);}

Reservacion::Reservacion (struct tm _fechaInicio, struct tm _fechaFin, time_t _idReservacion) 
        : fechaInicio(_fechaInicio), fechaFin(_fechaFin), idReservacion(_idReservacion) {}

Reservacion::~Reservacion () {}

 struct tm& Reservacion::getFechaInicio ()  {return this->fechaInicio;}

 struct tm& Reservacion::getFechaFin ()  {return this->fechaFin;}

void Reservacion::setFechaInicio(struct tm _fechaInicio){this->fechaInicio = _fechaInicio;}

void Reservacion::setFechaFin(struct tm _fechaFin){this->fechaFin = _fechaFin;}

time_t Reservacion::getIdReservacion(){return this->idReservacion;}

string Reservacion::getFecha( struct tm& fecha) {
    char fecha_formateada[17];  // Suficiente para "dd/mm/yyyy HH:MM" + '\0'
    strftime(fecha_formateada, sizeof(fecha_formateada), "%d/%m/%Y %H:%M", &fecha);
    return "(" + std::string(fecha_formateada) + ")";
}

void Reservacion::escribirIdYFechas(ofstream& archivo) {
    //Escribo la fecha de inicio:
    archivo << this->fechaInicio.tm_mday << ","
        << (this->fechaInicio.tm_mon + 1) << ","
        << (this->fechaInicio.tm_year + 1900) << ","
        << this->fechaInicio.tm_min << ","
        << this->fechaInicio.tm_hour << ",";

    //Escribo la fecha de fin:
    archivo << this->fechaFin.tm_mday << ","
        << (this->fechaFin.tm_mon + 1) << ","
        << (this->fechaFin.tm_year + 1900) << ","
        << this->fechaFin.tm_min << ","
        << this->fechaFin.tm_hour <<",";

    archivo<<this->idReservacion<<endl;
}

bool Reservacion::choqueFechas(struct tm& fechaInicioOtra, struct tm& fechaFinOtra){
    //Paso ambas fechas de inicio y fin a segundos para poder compararlas
    time_t segundosInicio = mktime(&this->fechaInicio);
    time_t segundosFin = mktime(&this->fechaFin);
    time_t segundosInicioOtra = mktime(&fechaInicioOtra);
    time_t segundosFinOtra = mktime(&fechaFinOtra);

    //La fecha de inicio choca con mi reservación
    if(segundosInicio<=segundosInicioOtra && segundosInicioOtra<=segundosFin || segundosInicio<=segundosFinOtra && segundosFinOtra<=segundosFin){
        return true;
    } 

    //No hay choque
    return false;
}
