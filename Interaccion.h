#ifndef INTERACCION_H
#define INTERACCION_H
#include "Usuario.h"
#include "ContribuidorI.h"
#include "Manager.h"
#include "ListaUsuario.h"

#include "Comprobacion.h"
#include <cstdlib>

class Interaccion{
private:
    ListaUsuario* lista;
    Usuario* usuarioActivo{nullptr};
    Manager* manActivo{nullptr};    //esto me funciona para la comprobacion
public:
    Interaccion();
    Usuario *crear_Usuario();
    int menu_entrada();
    bool iniciar_sesion(); //iniciar sesion pide contrasenna y nombre de usuario
    int menu_accion_usuario();
    void ejecutar();
    bool modificar_empleados(); //modificar la lista de empleados de un manager, pide el id por agregar
};
#endif  //INTERACCION_H