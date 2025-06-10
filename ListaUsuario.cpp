#include "ListaUsuario.h"
#include <iostream>
 
ListaUsuario::Nodo::Nodo(Usuario* us, Nodo* sig):usuario(us), next(sig){}

ListaUsuario::Nodo::~Nodo(){delete this->usuario;}

// ListaUsuario::ListaUsuario(std::ifstream& archivo) {
//     std::string linea;
//     while (std::getline(archivo, linea)) {
//         std::cout << linea << std::endl;
//     }
// }

ListaUsuario::ListaUsuario(){}

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

void ListaUsuario::guardarEnArchivo(std::ofstream& archivo) {
    //Primero guardamos todos los Contribuidores
    Nodo* aux = this->head;
    while(aux != nullptr) {
        if(aux->usuario->getPuesto() == "Contribuidor"){
            archivo << aux->usuario->obtenerInfo() << endl;  // Agregar salto de línea  
        }
        aux = aux->next;
    }
    //Segundo, guardamos todos los Managers
    aux = this->head;
    while(aux != nullptr) {
        if(aux->usuario->getPuesto() == "Manager"){
            archivo << aux->usuario->obtenerInfo() <<endl;  // Agregar salto de línea  
        }
        aux = aux->next;
    }
}

void ListaUsuario::agregarUsuario(Usuario* us){
    if (!this->head){   //Lista vacía
       this->head = new Nodo(us,nullptr);
    }else{  //La lista no está vacía
        this->head = new Nodo(us, this->head);  //Se agregan en forma de pila
    }
}

void ListaUsuario::agregar_usuario_por_id(ListaUsuario* usuarios_totales, int id){
    if((!this->comprobar_ID(id))){    //Si NO tenemos el id en nuestra lista (para no repetir):
        //Encuentro el usuario que quiero agregar:
        Nodo* temp = usuarios_totales->head;
        while(temp){ //Recorremos la lista de usuarios totales:
            if(temp->usuario->getId() == id){
                break;
            }
            temp = temp->next;
        }
        //En "temp" ya tenemos el usuario que queremos agregar
        if (!this->head){   //Lista vacía
            this->head = new Nodo(temp->usuario,nullptr);
        }else{  //La lista no está vacía
            this->head = new Nodo(temp->usuario, this->head);  //Se agregan en forma de pila
        }
    }

}

bool ListaUsuario::comprobar_ID(int id){
    Nodo* temp = this->head;
    while(temp){    //Mientras no estemos en un nodo nullptr
        if(temp->usuario->getId() == id){   //Encontramos el id
            return true;
        }
        temp = temp->next;
    }
    return false;   //No encontramos el id

}

void ListaUsuario::imprimir(){
    if(!this->head){    //No hay usuarios
        cout<<"\033[33m"<<"No hay usuarios registrados..."<<"\033[0m"<<endl;
    }else{
        Nodo* actual = head;
        int contador = 0;
        while(actual != nullptr){
            actual->usuario->imprimir("USUARIO: " + std::to_string(contador));
            actual = actual->next;
        }
        contador++;
    }
}

void ListaUsuario::imprimir_id(){
    if(this->head){
        Nodo* actual = head;
        cout<<"\033[33m"<<"Ids asociados: ";
        while(actual != nullptr){
            cout<<actual->usuario->getId();
            if(actual->next){cout<<",";}
            actual = actual->next;
        }
        cout<<"\033[0m"<<endl;
    }else{
        cout<<"\033[33m"<<"No hay ids asociados..."<<"\033[0m"<<endl;
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

Usuario* ListaUsuario::verificador(const std::string& respuestaUs,const std::string& respuestaPass){
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