#include "../include/busquedaBin.h"
#include "../include/generaArreglos.h"
#include "../include/caso1.h"
#include "../include/caso2.h"
#include "../include/caso3.h"
#include "../include/argumentos.h"

int main(int argc, char* argv[]) {
    // Argumentos
    int tamanio;
    int semilla;
    int opcion;

    procesarArgumentos(argc, argv, tamanio, semilla);

    do {
        cout << "Que caso quiere ejecutar?" << endl;
        cout << "1. Caso 1 (Arreglo explicito)" << endl;
        cout << "2. Caso 2 (Arreglo representado con Gap-Coding)" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        const int Cantidad = tamanio; // Tamano del arreglo         
        srand(semilla);

        int *ArregloLineal = new int[Cantidad]; //arreglo Lineal
        int *ArregloNormal = new int[Cantidad]; //arreglo Normal

        generarArregloLineal(ArregloLineal, Cantidad, 10);  // Generar arreglo ordenado con valores aleatorios de forma lineal
        generarArregloNormal(ArregloNormal, Cantidad, 100, 20); // Generar arreglo ordenado con valores aleatorios segun una distribucion normal

        switch (opcion) {
            case 1:
                Caso1(ArregloLineal,ArregloNormal,Cantidad);
                break;
            case 2:
                int m;
                cout << "Ingrese el tamaño de la estructura sample: ";
                cin >> m;
                if (m <= 0 || m >= Cantidad) {
                    cout << "El valor de m debe ser mayor a 0 y menor a " << Cantidad << ". Intente de nuevo." << endl;
                    continue;
                }
                Caso2(ArregloLineal,ArregloNormal,Cantidad,m);
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

