#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <cstdlib>

using namespace std;

// Función que genera el rango de las carreras en general, permitiendo cambiar dentro del main las variables min y max dependiendo del tipo de carrera
int generateRandomRaceRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Función que genera el rango del area 3, ya que para obtener un resultado más cercano a la realidad, dando distintos valores para las 15 categorias
vector<int> generateCategoryRanges(int numCategories, int min, int max)
{
    vector<int> ranges;
    int i, range;
    for (i = 0; i < numCategories; ++i)
    {
        range = min + rand() % (max - min + 1);
        ranges.push_back(range);
    }

    return ranges;
}

// Función que llena un vector de manera ascendente hasta el tamaño especificado
void ascendingVector(vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        vec.push_back(i + 1);
    }
}

// Función que llena un vector de manera descendente hasta el tamaño especificado
void descendingVector(vector<int> &vec, int size)
{
    for (int i = size; i > 0; i--)
    {
        vec.push_back(i);
    }
}

// Función que llena un vector de manera completamente aleatoria hasta el tamaño especificado
void fullRandomVector(vector<int> &vec, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % (size + 1));
    }
}

// Función que llena un vector de manera aleatoria hasta el tamaño especificado (sin números duplicados)
void semiRandomVector(vector<int> &vec, int size)
{
    srand(time(NULL));
    vector<int> allNumbers(size);

    for (int i = 0; i < size; i++)
    {
        allNumbers[i] = i + 1;
    }

    for (int i = 0; i < size; i++)
    {
        int index = rand() % (size - i);
        vec.push_back(allNumbers[index]);
        allNumbers[index] = allNumbers[size - i - 1];
    }
}

// ------------------------------algoritmos de ordenamiento------------------------------//

// Bubble Sort:
/*
Este recorre el arreglo comparando elementos vecinos y los intercambia si están en el orden incorrecto.En cada pasada, 
el elemento más grande (ascendente) o más pequeño (descendente) se mueve  hacia su posición final. 
*/

void bubbleSortAscendant(vector<int> &vec)
{
    int i, j, temp;
    for (i = 0; i < vec.size() - 1; i++)
    {
        for (j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(vector<int> &vec)
{
    int i, j, temp;
    for (i = 0; i < vec.size() - 1; i++)
    {
        for (j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] < vec[j + 1])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// Heap Sort:
/*
En este se construye un heap(montículo) ascendente o descendente a partir del arreglo y luego se extraen los elementos uno a uno para obtener el 
arreglo ordenado de manera ascendente o descendente.
*/

void heapifyAscendant(vector<int> &vec, int size, int i)
{
    int right = (2 * i) + 2;
    int left = (2 * i) + 1;
    int max = i;
    int temp;

    if (left < size && vec[left] > vec[max])
    {
        max = left;
    }

    if (right < size && vec[right] > vec[max])
    {
        max = right;
    }

    if (max != i)
    {
        temp = vec[i];
        vec[i] = vec[max];
        vec[max] = temp;

        heapifyAscendant(vec, size, max);
    }
}

void heapSortAscendant(vector<int> &vec)
{
    int i, temp;

    for (i = vec.size() / 2 - 1; i >= 0; i--)
    {
        heapifyAscendant(vec, vec.size(), i);
    }

    for (int i = vec.size() - 1; i > 0; i--)
    {
        temp = vec[0];
        vec[0] = vec[i];
        vec[i] = temp;

        heapifyAscendant(vec, i, 0);
    }
}

void heapifyDescending(vector<int> &vec, int size, int i)
{
    int right = (2 * i) + 2;
    int left = (2 * i) + 1;
    int min = i;
    int temp;

    if (left < size && vec[left] < vec[min])
    {
        min = left;
    }

    if (right < size && vec[right] < vec[min])
    {
        min = right;
    }

    if (min != i)
    {
        temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;

        heapifyDescending(vec, size, min);
    }
}

void heapSortDescending(vector<int> &vec)
{
    int i, temp;

    for (int i = vec.size() / 2 - 1; i >= 0; i--)
    {
        heapifyDescending(vec, vec.size(), i);
    }

    for (int i = vec.size() - 1; i > 0; i--)
    {
        temp = vec[0];
        vec[0] = vec[i];
        vec[i] = temp;

        heapifyDescending(vec, i, 0);
    }
}

// Quick Sort:
/*
Este selecciona un elemento (pivote) y reorganiza los elementos en dos grupos, uno con valores menores que el pivote y otro con valores mayores. 
Luego, se aplica el mismo proceso a cada grupo(el dicho anteriormente) hasta que el arreglo esté completamente ordenado, ya sea en orden ascendente o descendente.
*/

int pivotPartitionAscendant(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (vec[j] < pivot)
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
        }
    }

    temp = vec[i];
    vec[i] = vec[high];
    vec[high] = temp;

    return i;
}

void quickSortAscendant(vector<int> &vec, int low, int high)
{
    int pivotIndex;

    if (low < high)
    {
        pivotIndex = pivotPartitionAscendant(vec, low, high);

        quickSortAscendant(vec, low, pivotIndex - 1);
        quickSortAscendant(vec, pivotIndex + 1, high);
    }
}

int pivotPartitionDescending(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (vec[j] > pivot)
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
        }
    }

    temp = vec[i];
    vec[i] = vec[high];
    vec[high] = temp;

    return i;
}

void quickSortDescending(vector<int> &vec, int low, int high)
{
    int pivotIndex;

    if (low < high)
    {
        pivotIndex = pivotPartitionDescending(vec, low, high);

        quickSortDescending(vec, low, pivotIndex - 1);
        quickSortDescending(vec, pivotIndex + 1, high);
    }
}

// Merge Sort:
/*
Este divide repetidamente el arreglo en dos mitades, ordena cada mitad usando recursividad, 
y luego combina las dos mitades ordenadas para obtener el arreglo completo, ya sea en orden ascendente o descendente
*/

