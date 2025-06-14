#ifndef RESERVACION_H   
#define RESERVACION_H   

#include "Encabezados.h"

class Reservacion {
    protected:
        struct tm fechaInicio = {};  //Inicializo cada campo de fecha en cero
        struct tm fechaFin = {};  //Inicializo cada campo de fecha en cero
        time_t idReservacion {0};
        std::string tipo;

    public:
        //Constructores y destructores:
        Reservacion(struct tm, struct tm,std::string);  //Genera el id
        Reservacion(struct tm, struct tm,std::string, time_t);  //Le paso el id
        ~Reservacion();
        
        //Setters y Getters
        struct tm& getFechaInicio();     
        struct tm& getFechaFin();
        std::string getTipo(); 
        void setTipo(string);
        void setFechaInicio(struct tm);
        void setFechaFin(struct tm);
        time_t getIdReservacion();

        //Para visualizar
        virtual void imprimirReservacion(int) = 0;     //Imprime la reservación con todos sus detalles
        virtual void imprimirReservacionOculta(int) = 0;   //Imprime la reservación solo con datos de las fechas
        string getFecha(struct tm&);     //Me da en formato de string una fecha ingresada

        //Para comprobar si una fecha incresada choca con esta fecha
        bool choqueFechas(struct tm&, struct tm&);
};  

#endif  // RESERVACION_H    