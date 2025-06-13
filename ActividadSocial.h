#ifndef ACTIVIDAD_SOCIAL_H
#define ACTIVIDAD_SOCIAL_H

#include "Reservacion.h"

class ActividadSocial : public Reservacion {
    protected:
        std::string lugar {"Comedor al aire libre"};
    public:
        //Constructores destructores
        ActividadSocial(struct tm, struct tm);
        ActividadSocial(struct tm, struct tm, time_t);
        ~ActividadSocial();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int)  override; 
        void escribirReservacionArchivo(std::ofstream&, ofstream&)  override;
};

#endif  // ACTIVIDAD_SOCIAL_H
