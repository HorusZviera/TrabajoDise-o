#include "general.h"
#include <random> //rand y srand
#include <cstdlib> //rand y srand
#include <algorithm> //sort y binary_search


void generarArregloLineal(int A[], int n, int Incremento);
void generarArregloNormal(int A[], int n, double media, double desviacion);
void crearGapCoding(int A[], int GC[], int n);
vector<int> crearSample(int A[],int n, int m);