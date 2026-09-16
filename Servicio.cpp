//
// Created by Matías Collao on 16-09-2026.
//

#include "Servicio.h"

Servicio::Servicio(std::string &nombre) {
    this->nombre = nombre;
    this->listaPacientes = new Cola<Paciente*>();
}

Servicio::~Servicio() {
    delete this->listaPacientes;
}

std::string Servicio::getNombre() {
    return this->nombre;
}

Cola<Paciente *> *Servicio::getListaPacientes() {
    return this->listaPacientes;
}
