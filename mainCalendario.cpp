#include "Calendario.h"

int main() {

    Calendario* c = new Calendario();
    system("cls");
    
    while(true){
        c->crear_reservacion();
        c->imprimirCalendario();
        cout<<"Ingrese 1 para salir: ";
        std::string salir;
        getline(cin,salir);
        if(salir == "1"){break;}
    }
    cout<<"Llegamos al final"<<endl;
    


    return 0;
}