#include "../include/caso3.h"  // Se incluye el archivo de encabezado caso3.h



// Estructura para representar un nodo en el árbol de Huffman
struct NodoHuffman {
    int valor;                  // Valor almacenado en el nodo
    unsigned frecuencia;        // Frecuencia de aparición del valor
    NodoHuffman* izquierdo;      // Puntero al hijo izquierdo del nodo
    NodoHuffman* derecho;       // Puntero al hijo derecho del nodo

    NodoHuffman(int valor, unsigned frecuencia) : valor(valor), frecuencia(frecuencia), izquierdo(nullptr), derecho(nullptr) {}
};

// Función para comparar nodos Huffman según su frecuencia (mayor frecuencia primero)
struct CompararNodos {
    bool operator()(NodoHuffman* a, NodoHuffman* b) {
        return a->frecuencia > b->frecuencia;
    }
};

// Función para construir el árbol de Huffman
NodoHuffman* construirArbolHuffman(const std::unordered_map<int, unsigned>& mapaFrecuencias) {
    std::priority_queue<NodoHuffman*, std::vector<NodoHuffman*>, CompararNodos> colaPrioridad;

    // Crear un nodo hoja para cada valor único y agregarlo a la cola de prioridad
    for (const auto& par : mapaFrecuencias) {
        colaPrioridad.push(new NodoHuffman(par.first, par.second));
    }

    // Construir el árbol de Huffman fusionando nodos de la cola de prioridad
    while (colaPrioridad.size() > 1) {
        NodoHuffman* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        NodoHuffman* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        NodoHuffman* nuevoNodo = new NodoHuffman(-1, izquierdo->frecuencia + derecho->frecuencia);
        nuevoNodo->izquierdo = izquierdo;
        nuevoNodo->derecho = derecho;

        colaPrioridad.push(nuevoNodo);
    }

    return colaPrioridad.top();
}

// Función para generar códigos Huffman para cada valor en el árbol de Huffman
void generarCodigosHuffman(NodoHuffman* raiz, std::unordered_map<int, std::string>& codigos, std::string codigo = "") {
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        codigos[raiz->valor] = codigo;
        return;
    }

    generarCodigosHuffman(raiz->izquierdo, codigos, codigo + "0");
    generarCodigosHuffman(raiz->derecho, codigos, codigo + "1");
}

void Caso3(int ArregloLineal[], int ArregloNormal[], int Cantidad) {
    // Calcular la frecuencia de cada valor en el arreglo lineal
    std::unordered_map<int, unsigned> mapaFrecuencias;
    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuencias[ArregloLineal[i]]++;
    }

    // Construir el árbol de Huffman
    NodoHuffman* raiz = construirArbolHuffman(mapaFrecuencias);

    // Generar códigos Huffman para cada valor en el árbol de Huffman
    std::unordered_map<int, std::string> codigosHuffman;
    generarCodigosHuffman(raiz, codigosHuffman);

    // Comprimir el arreglo lineal usando los códigos Huffman
    for (int i = 0; i < Cantidad; i++) {
        ArregloNormal[i] = std::stoi(codigosHuffman[ArregloLineal[i]], nullptr, 2);
    }

    // TODO: Manejar valores atípicos para evitar una degradación significativa de la compresión
}

/*
  Comentario final:
  - Los datos se consideran fijos ("const").
*/
