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


Preguntas profe:
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
    