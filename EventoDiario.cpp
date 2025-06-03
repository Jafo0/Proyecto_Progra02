#include "EventoDiario.h"

EventoDiario::EventoDiario(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

EventoDiario::~EventoDiario(){}

void EventoDiario::imprimir(){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    this->ver_fechas();
    cout<<" | "<<"Evento Diario"<<"\n"<<endl;
}