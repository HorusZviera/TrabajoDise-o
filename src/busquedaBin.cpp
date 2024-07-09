#include "../include/busquedaBin.h"

// Busqueda binaria
pair<int,double> busquedaBinaria(int A[], int n, int clave, bool ifSample) {
    auto start = chrono::high_resolution_clock::now(); // Inicio de tiempo
    int medio;
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        medio = inicio + (fin - inicio) / 2;
        if (A[medio] == clave){ // En caso de encontrar la clave
            // Termina el tiempo
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            double Tiempo = chrono::duration<double>(duration).count();
            return {medio, Tiempo}; // Devolver el índice y el tiempo
        } 
        else if (A[medio] < clave) inicio = medio + 1;
        else fin = medio - 1;
    }
    if(ifSample){
        if(A[medio]>clave) medio--;
        // Termina el tiempo
        auto end = chrono::high_resolution_clock::now();
        auto duration = end - start;
        double Tiempo = chrono::duration<double>(duration).count();
        return {medio,Tiempo};
    }
    return {-1,0}; // Si no se encuentra la clave1  
}

// Búsqueda binaria en arreglo Gap-Coded
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int Cantidad, int n, int clave, int b) {
    // Inicia el tiempo
    auto start = chrono::high_resolution_clock::now();

    auto resultado=busquedaBinaria(sample,n,clave,true); // Realiza la busqueda binaria sobre el sample
    resultado.first*=b; // Salta al indice correspondiente en el arreglo

    // Busqueda lineal sobre el intervalo obtenido por el sample
    //cout<<"Encontro: "<<resultado.first<<endl;
    //cout<<"Clave: "<<clave<<endl;
    int valor = decodeGap(GC,Cantidad,resultado.first);
    //cout<<"Valor: "<<valor<<endl;
    while(valor!=clave){
        resultado.first++;
        //valor = reconstruirValor(GC, sample, resultado.first, b);
        //valor=decodeGap(GC,Cantidad,resultado.first);
        valor+=GC[resultado.first];

    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {resultado.first,Tiempo};
}

pair<int,double> busquedaBinariaHuffman(Nodo* root, bitset<8>* GC_Huffman, int GC[], int* sample, int Cantidad, int n, int clave, int b) {
    // Inicia el tiempo
    auto start = chrono::high_resolution_clock::now();

    auto resultado=busquedaBinaria(sample,n,clave,true); // Realiza la busqueda binaria sobre el sample
    resultado.first*=b; // Salta al indice correspondiente en el arreglo
    // Busqueda lineal sobre el intervalo obtenido por el sample

    //imprimirArbolHuffman(root);
    //cout<<"Encontro: "<<resultado.first<< " "<<GC_Huffman[80]<<endl;
    int valor=decodeHuffman(root, GC_Huffman[resultado.first]);
    //cout<<"Gap: "<<valor<<endl;
    valor = decodeGap(GC,Cantidad,resultado.first);
    //cout<<"Valor: "<<valor<<endl;
    //cout<<"Clave: "<<clave<<endl;
    while(valor!=clave){
        resultado.first++;
        valor+=GC[resultado.first];
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {resultado.first,Tiempo};
}

int decodeHuffman(Nodo* root, const std::bitset<8>& encodedData) {
    Nodo* current = root;

    for (int i = 0; i < 8; ++i) { // asumiendo que el tamaño de los datos codificados es de 8 bits
        bool bit = encodedData.test(i); // Obtener el bit en la posición i

        if (!bit) {
            current = current->izquierdo;
        } else {
            current = current->derecho;
        }

        if (current->izquierdo == nullptr && current->derecho == nullptr) {
            return current->valor; // Retornar el valor decodificado
        }
    }

    // En un caso real, manejarías adecuadamente las situaciones donde no se puede decodificar completamente.
    return -1; // Retorno de valor inválido en caso de error
}


int decodeGap(const int encodedArray[], int size, int position) {
    if (position >= size) {
        std::cerr << "Posición fuera de rango." << std::endl;
        return -1; // Manejo de error, posición fuera de rango
    }

    int decodedValue = encodedArray[position];

    // Ajuste el valor decodificado si no es el primer elemento
    for (int i = position - 1; i >= 0; --i) {
        decodedValue += encodedArray[i];
    }

    return decodedValue;
}


