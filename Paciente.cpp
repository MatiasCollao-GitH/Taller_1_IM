//
// Created by Matías Collao on 14-09-2026.
//

#include "Paciente.h"
#include <iostream>
Paciente::Paciente(std::string id, std::string nombre, int edad, std::string servicio)
: Persona(nombre,edad), id(id), servicio(servicio) {
}

std::string Paciente::getId() {
    return this->id;
}

std::string Paciente::getServicio() {
    return this->servicio;
}

void Paciente::setServicio(std::string servicio) {
    this->servicio = servicio;
}

Paciente::~Paciente() {
}

void Paciente::datos() {
    std::cout << "ID: " << this->id
              << " Nombre: " << this->nombre
              << " Edad: " << this->edad
              << " Servicio: " << this->servicio << std::endl;
}

