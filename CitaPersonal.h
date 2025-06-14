#ifndef CITA_PERSONAL_H
#define CITA_PERSONAL_H

#include "Reservacion.h"

class CitaPersonal : public Reservacion {
    public:
        //Constructores y destructores
        CitaPersonal(struct tm, struct tm);
        CitaPersonal(struct tm, struct tm, time_t);
        ~CitaPersonal();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int)  override;
};

#endif  // CITA_PERSONAL_H