#include "CitaPersonal.h"

CitaPersonal::CitaPersonal(struct tm _fecha_inicio, struct tm _fecha_fin) : Reservacion(_fecha_inicio, _fecha_fin){}

CitaPersonal::~CitaPersonal(){}

void CitaPersonal::imprimir(int posicion){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->imprimir_fecha(this->fecha_inicio)<<" -> "<<this->imprimir_fecha(this->fecha_fin);
    cout<<" | "<<"Cita Personal"<<"\n"<<endl;
}