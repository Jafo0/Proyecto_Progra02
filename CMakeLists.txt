cmake_minimum_required(VERSION 3.25)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto2 
               Reservacion.cpp Reunion.cpp CitaPersonal.cpp ActividadSocial.cpp EventoDiario.cpp Calendario.cpp
               Usuario.cpp Manager.cpp Contribuidor.cpp ListaUsuario.cpp
               Interaccion.cpp main.cpp)
