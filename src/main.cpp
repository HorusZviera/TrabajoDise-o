#include "../include/busquedaBin.h"
#include "../include/generaArreglos.h"
#include "../include/caso1.h"
#include "../include/caso2.h"
#include "../include/caso3.h"

int main() {

    int opcion;
        do {
            cout << "Que caso quiere ejecutar?" << endl;
            cout << "1. Caso 1 (Arreglo explicito)" << endl;
            cout << "2. Caso 2 (Arreglo representado con Gap-Coding)" << endl;
            cout << "3. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;

    const int Cantidad = 100000; // Tamano del arreglo         
    srand(time(NULL));

    int *ArregloLineal = new int[Cantidad]; //arreglo Lineal
    int *ArregloNormal = new int[Cantidad]; //arreglo Normal

    generarArregloLineal(ArregloLineal, Cantidad, 10);  // Generar arreglo ordenado con valores aleatorios de forma lineal
    generarArregloNormal(ArregloNormal, Cantidad, 100, 20); /// Generar arreglo ordenado con valores aleatorios segun una distribucion normal

    switch (opcion) {
        case 1:
            Caso1(ArregloLineal,ArregloNormal,Cantidad);
            break;
        case 2:
            Caso2(ArregloLineal,ArregloNormal,Cantidad);
            break;
        case 3:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
    }
    cout << endl;
    } while (opcion != 3);

    return 0;
}

