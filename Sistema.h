//
// Created by Matías Collao on 14-09-2026.
//

#ifndef TALLER_1_IM_SISTEMA_H
#define TALLER_1_IM_SISTEMA_H
#include <string>

#include "Cola.h"
#include "Lista.h"
#include "Paciente.h"
#include "Servicio.h"

class Sistema {
private:
    Cola<Paciente*>* colaEspera;
    Lista<Servicio*>* listaServicios;
public:
    void iniciar();

    void imprimirColaSINEliminar(Nodo<Paciente *> *cola);

    void leer();
    void menu();

    ~Sistema();

    void inicializarServicios();

    //Terminar
    bool esServicioValido(std::string(servicio));
    //------------------------------

    //tambien terminar
    bool existePaciente(std::string(id));



};



#endif //TALLER_1_IM_SISTEMA_H
