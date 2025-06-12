#ifndef CITA_PERSONAL_H
#define CITA_PERSONAL_H

#include "Reservacion.h"

class CitaPersonal : public Reservacion {
    public:
        CitaPersonal(struct tm, struct tm);
        ~CitaPersonal();
        void imprimir(int) override;
        void imprimirOculto(int) override;
        void guardarEnArchivo(std::ofstream&, int) override;
};

#endif  // CITA_PERSONAL_H