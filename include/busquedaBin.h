#include "general.h"
#include <chrono>
#include "generaArreglos.h"

pair<int,double> busquedaBinaria(int A[], int n, int clave);
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int n, int clave, int b);
int reconstruirValor(int GC[], int* sample, int index, int b);
