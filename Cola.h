//
// Created by Matías Collao on 14-09-2026.
//

#ifndef TALLER_1_IM_COLA_H
#define TALLER_1_IM_COLA_H
#include "Nodo.h"


template <class T>
class Cola {
private:
    Nodo<T>* inicio;
    Nodo<T>* final;
    int tamano;
    bool vacio;

public:
    Cola();
    int size();
    void push(T valor);
    T front();
    T back();
    void pop();
    bool isEmpty();
    ~Cola();

};



#endif //TALLER_1_IM_COLA_H
