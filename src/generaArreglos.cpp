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

//Crear la estructura arreglo dinamico "Sample"
int* crearSample(int A[], int n, int m) { //m: tamaño sample, n: tamaño arreglo A
    int* sample = new int[m];
    int b = (n / m); //saltos en el arreglo A
    cout << b << endl;

    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        sample[j] = A[i];
        i += b;
        j++;
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

// Función para imprimir el mapa de frecuencias
void imprimirMapa(const unordered_map<int, unsigned>& mapaFrecuencias) {
    for (const auto& par : mapaFrecuencias) {
        cout << "Valor: " << par.first << " - Frecuencia: " << par.second << endl;
    }
}

// Función para imprimir un mapa de (int, string)
void imprimirMapa(const unordered_map<int, string>& mapaFrecuencias) {
    for (const auto& par : mapaFrecuencias) {
        cout << "Clave: " << par.first << " - Valor: " << par.second << endl;
    }
}

/*
long long getRAMUsage() {
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    return r_usage.ru_maxrss;
}
*/


/*
int main() {
    // Llamar a tu función y medir el uso de RAM antes y después
    long long ramBefore = getRAMUsage();
    myFunction();
    long long ramAfter = getRAMUsage();

    // Calcular la diferencia de uso de RAM
    long long ramUsage = ramAfter - ramBefore;

    std::cout << "Uso de RAM durante la ejecución: " << ramUsage << " bytes" << std::endl;

    return 0;
*/