void combineArraysAscendant(vector<int> &vec, int left, int mid, int right)
{
    int i, j, k;

    int RArrSize = right - mid;
    vector<int> RightArr(RArrSize);

    int LArrSize = mid - left + 1;
    vector<int> LeftArr(LArrSize);

    for (i = 0; i < LArrSize; i++)
    {
        LeftArr[i] = vec[left + i];
    }
    for (j = 0; j < RArrSize; j++)
    {
        RightArr[j] = vec[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < LArrSize && j < RArrSize)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            vec[k] = LeftArr[i];
            i++;
        }
        else
        {
            vec[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < LArrSize)
    {
        vec[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < RArrSize)
    {
        vec[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSortAscendant(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortAscendant(vec, left, mid);
        mergeSortAscendant(vec, mid + 1, right);

        combineArraysAscendant(vec, left, mid, right);
    }
}

void combineArraysDescending(vector<int> &vec, int left, int mid, int right)
{
    int i, j, k;

    int RArrSize = right - mid;
    vector<int> RightArr(RArrSize);

    int LArrSize = mid - left + 1;
    vector<int> LeftArr(LArrSize);

    for (i = 0; i < LArrSize; i++)
    {
        LeftArr[i] = vec[left + i];
    }
    for (j = 0; j < RArrSize; j++)
    {
        RightArr[j] = vec[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < LArrSize && j < RArrSize)
    {
        if (LeftArr[i] >= RightArr[j])
        {
            vec[k] = LeftArr[i];
            i++;
        }
        else
        {
            vec[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < LArrSize)
    {
        vec[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < RArrSize)
    {
        vec[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSortDescending(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortDescending(vec, left, mid);
        mergeSortDescending(vec, mid + 1, right);

        combineArraysDescending(vec, left, mid, right);
    }
}

// Selection Sort:
/*
Este encuentra(selecciona) repetidamente el elemento mínimo (o máximo, dependiendo del orden) del arreglo y lo coloca en su posición correcta. 
Luego se repite este proceso para el resto de los elementos hasta obtener el arreglo completamente ordenado.
*/
void selectionSort(vector<int> &vec)
{
    int i, j, minIndex, temp;

    for (i = 0; i < vec.size() - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = temp;
    }
}

void selectionSortDescending(vector<int> &vec)
{
    int i, j, maxIndex, temp;

    for (i = 0; i < vec.size() - 1; i++)
    {
        maxIndex = i;
        for (j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] > vec[maxIndex])
            {
                maxIndex = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[maxIndex];
        vec[maxIndex] = temp;
    }
}

// Insertion Sort:
/*
Este construye una parte ordenada del arreglo al insertar cada elemento en su posición correcta dentro de esa sección ordenada. 
Luego se repite este proceso para todos los elementos hasta obtener el arreglo completamente ordenado.
*/

void insertionSortAscendant(vector<int> &vec)
{
    int i, j, current;

    for (i = 1; i < vec.size(); i++)
    {
    	
        current = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > current)
        {
        	
            vec[j + 1] = vec[j];
            j--;
        }
        
        vec[j + 1] = current;
    }
}

void insertionSortDescending(vector<int> &vec)
{
    int i, j, current;

    for (i = 1; i < vec.size(); i++)
    {
        current = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] < current)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = current;
    }
}

// Shell Sort:
/*
Este utiliza una secuencia de intervalos para comparar y mover elementos hacia su posición final. 
A medida que los intervalos disminuyen, el arreglo se va ordenando en pequeños grupos hasta obtener un arreglo completamente ordenado.
*/

void shellSortAscendant(vector<int> &vec)
{
    int i, j, gap, temp;

    for (gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < vec.size(); i++)
        {
            temp = vec[i];

            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

void shellSortDescending(vector<int> &vec)
{
    int i, j, gap, temp;

    for (gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < vec.size(); i++)
        {
            temp = vec[i];

            for (j = i; j >= gap && vec[j - gap] < temp; j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}



int main()
{
    srand(time(NULL));

    int Option, Order, range1, range2, range3;
    vector<int> CategoryRange3;

    vector<int> tableOfScoresSemiRandom;
    vector<int> tableOfScoresFullRandom;
    vector<int> tableOfScoresOrder;
    vector<int> tableOfScoresDisorder;

    vector<int> villagesRoadsSemiRandom;
    vector<int> villagesRoadsFullRandom;
    vector<int> villagesRoadsOrder;
    vector<int> villagesRoadsDisorder;

    vector<int> drawingSemiRandom;
    vector<int> drawingFullRandom;
    vector<int> drawingOrder;
    vector<int> drawingDisorder;

    cout << "Bienvenido a la carrera de algoritmos" << endl<< endl;

    cout << "Ingresa la manera en la que deseas que estos algoritmos ordenen:" << endl
         << "1)Ascendente " << endl
         << "2)Descendente" << endl;
    cin >> Order;
    while (Order != 1 && Order != 2)
    {
        cout << "La opcion ingresada no es valida, por favor ingrese la opcion correcta: " << endl
             << "1)Ascendente " << endl
             << "2)Descendente" << endl;
        cin >> Order;
    }
    if (Order == 1)
    {
        cout << "La opcion escogida fue: orden ascendente" << endl<< endl;
    }
    else if (Order == 2)
    {
        cout << "La opcion escogida fue: orden descendente" << endl<< endl;
    }

    cout << "Estas son las areas sobre las cuales estaran basadas las distintas carreras:" << endl<< endl;
    cout << "\tA)Tablero de puntajes: esta tendra de 9000 a 10000 datos" << endl
         << "\tB)Determinacion de camino entre aldeas: esta tendra de 5000 a 7000 datos" << endl
         << "\tC)Dibujo o renderizado de objetos: Esta tendra de 50 a 100 datos repartidos en 15 categorias(1500 datos maximos)" << endl;

    cout << "Ahora comenzara el sorteo de elementos para cada categoria" << endl<< endl;

    range1 = generateRandomRaceRange(9000, 10000);
    cout << "A)Tablero de puntajes: " << range1 << " datos" << endl<< endl;

    range2 = generateRandomRaceRange(5000, 7000);
    cout << "B)Determinacion de camino entre aldeas: " << range2 << " datos" << endl<< endl;

    vector<int> categoryRanges = generateCategoryRanges(15, 50, 100);

    for (int range : categoryRanges)
    {
        range3 += range;
    }

    cout << "C)Dibujo o renderizado de objetos: " << range3 << " datos" << endl<< endl;

    cout << "Ahora llenaremos los vectores de estas areas basados en las siguientes condiciones" << endl<< endl;
    cout << "\t1)Set de datos aleatorios(sin elementos duplicados)" << endl
         << "\t2)Set de datos aleatorios duplicados(con posibilidad de elementos duplicados)" << endl
         << "\t3)Set de datos ordenado(basado en la opcion inicialmente escogida)" << endl
         << "\t4)Set de datos inversamente ordenado(el contrario de lo inicialmente escogido)" << endl
         << endl;

    if (Order == 1)
    {

        cout << "Llenando vectores del area : Tablero de puntajes" << endl<< endl;

        semiRandomVector(tableOfScoresSemiRandom, range1); //Set de datos aleatorios
        fullRandomVector(tableOfScoresFullRandom, range1); //Set de datos aleatorios duplicados
        ascendingVector(tableOfScoresOrder, range1);      //Set de datos ordenados
        descendingVector(tableOfScoresDisorder, range1);  //Set de datos inversamente ordenados

        cout << "Llenando vectores del area : Determinacion de camino entre aldeas" << endl<< endl;

        semiRandomVector(villagesRoadsSemiRandom, range2); //Set de datos aleatorios
        fullRandomVector(villagesRoadsFullRandom, range2); //Set de datos aleatorios duplicados
        ascendingVector(villagesRoadsOrder, range2);      //Set de datos ordenados
        descendingVector(villagesRoadsDisorder, range2);  //Set de datos inversamente ordenados

        cout << "Llenando vectores del area : Dibujo o renderizado de objetos" << endl<< endl;

        semiRandomVector(drawingSemiRandom, range3); //Set de datos aleatorios
        fullRandomVector(drawingFullRandom, range3); //Set de datos aleatorios duplicados
        ascendingVector(drawingOrder, range3);      //Set de datos ordenados
        descendingVector(drawingDisorder, range3);  //Set de datos inversamente ordenados

        cout << "Todos los vectores han sido llenados correctamente!!" << endl<< endl;

        cout << "Ahora vamos a poner a prueba los vectores en los siguientes algoritmos: " << endl<< endl;
             
        cout << "\t1)Bubble sort" << endl
             << "\t2)Heap sort" << endl
             << "\t3)Quick sort" << endl
             << "\t4)Merge sort" << endl
             << "\t5)Selection sort" << endl
             << "\t6)Insertion sort" << endl
             << "\t7)Shell sort" << endl << endl;
    	
    	cout << "QUE COMIENCEN LAS CARRERAS!!!" << endl << endl;
    	
    	cout << "\t\t\t1)Carreras por tablero" << endl << endl;
    	
    	cout << "A)Carrera por tablero : Modo aleatorio sin duplicados" << endl << endl;
    	
	    auto startTime1A = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresSemiRandom);
	    auto endTime1A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1A = endTime1A - startTime1A;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1A.count() << " segundos" << endl;
	    
	    auto startTime2A = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresSemiRandom);
	    auto endTime2A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2A = endTime2A - startTime2A;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2A.count() << " segundos" << endl;
	    
	    auto startTime3A = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresSemiRandom, 0, tableOfScoresSemiRandom.size() - 1);
		auto endTime3A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3A = endTime3A - startTime3A;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3A.count() << " segundos" << endl;
	    
	    auto startTime4A = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresSemiRandom, 0, tableOfScoresSemiRandom.size() - 1);
		auto endTime4A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4A = endTime4A - startTime4A;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4A.count() << " segundos" << endl;
	    
	    auto startTime5A = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresSemiRandom);
	    auto endTime5A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5A = endTime5A - startTime5A;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5A.count() << " segundos" << endl;
	    
	    auto startTime6A = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresSemiRandom);
	    auto endTime6A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6A = endTime6A - startTime6A;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6A.count() << " segundos" << endl;
	    
	    auto startTime7A = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresSemiRandom);
	    auto endTime7A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7A = endTime7A - startTime7A;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7A.count() << " segundos" << endl;
		
		cout << endl<<endl;
	    
	           	
    	cout << "B)Carrera por tablero : Modo aleatorio con posibilidad de  duplicados" << endl << endl;
    	
    	auto startTime1B = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresFullRandom);
	    auto endTime1B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1B = endTime1B - startTime1B;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1B.count() << " segundos" << endl;
	    
	    auto startTime2B = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresFullRandom);
	    auto endTime2B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2B = endTime2B - startTime2B;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2B.count() << " segundos" << endl;
	    
	    auto startTime3B = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresFullRandom, 0, tableOfScoresFullRandom.size() - 1);
		auto endTime3B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3B = endTime3B - startTime3B;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3B.count() << " segundos" << endl;
	    
	    auto startTime4B = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresFullRandom, 0, tableOfScoresFullRandom.size() - 1);
		auto endTime4B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4B = endTime4B - startTime4B;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4B.count() << " segundos" << endl;
	    
	    auto startTime5B = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresFullRandom);
	    auto endTime5B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5B = endTime5B - startTime5B;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5B.count() << " segundos" << endl;
	    
	    auto startTime6B = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresFullRandom);
	    auto endTime6B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6B = endTime6B - startTime6B;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6B.count() << " segundos" << endl;
	    
	    auto startTime7B = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresFullRandom);
	    auto endTime7B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7B = endTime7B - startTime7B;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7B.count() << " segundos" << endl;
    	
    	cout << endl<<endl;
    	
    	cout << "C)Carrera por tablero : Modo ordenado" << endl << endl;
    	
    	auto startTime1C = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresOrder);
	    auto endTime1C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1C = endTime1C - startTime1C;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1C.count() << " segundos" << endl;
	    
	    auto startTime2C = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresOrder);
	    auto endTime2C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2C = endTime2C - startTime2C;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2C.count() << " segundos" << endl;
	    
	    auto startTime3C = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresOrder, 0, tableOfScoresOrder.size() - 1);
		auto endTime3C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3C = endTime3C - startTime3C;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3C.count() << " segundos" << endl;
	    
	    auto startTime4C = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresOrder, 0, tableOfScoresOrder.size() - 1);
		auto endTime4C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4C = endTime4C - startTime4C;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4C.count() << " segundos" << endl;
	    
	    auto startTime5C = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresOrder);
	    auto endTime5C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5C = endTime5C - startTime5C;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5C.count() << " segundos" << endl;
	    
	    auto startTime6C = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresOrder);
	    auto endTime6C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6C = endTime6C - startTime6C;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6C.count() << " segundos" << endl;
	    
	    auto startTime7C = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresOrder);
	    auto endTime7C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7C = endTime7C - startTime7C;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7C.count() << " segundos" << endl;
    	
    	cout << endl<<endl;
    	
    	cout << "D)Carrera por tablero : Modo inversamente ordenado" << endl << endl;
    	
    	auto startTime1D = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresDisorder);
	    auto endTime1D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1D = endTime1D - startTime1D;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1D.count() << " segundos" << endl;
	    
	    auto startTime2D = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresDisorder);
	    auto endTime2D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2D = endTime2D - startTime2D;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2D.count() << " segundos" << endl;
	    
	    auto startTime3D = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresDisorder, 0, tableOfScoresDisorder.size() - 1);
		auto endTime3D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3D = endTime3D - startTime3D;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3D.count() << " segundos" << endl;
	    
	    auto startTime4D = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresDisorder, 0, tableOfScoresDisorder.size() - 1);
		auto endTime4D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4D = endTime4D - startTime4D;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4D.count() << " segundos" << endl;
	    
	    auto startTime5D = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresDisorder);
	    auto endTime5D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5D = endTime5D - startTime5D;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5D.count() << " segundos" << endl;
	    
	    auto startTime6D = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresDisorder);
	    auto endTime6D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6D = endTime6D - startTime6D;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6D.count() << " segundos" << endl;
	    
	    auto startTime7D = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresDisorder);
	    auto endTime7D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7D = endTime7D - startTime7D;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7D.count() << " segundos" << endl<<endl;
         
		     
        cout << "\t\t\t2)Carreras por caminos entre aldeas" << endl << endl;
        
        cout << "A)Carrera por caminos : Modo aleatorio sin duplicados" << endl << endl;
        
        auto startTime1E = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsSemiRandom);
		auto endTime1E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1E = endTime1E - startTime1E;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1E.count() << " segundos" << endl;
		
		auto startTime2E = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsSemiRandom);
		auto endTime2E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2E = endTime2E - startTime2E;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2E.count() << " segundos" << endl;
		
		auto startTime3E = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsSemiRandom, 0, villagesRoadsSemiRandom.size() - 1);
		auto endTime3E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3E = endTime3E - startTime3E;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4E = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsSemiRandom, 0, villagesRoadsSemiRandom.size() - 1);
		auto endTime4E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4E = endTime4E - startTime4E;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4E.count() << " segundos" << endl;
		
		auto startTime5E = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsSemiRandom);
		auto endTime5E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5E = endTime5E - startTime5E;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5E.count() << " segundos" << endl;
		
		auto startTime6E = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsSemiRandom);
		auto endTime6E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6E = endTime6E - startTime6E;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6E.count() << " segundos" << endl;
		
		auto startTime7E = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsSemiRandom);
		auto endTime7E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7E = endTime7E - startTime7E;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7E.count() << " segundos" << endl;
		
		cout << endl << endl;		
		cout << "B)Carrera por caminos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1F = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsFullRandom);
		auto endTime1F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1F = endTime1F - startTime1F;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1F.count() << " segundos" << endl;
		
		auto startTime2F = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsFullRandom);
		auto endTime2F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2F = endTime2F - startTime2F;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2F.count() << " segundos" << endl;
		
		auto startTime3F = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsFullRandom, 0, villagesRoadsFullRandom.size() - 1);
		auto endTime3F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3F = endTime3F - startTime3F;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4F = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsFullRandom, 0, villagesRoadsFullRandom.size() - 1);
		auto endTime4F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4F = endTime4F - startTime4F;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4F.count() << " segundos" << endl;
		
		auto startTime5F = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsFullRandom);
		auto endTime5F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5F = endTime5F - startTime5F;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5F.count() << " segundos" << endl;
		
		auto startTime6F = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsFullRandom);
		auto endTime6F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6F = endTime6F - startTime6F;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6F.count() << " segundos" << endl;
		
		auto startTime7F = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsFullRandom);
		auto endTime7F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7F = endTime7F - startTime7F;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7F.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "C)Carrera por caminos : Modo ordenado" << endl << endl;
		
		auto startTime1G = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsOrder);
		auto endTime1G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1G = endTime1G - startTime1G;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1G.count() << " segundos" << endl;
		
		auto startTime2G = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsOrder);
		auto endTime2G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2G = endTime2G - startTime2G;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2G.count() << " segundos" << endl;
		
		auto startTime3G = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsOrder, 0, villagesRoadsOrder.size() - 1);
		auto endTime3G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3G = endTime3G - startTime3G;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3G.count() << " segundos" << endl;
		
		auto startTime4G = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsOrder, 0, villagesRoadsOrder.size() - 1);
		auto endTime4G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4G = endTime4G - startTime4G;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4G.count() << " segundos" << endl;
		
		auto startTime5G = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsOrder);
		auto endTime5G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5G = endTime5G - startTime5G;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5G.count() << " segundos" << endl;
		
		auto startTime6G = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsOrder);
		auto endTime6G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6G = endTime6G - startTime6G;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6G.count() << " segundos" << endl;
		
		auto startTime7G = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsOrder);
		auto endTime7G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7G = endTime7G - startTime7G;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7G.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "D)Carrera por caminos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1H = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsDisorder);
		auto endTime1H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1H = endTime1H - startTime1H;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1H.count() << " segundos" << endl;
		
		auto startTime2H = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsDisorder);
		auto endTime2H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2H = endTime2H - startTime2H;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2H.count() << " segundos" << endl;
		
		auto startTime3H = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsDisorder, 0, villagesRoadsDisorder.size() - 1);
		auto endTime3H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3H = endTime3H - startTime3H;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3H.count() << " segundos" << endl;
		
		auto startTime4H = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsDisorder, 0, villagesRoadsDisorder.size() - 1);
		auto endTime4H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4H = endTime4H - startTime4H;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4H.count() << " segundos" << endl;
		
		auto startTime5H = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsDisorder);
		auto endTime5H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5H = endTime5H - startTime5H;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5H.count() << " segundos" << endl;
		
		auto startTime6H = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsDisorder);
		auto endTime6H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6H = endTime6H - startTime6H;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6H.count() << " segundos" << endl;
		
		auto startTime7H = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsDisorder);
		auto endTime7H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7H = endTime7H - startTime7H;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7H.count() << " segundos" << endl;
		
		cout << endl << endl;
        
        cout << "\t\t\t3)Carreras por los dibujos" << endl << endl;
        
        cout << "A)Carrera por dibujos : Modo aleatorio sin duplicados" << endl << endl;
        
        auto startTime1I = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingSemiRandom);
		auto endTime1I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1I = endTime1I - startTime1I;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1I.count() << " segundos" << endl;
		
		auto startTime2I = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingSemiRandom);
		auto endTime2I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2I = endTime2I - startTime2I;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2I.count() << " segundos" << endl;
		
		auto startTime3I = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingSemiRandom, 0, drawingSemiRandom.size() - 1);
		auto endTime3I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3I = endTime3I - startTime3I;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3I.count() << " segundos" << endl;
		
		auto startTime4I = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingSemiRandom, 0, drawingSemiRandom.size() - 1);
		auto endTime4I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4I = endTime4I - startTime4I;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4I.count() << " segundos" << endl;
		
		auto startTime5I = chrono::high_resolution_clock::now();
		selectionSort(drawingSemiRandom);
		auto endTime5I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5I = endTime5I - startTime5I;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5I.count() << " segundos" << endl;
		
		auto startTime6I = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingSemiRandom);
		auto endTime6I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6I = endTime6I - startTime6I;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6I.count() << " segundos" << endl;
		
		auto startTime7I = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingSemiRandom);
		auto endTime7I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7I = endTime7I - startTime7I;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7I.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "B)Carrera por dibujos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1J = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingFullRandom);
		auto endTime1J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1J = endTime1J - startTime1J;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1J.count() << " segundos" << endl;
		
		auto startTime2J = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingFullRandom);
		auto endTime2J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2J = endTime2J - startTime2J;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2J.count() << " segundos" << endl;
		
		auto startTime3J = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingFullRandom, 0, drawingFullRandom.size() - 1);
		auto endTime3J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3J = endTime3J - startTime3J;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3J.count() << " segundos" << endl;
		
		auto startTime4J = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingFullRandom, 0, drawingFullRandom.size() - 1);
		auto endTime4J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4J = endTime4J - startTime4J;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4J.count() << " segundos" << endl;
		
		auto startTime5J = chrono::high_resolution_clock::now();
		selectionSort(drawingFullRandom);
		auto endTime5J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5J = endTime5J - startTime5J;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5J.count() << " segundos" << endl;
		
		auto startTime6J = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingFullRandom);
		auto endTime6J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6J = endTime6J - startTime6J;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6J.count() << " segundos" << endl;
		
		auto startTime7J = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingFullRandom);
		auto endTime7J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7J = endTime7J - startTime7J;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7J.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "C)Carrera por dibujos : Modo ordenado" << endl << endl;
		
		auto startTime1K = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingOrder);
		auto endTime1K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1K = endTime1K - startTime1K;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1K.count() << " segundos" << endl;
		
		auto startTime2K = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingOrder);
		auto endTime2K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2K = endTime2K - startTime2K;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2K.count() << " segundos" << endl;
		
		auto startTime3K = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingOrder, 0, drawingOrder.size() - 1);
		auto endTime3K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3K = endTime3K - startTime3K;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3K.count() << " segundos" << endl;
		
		auto startTime4K = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingOrder, 0, drawingOrder.size() - 1);
		auto endTime4K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4K = endTime4K - startTime4K;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4K.count() << " segundos" << endl;
		
		auto startTime5K = chrono::high_resolution_clock::now();
		selectionSort(drawingOrder);
		auto endTime5K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5K = endTime5K - startTime5K;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5K.count() << " segundos" << endl;
		
		auto startTime6K = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingOrder);
		auto endTime6K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6K = endTime6K - startTime6K;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6K.count() << " segundos" << endl;
		
		auto startTime7K = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingOrder);
		auto endTime7K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7K = endTime7K - startTime7K;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7K.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "D)Carrera por dibujos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1L = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingDisorder);
		auto endTime1L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1L = endTime1L - startTime1L;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1L.count() << " segundos" << endl;
		
		auto startTime2L = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingDisorder);
		auto endTime2L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2L = endTime2L - startTime2L;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2L.count() << " segundos" << endl;
		
		auto startTime3L = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingDisorder, 0, drawingDisorder.size() - 1);
		auto endTime3L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3L = endTime3L - startTime3L;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3L.count() << " segundos" << endl;
		
		auto startTime4L = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingDisorder, 0, drawingDisorder.size() - 1);
		auto endTime4L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4L = endTime4L - startTime4L;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4L.count() << " segundos" << endl;
		
		auto startTime5L = chrono::high_resolution_clock::now();
		selectionSort(drawingDisorder);
		auto endTime5L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5L = endTime5L - startTime5L;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5L.count() << " segundos" << endl;
		
		auto startTime6L = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingDisorder);
		auto endTime6L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6L = endTime6L - startTime6L;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6L.count() << " segundos" << endl;
		
		auto startTime7L = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingDisorder);
		auto endTime7L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7L = endTime7L - startTime7L;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7L.count() << " segundos" << endl;   
	}
	
	else if(Order == 2)
	{
		cout << "Llenando vectores del area : Tablero de puntajes" << endl<< endl;

        semiRandomVector(tableOfScoresSemiRandom, range1); //Set de datos aleatorios
        fullRandomVector(tableOfScoresFullRandom, range1); //Set de datos aleatorios duplicados        
        descendingVector(tableOfScoresDisorder, range1);//Set de datos ordenados
        ascendingVector(tableOfScoresOrder, range1);   //Set de datos inversamente ordenados     

        cout << "Llenando vectores del area : Determinacion de camino entre aldeas" << endl<< endl;

        semiRandomVector(villagesRoadsSemiRandom, range2); //Set de datos aleatorios
        fullRandomVector(villagesRoadsFullRandom, range2); //Set de datos aleatorios duplicados       
        descendingVector(villagesRoadsDisorder, range2);//Set de datos ordenados
        ascendingVector(villagesRoadsOrder, range2);  //Set de datos inversamente ordenados      

        cout << "Llenando vectores del area : Dibujo o renderizado de objetos" << endl<< endl;

        semiRandomVector(drawingSemiRandom, range3); //Set de datos aleatorios
        fullRandomVector(drawingFullRandom, range3); //Set de datos aleatorios duplicados        
        descendingVector(drawingDisorder, range3);//Set de datos ordenados
        ascendingVector(drawingOrder, range3);  //Set de datos inversamente ordenados

        cout << "Todos los vectores han sido llenados correctamente!!" << endl<< endl;

        cout << "Ahora vamos a poner a prueba los vectores en los siguientes algoritmos: " << endl<< endl;
             
        cout << "\t1)Bubble sort" << endl
             << "\t2)Heap sort" << endl
             << "\t3)Quick sort" << endl
             << "\t4)Merge sort" << endl
             << "\t5)Selection sort" << endl
             << "\t6)Insertion sort" << endl
             << "\t7)Shell sort" << endl << endl;
    	
    	cout << "QUE COMIENCEN LAS CARRERAS!!!" << endl << endl;
    	
    	cout << "\t\t\t1)Carreras por tablero" << endl << endl;
    	
    	cout << "A)Carrera por tablero : Modo aleatorio sin duplicados" << endl << endl;

		auto startTime1A = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresSemiRandom);
		auto endTime1A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1A = endTime1A - startTime1A;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1A.count() << " segundos" << endl;
		
		auto startTime2A = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresSemiRandom);
		auto endTime2A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2A = endTime2A - startTime2A;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2A.count() << " segundos" << endl;
		
		auto startTime3A = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresSemiRandom, 0, tableOfScoresSemiRandom.size() - 1);
		auto endTime3A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3A = endTime3A - startTime3A;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3A.count() << " segundos" << endl;
		
		auto startTime4A = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresSemiRandom, 0, tableOfScoresSemiRandom.size() - 1);
		auto endTime4A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4A = endTime4A - startTime4A;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4A.count() << " segundos" << endl;
		
		auto startTime5A = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresSemiRandom);
		auto endTime5A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5A = endTime5A - startTime5A;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5A.count() << " segundos" << endl;
		
		auto startTime6A = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresSemiRandom);
		auto endTime6A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6A = endTime6A - startTime6A;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6A.count() << " segundos" << endl;
		
		auto startTime7A = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresSemiRandom);
		auto endTime7A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7A = endTime7A - startTime7A;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7A.count() << " segundos" << endl;
		
		cout << endl<<endl;
		
		
		cout << "B)Carrera por tablero : Modo aleatorio con posibilidad de  duplicados" << endl << endl;
		
		auto startTime1B = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresFullRandom);
		auto endTime1B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1B = endTime1B - startTime1B;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1B.count() << " segundos" << endl;
		
		auto startTime2B = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresFullRandom);
		auto endTime2B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2B = endTime2B - startTime2B;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2B.count() << " segundos" << endl;
		
		auto startTime3B = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresFullRandom, 0, tableOfScoresFullRandom.size() - 1);
		auto endTime3B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3B = endTime3B - startTime3B;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3B.count() << " segundos" << endl;
		
		auto startTime4B = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresFullRandom, 0, tableOfScoresFullRandom.size() - 1);
		auto endTime4B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4B = endTime4B - startTime4B;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4B.count() << " segundos" << endl;
		
		auto startTime5B = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresFullRandom);
		auto endTime5B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5B = endTime5B - startTime5B;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5B.count() << " segundos" << endl;
		
		auto startTime6B = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresFullRandom);
		auto endTime6B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6B = endTime6B - startTime6B;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6B.count() << " segundos" << endl;
		
		auto startTime7B = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresFullRandom);
		auto endTime7B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7B = endTime7B - startTime7B;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7B.count() << " segundos" << endl;
		
		cout << endl<<endl;
		
		
		cout << "C)Carrera por tablero : Modo ordenado" << endl << endl;
		
		auto startTime1D = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresDisorder);
		auto endTime1D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1D = endTime1D - startTime1D;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1D.count() << " segundos" << endl;
		
		auto startTime2D = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresDisorder);
		auto endTime2D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2D = endTime2D - startTime2D;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2D.count() << " segundos" << endl;
		
		auto startTime3D = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresDisorder, 0, tableOfScoresDisorder.size() - 1);
		auto endTime3D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3D = endTime3D - startTime3D;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3D.count() << " segundos" << endl;
		
		auto startTime4D = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresDisorder, 0, tableOfScoresDisorder.size() - 1);
		auto endTime4D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4D = endTime4D - startTime4D;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4D.count() << " segundos" << endl;
		
		auto startTime5D = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresDisorder);
		auto endTime5D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5D = endTime5D - startTime5D;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5D.count() << " segundos" << endl;
		
		auto startTime6D = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresDisorder);
		auto endTime6D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6D = endTime6D - startTime6D;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6D.count() << " segundos" << endl;
		
		auto startTime7D = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresDisorder);
		auto endTime7D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7D = endTime7D - startTime7D;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7D.count() << " segundos" << endl << endl;
		
		
		cout << "C)Carrera por tablero : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1C = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresOrder);
		auto endTime1C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1C = endTime1C - startTime1C;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1C.count() << " segundos" << endl;
		
		auto startTime2C = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresOrder);
		auto endTime2C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2C = endTime2C - startTime2C;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2C.count() << " segundos" << endl;
		
		auto startTime3C = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresOrder, 0, tableOfScoresOrder.size() - 1);
		auto endTime3C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3C = endTime3C - startTime3C;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3C.count() << " segundos" << endl;
		
		auto startTime4C = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresOrder, 0, tableOfScoresOrder.size() - 1);
		auto endTime4C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4C = endTime4C - startTime4C;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4C.count() << " segundos" << endl;
		
		auto startTime5C = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresOrder);
		auto endTime5C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5C = endTime5C - startTime5C;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5C.count() << " segundos" << endl;
		
		auto startTime6C = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresOrder);
		auto endTime6C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6C = endTime6C - startTime6C;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6C.count() << " segundos" << endl;
		
		auto startTime7C = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresOrder);
		auto endTime7C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7C = endTime7C - startTime7C;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7C.count() << " segundos" << endl;
		
		cout << endl << endl;
		
		cout << "\t\t\t2)Carreras por caminos entre aldeas" << endl << endl;

		cout << "A)Carrera por caminos : Modo aleatorio sin duplicados" << endl << endl;
		
		auto startTime1E = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsSemiRandom);
		auto endTime1E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1E = endTime1E - startTime1E;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1E.count() << " segundos" << endl;
		
		auto startTime2E = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsSemiRandom);
		auto endTime2E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2E = endTime2E - startTime2E;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2E.count() << " segundos" << endl;
		
		auto startTime3E = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsSemiRandom, 0, villagesRoadsSemiRandom.size() - 1);
		auto endTime3E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3E = endTime3E - startTime3E;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4E = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsSemiRandom, 0, villagesRoadsSemiRandom.size() - 1);
		auto endTime4E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4E = endTime4E - startTime4E;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4E.count() << " segundos" << endl;
		
		auto startTime5E = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsSemiRandom);
		auto endTime5E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5E = endTime5E - startTime5E;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5E.count() << " segundos" << endl;
		
		auto startTime6E = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsSemiRandom);
		auto endTime6E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6E = endTime6E - startTime6E;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6E.count() << " segundos" << endl;
		
		auto startTime7E = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsSemiRandom);
		auto endTime7E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7E = endTime7E - startTime7E;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7E.count() << " segundos" << endl;
		
		cout << endl << endl;		
		cout << "B)Carrera por caminos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1F = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsFullRandom);
		auto endTime1F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1F = endTime1F - startTime1F;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1F.count() << " segundos" << endl;
		
		auto startTime2F = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsFullRandom);
		auto endTime2F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2F = endTime2F - startTime2F;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2F.count() << " segundos" << endl;
		
		auto startTime3F = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsFullRandom, 0, villagesRoadsFullRandom.size() - 1);
		auto endTime3F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3F = endTime3F - startTime3F;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3F.count() << " segundos" << endl;
		
		auto startTime4F = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsFullRandom, 0, villagesRoadsFullRandom.size() - 1);
		auto endTime4F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4F = endTime4F - startTime4F;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4F.count() << " segundos" << endl;
		
		auto startTime5F = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsFullRandom);
		auto endTime5F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5F = endTime5F - startTime5F;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5F.count() << " segundos" << endl;
		
		auto startTime6F = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsFullRandom);
		auto endTime6F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6F = endTime6F - startTime6F;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6F.count() << " segundos" << endl;
		
		auto startTime7F = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsFullRandom);
		auto endTime7F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7F = endTime7F - startTime7F;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7F.count() << " segundos" << endl;
		
		cout << endl << endl;
		
		cout << "C)Carrera por caminos : Modo ordenado" << endl << endl;
		
		auto startTime1H = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsDisorder);
		auto endTime1H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1H = endTime1H - startTime1H;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1H.count() << " segundos" << endl;
		
		auto startTime2H = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsDisorder);
		auto endTime2H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2H = endTime2H - startTime2H;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2H.count() << " segundos" << endl;
		
		auto startTime3H = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsDisorder, 0, villagesRoadsDisorder.size() - 1);
		auto endTime3H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3H = endTime3H - startTime3H;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3H.count() << " segundos" << endl;
		
		auto startTime4H = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsDisorder, 0, villagesRoadsDisorder.size() - 1);
		auto endTime4H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4H = endTime4H - startTime4H;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4H.count() << " segundos" << endl;
		
		auto startTime5H = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsDisorder);
		auto endTime5H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5H = endTime5H - startTime5H;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5H.count() << " segundos" << endl;
		
		auto startTime6H = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsDisorder);
		auto endTime6H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6H = endTime6H - startTime6H;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6H.count() << " segundos" << endl;
		
		auto startTime7H = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsDisorder);
		auto endTime7H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7H = endTime7H - startTime7H;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7H.count() << " segundos" << endl;
		
		cout << endl << endl;
		
		cout << "D)Carrera por caminos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1G = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsOrder);
		auto endTime1G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1G = endTime1G - startTime1G;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1G.count() << " segundos" << endl;
		
		auto startTime2G = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsOrder);
		auto endTime2G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2G = endTime2G - startTime2G;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2G.count() << " segundos" << endl;
		
		auto startTime3G = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsOrder, 0, villagesRoadsOrder.size() - 1);
		auto endTime3G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3G = endTime3G - startTime3G;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3G.count() << " segundos" << endl;
		
		auto startTime4G = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsOrder, 0, villagesRoadsOrder.size() - 1);
		auto endTime4G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4G = endTime4G - startTime4G;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4G.count() << " segundos" << endl;
		
		auto startTime5G = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsOrder);
		auto endTime5G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5G = endTime5G - startTime5G;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5G.count() << " segundos" << endl;
		
		auto startTime6G = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsOrder);
		auto endTime6G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6G = endTime6G - startTime6G;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6G.count() << " segundos" << endl;
		
		auto startTime7G = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsOrder);
		auto endTime7G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7G = endTime7G - startTime7G;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7G.count() << " segundos" << endl;
		
		cout << endl << endl;
		
        
        cout << "\t\t\t3)Carreras por los dibujos" << endl << endl;
        
		cout << "A)Carrera por dibujos : Modo aleatorio sin duplicados" << endl << endl;
		
		auto startTime1I = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingSemiRandom);
		auto endTime1I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1I = endTime1I - startTime1I;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1I.count() << " segundos" << endl;
		
		auto startTime2I = chrono::high_resolution_clock::now();
		heapSortDescending(drawingSemiRandom);
		auto endTime2I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2I = endTime2I - startTime2I;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2I.count() << " segundos" << endl;
		
		auto startTime3I = chrono::high_resolution_clock::now();
		quickSortDescending(drawingSemiRandom, 0, drawingSemiRandom.size() - 1);
		auto endTime3I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3I = endTime3I - startTime3I;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3I.count() << " segundos" << endl;
		
		auto startTime4I = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingSemiRandom, 0, drawingSemiRandom.size() - 1);
		auto endTime4I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4I = endTime4I - startTime4I;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4I.count() << " segundos" << endl;
		
		auto startTime5I = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingSemiRandom);
		auto endTime5I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5I = endTime5I - startTime5I;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5I.count() << " segundos" << endl;
		
		auto startTime6I = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingSemiRandom);
		auto endTime6I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6I = endTime6I - startTime6I;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6I.count() << " segundos" << endl;
		
		auto startTime7I = chrono::high_resolution_clock::now();
		shellSortDescending(drawingSemiRandom);
		auto endTime7I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7I = endTime7I - startTime7I;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7I.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "B)Carrera por dibujos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1J = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingFullRandom);
		auto endTime1J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1J = endTime1J - startTime1J;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1J.count() << " segundos" << endl;
		
		auto startTime2J = chrono::high_resolution_clock::now();
		heapSortDescending(drawingFullRandom);
		auto endTime2J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2J = endTime2J - startTime2J;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2J.count() << " segundos" << endl;
		
		auto startTime3J = chrono::high_resolution_clock::now();
		quickSortDescending(drawingFullRandom, 0, drawingFullRandom.size() - 1);
		auto endTime3J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3J = endTime3J - startTime3J;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3J.count() << " segundos" << endl;
		
		auto startTime4J = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingFullRandom, 0, drawingFullRandom.size() - 1);
		auto endTime4J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4J = endTime4J - startTime4J;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4J.count() << " segundos" << endl;
		
		auto startTime5J = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingFullRandom);
		auto endTime5J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5J = endTime5J - startTime5J;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5J.count() << " segundos" << endl;
		
		auto startTime6J = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingFullRandom);
		auto endTime6J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6J = endTime6J - startTime6J;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6J.count() << " segundos" << endl;
		
		auto startTime7J = chrono::high_resolution_clock::now();
		shellSortDescending(drawingFullRandom);
		auto endTime7J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7J = endTime7J - startTime7J;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7J.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "C)Carrera por dibujos : Modo ordenado" << endl << endl;
		
		auto startTime1L = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingDisorder);
		auto endTime1L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1L = endTime1L - startTime1L;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1L.count() << " segundos" << endl;
		
		auto startTime2L = chrono::high_resolution_clock::now();
		heapSortDescending(drawingDisorder);
		auto endTime2L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2L = endTime2L - startTime2L;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2L.count() << " segundos" << endl;
		
		auto startTime3L = chrono::high_resolution_clock::now();
		quickSortDescending(drawingDisorder, 0, drawingDisorder.size() - 1);
		auto endTime3L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3L = endTime3L - startTime3L;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3L.count() << " segundos" << endl;
		
		auto startTime4L = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingDisorder, 0, drawingDisorder.size() - 1);
		auto endTime4L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4L = endTime4L - startTime4L;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4L.count() << " segundos" << endl;
		
		auto startTime5L = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingDisorder);
		auto endTime5L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5L = endTime5L - startTime5L;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5L.count() << " segundos" << endl;
		
		auto startTime6L = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingDisorder);
		auto endTime6L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6L = endTime6L - startTime6L;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6L.count() << " segundos" << endl;
		
		auto startTime7L = chrono::high_resolution_clock::now();
		shellSortDescending(drawingDisorder);
		auto endTime7L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7L = endTime7L - startTime7L;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7L.count() << " segundos" << endl;
		
		cout << endl << endl;
		cout << "D)Carrera por dibujos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1K = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingOrder);
		auto endTime1K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1K = endTime1K - startTime1K;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1K.count() << " segundos" << endl;
		
		auto startTime2K = chrono::high_resolution_clock::now();
		heapSortDescending(drawingOrder);
		auto endTime2K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2K = endTime2K - startTime2K;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2K.count() << " segundos" << endl;
		
		auto startTime3K = chrono::high_resolution_clock::now();
		quickSortDescending(drawingOrder, 0, drawingOrder.size() - 1);
		auto endTime3K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3K = endTime3K - startTime3K;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3K.count() << " segundos" << endl;
		
		auto startTime4K = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingOrder, 0, drawingOrder.size() - 1);
		auto endTime4K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4K = endTime4K - startTime4K;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4K.count() << " segundos" << endl;
		
		auto startTime5K = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingOrder);
		auto endTime5K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5K = endTime5K - startTime5K;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5K.count() << " segundos" << endl;
		
		auto startTime6K = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingOrder);
		auto endTime6K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6K = endTime6K - startTime6K;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6K.count() << " segundos" << endl;
		
		auto startTime7K = chrono::high_resolution_clock::now();
		shellSortDescending(drawingOrder);
		auto endTime7K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7K = endTime7K - startTime7K;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7K.count() << " segundos" << endl;
		
		cout << endl << endl;
		
	}
		
    return 0;
}

