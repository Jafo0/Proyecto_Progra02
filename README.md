# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO


Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.


Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones.
    -Se restringen las horas a horas laborales (8-17, o sea 8am-5pm)


PENDIENTE:
    -En el menu reservación de calendario, hacerlo a prueba de errores. Por ejemplo, que ingrese texto
    -Que las horas no sean laborales, sino, todo el día.
    -Al hacer una reservación, indicar hasta el minuto
    -Explicar el Reservacion::verFechas()
    -Try catch para la recepción de datos en calendario (menu, fechas, etc)
    -Hacer que los eventos no choquen
    -Hacer que los eventos se vayan agregando en orden
    -Condición de creación de eventos: la fecha final debe ser posterior a la fecha inicial.



Cambios Ale:
    -Simplificación de ListaUsuario (Nodo en público)
    -El guardar en archivo lo llama la función de agregar usuario de ListaUsuario.
    -Agregué un menu_entrada a Interaccion para simplificar y le cambié el nombre a los otros porque los sentía confusos
    -La cedula la pasé a ser un entero, porque sino deberíamos hacer una comprobación de que no se incluyen letras.
    -Intentar usar nombres significativos y documentar el código
    -Agregar opción de imprimir usuarios en el menu entrada
    -Pendiente la verificación de cédula correcta
    -No puedo iniciar sesión si la lista está vacía
    -Cambié menu_inicio_sesion por inicio_sesion y lo saqué del while porque si no hubieran usuario o a uno se le olvida, nunca va a poder salir.
    -Solo llamo a accion usuario si inicié sesión correctamente
    -Los menus regresan un int

Cambios Jafet:
     *Añado atributo a usuario de id y el contadorId como un atributo estatico para que se sume y da un id unico a cada
     vez que se cree un usuario ademas de metodos getId() const, getPuesto() const.
     *Creacion de Lista Empleado como una lista enlazada simple que tiene los id de los usuarios en sus nodos, esta lista es un parametro publico de Manager y se modifica el constructor para que se cree una lista empleado para cada manager.
     *Tanto el Manager como el contribuidor ahora imprimen su id
     *Nuevo metodo en ListaUsuario para encontrar id en la lista, busca comprobar que el id este en la lista y que ese id le pertenezca a un Contribuidor, si si entonces retorna el usuario
     *Entre los cambio en Interaccion: agregar un Atributo de puntero a Manager llamado manActivo, se comporta parecido a usuario activo, permite que este manActivo use metodos especificos de manager relacionados a su atributo de listaEmpleados(lo importante aqui es se hace un casteo este se hace en iniciar sesion), ademas se crea un metodo especifico para que el manager pueda modificar su lista de empleados llamado modificar_empleados(); ademas en menu_accion_usuario() se agregan dos opciones especificas para los managers que son el modificar su lista de Empleados y el imprimir su lista, ambos son a prueba de errores en el sentido que no puede agrgar a la lista un id que yaestaba y por ende al imprimir la lista no se imprimen duplicados. 
     **queda pendiente que un contribuidor no tenga dos jefes

Preguntas profe:
    -se puede implementar static_cast<Manager*>(aux)?
    -Podemos utilizar <string>.empty()?



Pendiente:
    -Funciones del menu usuario en interaccion (operaciones con su calendario)
    -Hacerle un getCalendario al interaccion.
    -Ver que las reservaciones no se choquen entre sí (Si creo una)
    -Restricción del calendario, no puedo iniciar un evento en el pasado, ni iniciarlo en el presente/futuro y terminarlo en el pasado.

    -Ponerle un id a los usuarios y que se asigne de manera automática según la cantidad de usuarios (nodos) creados
    -Dos managers no pueden tener el mismo empleado contribuidor. Esto lo agregamos como suposicion en el readme y como comprobacion al modificar empleados. en manager.
    -El manager tiene un atributo adicional que es de tipo ListaEmpleados (similar a ListaUsuarios), inicializa vacío y puede operar sobre este.

    Dejar de último:
        -El manager tiene una opción adicional en el menu que es modificar empleados.
        -Otra opcion adicional del menu es ver la lista de empleados 