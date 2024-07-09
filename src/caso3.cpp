#include "../include/caso3.h"  // Se incluye el archivo de encabezado caso3.h

// Funcion para construir el arbol de Huffman
Nodo* construirArbolHuffman(const unordered_map<int, unsigned>& mapaFrecuencias) {
   priority_queue<Nodo*,vector<Nodo*>, CompararNodos> colaPrioridad;

    // Crear un nodo hoja para cada valor único y agregarlo a la cola de prioridad
    for (const auto& par : mapaFrecuencias) {
        colaPrioridad.push(new Nodo(par.first, par.second));
    }

    // Construir el arbol de Huffman fusionando nodos de la cola de prioridad
    while (colaPrioridad.size() > 1) {
        Nodo* izquierdo = colaPrioridad.top();
        colaPrioridad.pop();
        Nodo* derecho = colaPrioridad.top();
        colaPrioridad.pop();

        Nodo* nuevoNodo = new Nodo(-1, izquierdo->frecuencia + derecho->frecuencia);
        nuevoNodo->izquierdo = izquierdo;
        nuevoNodo->derecho = derecho;

        colaPrioridad.push(nuevoNodo);
    }

    return colaPrioridad.top();
}

// Funcion para generar codigos Huffman para cada valor en el arbol de Huffman
void generarCodigosHuffman(Nodo* raiz,unordered_map<int,string>& codigos,string codigo = "") {
    if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
        codigos[raiz->valor] = codigo;
        return;
    }

    generarCodigosHuffman(raiz->izquierdo, codigos, codigo + "0");
    generarCodigosHuffman(raiz->derecho, codigos, codigo + "1");
}


