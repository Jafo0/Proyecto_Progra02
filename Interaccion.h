#ifndef INTERACCION_H
#define INTERACCION_H
#include "Usuario.h"
#include "ContribuidorI.h"
#include "Manager.h"
#include "ListaUsuario.h"
#include <cstdlib>

class Interaccion{
private:
    ListaUsuario* lista;
    Usuario* usuarioActivo{nullptr};
public:
    Interaccion(ListaUsuario*);
    void ejecutar();
    void crear_Usuario();
    void menu_general(); //iniciar sesion pide contrasenna y nombre de usuario
    void menu_usuario();
    //verifica que la contrasenna y el nombre de usuario este en el sistema esto va en lista
};
#endif