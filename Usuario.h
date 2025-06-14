#ifndef USUARIO_H
#define USUARIO_H

#include "Calendario.h"
#include "Encabezados.h"

class Usuario{
protected:
    std::string nombre;
    int cedula;
    std::string nomUsuario;
    std::string puesto;
    std::string contrasena;
    Calendario* calendario;
    Calendario* invitaciones;
    int id;
    
public:
    static int contadorId; //esto es estatico por tanto es el que se aumenta o
    //Constructores y Destructores
    Usuario(std::string,int,std::string,std::string,std::string, int);

    //Setters y getters:
    std::string getNombre() const;
    void setNombre(const std::string&);
    int getCedula() const;
    void setCedula(int);
    std::string getNomUsuario() const;
    void setNomUsuario(const std::string&);
    std::string getPuesto() const;
    void setPuesto(const std::string&);
    std::string getContrasena() const;
    void setContrasena(const std::string&);
    Calendario*& getCalendario();
    void setCalendario(Calendario*);
    int getID() const;
    void setID(int);
    Calendario* getInvitaciones();
    

    //Otros métodos
    virtual void imprimir(std::string) = 0;
    std::string infoUsuario() const;

    //Para escribir y leer de archivos
    virtual void escribirEnArchivo(ofstream&, ofstream&) = 0;
    virtual void leerCalendarioDeArchivo(std::ifstream&) = 0;

};
#endif