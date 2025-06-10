#ifndef INTERACCION_H
#define INTERACCION_H
#include "Usuario.h"
#include "Contribuidor.h"
#include "Manager.h"
#include "ListaUsuario.h"

#include "Comprobacion.h"
#include <cstdlib>
#include <fstream>

class Interaccion{
private:
    ListaUsuario* usuarios_registrados;
    Usuario* usuarioActivo{nullptr};
    Manager* manActivo{nullptr};    //esto me funciona para la comprobacion
public:
    Interaccion();  //Cosntructor vacío
    Interaccion(std::ifstream&);    //Constructor a partir de un archivo de texto
    Usuario* crear_Usuario();
    int menu_entrada();
    bool iniciar_sesion(); //iniciar sesion pide contrasenna y nombre de usuario
    int escoger_accion_usuario_contribuidor();
    void realizar_accion_contribuidor();
    int escoger_accion_usuario_manager();
    void realizar_accion_manager();
    void ejecutar();
    bool guardar_en_archivo();
};
#endif  //INTERACCION_H