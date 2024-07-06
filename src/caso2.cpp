#include "../include/caso2.h"

void Caso2(int ArregloLineal[], int ArregloNormal[],int Cantidad){
    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    // Crea gap coding
    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample"
    int m = 4; // ---------------------------------------------------------------> pedir al usuario
    vector<int> sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    vector<int> sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    cout<<"Lineal"<<endl;
    imprimirArreglo(ArregloLineal,Cantidad);
    imprimirArreglo(GC_Lineal,Cantidad);
    imprimirVector(sampleLineal);
    cout<<"####################"<<endl;
    
    cout<<"Normal"<<endl;
    imprimirArreglo(ArregloNormal,Cantidad);
    imprimirArreglo(GC_Normal,Cantidad);
    imprimirVector(sampleNormal);
    cout<<endl;

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];
    int b = Cantidad / m;


    // Búsqueda binaria Gap-coded lineal
    auto resultadoLineal = busquedaBinariaGapCoding(GC_Lineal, sampleLineal, m, claveLineal, b);
    cout << "Para el arreglo Gap-Coded con distribucion lineal: ";
    if (resultadoLineal.first != -1) {
        cout << "La clave " << claveLineal << " se encontro en el indice " << resultadoLineal.first << endl;
    } else {
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << resultadoLineal.second << " milisegundos." << endl;


   // Búsqueda binaria Gap-coded Normal
   auto resultadoNormal = busquedaBinariaGapCoding(GC_Normal, sampleNormal, m, claveNormal, b);
    cout << "Para el arreglo Gap-Coded con distribucion normal: ";
    if (resultadoNormal.first != -1) {
        cout << "La clave " << claveNormal << " se encontro en el indice " << resultadoNormal.first << endl;
    } else {
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl << endl ;
    }
    cout << "Tiempo transcurrido: " << resultadoNormal.second << " milisegundos." << endl;
    

    // Liberar la memoria asignada dinámicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
    delete[] GC_Lineal;
    delete[] GC_Normal;

}