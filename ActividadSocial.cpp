#include "ActividadSocial.h"

ActividadSocial::ActividadSocial(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

ActividadSocial::~ActividadSocial(){}

void ActividadSocial::imprimir(){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    this->ver_fechas();
    cout<<" | "<<"Actividad Social"<<" | "<<"Sala de uso comun"<<endl;
    cout<<"Participantes: "<<"\n"<<endl;

}