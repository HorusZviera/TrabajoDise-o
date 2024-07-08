#include "../include/caso3.h"  // Se incluye el archivo de encabezado caso3.h

// Función para construir el árbol de Huffman
Nodo* construirArbolHuffman(const unordered_map<int, unsigned>& mapaFrecuencias) {
   priority_queue<Nodo*,vector<Nodo*>, CompararNodos> colaPrioridad;

    // Crear un nodo hoja para cada valor único y agregarlo a la cola de prioridad
    for (const auto& par : mapaFrecuencias) {
        colaPrioridad.push(new Nodo(par.first, par.second));
    }

    // Construir el árbol de Huffman fusionando nodos de la cola de prioridad
    while (colaPrioridad.size() > 1) {
        Nodo* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        Nodo* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        Nodo* nuevoNodo = new Nodo(-1, izquierdo->frecuencia + derecho->frecuencia);
        nuevoNodo->izquierdo = izquierdo;
        nuevoNodo->derecho = derecho;

        colaPrioridad.push(nuevoNodo);
    }

    return colaPrioridad.top();
}

void imprimirArbolHuffman(Nodo* nodo, int nivel = 0) {
    if (nodo == nullptr) {
        return;
    }

    // Imprimir espacios en blanco para representar la profundidad del nodo
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }

    // Imprimir el valor y la frecuencia del nodo
    cout << nodo->valor << " (" << nodo->frecuencia << ")" << endl;

    // Recursivamente imprimir los hijos izquierdo y derecho
    imprimirArbolHuffman(nodo->izquierdo, nivel + 1);
    imprimirArbolHuffman(nodo->derecho, nivel + 1);
}

// Función para generar códigos Huffman para cada valor en el árbol de Huffman
void generarCodigosHuffman(Nodo* raiz,unordered_map<int,string>& codigos,string codigo = "") {
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        codigos[raiz->valor] = codigo;
        return;
    }

    generarCodigosHuffman(raiz->izquierdo, codigos, codigo + "0");
    generarCodigosHuffman(raiz->derecho, codigos, codigo + "1");
}



void Caso3(int ArregloLineal[], int ArregloNormal[], int Cantidad, int m) {

    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    // Crea gap coding
    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample" "Con m ingresado por el usuario"
    int* sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    int* sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    // Codificacion Arreglo Lineal
    unordered_map<int, unsigned> mapaFrecuenciasLineal;
    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuenciasLineal[GC_Lineal[i]]++; // Calcular la frecuencia de cada valor en el arreglo lineal
    }

    Nodo* raiz_Lineal = construirArbolHuffman(mapaFrecuenciasLineal);    // Construir el árbol de Huffman    
    
    unordered_map<int,string> codigosHuffmanLineal;
    generarCodigosHuffman(raiz_Lineal, codigosHuffmanLineal); // Generar códigos Huffman para cada valor en el árbol de Huffman
    


    
    cout<<"Lineal"<<endl;
    imprimirArreglo(ArregloLineal,Cantidad);
    imprimirArreglo(GC_Lineal,Cantidad);
    imprimirArreglo(sampleLineal, m);

    cout << "Códigos Huffman Arreglo Lineal:" << endl;  // Imprimir los códigos Huffman generados
    for (const auto& par : codigosHuffmanLineal) {
        cout << par.first << ": " << par.second << endl;
    }
    cout << endl << endl << endl ;

    for (int i = 0; i < Cantidad; ++i) {
        cout << GC_Lineal[i] << endl;
    }
    imprimirArreglo(GC_Lineal,Cantidad);

    cout<<"####################"<<endl;
    






















    /*
    // Codificacion Arreglo Normal
    unordered_map<int, unsigned> mapaFrecuenciasNormal;
    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuenciasNormal[ArregloNormal[i]]++; // Calcular la frecuencia de cada valor en el arreglo Normal
    }

    Nodo* raiz_Normal = construirArbolHuffman(mapaFrecuenciasNormal); // Construir el árbol de Huffman

    unordered_map<int,string> codigosHuffmanNormal; 
    generarCodigosHuffman(raiz_Normal, codigosHuffmanNormal); // Generar códigos Huffman para cada valor en el árbol de Huffman
    
    cout << "Códigos Huffman Arreglo Normal:" << endl; // Imprimir los códigos Huffman generados
    for (const auto& par : codigosHuffmanNormal) {
        cout << par.first << ": " << par.second << endl;
    }
    cout << endl << endl << endl;
    */
    
}





/*
    // Funciones que pueden ayudar
        imprimirMapa(mapaFrecuencias); // Se imprime el mapa de frecuencias
        imprimirArbolHuffman(raiz_Lineal); // Imprimir el árbol de Huffman
*/





