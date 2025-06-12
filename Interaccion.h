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

    //nuevo atributo
    //Calendario* calendarios_registrados; //una lista de calendarios
public:
    Interaccion();  //Cosntructor vacío
    Interaccion(std::ifstream&);  //, std::ifstream& Constructor a partir de dos archivos de texto usuarios y calendario
    Usuario* crear_Usuario();                     
    int menu_entrada();
    bool iniciar_sesion(); //iniciar sesion pide contrasenna y nombre de usuario
    int escoger_accion_usuario_contribuidor();
    void realizar_accion_contribuidor();
    int escoger_accion_usuario_manager();
    void realizar_accion_manager();
    void ejecutar();
    bool guardar_en_archivo();
    std::string codificar (std::string);

    //Nuevo guardar en archivo para Calendario
    bool guardar_en_archivo_cal(int);
};
#endif  //INTERACCION_H