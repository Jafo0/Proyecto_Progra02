#ifndef RESERVACION_H   
#define RESERVACION_H   

#include "Encabezados.h"

class Reservacion {
    protected:
        struct tm fechaInicio = {};  //Inicializo cada campo de fecha en cero
        struct tm fechaFin = {};  //Inicializo cada campo de fecha en cero

    public:
        //Constructores y destructores:
        Reservacion(struct tm, struct tm); 
        Reservacion(ifstream&);   //Apartir de un archivo 
        ~Reservacion();
        
        //Setters y Getters
        struct tm& getFechaInicio();     
        struct tm& getFechaFin(); 
        void setFechaInicio(struct tm);
        void setFechaFin(struct tm);

        //Para visualizar
        virtual void imprimirReservacion(int) = 0;     //Imprime la reservación con todos sus detalles
        virtual void imprimirReservacionOculta(int) = 0;   //Imprime la reservación solo con datos de las fechas
        string getFecha(struct tm&);     //Me da en formato de string una fecha ingresada

        //Para escribir en archivo
        void escibirFechasReservacionArchivo(ofstream&);   //Escribe las fechas de la reservacion
        virtual void escribirReservacionArchivo(ofstream&) = 0; //Varía según el tipo de reservación

        //Para comprobar si una fecha incresada choca con esta fecha
        bool choqueFechas(struct tm&, struct tm&);
};  

#endif  // RESERVACION_H    