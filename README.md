# TrabajoDise-o

Uso:
´´´bash
./main -n 100 -s 256
´´´
Donde:
- n: tamaño del arreglo a generar
- s: semilla usada para generar numeros aleatorios


Cambios (sabado por la noche)

-- CASO 3 NO ESTA TERMINADO!!!!!!!!!!!!!!1

-- reciclar busqueda binaria en una funcion (caso 2)
-- Ir limpiando los comentarios y los codigos de prueba


Para el informe

--la busqueda binaria demora O(logn), donde 𝑛 es el número de elementos en el arreglo.









# Proyecto de Comparacion de Búsqueda Binaria con distintos tipos de arreglos

Este proyecto implementa un programa en C++ que demuestra diferentes casos de uso de la búsqueda binaria en arreglos de datos. Utiliza distintas técnicas de codificación y estructuras de datos para optimizar la búsqueda y el almacenamiento de los datos.

## Características

- **Caso 1**: Búsqueda en un arreglo explícito.
- **Caso 2**: Búsqueda en un arreglo utilizando Gap-Coding.
- **Caso 3**: Búsqueda en un arreglo utilizando Codificación de Huffman.
- **Argumentos de línea de comando**: Permite especificar el tamaño del arreglo y la semilla para la generación de números aleatorios.

## Requisitos Previos

Para compilar y ejecutar este proyecto, necesitarás:

- Un compilador de C++, como GCC.
- Make (opcional, para automatizar la compilación).


## Explicacion funciones pequeñas

1. **busquedaBinaria**
Realizar una búsqueda binaria estándar en un arreglo de enteros.
- Parámetros:
    - A[]: Arreglo de enteros en el que se busca.
    - n: Tamaño del arreglo.
    - clave: Valor entero que se busca en el arreglo.
- Funcionamiento:
    - Mide el tiempo al inicio de la búsqueda.
    - Utiliza un bucle while para dividir el rango de búsqueda a la mitad en cada iteración, ajustando los índices inicio y fin según si el valor medio es menor o mayor que la clave.
    - Si encuentra la clave, detiene el tiempo, calcula la duración de la búsqueda y devuelve el índice donde se encontró la clave junto con el tiempo que tomó encontrarla.
    - Si la clave no se encuentra en el arreglo, devuelve -1 y el tiempo que tomó realizar la búsqueda.

2. **busquedaBinariaGapCoding**
Realizar una búsqueda binaria en un arreglo que ha sido codificado usando Gap Coding, utilizando una estructura de muestreo para optimizar la búsqueda.
- **Parámetros**:
    - GC[]: Arreglo codificado por brechas.
    - sample[]: Arreglo de muestreo utilizado para acelerar la búsqueda.
    - n: Tamaño del arreglo de muestreo.
    - clave: Valor entero que se busca.
    - b: Tamaño del bloque de muestreo.
- **Funcionamiento**:
    - Mide el tiempo al inicio de la búsqueda.
    - Realiza una búsqueda binaria en el arreglo de muestreo para encontrar un intervalo aproximado donde podría encontrarse la clave.
    - Utiliza una búsqueda lineal y la función reconstruirValor para encontrar el valor exacto de la clave en el arreglo codificado por brechas, ajustando el índice según sea necesario.
    - Detiene el tiempo, calcula la duración de la búsqueda y devuelve el índice donde se encontró la clave (ajustado a partir del muestreo) junto con el tiempo que tomó encontrarla.

3. **reconstruirValor**
Reconstruir el valor original de un elemento en un arreglo codificado por brechas, utilizando un arreglo de muestreo.
- **Parámetros**:
    - GC[]: Arreglo codificado por brechas.
    - sample[]: Arreglo de muestreo.
    - index: Índice del elemento en el arreglo codificado por brechas.
    - b: Tamaño del bloque de muestreo.
