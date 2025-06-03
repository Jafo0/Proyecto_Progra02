#include "CitaPersonal.h"

CitaPersonal::CitaPersonal(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

CitaPersonal::~CitaPersonal(){}

void CitaPersonal::imprimir(){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    this->ver_fechas();
    cout<<" | "<<"Cita Personal"<<"\n"<<endl;
}