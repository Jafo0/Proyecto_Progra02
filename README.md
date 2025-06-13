# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO


Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.


Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones.
    -El código será ejecutado en Windows. Esto ya que usamos comandos como system("cls") para poder limpiar la pantalla.
    -No es posible eliminar usuarios registrados.
    -Varios managers pueden tener el mismo contribuidor
    -Al modificar una reservación, se pedirán todos los datos desde cero.



Preguntas profe:
    -se puede implementar static_cast<Manager*>(aux)?
    -Podemos utilizar <string>.empty()?




Comando Compilacion main.cpp:
    g++ .\Encabezados.h .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Usuario.cpp .\Manager.cpp .\Contribuidor.cpp .\ListaUsuario.cpp .\Interaccion.cpp .\Comprobacion.cpp .\main.cpp
    

Comando Compilacion mainCalendario.cpp:
    g++ .\Encabezados.h .\Reservacion.cpp .\Reunion.cpp .\CitaPersonal.cpp .\ActividadSocial.cpp .\EventoDiario.cpp .\Calendario.cpp .\Comprobacion.cpp .\mainCalendario.cpp


Comando de Compilación con el CMakeLists.txt:
    1. cmake .. -G "MinGW Makefiles"        //Crea un Archivo MakeFile
    2. mingw32-make                         //Compila el código y crea un ejecutable

