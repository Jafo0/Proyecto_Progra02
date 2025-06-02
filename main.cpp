#include "Usuario.h"
#include "ContribuidorI.h"
#include "Manager.h"
#include "ListaUsuario.h"
int main(){
    ListaUsuario lista;
    Usuario* m = new Manager("Ana", "111", "ana_m", "pass123", &lista);
    Usuario* c = new ContribuidorI("Luis", "222", "luis_c", "pass456", &lista);
    lista.imprimirUsuarios();
    return 0;
}