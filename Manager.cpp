#include"Manager.h"
#include "ListaUsuario.h"
#include "Encabezados.h"

Manager::Manager(std::string nom, int ced, std::string nomUs, std::string pass, int id)
    :Usuario(nom,ced,nomUs,"Manager",pass, id){
        this->listaSubordinados = new ListaUsuario(); //atributo de lista empleado de manager
}

Manager::~Manager(){}   //No elimino los subordinados porque esto se elimina luego en los usuarios totales registrados

void Manager::setListaSubordinados(ListaUsuario* _listaSubordinados){this->listaSubordinados = _listaSubordinados;}

void Manager::imprimirSubordinados(){
    this->listaSubordinados->imprimirIDS();
}

void Manager::imprimir(std::string encabezado){
    cout<<"-------------------------------------------";
    cout<<encabezado;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Datos Persona: "<<"Puesto: Manager"<<"\t|"<<"Nombre: "<<nombre<<"\t|"<<"Cedula: "<<cedula<<endl;
    cout<<"Datos Usuario: "<<"Nombre usuario: "<<nomUsuario<<"\t|"<<"Contrasenna: "<<contrasena <<"\t|"<<"Id: "<<id<<endl;
}

void Manager::agregarSubordinado(Usuario* subordinado){ 
    if(this->listaSubordinados->vacia()){
        if(subordinado->getPuesto() == "Contribuidor"){  //Es un contribuidor
            this->listaSubordinados->agregarUsuario(subordinado);
        }
    }else if(!this->listaSubordinados->comprobarID(subordinado->getID()) && subordinado->getPuesto() == "Contribuidor"){  //No está en la lista y es un contribuidor
        this->listaSubordinados->agregarUsuario(subordinado);
        cout<<"\033[32m"<<"Subalterno agregado exitosamente"<<"\033[0m"<<endl;
    }else{cout<<"\033[33m"<<"No puede ser agregado ya que se encuentra o no es un contribuidor"<<"\033[0m"<<endl;}
}

void Manager::eliminarSubordinado(int id){ //Aquí ya hay contribuidores
    if(!this->listaSubordinados->vacia() && this->listaSubordinados->comprobarID(id)){  //No está vacía y el id sí está
        this->listaSubordinados->eliminarContribuidorPorID(id);
    }
}

int Manager::menuAccionesSubordinados(){
    cout<<"--------------Opciones para los subalternos--------------"<<endl;
    cout<<"1. Agregar"<<endl;
    cout<<"2. Eliminar"<<endl;
    cout<<"3. Regresar"<<endl;

    std::string respuesta;
    do{
        cout<<"Indique que accion desea realizar: ";
        getline(cin,respuesta);
    }while(!numero_entero_dentro_de_rango(1,3, respuesta));

    return stoi(respuesta);
}

void Manager::modificarSubordinados(ListaUsuario* usuariosRegistrados){
    switch (this->menuAccionesSubordinados()){
        case 1:{
            string id;
            cout<<"Ingrese el id por agregar: ";
            getline(cin, id);
            if(numero_entero_sin_rango(id)){    //número válido
                if(usuariosRegistrados->comprobarID(stoi(id)) && usuariosRegistrados->IdEsContribuidor(stoi(id))){ //id válido y es contribuidor
                    this->listaSubordinados->agregarUsuario(usuariosRegistrados->UsuarioPorID(stoi(id)));
                }else{
                    cout<<"\033[31m"<<"No se pudo agregar el subordinado..."<<"\033[0m"<<endl;
                }
            }
            break;
        }case 2:
            if(!this->listaSubordinados->vacia()){   //Si tengo agregado algún contribuidor
                string id;
                cout<<"Ingrese el id por eliminar: ";
                getline(cin, id);
                if(numero_entero_sin_rango(id)){    //número válido
                    if(this->listaSubordinados->comprobarID(stoi(id))) //id válido 
                    this->listaSubordinados->eliminarContribuidorPorID(stoi(id));
                }
                break;
            }
            break;
        case 3:
            cout<<"\033[33m"<<"Estoy regresando..."<<"\033[0m"<<endl;
            break;
        default:
            break;
    }
}

void Manager::escribirEnArchivo(std::ofstream& archivo){
    archivo<<"Manager"<<endl;
    archivo<<nombre + "," + std::to_string(cedula) + "," + nomUsuario + "," + contrasena + "," + std::to_string(id)<<endl;
    archivo<<"Ids asociados,";
    this->listaSubordinados->escribirIdsEnArchivo(archivo);
    archivo<<"Calendario: "<<endl;
    this->calendario->escribirEnArchivo(archivo);
}

void Manager::leerCalendarioDeArchivo(std::ifstream& archivo){
    this->calendario->leerDeArchivo(archivo);
} 