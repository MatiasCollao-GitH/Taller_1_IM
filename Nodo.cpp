//
// Created by Matías Collao on 14-09-2026.
//

#include "Nodo.h"

template<class T>
T Nodo<T>::getValor() {
    return this->valor;
}

template<class T>
T Nodo<T>::getNext() {
    return this->next;
}

template<class T>
void Nodo<T>::setNext(Nodo<T> *next) {
    this->next = next;
}

template<class T>
void Nodo<T>::setValor(T valor) {
    this->valor = valor;
}

template<class T>
Nodo<T>::~Nodo() {
}
