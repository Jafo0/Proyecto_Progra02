#ifndef RESERVACION_H   
#define RESERVACION_H   

#include <ctime>    //Para trabajar con tiempo y fechas
#include <iomanip>  //Para formatear la salida 
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Reservacion {
    protected:
        struct tm fecha_inicio = {};  //Inicializo cada campo de fecha en cero
        struct tm fecha_fin = {};  //Inicializo cada campo de fecha en cero

    public:
        Reservacion(struct tm, struct tm);
        ~Reservacion();
        struct tm get_fecha_inicio();
        struct tm get_fecha_fin();
        virtual void imprimir() = 0;
        void ver_fechas();

};

#endif  // RESERVACION_H    