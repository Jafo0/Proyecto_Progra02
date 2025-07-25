#include "Comprobacion.h"

bool cadena_vacia(std::string entrada){
    if(entrada.empty()){
        cout << "\033[31m"<<"\nIngrese una respuesta NO vacia\n"<<"\033[0m" << endl;
        return true;
    }
    return false;
}

bool cadena_con_punto(std::string entrada){
    if((entrada.find('.') != std::string::npos) || (entrada.find(',') != std::string::npos)){
        cout << "\033[31m"<<"\nIngrese un valor sin punto decimal\n"<<"\033[0m" << endl;
        return true;
    }
    return false;
}

bool cadena_con_espacio(std::string entrada){
    if(entrada.find(' ') != std::string::npos){
        cout << "\033[31m"<<"\nIngrese una cadena sin espacios\n"<<"\033[0m" << endl;
        return true;
    }
    return false;
}

bool de_string_a_int(std::string entrada){
    try {   //Intento convertir la entrada a int
        int respuesta_i = stoi(entrada);
        return true;
    }catch (std::invalid_argument& e) {  //Error
        cout << "\033[31m"<<"\nIngrese un numero valido\n"<<"\033[0m" << endl;
    }   
    return false;
}
bool numero_fuera_de_rango(int lim_inferior, int lim_superior, int entrada){
    if(entrada<lim_inferior || lim_superior<entrada){
        cout<<"\033[31m"<<"\nIngrese un numero dentro del rango ["<<lim_inferior<<","<<lim_superior<<"]\n"<<"\033[0m"<<endl;
        return true;
    }
    return false;
}

bool texto_no_vacio_sin_espacios(std::string entrada){
    if(!cadena_vacia(entrada)){ //Que NO esté vacía
        if(!cadena_con_espacio(entrada)){   //Que NO tenga espacios
            return true;
        }
    }
    return false;
}

bool numero_entero_dentro_de_rango(int lim_inferior, int lim_superior, std::string entrada){
    if(!cadena_vacia(entrada)){ //Que NO esté vacía
        if(!cadena_con_espacio(entrada)){ //Que NO tenga espacios
            if(!cadena_con_punto(entrada)){ //Que NO tenga el punto
                if(de_string_a_int(entrada)){   //Que pueda hacerse el stoi
                    int entrada_i = stoi(entrada);
                    if((lim_inferior == lim_superior) && (entrada_i == lim_inferior)){
                        return true;
                    }else if(numero_fuera_de_rango(lim_inferior, lim_superior ,entrada_i)){  //Que NO esté fuera del rango
                        return false;
                    }else{
                       return true; 
                    }
                }
            }
        }
    }
    return false;
}

bool numero_entero_sin_rango(std::string entrada){
    if(!cadena_vacia(entrada)){ //Que NO esté vacía
        if(!cadena_con_espacio(entrada)){ //Que NO tenga espacios
            if(!cadena_con_punto(entrada)){ //Que NO tenga el punto
                if(de_string_a_int(entrada)){   //Que pueda hacerse el stoi
                    int entrada_i = stoi(entrada);
                    return true;
                }
            }
        }
    }
    return false;
}

bool annoValido(int anno){return 2025 < anno;}

bool mesValido(int mes) {return 1 <= mes && mes <= 12;}

bool diaValido(int dia) {return 1 <= dia && dia <= 31;}

bool horaValida(int hora) {return 0 <= hora && hora <= 23;}

bool minutoValido(int minuto) {return 0 <= minuto && minuto <= 59;}