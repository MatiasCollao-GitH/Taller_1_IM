
#pragma once
#include "Node.h"
template <class T>

class List {

    private:
    Node<T>* start;
    int size;
    public:
    List() {
        this->start = nullptr;
        this->size = 0;
    }

    //Comprobamos si la lista está vacía
    bool isEmpty() {
        return this->start == nullptr;
    }

    //Devuelve la cantidad de elementos
    int getSize() {
        return this->size;
    }

    //Inserta al inicio
    void insertFirst(T value) {
        Node<T>* nuevo = new Node<T>(value);

        nuevo->setNext(this->start);
        this->start = nuevo;
        this->size++;
    }

    //Inserta al final
    void insertLast(T value) {
        Node<T>* nuevo = new Node<T>(value);
        if (this->start == nullptr) {
            this->start = nuevo;
            this->size++;
            return;
        }
        Node<T>* cursor = this->start;

        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        cursor->setNext(nuevo);
        this->size++;
    }

    //Inserta en una posición
    void insert(T value, int index) {
        if (index < 0 || index > this->size) {
            return;
        }
        if (index == 0) {
            insertFirst(value);
            return;
        }
        if (index == this->size) {
            insertLast(value);
            return;
        }
        Node<T>* cursor = this->start;
        for (int i = 0; i < index-1; i++) {
            cursor = cursor->getNext();
        }

        Node<T>* nuevo = new Node<T>(value);

        nuevo->setNext(cursor->getNext());
        cursor->setNext(nuevo);

        this->size++;
    }

    //Obtener primer elemento
    T getFirst() {
        if (this->start == nullptr) {
            return T{};
        }

        return this->start->getValue();
    }

    //Obtener último elemento
    T getLast() {
        if (this->start == nullptr) {
            return T{};
        }

        Node<T>* cursor = this->start;

        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    //Obtener elemento por posición
    T get(int index) {
        if (index < 0 || index >= this->size) {
            return T{};
        }
        Node<T>* cursor = this->start;
        for (int i = 0; i < index; i++) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    //Eliminar elemento por posición
    void remove(int index) {
        if (index < 0 || index >= this->size) {
            return;
        }

        //Eliminar primero
        if (index == 0) {
            Node<T>* temp = this->start;

            this->start = this->start->getNext();

            delete temp;

            this->size--;

            return;
        }
        Node<T>* cursor = this->start;

        for (int i = 0; i < index-1; i++) {
            cursor = cursor->getNext();
        }
        Node<T>* eliminar = cursor->getNext();

        cursor->setNext(eliminar->getNext());
        delete eliminar;

        this->size--;
    }

    //Vaciar la lista
    void clear() {
        while (this->start != nullptr) {
            Node<T>* temp = this->start->getNext();
            delete this->start;
            this->start = temp;
        }
        this->size = 0;
    }

    //Destructor
    ~List() {
        clear();
    }
};