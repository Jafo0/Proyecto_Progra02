#ifndef MANAGER_H
#define MANAGER_H
#include "Usuario.h"

class Manager : public Usuario{
    public:
    Manager(string,int,string,string);//ListaUsuario*
    //~Manager() override = default;
    void imprimir() override;
};
#endif