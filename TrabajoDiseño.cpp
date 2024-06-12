#include <iostream> //cin y cout
#include <cstdlib> //rand y srand
#include <ctime> //time y clock
#include <algorithm> //sort y binary_search
#include <random> //rand y srand

using namespace std;

// Funcion para generar un arreglo ordenado con valores aleatorios segun una distribucion lineal
void generarArregloLineal(int A[], int n, int Incremento) {
    A[0] = rand();
    for (int i = 1; i < n; ++i) {
        A[i] = A[i - 1] + rand() % Incremento;
    }
}

// Funcion para generar un arreglo ordenado con valores aleatorios segun una distribucion normal
void generarArregloNormal(int A[], int n, double media, double desviacion) {
    default_random_engine generator;
    normal_distribution <double> distribution (media, desviacion);
    for (int i = 0; i < n; ++i) {
        A[i] = distribution(generator);
    }
    sort(A, A + n);
}

// Busqueda binaria
int busquedaBinaria(int A[], int n, int clave) {
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (A[medio] == clave) return medio;
        else if (A[medio] < clave) inicio = medio + 1;
        else fin = medio - 1;
    }
    return -1; // Si no se encuentra la clave
}

int main() {


    const int Cantidad = 10000000; // Tamano del arreglo         
    srand(time(NULL));

    int *ArregloLineal = new int[Cantidad]; //arreglo Lineal
    int *ArregloNormal = new int[Cantidad]; //arreglo Normal

    generarArregloLineal(ArregloLineal, Cantidad, 10);  // Generar arreglo ordenado con valores aleatorios de forma lineal
    generarArregloNormal(ArregloNormal, Cantidad, 100, 20); /// Generar arreglo ordenado con valores aleatorios segun una distribucion normal

    // Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];

    // Busqueda binaria para el arreglo generado con distribucion lineal
    clock_t inicioLineal = clock();
    int indiceLineal = busquedaBinaria(ArregloLineal, Cantidad, claveLineal);
    clock_t finLineal = clock();
    double tiempo_transcurrido_lineal = double(finLineal - inicioLineal) / CLOCKS_PER_SEC * 1000000; // Tiempo en microsegundos


    // Busqueda binaria para el arreglo generado con distribucion normal
    clock_t inicioNormal = clock();
    int indiceNormal = busquedaBinaria(ArregloNormal, Cantidad, claveNormal);
    clock_t finNormal = clock();
    double tiempo_transcurrido_normal = double(finNormal - inicioNormal) / CLOCKS_PER_SEC * 1000000; // Tiempo en microsegundos

    // Mostrar resultados para el arreglo con distribucion lineal
    if (indiceLineal != -1) {
        cout << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " se encontro en el indice " << indiceLineal << endl;
    } else {
        cout << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_lineal << " milisegundos." << endl;

    // Mostrar resultados para el arreglo con distribucion normal
    if (indiceNormal != -1) {
        cout << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " se encontro en el indice " << indiceNormal << endl;
    } else {
        cout << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_normal << " milisegundos." << endl;

    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;

    return 0;
}
