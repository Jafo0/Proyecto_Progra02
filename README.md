# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO


Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.
    -Se permite el uso de  dinamic_cast y static_cast y se utiliza para manageractivo, usuario activo presentes en Interaccion, ademas de otros usos a lo largo del programa.

Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones, esto quiere decir que no podra ingresar reservaciones si estas se encuentran en el pasado.
    -Los usuarios son cargados y manipulados desde el archivo.
    -El main hace un llamado a el metodo de ejecutar interaccion, esta es la clase que se encarga de desplegar los menus y realizar comprobaciones haciendo llamados a metodos de clases como contenedores y clases encargadas del manejo de errores, asi como clases padres abstractas y sus respectivas hijas.
    -Las reservaciones utilizan un id de tipo tm que se importa desde la libreria ctime, esta libreria permite el correcto manejo de fechas como fecha de inicio de una reservacion y fecha de finalizacion.
    -Los usuarios pueden ser invitados a una Reunion y/o actividad Social por medio de su id, siempre que haya mas de un usuario creado a la vez, para salir de la seleccion de losusuarios que desea que participen solo debe ingresar -1.
    -El código será ejecutado en Windows. Esto ya que usamos comandos como system("cls") para poder limpiar la pantalla.
    -Varios managers pueden tener el mismo contribuidor como empleado, se puede modificar y ver la lista de contribuidores/empleados asignados a un manager, estas son opciones extras en el menu de acciones que tiene el manager.
    -Existen metodos de impresion Ocultos y normales que dependen de si la reservacion la he creado yo o si está en mi calendario, de esta manera se muestra diferente segun el calendario de quien quiera ver.
    -Al modificar una reservación, se pedirán todos los datos desde cero.
    -Lista de usuarios es una lista que contiene a los usuarios registrados, es una lista simplemente enlazada.
    -Calendario es una lista simplemente enlazada que guarda las reservaciones creadas de cada usuario.
    -Comprobacion es una clase que contiene comprobaciones de strings y tipos de datos para evitar caidas del programa, sus metodos son usados como comprobacion de errores.
    -Se encriptan las contraseñas haciendo manipulacion por medio de char* haciendo un mapeo para que la contraseña no se vea como la ingresada por el usuario.
    -Se utiliza CMake relacionado a mingw.



Comando Compilacion main.cpp:
    g++ .\Encabezados.h .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Usuario.cpp .\Manager.cpp .\Contribuidor.cpp .\ListaUsuario.cpp .\Interaccion.cpp .\Comprobacion.cpp .\main.cpp
    

Comando Compilacion mainCalendario.cpp:
    g++ .\Encabezados.h .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Comprobacion.cpp .\mainCalendario.cpp


Comando de Compilación con el CMakeLists.txt:
    1. cmake .. -G "MinGW Makefiles"        //Crea un Archivo MakeFile
    2. mingw32-make                         //Compila el código y crea un ejecutable
