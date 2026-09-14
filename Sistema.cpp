//
// Created by Matías Collao on 14-09-2026.
//

#include "Sistema.h"

#include <fstream>
#include <iostream>
using namespace std;

void Sistema::iniciar() {
    //leer();
    menu();
}

/*
void Sistema::leer() {
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo pacientes.txt" << endl;
        return;
    }
}
*/

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








