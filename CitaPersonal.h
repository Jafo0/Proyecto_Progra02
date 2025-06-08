#ifndef CITA_PERSONAL_H
#define CITA_PERSONAL_H

#include "Reservacion.h"

class CitaPersonal : public Reservacion {
    public:
        CitaPersonal(struct tm, struct tm);
        ~CitaPersonal();
        void imprimir(int) override;
};

#endif  // CITA_PERSONAL_H