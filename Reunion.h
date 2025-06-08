#ifndef REUNION_H
#define REUNION_H

#include "Reservacion.h"

class Reunion : public Reservacion{
    private:
        std::string lugar;
        //ListaUsuarios* participantes {nullptr};

    public:
        Reunion(struct tm, struct tm, std::string);
        ~Reunion();
        void imprimir(int) override;

};

#endif  // REUNION_H
