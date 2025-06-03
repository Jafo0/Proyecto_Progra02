#include "Calendario.h"

int main() {

    Calendario* c = new Calendario();
    
    while(true){
        c->agregarReservacion();
        c->imprimirCalendario();
        cout<<"Ingrese 1 para salir: ";
        int salir;
        cin>>salir;
        cout<<endl;
        if(salir == 1){break;}
    }
    cout<<"Llegamos al final"<<endl;
    


    return 0;
}