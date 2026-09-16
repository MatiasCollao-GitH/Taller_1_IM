//
// Created by Matías Collao on 16-09-2026.
//

#ifndef TALLER_1_IM_SERVICIO_H
#define TALLER_1_IM_SERVICIO_H

#include "Cola.h"


class Servicio {
private:
    std::string nombre;
    Cola<Paciente*>* listaPacientes;

public:
    Servicio(std::string &nombre);

    ~Servicio();

    std::string getNombre();
    Cola<Paciente*>* getListaPacientes();
};



#endif //TALLER_1_IM_SERVICIO_H
