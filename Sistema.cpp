//
// Created by Matías Collao on 14-09-2026.
//

#include "Sistema.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Nodo.h"
#include "Paciente.h"
using namespace std;

void Sistema::iniciar() {
    colaEspera = new Cola<Paciente*>();
    leer();
    menu();
}

//------------------------------------------------------------------------


//Crear lista enlazada de los 8 posibles servicios
bool Sistema::esServicioValido(std::string(servicio)) {
    return false;
}

//Esto cambiar al hacer las listas enlazadas (revisar porque no se me ocurre aún cómo hacer que no se repita)
bool Sistema::existePaciente(std::string id) {
    return false;
}

//----------------------------------------------------------------------
void Sistema::leer() {
    ifstream archivo("../Pacientes.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo pacientes.txt" << endl;
        return;
    }

    string linea;
    while (getline(archivo,linea)) {
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);
        string id, nombre, stringEdad, servicio;

        if (getline(ss, id, ';')&&
            getline(ss, nombre, ';') &&
            getline(ss, stringEdad, ';') &&
            getline(ss, servicio)) {

            try {
                int edad = stoi(stringEdad);
                //Hacer lista con punteros para validar que el servicio sea uno de los 8
                if (esServicioValido(servicio)) {
                    cerr << "Error: Servicio invalido" << endl;
                    continue;
                }

                //Validar que el paciente no esté duplicado por Id
                if (existePaciente(id)) {
                    cerr << "Error: Servicio invalido" << endl;
                    continue;
                }

                //Crear al paciente
                Paciente* nuevo = new Paciente(id,nombre,edad,servicio);

                //Meterlo a cola:
                colaEspera->push(nuevo);

            } catch (invalid_argument& e) {
                cerr << "Error: Edad Formato" << endl;
            }
        } else {
            cerr << "Error: Formato e linea invalido" << endl;
        }
    }
    //colaEspera->imprimir();//La wea más Complicada y Simple de hacer solo para comprobar que el guardado funciona
    archivo.close();
}

void Sistema::menu() {

    int opcion = 0;

    while (true) {
        cout << "=== HOSPITAL MARMAJA ===\n"
                "1. Atender pacientes\n"
                "2. Ver departamento\n"
                "3. Revisar historial de atencion\n"
                "4. Salir\n"
                "\nSeleccionar opcion: " << endl;
        cin >> opcion;
    if (cin.fail()) {
        cout << "Error: Opcion desconocida, intente nuevamente: " << endl;
        opcion = 0;
        cin.clear();
        cin.ignore(10000, '\n');
        }else if (opcion == 1) {
            //atenderPacientes();
        } else if (opcion == 2) {
            //verDepartamento();
        } else if (opcion == 3) {
            //revisarHistorial();
        } else if (opcion == 4) {
            cout << "Hasta luego :D." << endl;
            break;
        }
    }

}
Sistema::~Sistema() {
}







