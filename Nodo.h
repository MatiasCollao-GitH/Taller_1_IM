//
// Created by Matías Collao on 14-09-2026.
//

#ifndef TALLER_1_IM_NODO_H
#define TALLER_1_IM_NODO_H

#pragma once
template <class T>

class Nodo {
private:
    T valor;
    Nodo<T>* next;
public:
    Nodo(T valor) {
        this->valor = valor;
        this->next = nullptr;
    }
    T getValor();
    T getNext();

    void setValor(T valor);
    void setNext(Nodo<T>* next);

    ~Nodo();
};



#endif //TALLER_1_IM_NODO_H
