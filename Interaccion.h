#ifndef INTERACCION_H
#define INTERACCION_H
#include "Usuario.h"
#include "Contribuidor.h"
#include "Manager.h"
#include "ListaUsuario.h"

#include "Comprobacion.h"


class Interaccion{
private:
    //Atributos
    ListaUsuario* usuariosRegistrados;
    Usuario* usuarioActivo{nullptr};
    Manager* manActivo{nullptr};    //esto me funciona para la comprobacion

public:
    //Constructores y destructores
    Interaccion();  
    // Interaccion(std::ifstream&);  //, std::ifstream& Constructor a partir de dos archivos de texto usuarios y calendario
    ~Interaccion();

    //Pedir información
    int menu_entrada();
    string pedirTexto(string);
    int pedirCedula();
    int pedirPuesto();
    int menuAccionContribuidor();
    int menuAccionManager();

    //Realizar acciones:
    Usuario* crear_Usuario(); 
    bool iniciar_sesion(); //iniciar sesion pide contrasenna y nombre de usuario
    void realizarAccionContribuidor();
    void realizarAccionManager();

    //Lectura y escritura del archivo:
    void escribirEnArchivo();
    bool guardar_en_archivo_cal(int); //Nuevo guardar en archivo para Calendario
    void leerArchivo(std::ifstream&);
    Usuario* leerManager(std::ifstream&);
    Usuario* leerContribuidor(std::ifstream&);

    //Codificación de las contraseñas
    std::string codificar (std::string);

    //Método principal                
    void ejecutar();
};
#endif  //INTERACCION_H