- **Funcionamiento**:
    - Calcula el valor original del elemento en el índice dado, sumando los valores de brecha desde el inicio del bloque de muestreo hasta el índice.
    - Este código es útil para realizar búsquedas eficientes en arreglos grandes, especialmente cuando están codificados para ahorrar espacio o acelerar operaciones de búsqueda mediante la técnica de codificación de brechas y el uso de estructuras de muestreo.












## Caso 1

- **Recibe dos arreglos y una cantidad**: ArregloLineal[] y ArregloNormal[] son dos arreglos de enteros, y Cantidad es un entero que indica el tamaño de estos arreglos.

- **Selecciona claves aleatorias**: Selecciona un elemento aleatorio de cada arreglo para ser la clave de búsqueda. Esto se hace utilizando rand() % Cantidad, lo que garantiza que el índice seleccionado esté dentro del rango válido de los arreglos.

- **Realiza una búsqueda binaria en ambos arreglos**: Llama a busquedaBinaria para cada arreglo, pasando el arreglo, su tamaño (Cantidad), y la clave seleccionada. La función busquedaBinaria probablemente devuelve un par, donde el primer elemento es el índice de la clave en el arreglo (o -1 si no se encuentra) y el segundo elemento es el tiempo que tomó la búsqueda.

- **Imprime los resultados de la búsqueda**: Para cada arreglo, imprime si la clave fue encontrada o no, y en caso afirmativo, en qué índice. También imprime el tiempo que tomó cada búsqueda, formateado a 10 decimales.

- **Libera la memoria asignada dinámicamente**: Al final, libera la memoria de los arreglos ArregloLineal y ArregloNormal utilizando delete[].

## Caso 2

- **Recibe dos arreglos una cantidad y un tamaño para el sample**: 
ArregloLineal[]: Un arreglo de enteros con distribución lineal.
ArregloNormal[]: Un arreglo de enteros con distribución normal.
Cantidad: El tamaño de los arreglos.
m: Un valor entero proporcionado por el usuario que se utiliza para crear estructuras de muestreo (samples) y afecta la búsqueda binaria.

- **Inicialización de Arreglos Gap-Coded**: La función comienza creando dos arreglos dinámicos, GC_Lineal y GC_Normal, que almacenarán las versiones codificadas por brechas de los arreglos originales ArregloLineal y ArregloNormal, respectivamente. La codificación de brechas es una técnica de compresión de datos que representa las diferencias entre valores consecutivos en lugar de los valores mismos, lo cual puede ser útil para optimizar búsquedas en ciertos contextos.

- **Codificación de Brechas**: Utiliza la función crearGapCoding para transformar los arreglos originales en sus versiones codificadas por brechas, almacenándolas en GC_Lineal y GC_Normal.

- **Creación de Estructuras de Muestreo**: Genera estructuras de muestreo (sampleLineal y sampleNormal) para los arreglos originales utilizando la función crearSample. Estas estructuras de muestreo se utilizan para acelerar la búsqueda binaria, especialmente en arreglos grandes, al reducir el número de comparaciones necesarias.

- **Selección de Claves para la Búsqueda**: Selecciona aleatoriamente una clave de búsqueda de cada uno de los arreglos originales. Estas claves se buscarán posteriormente en los arreglos codificados por brechas para medir el rendimiento de la búsqueda.

- **Búsqueda Binaria en Arreglos Gap-Coded**: Realiza una búsqueda binaria en los arreglos codificados por brechas (GC_Lineal y GC_Normal) para encontrar las claves seleccionadas. La función busquedaBinariaGapCoding devuelve un par que contiene el índice de la clave (si se encuentra) y el tiempo transcurrido durante la búsqueda. Los resultados de la búsqueda, incluyendo si la clave fue encontrada y el tiempo que tomó encontrarla, se imprimen en la consola.

- **Liberación de Memoria**: Finalmente, la función libera la memoria asignada dinámicamente para los arreglos GC_Lineal, GC_Normal, sampleLineal, y sampleNormal, así como para los arreglos originales ArregloLineal y ArregloNormal, utilizando delete[].
