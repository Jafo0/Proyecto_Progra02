#ifndef CONTRIBUIDOR_H
#define CONTRIBUIDOR_H
#include "Usuario.h"

class Contribuidor : public Usuario{
    public:
    Contribuidor(std::string,int,std::string,std::string, int); 
    ~Contribuidor();
    void imprimir(std::string) override;
    void escribirEnArchivo(std::ofstream&) override;
};
#endif