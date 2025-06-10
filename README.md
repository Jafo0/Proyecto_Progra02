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
        -Comprobar que el modificar evento sirva.
        -Que las reservaciones tengan un id de host y un id de reservacion. 
        -Modificar reunión: Hacer menu de 1: modificar fecha, 2: modificar ids.

        LUEGO:
        -Agregarle funcionalidad a la opción de ver calendario de otra persona por id.
        -Hacer dos prints del calendario, uno total y otro reducido. Al imprimir mi calendario, hacerlo total, pero al imprimir el calendario de otra persona si soy contribuidor, imprimir reducido. Si soy manager y tengo subordinados, imprimir total, sino, imprimir reducidos.
        -Hacer la estructura de las invitaciones:
            Cada usuario tiene otro atributo que es Calendario* invitaciones_pendientes.
            Cada usuario tendrá una función nueva que sea recibir invitacion. Esto recibe una reservación y la agrega a this->invitaciones_pendientes.
            Agregarle funcionalidad al botón de revisar invitaciones para recorrerlo e ir indicando si aceptar, rechazar u omitir la invitación. Si la acepta, se pasa al calendario propio, si la rechaza, se elimina, si la omite, se mantiene.
            Al crear un evento, indicar los ids que quiero invitar.
            Por cada id, hacer un usuario_del_id->recibir_reservacion(reservacion_creada)
        -Hacer la estructura de eliminar reservacion. Si la elimino y soy el host, recorre todos los usuarios_Registrados y elimina la reservacion por id. Si no soy el host, solo me la elimina a mi.
        -Hacer la estructura de modificar reservacion. Es eliminarla, y volver a crearla.
        -Cifrar las contraseñas.
            Ejemplo: afaka->!irddd
            Al iniciar sesion: Ingresa: afaka->!irddd, y luego compara !irddd con !irddd
    Jaffet:
        -No poder crear dos usuarios con los mismos datos. Para datos diferentes, tampoco pueden repetir nombre y contraseña. Esto lo hacemos con un verificador2 dentro de lista Usuario que es llamado en Interaccion::crear_Usuario
        






Comando Compilacion main.cpp:
    g++ .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Usuario.cpp .\Manager.cpp .\ContribuidorI.cpp .\ListaUsuario.cpp .\ListaEmpleados.cpp .\Interaccion.cpp .\Comprobacion.cpp .\main.cpp

Comando Compilacion mainCalendario.cpp:
    g++ .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Comprobacion.cpp .\mainCalendario.cpp


Comando de Compilación con el CMakeLists.txt:
    1. cmake .. -G "MinGW Makefiles"        //Crea un Archivo MakeFile
    2. mingw32-make                         //Compila el código y crea un ejecutable

Cambios Ale:
    -Ya se agregan y eliminan por id los subordinados de los managers. Un manager no puede ser jefe de otro manager.
    -Ya se escriben y cargan los subordinados del archivo de texto
    -Ya las fechas deben ser válidas (no pueden chocar con otro evento del calendario).

    -Me hace falta:
        -Enviar invitaciones
        -Reestricciones al calendario para choque de fechas
        -Contraseña codificada



Para Reunión y Actividad social:
    -Hay un orgnizador/varios organizadores (ListaUsuarios)
