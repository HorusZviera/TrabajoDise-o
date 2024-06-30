#include "../include/argumentos.h"

void procesarArgumentos(int argc, char* argv[], int& tamanio, int& semilla) {
    int opcion;
    tamanio = 0;
    semilla = 0;

    // Procesar argumentos de línea de comandos con getopt
    while ((opcion = getopt(argc, argv, "n:s:")) != -1) {
        switch (opcion) {
            case 'n':
                tamanio = atoi(optarg); // Tamaño del arreglo
                break;
            case 's':
                semilla = atoi(optarg); // Establece semilla 
                break;
            default:
                cout << "Uso: " << argv[0] << "  -n <Tamaño arreglo> -s <semilla>" << endl;
                exit(EXIT_FAILURE);
        }
    }

    // Verificar que se hayan ingresado las opciones
    if (tamanio == 0 || semilla == 0) {
        cout << "Debe ingresar las opciones requeridas: -n <Tamaño arreglo> -s <semilla>" << endl;
        exit(EXIT_FAILURE);
    }
}