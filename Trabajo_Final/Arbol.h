#pragma once
#include <iostream>
#include <functional>
#include <conio.h>
#include <vector>
#include "Usuario.h"

using namespace std;

template<class T>
class Heap {
    vector<T>* heap;
    function<bool(T, T)> comp;
public:
    Heap(function<bool(T, T)> comp) : comp(comp) { heap = new vector<T>; } // Constructor

    size_t binarySearch(T value) const {
        size_t left = 0;
        size_t right = heap->size() - 1;

        while (left <= right) {
            size_t mid = left + (right - left) / 2;

            if ((*heap)[mid] == value) {
                return mid;  
            }
            else if (comp(value, (*heap)[mid])) {
                right = mid - 1; 
            }
            else {
                left = mid + 1;  
            }
        }

        return -1;  // Elemento no encontrado
    }

    ~Heap() { // Destructor
        if (heap->empty())
            heap->clear();
        delete heap;
    }

    size_t obtenerTamano() const { // Obtener el tamano
        return heap->size();
    }

    void push(T value) { // Insertar un elemento
        heap->push_back(value);
        heapifyForInsertion();
    }

    T pop() { // Eliminar un elemento
        if (heap->size() == 0)
            return T();
        T value = (*heap)[0];
        (*heap)[0] = (*heap)[heap->size() - 1];
        heap->pop_back();
        heapyfyForElimination();
        return value;
    }

    void removeAtPosition(size_t position) { // Eliminar un elemento en una posicion especifica
        if (position >= heap->size()) 
            return;
        swap((*heap)[position], (*heap)[heap->size() - 1]); 
        heap->pop_back(); 
        heapifyForDeletion(position);
    }

    void print() { // Ve citas
        for (Horarios elem : *heap) {
            elem.MostrarHorario();
            cout << "\n\n";
        }
        cout << "\n";
    }

    void MostrarHorarios() { // Para poder eliminar
        int i = 1;

        for (Horarios elem : *heap) {
            cout << "NrCurso: " << i << endl;
            elem.MostrarHorario();
            cout << "\n\n";
            i++;
        }
        cout << "\n";
    }

    T getHorariosAtPosition(size_t position) { // Para poder eliminar
        if (position >= heap->size())
            return T();
        return (*heap)[position];
    }

    void setHorarioAtPosition(size_t position, int newHorario) { // Para poder eliminar
        if (position >= heap->size())
            return;
        (*heap)[position].setHorario(newHorario);
    }
private:

    void heapifyForInsertion() { // Para insertar
        if (heap->size() <= 1)
            return;
        size_t child = heap->size();
        size_t parent = (child - 1) / 2;
        while (comp((*heap)[child], (*heap)[parent])) {
            swap((*heap)[child], (*heap)[parent]);
            if (parent == 0)
                break;
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void heapyfyForElimination() { // Para eliminar
        if (heap->size() <= 1)
            return;
        size_t parent = 0;
        while (true) {
            size_t leftChild = 2 * parent + 1;
            size_t rightChild = 2 * parent + 2;
            if (leftChild >= heap->size() && rightChild >= heap->size())
                break;
            size_t r;
            if (leftChild >= heap->size())
                r = rightChild;
            else if (rightChild >= heap->size())
                r = leftChild;
            else
                r = (comp((*heap)[leftChild], (*heap)[rightChild])) ? leftChild : rightChild;
            if (comp((*heap)[r], (*heap)[parent])) {
                swap((*heap)[r], (*heap)[parent]);
                parent = r;
                continue;
            }
            break;
        }
    }

    void heapifyForDeletion(size_t position) { // Para eliminar
        if (position >= heap->size())
            return;
        size_t parent = (position - 1) / 2;
        if (position > 0 && comp((*heap)[position], (*heap)[parent])) {
            while (position > 0 && comp((*heap)[position], (*heap)[parent])) {
                swap((*heap)[position], (*heap)[parent]);
                position = parent;
                parent = (position - 1) / 2;
            }
        }
        else {
            heapyfyForElimination();
        }
    }

    void swap(T& a, T& b) { // Para intercambiar
        T c = a;
        a = b;
        b = c;
    }
};