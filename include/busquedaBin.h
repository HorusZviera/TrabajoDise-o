#include "general.h"
#include <chrono>                // se incluye la libreria para medir el tiempo de ejecucion
#include "generaArreglos.h"

pair<int,double> busquedaBinaria(int A[], int n, int clave, bool ifSample);
pair<int,double> busquedaBinariaGapCoding(int GC[], int* sample, int Cantidad, int n, int clave, int b);
pair<int,double> busquedaBinariaHuffman(Nodo* root, bitset<8>* GC_Huffman[], int GC[], int* sample, int Cantidad, int n, int clave, int b);
int decodeGap(const int encodedArray[], int size, int position);
int decodeHuffman(Nodo* root, const std::bitset<8>& encodedData);
int reconstruirValor(int GC[], int* sample, int index, int b);
