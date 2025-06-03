#include "Reunion.h"

Reunion::Reunion(struct tm _fecha_inicio, struct tm _fecha_fin, std::string _lugar) : Reservacion(_fecha_inicio, _fecha_fin), lugar(_lugar){}

Reunion::~Reunion(){}

void Reunion::imprimir(){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    this->ver_fechas();
    cout<<" | "<<"Reunion"<<" | "<<this->lugar<<endl;
    cout<<"Participantes: "<<"\n"<<endl;
}