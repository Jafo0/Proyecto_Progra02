#ifndef EVENTO_DIARIO_H
#define EVENTO_DIARIO_H

#include "Reservacion.h"

class EventoDiario : public Reservacion {
    public:
        EventoDiario(struct tm, struct tm);
        ~EventoDiario();
        void imprimir(int) override;
};

#endif  // EVENTO_DIARIO_H
