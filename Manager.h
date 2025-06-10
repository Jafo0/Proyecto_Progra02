#ifndef MANAGER_H
#define MANAGER_H

#include "ListaUsuario.h"

class Manager : public Usuario{
    public:
        ListaUsuario* listaEmp; //pongo atributo en public
        Manager(std::string,int,std::string,std::string, int);
        Manager(std::string,int,std::string,std::string, int, ListaUsuario*);
        void imprimirEmpleados();
        void imprimir(std::string) override;
        void agregar_empleado(ListaUsuario*);
        void eliminar_empleado();
        void modificar_listaEmp(ListaUsuario*);
        void guardar_en_archivo(std::ofstream&) override;
};
#endif