void Caso3(int ArregloLineal[], int ArregloNormal[], int Cantidad, int m) {

    int* GC_Lineal = new int[Cantidad]; //Arreglo Gap-Coded Lineal
    int* GC_Normal = new int[Cantidad]; //Arreglo Gap-Coded Normal

    int claveLineal = ArregloLineal[rand() % Cantidad];
    int claveNormal = ArregloNormal[rand() % Cantidad];
    int b = Cantidad / m;

    bitset<8>* GC_Lineal_Comprimido = new bitset<8>[Cantidad];
    bitset<8>* GC_Normal_Comprimido = new bitset<8>[Cantidad];

    // Crea gap coding
    crearGapCoding(ArregloLineal, GC_Lineal, Cantidad);
    crearGapCoding(ArregloNormal, GC_Normal, Cantidad);

    //Estructura "Sample" "Con m ingresado por el usuario"
    int* sampleLineal = crearSample(ArregloLineal, Cantidad, m);
    int* sampleNormal = crearSample(ArregloNormal, Cantidad, m);

    //-----------------------------------------------------------------------------------------------------------
    // Calcula Frecuencia en los arreglos
    unordered_map<int, unsigned> mapaFrecuenciasLineal;
    unordered_map<int, unsigned> mapaFrecuenciasNormal;
    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuenciasLineal[GC_Lineal[i]]++; 
    }

    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuenciasNormal[GC_Normal[i]]++; 
    }
    //-----------------------------------------------------------------------------------------------------------
    // Construir el arbol de Huffman
    Nodo* raiz_Lineal = construirArbolHuffman(mapaFrecuenciasLineal);
    //cout<<"pasooooooooooooooo"<<endl;
    Nodo* raiz_Normal = construirArbolHuffman(mapaFrecuenciasNormal);

    
    //-----------------------------------------------------------------------------------------------------------
    // Generar codigos Huffman para cada valor en el arbol de Huffman
    unordered_map<int,string> codigosHuffmanLineal;
    generarCodigosHuffman(raiz_Lineal, codigosHuffmanLineal); 
    
    unordered_map<int,string> codigosHuffmanNormal;
    generarCodigosHuffman(raiz_Normal, codigosHuffmanNormal); 


    //-----------------------------------------------------------------------------------------------------------
    //Convertir a Binario
    for(int i=0;i<Cantidad;i++) {
        //cout<<codigosHuffmanLineal[GC_Lineal[i]]<<" "<<convertirABinario(codigosHuffmanLineal[GC_Lineal[i]])<<" "<<GC_Lineal[i]<<endl;
        GC_Lineal_Comprimido[i] = convertirABinario(codigosHuffmanLineal[GC_Lineal[i]]);
    }

    for(int i=0;i<Cantidad;i++) {
       //cout<<codigosHuffmanLineal[GC_Lineal[i]]<<" "<<convertirABinario(codigosHuffmanLineal[GC_Lineal[i]]) <<" "<<GC_Lineal[i]<<endl;
        GC_Normal_Comprimido[i] = convertirABinario(codigosHuffmanLineal[GC_Normal[i]]);
    }

    //-----------------------------------------------------------------------------------------------------------
    //  Busqueda Binaria
    auto resultadoLineal = busquedaBinariaHuffman(raiz_Lineal, &GC_Lineal_Comprimido, GC_Lineal, sampleLineal, Cantidad, m, claveLineal, b);
    cout << "Para el arreglo Gap-Coded con distribucion lineal: ";
    if (resultadoLineal.first != -1) {
        cout << "La clave " << claveLineal << " se encontro en el indice " << resultadoLineal.first << endl;
    } else {
        cout << "La clave " << claveLineal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoLineal.second << " Segundos." << endl << endl;


    auto resultadoNormal = busquedaBinariaHuffman(raiz_Normal, &GC_Normal_Comprimido, GC_Normal, sampleNormal, Cantidad, m, claveNormal, b);
    cout << "Para el arreglo Gap-Coded con distribucion Normal: ";
    if (resultadoLineal.first != -1) {
        cout << "La clave " << claveNormal << " se encontro en el indice " << resultadoNormal.first << endl;
    } else {
        cout << "La clave " << claveNormal << " no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo transcurrido: " << fixed << setprecision(10) << resultadoNormal.second << " Segundos." << endl << endl;
    
    cout<<"####################"<<endl;


    //-----------------------------------------------------------------------------------------------------------
    // Test
    cout<<"Lineal(Arreglo,GAP,Sample,Huffman)"<<endl;
    cout << "Arreglo Original: ";
    imprimirArreglo(ArregloLineal,Cantidad);
    cout << "Arreglo GAP: ";
    imprimirArreglo(GC_Lineal,Cantidad);
    cout << "Arreglo Sample: ";
    imprimirArreglo(sampleLineal, m);
    cout<< endl << "####################"<<endl;
    
    /*
    cout << "Codigos Huffman Arreglo Lineal:" << endl;
    for (const auto& par : codigosHuffmanLineal) {
        cout << par.first << ": " << par.second << endl;
    }
    cout << endl << endl << endl ;
    */
    //imprimirArbolHuffman(raiz_Lineal);


    

    cout<<"Normal(Arreglo,GAP,Sample,Huffman)"<<endl;
    cout << "Arreglo Original: ";
    imprimirArreglo(ArregloNormal,Cantidad);
    cout << "Arreglo GAP: ";
    imprimirArreglo(GC_Normal,Cantidad);
    cout << "Arreglo Sample: ";
    imprimirArreglo(sampleNormal, m);
    cout<< endl << "####################"<<endl;




    //imprimirArreglo(GC_Lineal_Comprimido,Cantidad);
    //imprimirArbolHuffman(raiz_Normal);






















    /*
    // Codificacion Arreglo Normal
    unordered_map<int, unsigned> mapaFrecuenciasNormal;
    for (int i = 0; i < Cantidad; i++) {
        mapaFrecuenciasNormal[ArregloNormal[i]]++; // Calcular la frecuencia de cada valor en el arreglo Normal
    }

    Nodo* raiz_Normal = construirArbolHuffman(mapaFrecuenciasNormal); // Construir el arbol de Huffman

    unordered_map<int,string> codigosHuffmanNormal; 
    generarCodigosHuffman(raiz_Normal, codigosHuffmanNormal); // Generar codigos Huffman para cada valor en el arbol de Huffman
    
    cout << "Codigos Huffman Arreglo Normal:" << endl; // Imprimir los codigos Huffman generados
    for (const auto& par : codigosHuffmanNormal) {
        cout << par.first << ": " << par.second << endl;
    }
    cout << endl << endl << endl;
    */
    
}






