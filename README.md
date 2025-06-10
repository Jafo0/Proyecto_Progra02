# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO


Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.


Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones.
    -El código será ejecutado en Windows. Esto ya que usamos comandos como system("cls") para poder limpiar la pantalla.
    -No es posible eliminar usuarios.
    -Varios managers pueden tener el mismo contribuidor



Preguntas profe:
    -se puede implementar static_cast<Manager*>(aux)?
    -Podemos utilizar <string>.empty()?





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


Comando de Compilación con el CMakeLists.txt:
    1. cmake .. -G "MinGW Makefiles"        //Crea un Archivo MakeFile
    2. mingw32-make                         //Compila el código y crea un ejecutable

Cambios Ale:
    -Para poder leer de un archivo de texto, se ocupa saber qué id tiene cada usuario. Para esto modifiqué los constructores de usuario, manager y contribuidor.
    -Que la función de guardar en un archivo esté únicamente en interaccion. Estoy porque no solo debemos guardar usuarios, sino también el calendario y etc.
    -En el ArchivoUsuarios.txt primero guardamos todos los Contribuidores y luego todos los managers. Esto para que ya cuando estemos leyendo los id de los managers, ya existan los contribuidores
    -Ya se lee de un archivo de texto (hace falta agregar la lista de contribuidores a los managers y los calendarios siempre inician vacíos)
    -Ahora hay dos menus, uno para contribuidor y otro para manager
    -Ya podemos eliminar reservaciones indicando el número
    -Eliminé clase listaEmpleados. Esto es porque no sirve tener solamente guardado el id de un usuario. No podríamos llamar a las funciones de los usuarios.
    -Me hace falta:
        -Enviar invitaciones
        -Reestricciones al calendario para choque de fechas
        -Contraseña codificada
