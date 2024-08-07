#include "../include/generaArreglos.h"

// Funcion para generar un arreglo ordenado con valores aleatorios segun una distribucion lineal
void generarArregloLineal(int A[], int n, int Incremento) {
    A[0] = rand() % 101;
    for (int i = 1; i < n; ++i) {
        A[i] = A[i - 1] + rand() % Incremento;
    }
}

// Funcion para generar un arreglo ordenado con valores aleatorios segun una distribucion normal
void generarArregloNormal(int A[], int n, double media, double desviacion) {
    default_random_engine generator;
    normal_distribution <double> distribution (media, desviacion);
    
    for (int i = 0; i < n; ++i) {
        A[i] = static_cast<int>(distribution(generator));
    }
    sort(A, A + n);
}

//-----------------------------------------------------------------------------------

// Crear arreglo Gap-Coded
void crearGapCoding(int A[], int GC[], int n) {
    GC[0] = A[0];
    for (int i = 1; i < n; ++i) {
        GC[i] = A[i] - A[i - 1];
    }
}

//Crear la estructura arreglo dinamico "Sample"
int* crearSample(int A[], int n, int m) { //m: tamano sample, n: tamano arreglo A
    int* sample = new int[m];
    int b = (n / m); //saltos en el arreglo A

    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        sample[j] = A[i];
        i += b;
        j++;
    }
    return sample;
}

//-----------------------------------------------------------------------------------

// Imprime arreglos
void imprimirArreglo(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void imprimirArreglo(const bitset<8> arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//-----------------------------------------------------------------------------------

// Funcion para imprimir el mapa de frecuencias
void imprimirMapa(const unordered_map<int, unsigned>& mapaFrecuencias) {
    for (const auto& par : mapaFrecuencias) {
        cout << "Valor: " << par.first << " - Frecuencia: " << par.second << endl;
    }
}

// Funcion para imprimir un mapa de (int, string)
void imprimirMapa(const unordered_map<int, string>& mapaFrecuencias) {
    for (const auto& par : mapaFrecuencias) {
        cout << "Clave: " << par.first << " - Valor: " << par.second << endl;
    }
}

// Función para imprimir el árbol de Huffman (inorder traversal)
void imprimirArbolHuffman(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }

    // Recorrido inorder: izquierdo - raíz - derecho
    imprimirArbolHuffman(nodo->izquierdo);
    std::cout << "(" << nodo->valor << ", " << nodo->frecuencia << ") ";
    imprimirArbolHuffman(nodo->derecho);
}


//-----------------------------------------------------------------------------------

bitset<8> convertirABinario(const string& cadenaBinaria) {
    // Asegurarse de que la cadena tenga exactamente 8 bits
    string cadenaBinariaAjustada = cadenaBinaria;

    // Si la cadena es menor de 8 bits, se completan con ceros a la izquierda
    if (cadenaBinariaAjustada.size() < 8) {
        cadenaBinariaAjustada.insert(0, 8 - cadenaBinariaAjustada.size(), '0');
    }
    // Si la cadena es mayor de 8 bits, se truncan los bits extras
    else if (cadenaBinariaAjustada.size() > 8) {
        cadenaBinariaAjustada = cadenaBinariaAjustada.substr(0, 8);
    }

    // Convertir la cadena ajustada a un número binario de 8 bits
    bitset<8> binario8Bits(cadenaBinariaAjustada);
    return binario8Bits;
}

