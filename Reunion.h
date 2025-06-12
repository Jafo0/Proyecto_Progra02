#ifndef REUNION_H
#define REUNION_H

#include "Reservacion.h"

class Reunion : public Reservacion{
    private:
        std::string lugar;
        // ListaUsuario* participantes {nullptr};
        int id_organizador;

    public:
        Reunion(struct tm, struct tm, std::string, int);
        ~Reunion();
        void imprimir(int) override;
        void imprimirOculto(int) override; //no muestro tipo de reservacion ni lugar
        void guardarEnArchivo(std::ofstream&,int) override;

};

#endif  // REUNION_H
