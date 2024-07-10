#include "../include/caso1.h"

void Caso1(int ArregloLineal[], int ArregloNormal[],int Cantidad){

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];

    auto resultadoLineal = busquedaBinaria(ArregloLineal, Cantidad, claveLineal,false); // Busqueda binaria para el arreglo generado con distribucion lineal
    auto resultadoNormal = busquedaBinaria(ArregloNormal, Cantidad, claveNormal,false); // Busqueda binaria para el arreglo generado con distribucion normal

    // Mostrar resultados para el arreglo con distribucion lineal
    if (resultadoLineal.first != -1) {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " se encontro en el indice " << resultadoLineal.first<< endl;
    } else {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << endl;
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoLineal.second << " Segundos." << endl << endl;

    // Mostrar resultados para el arreglo con distribucion normal
    if (resultadoNormal.first != -1) {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " se encontro en el indice " << resultadoNormal.first << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoNormal.second << " Segundos." << endl << endl;

    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
}
