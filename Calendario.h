#ifndef CALENDARIO_H
#define CALENDARIO_H

#include "Reservacion.h"
#include "Reunion.h" 
#include "CitaPersonal.h"
#include "ActividadSocial.h"
#include "EventoDiario.h"

#include "Comprobacion.h"

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
        time_t segundos_actual;
        struct tm fecha_actual;
        int cantidad_reservaciones {0};

    public:
        Calendario();
        ~Calendario();
        int getCantidadReservaciones();
        bool reservacion_incorrecta(struct tm, struct tm, struct tm);
        struct tm preguntarDia();
        struct tm preguntarFecha(std::string);
        int menu_reservaciones();
        void crear_reservacion();
        void acomodarReservacion(Reservacion*);
        void eliminarReservacion(int);
        void modificarReservacion(int);
        void imprimirCalendario();
};

#endif  // CALENDARIO_H
