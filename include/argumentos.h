#include "general.h"
#include <string>              // se incluye la libreria string para poder usar el tipo de dato string
#include <unistd.h>            // se incluye la libreria unistd.h para poder usar la funcion getopt
#include <cstdlib>             // se incluye la libreria cstdlib para poder usar la funcion atoi

void procesarArgumentos(int argc, char* argv[], int& tamanio, int& semilla);