//
// Created by Matías Collao on 14-09-2026.
//

#ifndef TALLER_1_IM_PACIENTE_H
#define TALLER_1_IM_PACIENTE_H
#include "Persona.h"
#pragma once

class Paciente : public Persona {
private:
    std::string id;
    std::string servicio;

public:
    Paciente(std::string id, std::string nombre, int edad, std::string servicio);
    ~Paciente() override;
    void setServicio(std::string servicio);
    std::string getId();
    std::string getServicio();
    void datos() override;


};



#endif //TALLER_1_IM_PACIENTE_H
