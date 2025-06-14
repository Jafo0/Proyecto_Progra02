#ifndef CALENDARIO_H
#define CALENDARIO_H

//Las reservaciones
#include "Reservacion.h"
#include "Reunion.h" 
#include "CitaPersonal.h"
#include "ActividadSocial.h"
#include "EventoDiario.h"

#include "Comprobacion.h"
#include "Encabezados.h"

class Usuario;
class Calendario {
    private:
        //Definido dentro de calendario
        class Nodo{
            public:
                //Atributos
                Reservacion* reservacion {nullptr};
                Nodo* nodoSiguiente {nullptr};
                //Constructores y destructores
                Nodo(Reservacion*, Nodo*);
                ~Nodo();
                //Setters y getters
                Reservacion* getReservacion() const;
                void setReservacion(Reservacion*);
                Nodo* getNodoSiguiente() const;
                void setNodoSiguiente(Nodo*);
        };

        //Atributos de calendario
        Nodo* primeraReservacion {nullptr};
        time_t segundosActual;
        struct tm fechaActual;
        int cantidadReservaciones {0};

    public:
        //Constructores y destructores
        Calendario();
        ~Calendario();

        //Setters y getters
        time_t getSegundosActual() const;
        struct tm getFechaActual() const;
        int getCantidadReservaciones() const;

        //Comprobación de fechas correctas
        bool nuevaReservacionLogica(struct tm, struct tm) const;   //Fecha de fin sea mayor a la fecha inicio y posterior al pasado
        bool choqueConCalendario(struct tm, struct tm) const;   //Revisa que la reserva no choque con otra del calendario

        //Para pedir días
        int preguntarAnno() const;
        int preguntarMes() const;
        int preguntarDia() const;
        int preguntarHora() const;
        int preguntarMinuto() const;

        //Para pedir fechas
        struct tm preguntarFechaGeneral() const;
        struct tm preguntarFechaEspecifica(string)const;

        //Para la visualización del calendario:
        void imprimirCalendarioCompleto();
        void imprimirCalendarioOculto();
        int menuReservaciones() const;
        void crearReservacion(Usuario*,ListaUsuario*);        //le llega un puntero a usuario
        ListaUsuario* printParaAgregarId(Usuario*,ListaUsuario*);           //print para agregar el id
        void ordenarReservacion(Reservacion*);
        void eliminarReservacion(int);
        
        //Lectura y escritura del archivo
        void escribirEnArchivo(ofstream&, ofstream&) const; //guardar en archivo calendario
        struct tm* leerIdYFechasDeArchivo(ifstream&);
        Reservacion* leerReunionDeArchivo(ifstream&);
        Reservacion* leerActividadSocialDeArchivo(ifstream&);
        Reservacion* leerEventoDiarioDeArchivo(ifstream&);
        Reservacion* leerCitaPersonalDeArchivo(ifstream&);
        void leerDeArchivo(ifstream&);
};

#endif  // CALENDARIO_H
