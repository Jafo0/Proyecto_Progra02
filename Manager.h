#ifndef MANAGER_H
#define MANAGER_H
#include "Usuario.h"
#include "ListaEmpleados.h"

class Manager : public Usuario{
    public:
    ListaEmpleados listaEmp; //pongo atributo en public
    Manager(string,int,string,string);//ListaUsuario*
    void imprimir() override;
};
#endif