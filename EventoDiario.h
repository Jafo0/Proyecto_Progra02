#ifndef EVENTO_DIARIO_H
#define EVENTO_DIARIO_H

#include "Reservacion.h"

class EventoDiario : public Reservacion {
    public:
        //Constructores y destructores
        EventoDiario(struct tm, struct tm);
        EventoDiario(struct tm, struct tm, time_t);
        ~EventoDiario();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int)  override;
        void escribirReservacionArchivo(ofstream&)  override;
};

#endif  // EVENTO_DIARIO_H
