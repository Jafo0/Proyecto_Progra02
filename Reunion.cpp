#include "Reunion.h"

Reunion::Reunion(struct tm _fecha_inicio, struct tm _fecha_fin, std::string _lugar) : Reservacion(_fecha_inicio, _fecha_fin), lugar(_lugar){}

Reunion::~Reunion(){}

void Reunion::imprimir(int posicion){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->imprimir_fecha(this->fecha_inicio)<<" -> "<<this->imprimir_fecha(this->fecha_fin);
    cout<<" | "<<"Reunion"<<" | "<<this->lugar<<endl;
    cout<<"Participantes: "<<"\n"<<endl;
}