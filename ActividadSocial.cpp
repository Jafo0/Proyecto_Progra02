#include "ActividadSocial.h"
#include "ListaUsuario.h"
#include "Usuario.h"

ActividadSocial::ActividadSocial(struct tm _fechaInicio, struct tm _fecha_fin, Usuario* _organizador, ListaUsuario* lista):
Reservacion(_fechaInicio,_fecha_fin,"ActividadSocial"), organizador(_organizador), lista_org(lista){
    this->lista_org->invitar(this);
}

ActividadSocial::ActividadSocial(struct tm _fechaInicio, struct tm _fecha_fin, time_t _idReservacion) : Reservacion(_fechaInicio, _fecha_fin,"ActividadSocial", _idReservacion){}

ActividadSocial::~ActividadSocial(){}

void ActividadSocial::imprimirReservacion(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)
        <<" | "<<"Actividad Social"<<" | "<<"Sala de uso comun"<<endl;
}

void ActividadSocial::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}

void ActividadSocial::escribirReservacionArchivo(std::ofstream& archivo, ofstream& archivoOtro) {
    archivo<< "Actividad Social"<<endl;
    this->escribirIdYFechas(archivo);

    //Escribo en mi otro archivo
    archivoOtro<< "Actividad Social"<<endl;
    this->escribirIdYFechas(archivoOtro);
    archivoOtro<<"IdsOrganizadores, "<<"<Hace falta agregarlo en ActividadSocial.cpp>"<<endl;
}