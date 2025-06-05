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
    Interaccion();
    Usuario *crear_Usuario();
    int menu_entrada();
    bool iniciar_sesion(); //iniciar sesion pide contrasenna y nombre de usuario
    int menu_accion_usuario();
    //verifica que la contrasenna y el nombre de usuario este en el sistema esto va en lista
    void ejecutar();
};
#endif