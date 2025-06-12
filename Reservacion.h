#ifndef RESERVACION_H   
#define RESERVACION_H   

#include <ctime>    //Para trabajar con tiempo y fechas
#include <iomanip>  //Para formatear la salida 
#include <iostream>
#include <string>
#include <fstream>  //Para poder usar el ofstream e ifstream en clases hijas 
#include <sstream>

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
        struct tm& get_fecha_inicio();
        struct tm& get_fecha_fin();
        // virtual void modificar() = 0;
        virtual void imprimir(int) = 0;
        virtual void imprimirOculto(int) = 0;
        std::string imprimir_fecha(const struct tm& fecha);
        bool fecha_choca(struct tm);

        //Nuevos metodos
        std::string obtenerInfo() const;
        virtual void guardarEnArchivo(std::ofstream&,int) = 0; //cada reservacion debe saber como guardarse en el archivo
        std::string imprimir_fecha_const(const struct tm& fecha) const;
};  

#endif  // RESERVACION_H    