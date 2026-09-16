//
// Created by Matías Collao on 14-09-2026.
//

#include "Sistema.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Nodo.h"
#include "Paciente.h"
#include "Servicio.h"
using namespace std;

void Sistema::iniciar() {
    colaEspera = new Cola<Paciente*>();
    inicializarServicios();
    leer();
    menu();
}

void Sistema::inicializarServicios() {
    this->listaServicios = new Lista<Servicio*>();

    const std::string serviciosBase[8] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    for (int i = 0; i < 8; i++) {
        this->listaServicios->agregarFinal(new Servicio(serviciosBase[i]));
    }
}




bool Sistema::esServicioValido(std::string servicio) {
    Nodo<Servicio*>* actual = this->listaServicios->getCabeza();
    while (actual != nullptr) {
        if (actual->getValor()->getNombre() == servicio) {
            return true;
        }
        actual = actual->getNext();
    }
    return false;
}

bool Sistema::existePaciente(std::string id) {
    Nodo<Paciente*>* actual = this->colaEspera->getInicio();
    while (actual != nullptr) {
        Paciente* p = actual->getValor();
        if (p != nullptr && p->getId() == id) {
            return true;
        }
        actual = actual->getNext();
    }

    return false;
}

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
                if (!esServicioValido(servicio)) {
                    cerr << "Error: Servicio invalido (" << servicio << ")" << endl;
                    continue;
                }

                if (existePaciente(id)) {
                    cerr << "Error: Paciente con ID duplicado (" << id << ")" << endl;
                    continue;
                }

                Paciente* nuevo = new Paciente(id,nombre,edad,servicio);

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
    delete this->colaEspera;

    if (this->listaServicios != nullptr) {
        Nodo<Servicio*>* actual = this->listaServicios->getCabeza();
        while (actual != nullptr) {
            delete actual->getValor();
            actual = actual->getNext();
        }
        delete this->listaServicios;
    }
}







