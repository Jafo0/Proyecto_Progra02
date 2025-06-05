#include "Usuario.h"
#include "ContribuidorI.h"
#include "Manager.h"
#include "ListaUsuario.h"
#include "Interaccion.h"
int main(){
    ListaUsuario lista;
    Interaccion i(&lista);
    i.ejecutar();
    lista.imprimirUsuarios();
    return 0;
}