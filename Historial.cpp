#include "Historial.h"

#include <iostream>

Historial::Historial() {
    this->pilaAtenciones = new Stack<Paciente*>();
}

void Historial::registrarAtencion(Paciente *paciente) {
    this->pilaAtenciones->push(paciente);
}

bool Historial::isEmpty() {
    return this->pilaAtenciones->isEmpty();
}

void Historial::mostrarHistorial() {
    if (this->pilaAtenciones->isEmpty()) {
        std::cout << "No hay atenciones registradas." << std::endl;
        return;
    }
    Nodo<Paciente*>* nodo = this->pilaAtenciones->getHead();

    while (nodo != nullptr) {
        Paciente* paciente = nodo->getValor();

        if (paciente != nullptr) {
            paciente->datos();
        }
        nodo = nodo->getNext();
    }
}

Historial::~Historial() {
    delete this->pilaAtenciones;
}