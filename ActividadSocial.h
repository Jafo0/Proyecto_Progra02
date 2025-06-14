#ifndef ACTIVIDAD_SOCIAL_H
#define ACTIVIDAD_SOCIAL_H

#include "Reservacion.h"
class ListaUsuario;
class Usuario;
class ActividadSocial : public Reservacion {
    protected:
        Usuario* organizador{nullptr};
        ListaUsuario* lista_org{nullptr};
        std::string lugar {"sala de uso comun"};
    public:
        //Constructores destructores
        ActividadSocial(struct tm, struct tm, time_t);
        ActividadSocial(struct tm, struct tm, Usuario*, ListaUsuario*); //nuevo constructor
        ~ActividadSocial();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int)  override; 
        void eliminarParaOrganizadores(int);
};

#endif  // ACTIVIDAD_SOCIAL_H
