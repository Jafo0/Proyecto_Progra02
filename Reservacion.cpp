#include "Reservacion.h"

Reservacion::Reservacion(struct tm _fecha_inicio, struct tm _fecha_fin) : fecha_inicio(_fecha_inicio), fecha_fin(_fecha_fin){}

Reservacion::~Reservacion() {}

struct tm& Reservacion::get_fecha_inicio(){return this->fecha_inicio;}

struct tm& Reservacion::get_fecha_fin(){return this->fecha_fin;}

std::string Reservacion::imprimir_fecha(const tm& fecha){
    char fecha_formateada[17];  // Suficiente para "dd/mm/yyyy HH:MM" + '\0'
    strftime(fecha_formateada, sizeof(fecha_formateada), "%d/%m/%Y %H:%M", &fecha);
    return "(" + std::string(fecha_formateada) + ")";
}