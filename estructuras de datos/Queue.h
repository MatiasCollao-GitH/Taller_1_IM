#pragma once

#include "Node.h"
template <class T>
class Queue {

    private:
    Node<T>* start;
    Node<T>* end;
    int sizeQueue;

    public:

    //Constructor
    Queue() {
        this->start = nullptr;
        this->end = nullptr;
        this->sizeQueue = 0;
    }

    //Insertar al final de la cola
    void push(T value) {
        Node<T>* nuevo = new Node<T>(value);

        //Si la cola está vacía
        if (this->start == nullptr) {
            this->start = nuevo;
            this->end = nuevo;
            this->sizeQueue++;
            return;
        }
        //El último nodo apunta al nuevo
        this->end->setNext(nuevo);
        //El nuevo pasa a ser el último
        this->end = nuevo;
        this->sizeQueue++;
    }
    //Eliminar el primer elemento
    void pop() {
        if (this->start == nullptr) {
            throw 0;
        }

        Node<T>* eliminar = this->start;

        this->start = this->start->getNext();
        delete eliminar;

        this->sizeQueue--;

        if (this->start == nullptr) {
            this->end = nullptr;
        }
    }

    //Obtener el primer elemento
    T front() {
        if (this->start == nullptr) {
            throw 0;
        }
        return this->start->getValue();
    }

    //Obtener el último elemento
    T back() {
        if (this->end == nullptr) {
            throw 0;
        }
        return this->end->getValue();
    }

    //Comprobar si está vacía
    bool isEmpty() {
        return this->start == nullptr;
    }

    //Obtener cantidad de elementos
    int size() {
        return this->sizeQueue;
    }

    //Destructor
    ~Queue() {
        while (this->start != nullptr) {
            Node<T>* eliminar = this->start;

            this->start = this->start->getNext();
            delete eliminar;
        }
        this->end = nullptr;
        this->sizeQueue = 0;
    }
};