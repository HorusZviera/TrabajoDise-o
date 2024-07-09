#include "../include/busquedaBin.h"

// Busqueda binaria
pair<int,double> busquedaBinaria(int A[], int n, int clave, bool ifSample) {
    // Inicio de tiempo
    auto start = chrono::high_resolution_clock::now();

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
    int valor = decodeGap(GC,Cantidad,resultado.first);;
    //cout<<"Valor: "<<valor<<endl;
    while(valor!=clave && resultado.first<15){
        resultado.first++;
        //valor = reconstruirValor(GC, sample, resultado.first, b);
        valor=decodeGap(GC,Cantidad,resultado.first);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {resultado.first,Tiempo};
}

pair<int,double> busquedaBinariaHuffman(bitset<8>* GC_Huffman[], int* sample, int n, int clave, int b) {
    // Inicia el tiempo
    auto start = chrono::high_resolution_clock::now();

    auto resultado=busquedaBinaria(sample,n,clave,true); // Realiza la busqueda binaria sobre el sample

    cout<<"Encontro: "<<resultado.first<<endl;
    /*
    // Busqueda lineal sobre el intervalo obtenido por el sample
    int valor = reconstruirValor(GC, sample, resultado.first, b);
    while(valor!=clave){
        resultado.first++;
        valor = reconstruirValor(GC, sample, resultado.first, b);
    }*/
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {resultado.first,Tiempo};
}

// Reconstruir valor original usando Gap-Coding y sample
int reconstruirValor(int GC[], int* sample, int index, int b) {
    int value = sample[index / b];
    for (int i = (index / b) * b + 1; i <= index; ++i) {
        value += GC[i];
    }
    return value;
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
