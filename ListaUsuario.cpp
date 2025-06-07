#include "ListaUsuario.h"
#include <iostream>
 
ListaUsuario::Nodo::Nodo(Usuario* us, Nodo* sig):usuario(us), next(sig){}

ListaUsuario::Nodo::~Nodo(){delete this->usuario;}

ListaUsuario::~ListaUsuario(){
    while(this->head != nullptr){
        Nodo* aux = this->head;
        this->head = this->head->next;
        delete aux;
    }
}

bool ListaUsuario::vacia(){
    if(!this->head){
        return true;
    }else{
        return false;
    }
}

bool ListaUsuario::guardarEnArchivo() {
    ofstream archivo("ArchivoUsuarios.txt");
    if (!archivo.is_open()) {
        return false;  // No se pudo abrir el archivo
    }
    Nodo* aux = this->head;
    while(aux != nullptr) {
        archivo << aux->usuario->obtenerInfo() << "\n";  // Agregar salto de línea
        aux = aux->next;
    }
    archivo.close();  
    return true;  
}
void ListaUsuario::agregarUsuario(Usuario* us){
    if (!this->head){   //Lista vacía
       this->head = new Nodo(us,nullptr);
    }else{  //La lista no está vacía
        this->head = new Nodo(us, this->head);  //Se agregan en forma de pila
    }
    this->guardarEnArchivo();
}
void ListaUsuario::imprimirUsuarios(){
    if(this->head == nullptr){
        return;
    }
    Nodo* actual = head;
    while(actual != nullptr){
        actual->usuario->imprimir();
        actual = actual->next;
    }
}

Usuario* ListaUsuario::encontrarId(const int& idEntrada){
    Nodo* actual = head;
    if(actual == nullptr){
        cout << "\033[31m"<<"La lista no contiene ningun usuario"<<"\033[0m" << endl;
    }
    while (actual != nullptr){
        if(actual->usuario->getPuesto() == "Contribuidor" && actual->usuario->getId() == idEntrada){
            return actual->usuario;
            break;
        }
        actual = actual->next;
    }
    return nullptr;
}

Usuario* ListaUsuario::verificador(const string& respuestaUs,const string& respuestaPass){
    Nodo* actual = head;
    if(actual == nullptr){
        cout << "\033[31m"<<"La lista no contiene ningun usuario"<<"\033[0m" << endl;
    }
    while (actual != nullptr){

        if(actual->usuario->getNomUs() == respuestaUs && actual->usuario->getContra() == respuestaPass){
            return actual->usuario;
            break;
        }
        actual = actual->next;
    }
    return nullptr;
}