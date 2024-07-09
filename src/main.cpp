#include "../include/busquedaBin.h"
#include "../include/generaArreglos.h"
#include "../include/caso1.h"
#include "../include/caso2.h"
#include "../include/caso3.h"
#include "../include/argumentos.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char* argv[]) {
    // Argumentos
    int tamanio;
    int semilla;
    int opcion;

    procesarArgumentos(argc, argv, tamanio, semilla);


    // Crea los arreglos que se usaran en los casos
    const int Cantidad = tamanio; // Tamano del arreglo         
    srand(semilla);

    int *ArregloLineal = new int[Cantidad]; //arreglo Lineal
    int *ArregloNormal = new int[Cantidad]; //arreglo Normal

    generarArregloLineal(ArregloLineal, Cantidad, 10);  // Generar arreglo ordenado con valores aleatorios de forma lineal
    generarArregloNormal(ArregloNormal, Cantidad, 100, 20); // Generar arreglo ordenado con valores aleatorios segun una distribucion normal

    cout << ANSI_COLOR_BLUE << "==================================" << endl;
    cout << "============== Menú ==============" << endl;
    cout << "==================================" << endl;
    cout << ANSI_COLOR_GREEN << "1. "  << "Caso 1 (Arreglo explicito)" << endl;
    cout << "2. " <<  "Caso 2 (Arreglo representado con Gap-Coding)" << endl;
    cout << "3. " <<  "Caso 3 (Codificacion de Huffman)" << endl;
    cout << ANSI_COLOR_RED << "4. " <<  "Salir" << endl;
    cout << ANSI_COLOR_BLUE << "Ingrese su opción: " << ANSI_COLOR_RESET;
    cin >> opcion;

    switch (opcion) {
        case 1:
            Caso1(ArregloLineal,ArregloNormal,Cantidad);
            break;
        case 2:
            int m;
            cout << "Ingrese el tamaño de la estructura sample: ";
            cin >> m;
            if (m <= 0 || m >= Cantidad)
                cout << "El valor de m debe ser mayor a 0 y menor a " << Cantidad << ". Intente de nuevo." << endl;
            else
                Caso2(ArregloLineal,ArregloNormal,Cantidad,m);
            break;
        case 3:
            cout << "Ingrese el tamaño de la estructura sample: ";
            cin >> m;
            if (m <= 0 || m >= Cantidad) 
                cout << "El valor de m debe ser mayor a 0 y menor a " << Cantidad << ". Intente de nuevo." << endl;
            else 
                Caso3(ArregloLineal,ArregloNormal,Cantidad,m);
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
    }
    cout << endl;

    return 0;
}

