#include "general.h"
#include "generaArreglos.h"
#include "busquedaBin.h"
#include <queue>                 // Se incluye la biblioteca queue para manejar colas de prioridad

Nodo* construirArbolHuffman(const unordered_map<int, unsigned>& mapaFrecuencias);
void liberarArbol(Nodo* raiz);
void Caso3(int ArregloLineal[], int ArregloNormal[],int Cantidad,int m);

