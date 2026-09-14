//
// Created by ignac on 13/09/2026.
//

#pragma once
#include <string>
using namespace std;

class Paciente {

private:
    string id;
    string nombre;
    int edad;
    string servicio;

    public:

    Paciente(string id, string nombre, int edad, string servicio);

    string getId();
    string getNombre();
    int getEdad();
    string getServicio();

    ~Paciente();
};



