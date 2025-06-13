#include "Interaccion.h"
#include "Comprobacion.h"
#include "Encabezados.h"

int main(){
    string eleccion;
    Interaccion* i = new Interaccion();

    //Para ver si cargamos de un archivo de texto
    do{
        cout<<"Desea cargar la sesion anterior? (1:Si/ 2:No): ";
        getline(cin, eleccion);
    }while(!numero_entero_dentro_de_rango(1, 2, eleccion));

          //Limpio pantalla
    if(stoi(eleccion) == 1){    //Leemos de archivo
        std::ifstream archivo("../ArchivoUsuarios.txt");
        if(archivo.is_open()){
            i->leerArchivo(archivo);
        }
    }
    i->ejecutar();
    delete i;

    return 0;
}
