#include <string>
#include <iostream>

using namespace std;

std::string codificar (std::string contrasenna){
    int longitud = contrasenna.length();    //Longitud de la contraseña
    const char* arreglo_original = contrasenna.c_str(); //Función vista en clase
    std::string contrasenna_codificada; //Contraseña codificada
    for(int i = 0; i < longitud; i++){
        contrasenna_codificada += arreglo_original[i] + '5'; //Hago el mapeo para que la contraseña no se vea como la ingresada por el usuario
    }
    return contrasenna_codificada;
}

int main(){
    cout<<codificar("Hola")<<endl;

}