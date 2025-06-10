#include "Usuario.h"
#include "Contribuidor.h"
#include "Manager.h"
#include "ListaUsuario.h"
#include "Interaccion.h"
#include "Comprobacion.h"

int main(){
    std::string eleccion;
    Interaccion* i;

    system("cls");      //Limpio pantalla
    //Para ver si cargamos de un archivo de texto
    do{
        cout<<"Desea cargar la sesion anterior? (1:Si/ 2:No): ";
        getline(cin, eleccion);
    }while(!numero_entero_dentro_de_rango(1, 2, eleccion));

    system("cls");      //Limpio pantalla
    if(stoi(eleccion) == 1){    //Leemos de archivo
        std::ifstream archivo("../ArchivoUsuarios.txt");
        if(archivo.is_open()){
            i = new Interaccion(archivo);
        }
    }else{
        i = new Interaccion();
        
    } 
    i->ejecutar();
    
    delete i;

    return 0;
}

// int main(){
//     cout<<numero_entero_dentro_de_rango(0,0,"0")<<endl;
//     cout<<"hola"<<endl;

//     return 0;
// }