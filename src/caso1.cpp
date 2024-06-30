#include "../include/caso1.h"

void Caso1(int ArregloLineal[], int ArregloNormal[],int Cantidad){

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];

    // Busqueda binaria para el arreglo generado con distribucion lineal
    int indiceLineal,tiempo_transcurrido_lineal = busquedaBinaria(ArregloLineal, Cantidad, claveLineal);

    // Busqueda binaria para el arreglo generado con distribucion normal
    int indiceNormal,tiempo_transcurrido_normal = busquedaBinaria(ArregloNormal, Cantidad, claveNormal);

    // Mostrar resultados para el arreglo con distribucion lineal
    if (indiceLineal != -1) {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " se encontro en el indice " << indiceLineal << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion lineal: ";
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_lineal << " milisegundos." << endl << endl;
    // Mostrar resultados para el arreglo con distribucion normal
    if (indiceNormal != -1) {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " se encontro en el indice " << indiceNormal << endl;
    } else {
        cout << endl << "Para el arreglo con distribucion normal: ";
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << tiempo_transcurrido_normal << " milisegundos." << endl << endl;
    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
}