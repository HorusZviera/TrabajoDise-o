#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>     //se incluye para poder usar cout y cin
#include <vector>       //se incluye para poder usar vectores
#include <iomanip>      //se incluye para poder usar colores en la consola

using namespace std;

// Estructura para representar un nodo en el árbol de Huffman
struct Nodo {
    int valor;                  // Valor almacenado en el nodo
    unsigned frecuencia;        // Frecuencia de aparición del valor
    Nodo* izquierdo;      // Puntero al hijo izquierdo del nodo
    Nodo* derecho;       // Puntero al hijo derecho del nodo

    Nodo(int valor, unsigned frecuencia) : valor(valor), frecuencia(frecuencia), izquierdo(nullptr), derecho(nullptr) {}
};

// Función para comparar nodos Huffman según su frecuencia (mayor frecuencia primero)
struct CompararNodos {
    bool operator()(Nodo* a, Nodo* b) {
        return a->frecuencia > b->frecuencia;
    }
};

#endif