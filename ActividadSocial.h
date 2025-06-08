#ifndef ACTIVIDAD_SOCIAL_H
#define ACTIVIDAD_SOCIAL_H

#include "Reservacion.h"

class ActividadSocial : public Reservacion {
    protected:
        //ListaUsuarios* participantes {nullptr};
        std::string lugar {"Comedor al aire libre"};
    public:
        ActividadSocial(struct tm, struct tm);
        ~ActividadSocial();
        void imprimir(int) override;
};

#endif  // ACTIVIDAD_SOCIAL_H
