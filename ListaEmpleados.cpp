#include "ListaEmpleados.h"
ListaEmpleados::Nodo::Nodo(int contribuidorID, Nodo* sig):id(contribuidorID), next(sig){}
ListaEmpleados::Nodo::~Nodo(){}

ListaEmpleados::~ListaEmpleados(){
    while(this->head != nullptr){
        Nodo* aux = head;
        this->head = head->next;
        delete aux;
    }
}

bool ListaEmpleados::agregarId(Usuario* con){
    int id_nuevo = con->getId();

    if(comprobarLista(id_nuevo)){
        head = new Nodo(id_nuevo,head); //siempre va ser el head
        return true;
    }else{
        return false;
    }
}
/*
void ListaEmpleados::popId(int idEntrada){
    if(!head){          //head nula
        return false;   //si no se pudo eliminar
    }else if(head->id == idEntrada){
        Nodo* aux = head;
        head=head->next;
        delete aux;
    }else{
        Nodo* aux=head;
        while(aux->next && aux->next->id != idEntrada){
            aux = aux->next;
        }
        if(aux->next == nullptr){
            return false;
        }else{
            Nodo* borrar = aux->next;
            aux->next = aux->next->next;
            delete borrar;
            return true;
        }
    }
}
*/
void ListaEmpleados::imprimir(){
    if(!this->head){ // cabeza nula
        return;
    }
    Nodo* actual = head;
    cout<<"--------------Lista de sus usuarios--------------"<<endl;
    cout<<"[";
    while(actual != nullptr){
        if(actual->next != nullptr){
            cout << actual->id << " , ";
        } else {
            cout << actual->id <<"]"<<endl;
        }
        actual = actual->next;
    }
}
bool ListaEmpleados::comprobarLista(int id){
    Nodo* aux=head;
    while (aux != nullptr){ //si la cabeza no es nula
        if(aux->id == id){  //si el id de la cabeza = id entrada es false
            return false;   //es false porque se repite
        }
        aux=aux->next;
    }
    return true;            //no se repite
}