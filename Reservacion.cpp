#include "Reservacion.h"

Reservacion::Reservacion (struct tm _fechaInicio, struct tm _fechaFin,string tipo_e) 
        : fechaInicio(_fechaInicio), fechaFin(_fechaFin),tipo(tipo_e) {this->idReservacion = time(nullptr);}

Reservacion::Reservacion (struct tm _fechaInicio, struct tm _fechaFin,string tipo_e, time_t _idReservacion) 
        : fechaInicio(_fechaInicio), fechaFin(_fechaFin),tipo(tipo_e), idReservacion(_idReservacion) {}

Reservacion::~Reservacion(){}

struct tm& Reservacion::getFechaInicio ()  {return this->fechaInicio;}

struct tm& Reservacion::getFechaFin ()  {return this->fechaFin;}

std::string Reservacion::getTipo(){return this->tipo;} 

void  Reservacion::setTipo(string tipo_e){this->tipo = tipo_e;}

void Reservacion::setFechaInicio(struct tm _fechaInicio){this->fechaInicio = _fechaInicio;}

void Reservacion::setFechaFin(struct tm _fechaFin){this->fechaFin = _fechaFin;}

time_t Reservacion::getIdReservacion(){return this->idReservacion;}

string Reservacion::getFecha( struct tm& fecha) {
    char fecha_formateada[17];  // Suficiente para "dd/mm/yyyy HH:MM" + '\0'
    strftime(fecha_formateada, sizeof(fecha_formateada), "%d/%m/%Y %H:%M", &fecha);
    return "(" + std::string(fecha_formateada) + ")";
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
