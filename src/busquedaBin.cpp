#include "../include/busquedaBin.h"

// Busqueda binaria
pair<int,double> busquedaBinaria(int A[], int n, int clave) {
    // Inicio de tiempo
    auto start = chrono::high_resolution_clock::now();

    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
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
    // Termina el tiempo
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double>(duration).count();

    return {-1,Tiempo}; // Si no se encuentra la clave1  
}

// Búsqueda binaria en arreglo Gap-Coded
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int n, int clave, int b) {
    // Inicia el tiempo
    auto start = chrono::high_resolution_clock::now();

    auto resultado=busquedaBinaria(sample,n,clave); // Realiza la busqueda binaria sobre el sample

    // Busqueda lineal sobre el intervalo obtenido por el sample
    int valor = reconstruirValor(GC, sample, resultado.first, b);
    while(valor!=clave){
        resultado.first++;
        valor = reconstruirValor(GC, sample, resultado.first, b);
    }
    
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
