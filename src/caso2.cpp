#include "../include/caso2.h"



void Caso2(int ArregloLineal[], int ArregloNormal[],int Cantidad){
    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample"
    int m = 100;
    vector<int> sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    vector<int> sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];
    int b = Cantidad / m;

    // Búsqueda binaria Gap-coded lineal
    int indiceLineal,Tiempo_GapCoded_Lineal = busquedaBinariaGapCoding(GC_Lineal, sampleLineal, Cantidad, claveLineal, b);
    cout << "Para el arreglo Gap-Coded con distribucion lineal: ";
    if (indiceLineal != -1) {
        cout << "La clave " << claveLineal << " se encontro en el indice " << indiceLineal << endl;
    } else {
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << Tiempo_GapCoded_Lineal << " milisegundos." << endl;

   // Búsqueda binaria Gap-coded Normal
   int indiceNormal,Tiempo_GapCoded_Normal = busquedaBinariaGapCoding(GC_Normal, sampleNormal, Cantidad, claveNormal, b);
    cout << "Para el arreglo Gap-Coded con distribucion normal: ";
    if (indiceNormal != -1) {
        cout << "La clave " << claveNormal << " se encontro en el indice " << indiceNormal << endl;
    } else {
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl << endl ;
    }
    cout << "Tiempo transcurrido: " << Tiempo_GapCoded_Normal << " milisegundos." << endl;
    

    // Liberar la memoria asignada dinámicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
    delete[] GC_Lineal;
    delete[] GC_Normal;

}