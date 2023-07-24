# Proyecto3

# # Desarrollo:
    Este proyecto consiste en evaluar 3 situaciones distintas llamadas áreas, las cuales se basan en un tablero de puntaje con datos de entre 90000 a 
    100000,un 
    camino entre aldeas de entre 50000 a 70000 datos y un dibujo o renderizado de objetos de entre 500 a 1000 datos entre 15 categorias(15000 datos maximos).
    Estas areas son evaluadas en 7 distintos algoritmos de ordenamiento, donde dependiendo de una opcion escogida,estos algoritmos se encargaran de ordenar 
    los vectores de las areas, obteniendo distintos tiempos basados en la complejidad del algoritmos, los metodos de orden y las carreras.
    Finalmente, basados en el tiempo minimo de los algoritmos se encuentran y anuncian los ganadores de cada carrera.
    
# # Explicación de las funciones:
    1)Función generateRandomRaceRange: toma dos parámetros enteros: min y max. Su propósito es generar un número aleatorio dentro del rango especificado, 
    incluyendo tanto el valor mínimo como el máximo.
    
    2)Función generateCategoryRanges: toma tres parámetros enteros: numCategories, min, y max. Su propósito es generar un vector que contiene numCategories 
    elementos, donde cada elemento es un número aleatorio dentro del rango especificado [min, max], ambos límites incluidos.

    3)Función ascendingVector:toma dos parámetros: un vector de enteros por referencia vec y un entero size. Su propósito es llenar el vector vec con números 
    enteros en orden ascendente, comenzando desde 1 hasta el valor de size.

    4)Función descendingVector: toma dos parámetros: un vector de enteros por referencia vec y un entero size. Su propósito es llenar el vector vec con 
    números 
    enteros en orden descendente, comenzando desde el valor de size hasta 1.

    5)Función fullRandomVector: toma dos parámetros: un vector de enteros por referencia vec y un entero size. Su propósito es llenar el vector vec con 
    números enteros generados aleatoriamente en el rango [0, size]

    6)Función semiRandomVector: toma dos parámetros: un vector de enteros por referencia vec y un entero size. Su propósito es llenar el vector vec con 
    números enteros generados aleatoriamente de manera única, sin repetición, dentro del rango [1, size].

    7)Función bubbleSortAscendant : Esta función implementa el algoritmo de ordenación conocido como "Bubble Sort". Toma un vector de enteros por 
    referencia "vec" y ordena sus elementos en orden ascendente. El algoritmo compara elementos adyacentes en el vector y los intercambia si están en el 
    orden incorrecto, repitiendo este proceso hasta que todo el vector esté ordenado de menor a mayor.

    8)Función bubbleSortDescending : Similar a la función anterior, esta también implementa el algoritmo de ordenación "Bubble Sort". Igualmente, toma 
    un vector de enteros por referencia "vec", pero en este caso ordena sus elementos en orden descendente. El algoritmo compara elementos adyacentes en el 
    vector y los intercambia si están en el orden incorrecto, repitiendo este proceso hasta que todo el vector esté ordenado de mayor a menor. 

    9)Función heapifyAscendant : Esta función es parte del algoritmo de ordenación "Heap Sort" . Toma un vector de enteros por referencia "vec", un 
    entero "size" que representa el tamaño del subárbol o heap, y un entero "i" que representa la posición raíz del subárbol. Su propósito es mantener la 
    propiedad de "max-heap" en el subárbol con raíz en el índice "i". El "max-heap" es una estructura de datos donde cada nodo padre es mayor o igual a sus 
    hijos.

    10)Función heapSortAscendant : Esta función implementa el algoritmo de ordenación "Heap Sort" en C++ para ordenar el vector de enteros "vec" en orden     
    ascendente. Primero, crea un "max-heap" a partir del vector utilizando la función heapifyAscendant, y luego extrae repetidamente el máximo elemento (raíz 
    del "max-heap") y lo coloca al final del vector, reajustando el "max-heap" en cada paso.

    11)Función heapifyDescending : Esta función es similar a "heapifyAscendant", pero su propósito es mantener la propiedad de "min-heap" en el subárbol con 
    raíz en el índice "i". El "min-heap" es una estructura de datos donde cada nodo padre es menor o igual a sus hijos. 

    12)Función  heapSortDescending : Al igual que "heapSortAscendant", esta función implementa el algoritmo de ordenación "Heap Sort" en , pero en este 
    caso, ordena el vector de enteros "vec" en orden descendente. Primero, crea un "min-heap" a partir del vector utilizando la función heapifyDescending, y 
    luego extrae repetidamente el mínimo elemento (raíz del "min-heap") y lo coloca al final del vector, reajustando el "min-heap" en cada paso. 

    13)Función  swap : Esta función toma dos referencias a enteros "a" y "b" y tiene como objetivo intercambiar sus valores. Se utiliza para facilitar el 
    intercambio de elementos en los algoritmos de ordenación y partición.

    14)Función pivotPartitionAscendant : Esta función es parte del algoritmo de ordenación "Quick Sort" , específicamente para ordenar el vector de 
    enteros "vec" en orden ascendente. Toma el vector por referencia, y dos enteros "low" y "high" que representan los índices de la subsecuencia a ordenar. 
    Utiliza un elemento "pivot" para dividir la subsecuencia en dos partes, colocando los elementos menores al pivot en la parte izquierda y los mayores en 
    la parte derecha. Devuelve el índice del pivot después de la partición.

    15)Función quickSortAscendant : Esta función implementa el algoritmo de ordenación "Quick Sort" para ordenar el vector de enteros "vec" en orden 
    ascendente. Utiliza una pila para llevar a cabo la partición y ordenación de manera iterativa. Cada iteración selecciona un nuevo pivot y divide el 
    vector en dos subsecuencias más pequeñas, que son insertadas en la pila para futuras particiones hasta que el vector esté completamente ordenado.

    16)Función pivotPartitionDescending : Esta función es similar a "pivotPartitionAscendant", pero su objetivo es ordenar el vector de enteros "vec" en 
    orden descendente utilizando el algoritmo "Quick Sort". Toma el vector por referencia, y dos enteros "low" y "high" que representan los índices de la 
    subsecuencia a ordenar. Utiliza un elemento "pivot" para dividir la subsecuencia en dos partes, colocando los elementos mayores al pivot en la parte 
    izquierda y los menores en la parte derecha. Devuelve el índice del pivot después de la partición. 

    17)Función quickSortDescending : Similar a "quickSortAscendant", esta función implementa el algoritmo de ordenación "Quick Sort" , pero en este 
    caso, ordena el vector de enteros "vec" en orden descendente. Utiliza una pila para llevar a cabo la partición y ordenación de manera iterativa, 
    utilizando la función "pivotPartitionDescending" para realizar las particiones. El vector es dividido en subsecuencias más pequeñas hasta que esté 
    completamente ordenado.

    18)Función combineArraysAscendant : Esta función toma un vector de enteros por referencia "vec" y tres enteros "left", "mid", y "right". Su propósito es 
    combinar dos subarreglos ordenados en orden ascendente para formar un solo arreglo ordenado. La función utiliza los índices "left", "mid", y "right" 
    para identificar las posiciones iniciales y finales de los dos subarreglos. Los subarreglos deben estar ordenados previamente.

    19)Función mergeSortAscendant : Esta función implementa el algoritmo de ordenación "Merge Sort" para ordenar el vector de enteros "vec" en orden 
    ascendente. Divide recursivamente el vector en dos mitades hasta que se alcancen subarreglos de tamaño 1. Luego, combina los subarreglos ordenados 
    utilizando la función combineArraysAscendant para obtener el arreglo final ordenado.

    20)Función combineArraysDescending : Esta función es similar a "combineArraysAscendant", pero su objetivo es combinar dos subarreglos ordenados en orden 
    descendente para formar un solo arreglo ordenado en orden descendente. La función utiliza los índices "left", "mid", y "right" para identificar las 
    posiciones iniciales y finales de los dos subarreglos. Los subarreglos deben estar ordenados previamente.

    21)Función mergeSortDescending : Similar a "mergeSortAscendant", esta función implementa el algoritmo de ordenación "Merge Sort", pero en este 
    caso, ordena el vector de enteros "vec" en orden descendente. Divide recursivamente el vector en dos mitades hasta que se alcancen subarreglos de tamaño 
    1. Luego, combina los subarreglos ordenados utilizando la función combineArraysDescending para obtener el arreglo final ordenado en orden descendente

    22)Función selectionSort : Esta función implementa el algoritmo de ordenación "Selection Sort" , que ordena el vector de enteros "vec" en orden 
    ascendente. El algoritmo funciona encontrando el elemento más pequeño en cada iteración y lo intercambia con el elemento en la posición actual del 
    recorrido. A medida que avanza el recorrido, los elementos menores se van colocando en las primeras posiciones, lo que eventualmente resulta en un 
    vector ordenado.

    23)Función selectionSortDescending : Esta función es similar a "selectionSort", pero su objetivo es ordenar el vector de enteros "vec" en orden 
    descendente. El algoritmo "Selection Sort" modificado busca el elemento más grande en cada iteración y lo intercambia con el elemento en la posición 
    actual del recorrido. De esta manera, los elementos mayores se colocan en las primeras posiciones del vector, obteniendo finalmente un vector ordenado 
    en orden descendente

    24)Función insertionSortAscendant : Esta función implementa el algoritmo de ordenación "Insertion Sort", que ordena el vector de enteros "vec" en 
    orden ascendente. El algoritmo funciona recorriendo el vector desde el segundo elemento hasta el último. En cada iteración, el elemento actual se 
    compara con los elementos anteriores (ya ordenados) y se inserta en la posición correcta. Para ello, se realiza un desplazamiento hacia la derecha de 
    los elementos mayores que el elemento actual, hasta encontrar su posición adecuada.

    25)Función insertionSortDescending : Esta función es similar a "insertionSortAscendant", pero su objetivo es ordenar el vector de enteros "vec" en orden 
    descendente. El algoritmo "Insertion Sort" modificado recorre el vector desde el segundo elemento hasta el último. En cada iteración, el elemento actual 
    se compara con los elementos anteriores (ya ordenados) y se inserta en la posición correcta. Para ello, se realiza un desplazamiento hacia la derecha de 
    los elementos menores que el elemento actual, hasta encontrar su posición adecuada.

    26)Función shellSortAscendant : Esta función implementa el algoritmo de ordenación "Shell Sort" , que ordena el vector de enteros "vec" en orden 
    ascendente. El algoritmo utiliza la técnica de "gaps" o brechas para ordenar el vector de manera más eficiente que otros algoritmos de ordenación 
    cuadráticos. En cada iteración, el vector se divide en subgrupos y se aplican inserciones en los subgrupos utilizando el algoritmo de "Insertion Sort". 
    La brecha inicial es la mitad del tamaño del vector y se va reduciendo a la mitad en cada iteración hasta llegar a una brecha de tamaño 1, que 
    representa el último paso para ordenar el vector completamente.

    27)Función  shellSortDescending : Esta función es similar a "shellSortAscendant", pero su objetivo es ordenar el vector de enteros "vec" en orden 
    descendente. El algoritmo "Shell Sort" modificado utiliza la misma técnica de "gaps", pero en este caso, se aplica "Insertion Sort" para ordenar los 
    elementos en cada subgrupo de manera descendente.

    28)Función findMinTime: "findMinTime" toma siete nombres de algoritmos (name1, name2, ..., name7) y sus siete tiempos (time1, time2, ..., time7) 
    como parámetros y devuelve el tiempo mínimo registrado entre los algoritmos. Luego, muestra en pantalla al algoritmo ganador y su tiempo de carrera 
    mínimo.
   

# # Enlace del video:
    [VideoExplicativoProyectoUn3(https://drive.google.com/file/d/1gdmjZNNdXrR7wOSGitJHdEWurLVMdDxU/view?usp=drive_link)]



  
