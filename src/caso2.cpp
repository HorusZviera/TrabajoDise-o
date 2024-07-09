#include "../include/caso2.h"

void Caso2(int ArregloLineal[], int ArregloNormal[],int Cantidad,int m){
    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    // Crea gap coding
    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample" "Con m ingresado por el usuario"
    int* sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    int* sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    // Datos Busqueda binaria
    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];
    int b = Cantidad / m;

    // Busqueda binaria Gap-coded lineal
    auto resultadoLineal = busquedaBinariaGapCoding(GC_Lineal, sampleLineal, Cantidad, m, claveLineal, b);
    cout << "Para el arreglo Gap-Coded con distribucion lineal: ";
    if (resultadoLineal.first != -1) {
        cout << "La clave " << claveLineal << " se encontro en el indice " << resultadoLineal.first << endl;
    } else {
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoLineal.second << " Segundos." << endl << endl;

   // Busqueda binaria Gap-coded Normal
   auto resultadoNormal = busquedaBinariaGapCoding(GC_Normal, sampleNormal,Cantidad,m, claveNormal, b);
    cout << "Para el arreglo Gap-Coded con distribucion normal: ";
    if (resultadoNormal.first != -1) {
        cout << "La clave " << claveNormal << " se encontro en el indice " << resultadoNormal.first << endl;
    } else {
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl << endl ;
    }
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoNormal.second << " Segundos." << endl << endl;
    

    // Liberar la memoria asignada dinamicamente
    delete[] ArregloLineal;
    delete[] ArregloNormal;
    delete[] GC_Lineal;
    delete[] GC_Normal;

}


    /*
    cout<<"Lineal"<<endl;
    imprimirArreglo(ArregloLineal,Cantidad);
    imprimirArreglo(GC_Lineal,Cantidad);
    imprimirArreglo(sampleLineal, m);
    cout<<"####################"<<endl;
    
    cout<<"Normal"<<endl;
    imprimirArreglo(ArregloNormal,Cantidad);
    imprimirArreglo(GC_Normal,Cantidad);
    imprimirArreglo(sampleNormal, m);
    cout<<endl;
    
    */