#include "../include/busquedaBin.h"

// Busqueda binaria

pair<int,double> busquedaBinaria(int A[], int n, int clave) {
    auto start = chrono::high_resolution_clock::now();
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (A[medio] == clave){
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            double Tiempo = chrono::duration<double>(duration).count();
            return {medio, Tiempo}; // Devolver el índice y el tiempo
        } 
        else if (A[medio] < clave) inicio = medio + 1;
        else fin = medio - 1;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double>(duration).count();
    return {-1,Tiempo}; // Si no se encuentra la clave1  
}

/*
// Búsqueda binaria en arreglo Gap-Coded
pair<int,double> busquedaBinariaGapCoding(int GC[], const vector<int>& sample, int n, int clave, int b) {
    auto start = chrono::high_resolution_clock::now();
    int inicio = 0;
    int fin = n - 1;
    int medio;
    cout<<"Sample de busqedabin"<<endl;
    imprimirVector(sample);
    while (inicio <= fin) {
        medio = inicio + (fin - inicio) / 2;
        // int Valor = reconstruirValor(GC, sample, medio, b);
        cout<<sample[medio] << " ";
        if (sample[medio] == clave) {
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            double Tiempo = chrono::duration<double, milli>(duration).count();
            return {medio,Tiempo};
        } else if (sample[medio] < clave) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    cout<<endl;

    int valor = reconstruirValor(GC, sample, medio, b);
    while(valor!=clave){
        medio++;
        valor = reconstruirValor(GC, sample, medio, b);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {medio,Tiempo};
}
*/





// Búsqueda binaria en arreglo Gap-Coded
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int n, int clave, int b) {
    auto start = chrono::high_resolution_clock::now();
    int inicio = 0;
    int fin = n - 1;
    int medio;
    cout<<"Sample de busqedabin"<<endl;

    imprimirArreglo(sample,n);

    while (inicio <= fin) {
        medio = inicio + (fin - inicio) / 2;
        // int Valor = reconstruirValor(GC, sample, medio, b);
        //cout<<sample[medio] << " ";
        if (sample[medio] == clave) {
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            double Tiempo = chrono::duration<double, milli>(duration).count();
            return {medio,Tiempo};
        } else if (sample[medio] < clave) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    cout<<endl;

    int valor = reconstruirValor(GC, sample, medio, b);
    while(valor!=clave){
        medio++;
        valor = reconstruirValor(GC, sample, medio, b);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return {medio,Tiempo};
}


// Reconstruir valor original usando Gap-Coding y sample
int reconstruirValor(int GC[], int* sample, int index, int b) {
    int value = sample[index / b];
    for (int i = (index / b) * b + 1; i <= index; ++i) {
        value += GC[i];
    }
    return value;
}


