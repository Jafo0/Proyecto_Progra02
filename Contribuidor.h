#ifndef CONTRIBUIDOR_H
#define CONTRIBUIDOR_H
#include "Usuario.h"

class Contribuidor : public Usuario{
    public:
    //Constructores y destructores
    Contribuidor(std::string,int,std::string,std::string, int); 
    ~Contribuidor();

    //Para visualización
    void imprimir(std::string) override;

    //Lectura y escritura del archivo
    void escribirEnArchivo(std::ofstream&) override;
    void leerCalendarioDeArchivo(std::ifstream&) override;
};
#endif