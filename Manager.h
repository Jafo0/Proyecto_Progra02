#ifndef MANAGER_H
#define MANAGER_H
#include "Usuario.h"

class Manager : public Usuario{
    public:
    Manager(string,string,string,string,ListaUsuario*);//ListaUsuario*
    //~Manager() override = default;
    void registrar(ListaUsuario*) override;
    void imprimir() override;
};
#endif