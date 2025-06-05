#include "ListaUsuario.h"
#include <iostream>
 
ListaUsuario::Nodo::Nodo(Usuario* us, Nodo* sig):usuario(us), next(sig){}
ListaUsuario::Nodo* ListaUsuario::Nodo::getNext(){
    return this->next;
}
Usuario* ListaUsuario::Nodo::getUsuario(){
    return this->usuario;
}
ListaUsuario::Nodo::~Nodo(){delete this->usuario;}

ListaUsuario::~ListaUsuario(){
    while(this->head != nullptr){
        Nodo* aux = this->head;
        this->head = this->head->getNext();
        delete aux;
    }
}
void ListaUsuario::agregarUsuario(Usuario* us){
    if (this->head ==nullptr){
       this->head = new Nodo(us,nullptr);
    }else{
        this->head = new Nodo(us, this->head);
    }
}
bool ListaUsuario::guardarEnArchivo() {
    ofstream archivo("ArchivoUsuarios.txt");
    if (!archivo.is_open()) {
        return false;  // No se pudo abrir el archivo
    }
    Nodo* aux = this->head;
    while(aux != nullptr) {
        archivo << aux->getUsuario()->obtenerInfo() << "\n";  // Agregar salto de línea
        aux = aux->getNext();
    }
    archivo.close();  
    return true;  
}

void ListaUsuario::imprimirUsuarios(){
    if(this->head == nullptr){
        return;
    }
    Nodo* actual = head;
    while(actual != nullptr){
        actual->getUsuario()->imprimir();
        actual = actual->getNext();
    }
}

Usuario* ListaUsuario::verificador(const string& respuestaUs,const string& respuestaPass){
    Nodo* actual = head;
    if(actual == nullptr){
        cout << "\033[31m"<<"La lista no contiene ningun usuario"<<"\033[0m" << endl;
    }
    while (actual != nullptr){

        if(actual->getUsuario()->getNomUs() == respuestaUs && actual->getUsuario()->getContra() == respuestaPass){
            return actual->getUsuario();
            break;
        }
        actual = actual->getNext();
    }
    return nullptr;
}