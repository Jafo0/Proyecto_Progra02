#ifndef CONTRIBUIDORI_H
#define CONTRIBUIDORI_H
#include "Usuario.h"

class ContribuidorI : public Usuario{
    public:
    ContribuidorI(string,int,string,string); 
    //~ContribuidorI() override = default;
    void imprimir() override;
};
#endif