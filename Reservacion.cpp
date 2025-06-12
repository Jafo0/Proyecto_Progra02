#include "Reservacion.h"

Reservacion::Reservacion(struct tm _fecha_inicio, struct tm _fecha_fin) : fecha_inicio(_fecha_inicio), fecha_fin(_fecha_fin){}

Reservacion::~Reservacion() {}

struct tm& Reservacion::get_fecha_inicio(){return this->fecha_inicio;}

struct tm& Reservacion::get_fecha_fin(){return this->fecha_fin;}

std::string Reservacion::obtenerInfo()const{
    return imprimir_fecha_const(fecha_inicio) + "," + imprimir_fecha_const(fecha_fin);
}

std::string Reservacion::imprimir_fecha(const tm& fecha){
    char fecha_formateada[17];  // Suficiente para "dd/mm/yyyy HH:MM" + '\0'
    strftime(fecha_formateada, sizeof(fecha_formateada), "%d/%m/%Y %H:%M", &fecha);
    return "(" + std::string(fecha_formateada) + ")";
}
std::string Reservacion::imprimir_fecha_const(const tm& fecha) const{
    return std::to_string(fecha.tm_mday)+","+
    std::to_string(fecha.tm_mon + 1)+","+ //enero mes 1
    std::to_string(fecha.tm_year + 1900)+","+   //anno 2020 por ejemplo
    std::to_string(fecha.tm_hour)+":"+
    std::to_string(fecha.tm_min);
}

bool Reservacion::fecha_choca(struct tm fecha){
    time_t segundos_inicio = mktime(&this->fecha_inicio);
    time_t segundos_fin = mktime(&this->fecha_fin);
    time_t segundos_fecha = mktime(&fecha);
    return (segundos_inicio<=segundos_fecha && segundos_fecha<=segundos_fin)? true:false;   //Si la fecha está entre la fecha inicio y fecha final, hay choque de fechas
}