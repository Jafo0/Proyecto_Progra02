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
        void imprimirOculto(int) override; //no imprimi ni tipo de reservacion ni lugar
        void guardarEnArchivo(std::ofstream&,int) override;
};

#endif  // ACTIVIDAD_SOCIAL_H
