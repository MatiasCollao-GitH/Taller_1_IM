//
// Created by Matías Collao on 14-09-2026.
//

#ifndef TALLER_1_IM_SISTEMA_H
#define TALLER_1_IM_SISTEMA_H
#include <string>

#include "Cola.h"
#include "Paciente.h"

class Sistema {
private:
    Cola<Paciente*>* colaEspera;
public:
    void iniciar();

    void imprimirColaSINEliminar(Nodo<Paciente *> *cola);

    void leer();
    void menu();

    ~Sistema();

    //Terminar
    bool esServicioValido(std::string(servicio));
    //------------------------------

    //tambien terminar
    bool existePaciente(std::string(id));
};



#endif //TALLER_1_IM_SISTEMA_H
