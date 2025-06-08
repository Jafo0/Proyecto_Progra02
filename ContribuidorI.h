#ifndef CONTRIBUIDORI_H
#define CONTRIBUIDORI_H
#include "Usuario.h"

class ContribuidorI : public Usuario{
    public:
    ContribuidorI(std::string,int,std::string,std::string); 
    //~ContribuidorI() override = default;
    void imprimir() override;
};
#endif