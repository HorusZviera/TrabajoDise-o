#include <iostream> //cin y cout
#include <cstdlib> //rand y srand
#include <chrono> //Tomar tiempo
#include <algorithm> //sort y binary_search
#include <random> //rand y srand
#include <vector> //Trabajo de vectores Gap-Coded

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
    auto start = chrono::high_resolution_clock::now();
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (A[medio] == clave) return medio;
        else if (A[medio] < clave) inicio = medio + 1;
        else fin = medio - 1;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double>(duration).count();
    return -1,Tiempo; // Si no se encuentra la clave1  
}

// -----------------------------------------------------------------------------------------------------------------------------------------------
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

// Reconstruir valor original usando Gap-Coding y sample
int reconstruirValor(int GC[], const vector<int>& sample, int index, int b) {
    int value = sample[index / b];
    for (int i = (index / b) * b + 1; i <= index; ++i) {
        value += GC[i];
    }
    return value;
}

// Búsqueda binaria en arreglo Gap-Coded
int busquedaBinariaGapCoding(int GC[], const vector<int>& sample, int n, int clave, int b) {
    auto start = chrono::high_resolution_clock::now();
    int Izquierda = 0;
    int Derecha = n - 1;
    while (Izquierda <= Derecha) {
        int mitad = Izquierda + (Derecha - Izquierda) / 2;
        int Valor = reconstruirValor(GC, sample, mitad, b);
        if (Valor == clave) {
            return mitad;
        } else if (Valor < clave) {
            Izquierda = mitad + 1;
        } else {
            Derecha = mitad - 1;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    double Tiempo = chrono::duration<double, milli>(duration).count();
    return -1,Tiempo;
}


// -----------------------------------------------------------------------------------------------------------------------------------------------

void Caso1(int ArregloLineal[], int ArregloNormal[],int Cantidad){

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];

    // Busqueda binaria para el arreglo generado con distribucion lineal
    int indiceLineal,tiempo_transcurrido_lineal = busquedaBinaria(ArregloLineal, Cantidad, claveLineal);

    // Busqueda binaria para el arreglo generado con distribucion normal
    int indiceNormal,tiempo_transcurrido_normal = busquedaBinaria(ArregloNormal, Cantidad, claveNormal);

    // Mostrar resultados para el arreglo con distribucion lineal
    if (indiceLineal != -1) {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " se encontro en el indice " << indiceLineal << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_lineal << " milisegundos." << endl << endl;
    // Mostrar resultados para el arreglo con distribucion normal
    if (indiceNormal != -1) {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " se encontro en el indice " << indiceNormal << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_normal << " milisegundos." << endl << endl;
    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
}

void Caso2(int ArregloLineal[], int ArregloNormal[],int Cantidad){
    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample"
    int m = 100;
    vector<int> sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    vector<int> sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];
    int b = Cantidad / m;

    // Búsqueda binaria Gap-coded lineal
    int indiceLineal,Tiempo_GapCoded_Lineal = busquedaBinariaGapCoding(GC_Lineal, sampleLineal, Cantidad, claveLineal, b);
    cout << "Para el arreglo Gap-Coded con distribucion lineal: ";
    if (indiceLineal != -1) {
        cout << "La clave " << claveLineal << " se encontro en el indice " << indiceLineal << endl;
    } else {
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << Tiempo_GapCoded_Lineal << " milisegundos." << endl;

   // Búsqueda binaria Gap-coded Normal
   int indiceNormal,Tiempo_GapCoded_Normal = busquedaBinariaGapCoding(GC_Normal, sampleNormal, Cantidad, claveNormal, b);
    cout << "Para el arreglo Gap-Coded con distribucion normal: ";
    if (indiceNormal != -1) {
        cout << "La clave " << claveNormal << " se encontro en el indice " << indiceNormal << endl;
    } else {
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl << endl ;
    }
    cout << "Tiempo transcurrido: " << Tiempo_GapCoded_Normal << " milisegundos." << endl;
    

    // Liberar la memoria asignada dinámicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
    delete[] GC_Lineal;
    delete[] GC_Normal;

}

int main() {

    int opcion;
        do {
            cout << "Que caso quiere ejecutar?" << endl;
            cout << "1. Caso 1 (Arreglo explicito)" << endl;
            cout << "2. Caso 2 (Arreglo representado con Gap-Coding)" << endl;
            cout << "3. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;

    const int Cantidad = 100000; // Tamano del arreglo         
    srand(time(NULL));

    int *ArregloLineal = new int[Cantidad]; //arreglo Lineal
    int *ArregloNormal = new int[Cantidad]; //arreglo Normal

    generarArregloLineal(ArregloLineal, Cantidad, 10);  // Generar arreglo ordenado con valores aleatorios de forma lineal
    generarArregloNormal(ArregloNormal, Cantidad, 100, 20); /// Generar arreglo ordenado con valores aleatorios segun una distribucion normal

    switch (opcion) {
        case 1:
            Caso1(ArregloLineal,ArregloNormal,Cantidad);
            break;
        case 2:
            Caso2(ArregloLineal,ArregloNormal,Cantidad);
            break;
        case 3:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
    }
    cout << endl;
    } while (opcion != 3);

    return 0;
}

