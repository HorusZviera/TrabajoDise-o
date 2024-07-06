#include "../include/caso1.h"

void Caso1(int ArregloLineal[], int ArregloNormal[],int Cantidad){

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];

    // Busqueda binaria para el arreglo generado con distribucion lineal
    auto resultadoLineal = busquedaBinaria(ArregloLineal, Cantidad, claveLineal);

    // Busqueda binaria para el arreglo generado con distribucion normal
    auto resultadoNormal = busquedaBinaria(ArregloNormal, Cantidad, claveNormal);

    // Mostrar resultados para el arreglo con distribucion lineal
    if (resultadoLineal.first != -1) {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " se encontro en el indice " << resultadoLineal.first<< endl;
    } else {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << endl;
    cout << "Tiempo transcurrido: " << resultadoLineal.second << " milisegundos." << endl << endl;
    
    // Mostrar resultados para el arreglo con distribucion normal
    if (resultadoNormal.first != -1) {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " se encontro en el indice " << resultadoNormal.first << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << resultadoNormal.second << " milisegundos." << endl << endl;

    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
}