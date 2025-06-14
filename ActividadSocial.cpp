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
        <<" | "<<"Actividad Social"<<" | "<<"Sala de uso comun"

        << "Id Creador: ";
        
        if(this->organizador != nullptr){
            cout<<this->organizador->getID();
        }else{
            cout<<"--";
        }
        cout<<" | " << "Lista de Invitados: ";
        this->lista_org->imprimirIDS();
        cout<<endl;
}

void ActividadSocial::imprimirReservacionOculta(int posicion) {
    cout<<std::setfill('-')<<std::setw(80)<<""<<endl;
    cout<<"Reservacion #"<<posicion<<": "<<endl;
    cout<<this->getFecha(this->fechaInicio)<<" -> "<<this->getFecha(this->fechaFin)<<endl;
}

void ActividadSocial::eliminarParaOrganizadores(int idOrganizadorQueElimina){
    if(idOrganizadorQueElimina == this->organizador->getID()){
        this->organizador->getCalendario()->eliminarReservacion(this->idReservacion);
    }
    cout<< "\033[32m"<<"\nAMARILLO\n"<<"\033[0m" << endl;
    this->lista_org->eliminar(this->idReservacion);
    this->lista_org = new ListaUsuario();
}