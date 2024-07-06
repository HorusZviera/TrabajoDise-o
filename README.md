# TrabajoDise-o

Uso:
´´´bash
./main -n 100 -s 256
´´´
Donde:
- n: tamaño del arreglo a generar
- s: semilla usada para generar numeros aleatorios

--- Busqueda binaria se usa en los dos casos, talvez se puede optimizar creando una funcion aparte para evitar repeticion de codigo.

-- Gap-coded no funciona correctamente:
    Para el arreglo Gap-Coded con distribucion lineal: La clave 14878593 se encontro en el indice 0
    Tiempo transcurrido: 96874 milisegundos.

    Para el arreglo Gap-Coded con distribucion normal: La clave 15290028 se encontro en el indice 78
    Tiempo transcurrido: 96874 milisegundos.
queda corregir y comprobar que las funciones esten correctas

-- Arreglar tema de tiempo, da el tiempo en milisegundos, pero al transformarlas a segundo no tiene sentido el tiempo, porfavor comprobar.

-- Permitir que el usuario ingrese una semilla para los randoms "1,100,11000,123,144124"

-- Quizas la creacion de sample se pueda mejorar para un caso borde


-- Cambios (sabado por la noche)
--- Retorno de busqueda binaria, y en caso1 forma en que se recibe desde esa funcion
--- Primer numero aleatorio limitado entre 1 y 100 (cambiable a futuro)
-- Pide argumentos (tamaño de arreglo y semilla)
