cmake_minimum_required(VERSION 4.2)
project(Taller_1_IM)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_1_IM main.cpp
        "dominio/Paciente.cpp"
        "dominio/Paciente.h"
        "estructuras de datos/Node.h"
        "estructuras de datos/List.h"
        "estructuras de datos/Queue.h"
        "estructuras de datos/Stack.h")
