#ifndef MANAGER_H
#define MANAGER_H

#include "ListaUsuario.h"

class Manager : public Usuario{
    public:
        ListaUsuario* listaSubordinados {nullptr};
        
        //Constructores y destructores
        Manager(std::string,int,std::string,std::string, int);
        Manager();
        ~Manager();

        //Setters y getters
        void setListaSubordinados(ListaUsuario*);

        //Para visualizar:
        void imprimirSubordinados();
        void imprimir(std::string) override;

        //Para modificar los subordinados
        void agregarSubordinado(Usuario*);
        void eliminarSubordinado(int);
        int menuAccionesSubordinados();
        void modificarSubordinados(ListaUsuario*);

        //Para escribir y leer de archivos
        void escribirEnArchivo(std::ofstream&) override;
        void leerCalendarioDeArchivo(std::ifstream&) override;
};
#endif