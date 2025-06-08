#include "ActividadSocial.h"

ActividadSocial::ActividadSocial(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

ActividadSocial::~ActividadSocial(){}

void ActividadSocial::imprimir(int posicion){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<this->imprimir_fecha(this->fecha_inicio)<<" -> "<<this->imprimir_fecha(this->fecha_fin);
    cout<<" | "<<"Actividad Social"<<" | "<<"Sala de uso comun"<<endl;
    cout<<"Participantes: "<<"\n"<<endl;

}