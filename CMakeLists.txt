cmake_minimum_required(VERSION 4.2)
project(Taller_1_IM)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_1_IM main.cpp
        "estructuras de datos/List.h"
        "estructuras de datos/Stack.h"
        Sistema.cpp
        Sistema.h
        Nodo.h
        Cola.h
        Persona.cpp
        Persona.h
        Paciente.cpp
        Paciente.h
        Servicio.cpp
        Servicio.h
)
