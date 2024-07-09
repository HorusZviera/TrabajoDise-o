#include <unordered_map>
#include "general.h"
#include <random> //rand y srand
#include <cstdlib> //rand y srand
#include <algorithm> //sort y binary_search
#include <bitset>

void generarArregloLineal(int A[], int n, int Incremento);
void generarArregloNormal(int A[], int n, double media, double desviacion);
void crearGapCoding(int A[], int GC[], int n);
int* crearSample(int A[], int n, int m);
void imprimirArreglo(const int arr[], int n);
void imprimirArreglo(const bitset<8> arr[], int n);
void imprimirMapa(const unordered_map<int, unsigned>& mapaFrecuencias);
void imprimirMapa(const unordered_map<int, string>& mapaFrecuencias);
bitset<8> convertirABinario(const string& cadenaBinaria);
