cmake_minimum_required(VERSION 3.10)
project(Pruebas)

set(CMAKE_CXX_STANDARD 17)

add_executable(ejecutable Encabezados.h
               Reservacion.cpp ActividadSocial.cpp CitaPersonal.cpp EventoDiario.cpp Reunion.cpp Calendario.cpp
               Usuario.cpp Manager.cpp Contribuidor.cpp ListaUsuario.cpp 
               Interaccion.cpp Comprobacion.cpp main.cpp) #<nombre del ejecutable>, .cpp, .h, ...

#Comandos de compilación y ejecución:
    #Primero, ocupo estar en powershell
    #2: 
        # cmake .. -G "MinGW Makefiles"
        # Crea un Makefile
    #3: 
        # mingw32-make
        # Lee el make file y lo compila usando g++.
        # Crea el ejecutable del nombre indicado.