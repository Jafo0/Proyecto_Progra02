#ifndef REUNION_H
#define REUNION_H

#include "Reservacion.h"

class Usuario;
class ListaUsuario;

class Reunion : public Reservacion{
    private:
        string lugar;
        Usuario* organizador {nullptr};
        ListaUsuario* invitados {nullptr};

    public:
        //Constructores y destructores
        Reunion(struct tm, struct tm, std::string);
        Reunion(struct tm, struct tm, std::string, time_t);
        ~Reunion();

        //Setters y getters
        string getLugar() ;
        void setLugar(string);

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int) override; 

        //Para guardar en archivo
        void escribirReservacionArchivo(ofstream&) override; //Varía según el tipo de reservación

};

#endif  // REUNION_H
