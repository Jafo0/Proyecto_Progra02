void Usuario::revisarInvitaciones(){
	Reservacion* temp = this->invitaciones->getPrimeraReservacion();
	while(temp){
		temp->getReservacion()->imprimir();
		string decision;

        do{
            cout<<"1. Aceptar"<<endl;
            cout<<"2. Omitir"<<endl;
            cout<<"Ingrese la accion por realizar: ";
            getline(cin, decision);
        }while(!numero_entero_dentro_de_rango(1,2,decision));

        switch (decision){
            case 1:
                if(!this->calendario->choqueConCalendario(temp->getReservacion()->getFechaInicio(), temp->getReservacion()->getFechaFin())){
                    this->calendario->ordenar(temp);
                }
                break;
            case 2:
                break;
        }
	}
}
void Usuario::agregarInvitacion(Reservacion* reservacion){
    this->calendarioInvitaciones->ordenar(reservacion);
}

void Reunion::invitar(){
    Usuario* invitado = this->listaInvitados->getPrimero();
    while(invitado){
        invitado->agregarInvitacion(this);
        invitado = invitado->getNext;
    }
}