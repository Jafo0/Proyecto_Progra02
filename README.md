# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO


Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.


Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones.
    -El código será ejecutado en Windows. Esto ya que usamos comandos como system("cls") para poder limpiar la pantalla.
    -No es posible eliminar usuarios.
    -Varios managers pueden tener el mismo contribuidor


Cambios Ale:
    -Hice funciones genéricas de comprobaciones. Por ejemplo cadena vacioa, cadena con punto, de string a int, numero fuera de rango.
    -Cambios en calendario: No puedo crear una fecha en el pasado, que termine en el pasado o que inicie y termine en el mismo momento.
    -Ahora las reservaciones se imprimen con una posición, y se agregan en orden cronológico.
    -Botones que funcionan:
        1. Ver Calendario
        3. Crear reservación
        4. Cancelar Reservaciones
        5. Modificar
        7. Cerrar sesion

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

Próximo Avance:
    -Ordenar las opciones de calendario (cerrar sesión) vaya de último
    


    Ale:
        -Hacer la estructura de las invitaciones
        -Al cerrar sesión, usuario activo y manager activo en nullptr
        -Cifrar las contraseñas.
            Ejemplo: afaka->!irddd
            Al iniciar sesion: Ingresa: afaka->!irddd, y luego compara !irddd con !irddd
    Jaffet:
        -No poder crear dos usuarios con los mismos datos. Para datos diferentes, tampoco pueden repetir nombre y contraseña. Esto lo hacemos con un verificador2 dentro de lista Usuario que es llamado en Interaccion::crear_Usuario
        -Que al correr el programa no se borre lo que hay en la plantilla. Esto para agregar en la entrega ya ciertos empleados. Además, que la lista de usuarios siempre se cargue del .txt existente. Modificar el consrtuctor de listaUsuario para que reciba el nombre del archivo (esto no se lo pregunta la usuario). Le pregunta al usuario si lo quiere hacer. Otro constructor de Interaccion y lista usuario. La pregunta se hace en el main una única vez.






Comando Compilacion main.cpp:
    g++ .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Usuario.cpp .\Manager.cpp .\ContribuidorI.cpp .\ListaUsuario.cpp .\ListaEmpleados.cpp .\Interaccion.cpp .\Comprobacion.cpp .\main.cpp

Comando Compilacion mainCalendario.cpp:
    g++ .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Comprobacion.cpp .\mainCalendario.cpp



Comprobaciones de código a prueba de errores:
    Interaccion::menu_entrada()
        - Valor con decimales: Listo
        - String de entrada: Listo
        - Número fuera del rango: listo
        - Cadena vacía: Listo
    1) Interaccion::crear_Usuario()
        - Nombre:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
        - Cedula:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
            -> Valor con decimales: Listo
            -> String de entrada: Listo
        - Nombre de Usuario:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
        - Constraseña:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
        - Rol:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
            -> Valor con decimales: Listo
            -> String de entrada: Listo
            -> Valor dentro de rango: Listo
    2) Iniciar Sesion:
         - Nombre de Usuario:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo
        - Constraseña:
            -> Cadena vacía: Listo
            -> Valores sin espacios: Listo

            
        


