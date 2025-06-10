#ifndef CONTRIBUIDOR_H
#define CONTRIBUIDOR_H
#include "Usuario.h"

class Contribuidor : public Usuario{
    public:
    Contribuidor(std::string,int,std::string,std::string, int); 
    //~ContribuidorI() override = default;
    void imprimir(std::string) override;
};
#endif