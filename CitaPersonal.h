#ifndef CITA_PERSONAL_H
#define CITA_PERSONAL_H

#include "Reservacion.h"

class CitaPersonal : public Reservacion {
    public:
        //Constructores y destructores
        CitaPersonal(struct tm, struct tm);
        ~CitaPersonal();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int)  override;
        void escribirReservacionArchivo(ofstream&)  override;
};

#endif  // CITA_PERSONAL_H