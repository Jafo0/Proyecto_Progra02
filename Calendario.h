#ifndef CALENDARIO_H
#define CALENDARIO_H

#include "Reservacion.h"
#include "Reunion.h" 
#include "CitaPersonal.h"
#include "ActividadSocial.h"
#include "EventoDiario.h"

#include <cstdlib>  //Para limpiar la pantalla

class Calendario {
    private:
        class Nodo{
            public:
                Reservacion* reservacion {nullptr};
                Nodo* nodo_siguiente {nullptr};
                Nodo(Reservacion*, Nodo*);
                ~Nodo();
                void setSiguiente(Nodo*);
        };
        Nodo* primera_reservacion {nullptr};

    public:
        ~Calendario();
        bool choqueFechas(struct tm, struct tm);
        struct tm preguntarDia();
        struct tm preguntarFecha(std::string);
        char menu_reservaciones();
        Reservacion* crearReservacion();
        void agregarReservacion();
        void imprimirCalendario();
};

#endif  // CALENDARIO_H
