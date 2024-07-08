#include "generaArreglos.h"
#include "general.h"
#include <vector>                // Se incluye la biblioteca vector para manejar listas dinámicas
#include <algorithm>             // Se incluye la biblioteca algorithm para funciones de ordenamiento y búsqueda
#include <queue>                 // Se incluye la biblioteca queue para manejar colas de prioridad
#include <unordered_map>        // Se incluye la biblioteca unordered_map para manejar mapas sin orden

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

void Caso3(int ArregloLineal[], int ArregloNormal[],int Cantidad,int m);
//void imprimirArbolHuffman(Nodo* nodo, int nivel = 0);
Nodo* construirArbolHuffman(const unordered_map<int, unsigned>& mapaFrecuencias);


//void generarCodigosHuffman(NodoHuffman* raiz, std::unordered_map<int, std::string>& codigos, std::string codigo = "");
