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
                if (tamanio <= 0 || tamanio >= 1000000000) {
                    cout << "El tamaño del arreglo debe estar entre 1 y 1,000,000,000" << endl;
                    exit(EXIT_FAILURE);
                }
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
