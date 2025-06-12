#include "Reunion.h"

Reunion::Reunion(struct tm _fecha_inicio, struct tm _fecha_fin, std::string _lugar, int id_organizador) 
        : Reservacion(_fecha_inicio, _fecha_fin), lugar(_lugar), id_organizador(id_organizador){}

Reunion::~Reunion(){}

void Reunion::imprimir(int posicion){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<"(id organizador: "<<std::to_string(this->id_organizador)<<")"<<endl;
    cout<<this->imprimir_fecha(this->fecha_inicio)<<" -> "<<this->imprimir_fecha(this->fecha_fin);
    cout<<" | "<<"Reunion"<<" | "<<this->lugar<<endl;
    cout<<"Participantes: "<<"\n"<<endl;
}
void Reunion::imprimirOculto(int posicion){
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<"(id organizador: "<<std::to_string(this->id_organizador)<<")"<<endl;
    cout<<this->imprimir_fecha(this->fecha_inicio)<<" -> "<<this->imprimir_fecha(this->fecha_fin);
    cout<<"Participantes: "<<"\n"<<endl;
}

void Reunion::guardarEnArchivo(std::ofstream& archivo,int id_entrada){
    this->id_organizador = id_entrada;
    archivo << "Reunion\n"
    << std::to_string(this->id_organizador) << ","
    << this->obtenerInfo() << ","
    << lugar << std::endl;
}//muestra que tipo de reservacion, su posicion en el calendario, el id de quien la crea, inicio y final y el lugar
