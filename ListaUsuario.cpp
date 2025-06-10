#include "ListaUsuario.h"
#include <iostream>
 
ListaUsuario::Nodo::Nodo(Usuario* us, Nodo* sig):usuario(us), next(sig){}

ListaUsuario::Nodo::~Nodo(){delete this->usuario;}

void ListaUsuario::Nodo::set_siguiente(Nodo* siguiente){
    this->next = siguiente;
}

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
            aux->usuario->guardar_en_archivo(archivo);
        }
        aux = aux->next;
    }
    //Segundo, guardamos todos los Managers
    aux = this->head;
    while(aux != nullptr) {
        if(aux->usuario->getPuesto() == "Manager"){
            aux->usuario->guardar_en_archivo(archivo);
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

void ListaUsuario::agregar_contribuidor_por_id(ListaUsuario* usuarios_totales, int id){
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
        if(temp->usuario->getPuesto() == "Manager"){
            system("cls");
            cout<<"\033[33m"<<"No se puede agregar el id ya que corresponde a un manager..."<<"\033[0m"<<endl;
        }else{
            if (!this->head){   //Lista vacía
                this->head = new Nodo(temp->usuario,nullptr);
            }else{  //La lista no está vacía
                this->head = new Nodo(temp->usuario, this->head);  //Se agregan en forma de pila
            }
            system("cls");
            cout<<"\033[32m"<<"id agregado con exito..."<<"\033[0m"<<endl;
        }
    }else{
        system("cls");
        cout<<"\033[33m"<<"El id ingresado YA se encuentra en nuestra lista de subordinados..."<<"\033[0m"<<endl;

    }
}

void ListaUsuario::eliminar_contribuidor_por_id(int id){   //Asumimos que el id sí está y tenemos contribuidores
    if(this->head->usuario->getId() == id){  //Quiero eliminar el primer contribuidor
        this->head = this->head->next; //No eliminamos this->head ya que sigue en nuestra lista de usuarios registrados
    }else{  //Quiero eliminar una cabeza que no sea la primera
        Nodo* temp = this->head;     //Guardamos la primera reservacion en nodo temporal.
        while(true){
            if(temp->next->usuario->getId() == id){break;}  //Comparamos el id con el nodo siguiente
            temp = temp->next;
        }
        temp->set_siguiente(temp->next->next);  //No eliminamos temp->next ya que sigue en nuestra lista de usuarios registrados
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
            contador++;
        }
        
    }
}

void ListaUsuario::imprimir_contribuidores(){
    if(this->hay_contribuidores()){ //Hay contribuidores registrados
        Nodo* actual = head;
        int contador = 0;
        while(actual != nullptr){
            if(actual->usuario->getPuesto() == "Contribuidor"){
                actual->usuario->imprimir("CONTRIBUIDOR: " + std::to_string(contador));  
            }  
            actual = actual->next;
            contador++;
        }
    }else{
        cout<<"\033[33m"<<"No hay contribuidores registrados..."<<"\033[0m"<<endl;
    }
}

bool ListaUsuario::hay_contribuidores(){
    if(!this->head){    //No hay usuarios
        cout<<"\033[33m"<<"No hay contribuidores registrados..."<<"\033[0m"<<endl;
        return false;
    }else{
        Nodo* actual = head;
        while(actual != nullptr){
            if(actual->usuario->getPuesto() == "Contribuidor"){return true;}  
            actual = actual->next;
        }
        cout<<"\033[33m"<<"No hay contribuidores registrados..."<<"\033[0m"<<endl;
        return false;
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

void ListaUsuario::guardar_id_en_archivo(std::ofstream& archivo){
    Nodo* aux = this->head;
    archivo << "Ids asociados,";
    while(aux != nullptr) {
            archivo << aux->usuario->getId(); 
            if(aux->next){archivo<<",";} //Si hay un nodo siguiente
        aux = aux->next;
    }
    archivo<<endl;
}

void ListaUsuario::leer_id_de_archivo(std::ifstream& archivo, ListaUsuario* usuarios_registrados){
    //Me los va agregando

    std::string linea_temp;
    getline(archivo, linea_temp);   //Leo la línea
    std::stringstream ss(linea_temp);   //Creo un stream de la línea
    std::string id;               //Cada elemento separado por coma (csv)
    getline(ss, id, ',');  //Me deshago del encabezado "Ids asociados,"
    while(getline(ss, id, ',')){  //Leemos en intervalos de una coma
        this->agregar_contribuidor_por_id(usuarios_registrados, stoi(id));
    }
}