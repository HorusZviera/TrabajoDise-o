#include "general.h"
#include <unordered_map>        // se incluye para el uso de la libreria unordered_map
#include <random>               // se incluye para el uso de la libreria random 
#include <cstdlib>              // se incluye para el uso de la libreria srand
#include <algorithm>            // se incluye para el uso de la libreria sort y binary_search
#include <bitset>               // se incluye para el uso de la libreria bitset 

void generarArregloLineal(int A[], int n, int Incremento);
void generarArregloNormal(int A[], int n, double media, double desviacion);
void crearGapCoding(int A[], int GC[], int n);
int* crearSample(int A[], int n, int m);
void imprimirArreglo(const int arr[], int n);
void imprimirArreglo(const bitset<8> arr[], int n);
void imprimirMapa(const unordered_map<int, unsigned>& mapaFrecuencias);
void imprimirMapa(const unordered_map<int, string>& mapaFrecuencias);
void imprimirArbolHuffman(Nodo* nodo);
bitset<8> convertirABinario(const string& cadenaBinaria);
