#ifndef MANAGER_H
#define MANAGER_H
#include "Usuario.h"
#include "ListaEmpleados.h"

class Manager : public Usuario{
    public:
    ListaEmpleados listaEmp; //pongo atributo en public
    Manager(std::string,int,std::string,std::string);//ListaUsuario*
    void imprimir() override;
};
#endif