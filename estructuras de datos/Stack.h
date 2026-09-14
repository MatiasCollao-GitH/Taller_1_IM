
#pragma once

#include "Node.h"
template <class T>

class Stack {

    private:
    Node<T>* start;
    int sizeStack;


    public:
    //Constructor
    Stack() {
        this->start = nullptr;
        this->sizeStack = 0;
    }

    //Insertar al inicio de la pila
    void push(T value) {
        Node<T>* nuevo = new Node<T>(value);

        nuevo->setNext(this->start);
        this->start = nuevo;

        this->sizeStack++;
    }

    //Eliminar el elemento superior
    void pop() {
        if (this->start == nullptr) {
            throw 0;
        }
        Node<T>* eliminar = this->start;
        this->start = this->start->getNext();

        delete eliminar;
        this->sizeStack--;
    }

    T top() {
        if (this->start == nullptr) {
            throw 0;
        }
        return this->start->getValue();
    }

    //Comprobar si está vacía
    bool isEmpty() {
        return this->start == nullptr;
    }

    //Obtener cantidad de elementos
    int size() {
        return this->sizeStack;
    }

    //Destructor
    ~Stack() {
        while (this->start != nullptr) {
            Node<T>* eliminar = this->start;

            this->start = this->start->getNext();
            delete eliminar;
        }
        this->sizeStack = 0;
    }

};