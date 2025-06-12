#ifndef CALENDARIO_H
#define CALENDARIO_H

#include "Reservacion.h"
#include "Reunion.h" 
#include "CitaPersonal.h"
#include "ActividadSocial.h"
#include "EventoDiario.h"

#include "Comprobacion.h"
#include <fstream>
#include <cstdlib>  //Para limpiar la pantalla

class Calendario {
    private:
        class Nodo{
            public:
                Reservacion* reservacion {nullptr}; //elementos que guarda
                Nodo* nodo_siguiente {nullptr};
                Nodo(Reservacion*, Nodo*);
                ~Nodo();
                void setSiguiente(Nodo*);
        };
        Nodo* primera_reservacion {nullptr};
        time_t segundos_actual;
        struct tm fecha_actual;
        int cantidad_reservaciones {-1};

    public:
        Calendario();
        ~Calendario();
        int getCantidadReservaciones();
        bool reservacion_incorrecta(struct tm, struct tm, struct tm);   //Revisa que la fecha de fin sea mayor a la fecha inicio
        bool choque_con_calendario(struct tm, struct tm);   //Revisa que la reserva no choque con otra del calendario
        struct tm preguntarDia();
        struct tm preguntarFecha(std::string);
        int menu_reservaciones();
        void crear_reservacion(int);
        void acomodarReservacion(Reservacion*);
        void eliminarReservacion(int);
        void modificarReservacion(int, int);
        void imprimirCalendario();//int
        //void imprimirCalendarioR();

        void guardarEnArchivo(std::ofstream&,int); //guardar en archivo calendario
};

#endif  // CALENDARIO_H
