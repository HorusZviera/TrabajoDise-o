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

// Crear arreglo Gap-Coded
void crearGapCoding(int A[], int GC[], int n) {
    GC[0] = A[0];
    for (int i = 1; i < n; ++i) {
        GC[i] = A[i] - A[i - 1];
    }
}

//Crear la estructura vector "Sample"
vector<int> crearSample(int A[],int n, int m){
    vector<int> sample;
    int b = n / m;
    for (int i = 0; i < n; i += b) {
        sample.push_back(A[i]); //Se añade al final
    }
    return sample;
}

// Imprime arreglos
void imprimirArreglo(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void imprimirVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

