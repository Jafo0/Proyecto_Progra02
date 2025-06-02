#ifndef CONTRIBUIDORI_H
#define CONTRIBUIDORI_H
#include "Usuario.h"

class ContribuidorI : public Usuario{
    public:
    ContribuidorI(string,string,string,string,ListaUsuario*); 
    //~ContribuidorI() override = default;
    void registrar(ListaUsuario*) override;
    void imprimir() override;
};
#endif