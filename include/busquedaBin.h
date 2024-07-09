#include "general.h"
#include <chrono>
#include "generaArreglos.h"

pair<int,double> busquedaBinaria(int A[], int n, int clave, bool ifSample);
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int Cantidad, int n, int clave, int b);
int decodeGap(const int encodedArray[], int size, int position);
pair<int,double> busquedaBinariaHuffman(bitset<8>* GC_Huffman[], int* sample, int n, int clave, int b);
int reconstruirValor(int GC[], int* sample, int index, int b);
