#ifndef REUNION_H
#define REUNION_H

#include "Reservacion.h"
class Usuario;
class ListaUsuario;

class Reunion : public Reservacion{
    private:
        string lugar;
        Usuario* organizador{nullptr};
        ListaUsuario* lista_invitados {nullptr};

    public:
        //Constructores y destructores
        Reunion(struct tm, struct tm, std::string);
        Reunion(struct tm, struct tm, std::string, time_t);
        Reunion(struct tm, struct tm, std::string,Usuario*,ListaUsuario*); //constructor al que le llega el usuario
        ~Reunion();

        //Setters y getters
        string getLugar() ;
        Usuario* getOrganizador();
        void setListaInvitados(ListaUsuario*);
        void setLugar(string);
        ListaUsuario* getListaInv();

        //Otros métodos
        void imprimirReservacion(int)  override;
        void imprimirReservacionOculta(int) override; 
        void imprimirListaInvitados();

        //Para guardar en archivo
        void escribirReservacionArchivo(ofstream&, ofstream&) override; //Varía según el tipo de reservación
      
};

#endif  // REUNION_H
