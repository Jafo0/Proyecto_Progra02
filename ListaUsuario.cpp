#include "ListaUsuario.h"
#include <iostream>
 
ListaUsuario::Nodo::Nodo(Usuario* us, Nodo* sig):usuario(us), next(sig){}

ListaUsuario::Nodo::~Nodo(){delete this->usuario;}

ListaUsuario::Nodo* ListaUsuario::Nodo::getNext() const {return this->next;}

void ListaUsuario::Nodo::setNext(Nodo* _next){this->next = _next;}

Usuario* ListaUsuario::Nodo::getUsuario() const{return this->usuario;}

void ListaUsuario::Nodo::setUsuario(Usuario* _usuario){this->usuario = _usuario;}

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

bool ListaUsuario::vacia(){return !this->head;}

bool ListaUsuario::comprobarID(int id){
    Nodo* temp = this->head;
    while(temp){    //Mientras no estemos en un nodo nullptr
        if(temp->getUsuario()->getID() == id){  //Encontramos el id
            return true;
        }
        temp = temp->next;
    }
    return false;   //No encontramos el id
}

bool ListaUsuario::IdEsContribuidor(int id){
    if(this->vacia()){

    }
    if((this->comprobarID(id))){    
        Nodo* temp = this->head;
        while(temp){ //Recorremos la lista de usuarios totales:
            if(temp->getUsuario()->getID() == id){
                return temp->getUsuario()->getPuesto() == "Contribuidor";
            }
            temp = temp->next;
        }
    }
    return  false;
}

bool ListaUsuario::hayContribuidores(){
    if(this->head){    //Hay usuarios
        Nodo* actual = head;
        while(actual != nullptr){
            if(actual->getUsuario()->getPuesto() == "Contribuidor"){return true;}  
            actual = actual->next;
        }
        cout<<"\033[33m"<<"No hay contribuidores registrados..."<<"\033[0m"<<endl;
        return false;
    }

    cout<<"\033[33m"<<"No hay contribuidores registrados..."<<"\033[0m"<<endl;
    return false;
}

void ListaUsuario::agregarUsuario(Usuario* us){
    if (!this->head){   //Lista vacía
       this->head = new Nodo(us,nullptr);
    }else{  //La lista no está vacía
        this->head = new Nodo(us, this->head);  //Se agregan en forma de pila
    }
    cout<<"\033[32m"<<"Usuario agregado exitosamente..."<<"\033[0m"<<endl;
}

Usuario* ListaUsuario::UsuarioPorID(int id){
    if((this->comprobarID(id))){    //Si tenemos el id en nuestra lista:
        //Encuentro el usuario que quiero agregar:
        Nodo* temp = this->head;
        while(temp){ //Recorremos la lista de usuarios totales:
            if(temp->getUsuario()->getID() == id){
                return temp->getUsuario();
            }
            temp = temp->next;
        }
    }
    return nullptr;
}

void ListaUsuario::eliminarContribuidorPorID(int id){  //Para eliminar contribuidores, no de los usuarios totales
    if(this->comprobarID(id)){
        if(this->head->getUsuario()->getID() == id){  //Quiero eliminar el primer contribuidor
            this->head = this->head->next; //No eliminamos this->head ya que sigue en nuestra lista de usuarios registrados
        }else{  //Quiero eliminar una cabeza que no sea la primera
            Nodo* temp = this->head;     //Guardamos la primera reservacion en nodo temporal.
            while(true){
                if(temp->getNext()->getUsuario()->getID() == id){break;}  //Comparamos el id con el nodo siguiente
                temp = temp->next;
            }
            temp->setNext(temp->next->next);  //No eliminamos temp->next ya que sigue en nuestra lista de usuarios registrados
            cout<<"\033[32m"<<"Usuario eliminado exitosamente..."<<"\033[0m"<<endl;
        }  
    }  
}

void ListaUsuario::imprimir(string encabezado1, string encabezado2){
    if(!this->head){    //No hay usuarios
        cout<<"\033[33m"<<encabezado1<<"\033[0m"<<endl;
    }else{
        cout << "\033[33m"<<encabezado2<<"\033[0m" << endl;
        Nodo* actual = this->head;
        int contador = 0;
        while(actual != nullptr){
            actual->getUsuario()->imprimir("USUARIO " + std::to_string(contador) + ": ");
            contador++;
            actual = actual->next; 
        }
    }
}

void ListaUsuario::imprimirIDS(){
    // cout<<"\033[33m"<<"Ids asociados: ";
    if(this->head){
        Nodo* actual = this->head;
        while(actual != nullptr){
            cout<<actual->getUsuario()->getID();
            if(actual->next){cout<<",";}
            actual = actual->next;
        }
        cout<<"\033[0m"<<endl;
    }else{
        cout<<"\033[33m"<<"No hay ids asociados..."<<"\033[0m"<<endl;
    }
}

Usuario* ListaUsuario::verificador(const std::string& respuestaUs,const std::string& respuestaPass){
    Nodo* actual = head;
    if(actual == nullptr){
        cout << "\033[31m"<<"La lista no contiene ningun usuario"<<"\033[0m" << endl;
    }
    while (actual != nullptr){

        if(actual->getUsuario()->getNomUsuario() == respuestaUs && actual->getUsuario()->getContrasena() == respuestaPass){
            return actual->getUsuario();
            break;
        }
        actual = actual->next;
    }
    return nullptr;
}

bool ListaUsuario::verificador2(const int& ced,const std::string& nomUs){
    Nodo* actual = head;
    while(actual != nullptr){
        if(actual->getUsuario()->getCedula() == ced || actual->getUsuario()->getNomUsuario() == nomUs){
            return false;                   //no se pudo ingresar usuario
            break;                          //sale del ciclo while
        }
        actual = actual->next;
    }
    return true;                            //el nombre de usuario no coincide con ninguno en la lista
}

void ListaUsuario::escribirEnArchivo(std::ofstream& archivo, ofstream& archivoOtro) {
    //Primero guardamos todos los Contribuidores
    Nodo* aux = this->head;
    while(aux != nullptr) {
        if(aux->usuario->getPuesto() == "Contribuidor"){
            aux->getUsuario()->escribirEnArchivo(archivo, archivoOtro);
        }
        aux = aux->next;
    }
    //Segundo, guardamos todos los Managers
    aux = this->head;
    while(aux != nullptr) {
        if(aux->usuario->getPuesto() == "Manager"){
            aux->usuario->escribirEnArchivo(archivo, archivoOtro);
        }
        aux = aux->next;
    }
}

void ListaUsuario::escribirIdsEnArchivo(std::ofstream& archivo){
    if(this->vacia()){
        archivo<<"No hay ids asociados";
    }else{
       Nodo* aux = this->head;
        while(aux != nullptr) {
                archivo << aux->getUsuario()->getID(); 
                if(aux->next){archivo<<",";} //Si hay un nodo siguiente
            aux = aux->next;
        } 
    }
    archivo<<endl;
}

void ListaUsuario::leerIds(std::ifstream& archivo, ListaUsuario* listaOtra){
    string linea_temp;
    getline(archivo, linea_temp);   //Leo la línea
    std::stringstream ss(linea_temp);   //Creo un stream de la línea
    string id;               //Cada elemento separado por coma (csv)
    getline(ss, id, ',');  //Me deshago del encabezado "Ids asociados,"
    while(getline(ss, id, ',')){  //Leemos en intervalos de una coma
        if(id == "No hay ids asociados"){break;} 
        this->agregarUsuario(listaOtra->UsuarioPorID(stoi(id)));
    }
}