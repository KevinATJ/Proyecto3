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

    cout << "Bienvenido a la carrera de algoritmos" << endl
         << endl;

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
        cout << "La opcion escogida fue: orden ascendente" << endl
             << endl;
    }
    else if (Order == 2)
    {
        cout << "La opcion escogida fue: orden descendente" << endl
             << endl;
    }

    cout << "Estas son las areas sobre las cuales estaran basadas las distintas carreras:" << endl
         << endl;
    cout << "\tA)Tablero de puntajes: esta tendra de 9000 a 10000 datos" << endl
         << "\tB)Determinacion de camino entre aldeas: esta tendra de 5000 a 7000 datos" << endl
         << "\tC)Dibujo o renderizado de objetos: Esta tendra de 50 a 100 datos repartidos en 15 categorias(1500 datos maximos)" << endl;

    cout << "Ahora comenzara el sorteo de elementos para cada categoria" << endl
         << endl;

    range1 = generateRandomRaceRange(90000, 100000);
    cout << "A)Tablero de puntajes: " << range1 << " datos" << endl
         << endl;

    range2 = generateRandomRaceRange(50000, 70000);
    cout << "B)Determinacion de camino entre aldeas: " << range2 << " datos" << endl
         << endl;

    vector<int> categoryRanges = generateCategoryRanges(15, 500, 1000);

    for (int range : categoryRanges)
    {
        range3 += range;
    }

    cout << "C)Dibujo o renderizado de objetos: " << range3 << " datos" << endl
         << endl;

    cout << "Ahora llenaremos los vectores de estas areas basados en las siguientes condiciones" << endl
         << endl;
    cout << "\t1)Set de datos aleatorios(sin elementos duplicados)" << endl
         << "\t2)Set de datos aleatorios duplicados(con posibilidad de elementos duplicados)" << endl
         << "\t3)Set de datos ordenado(basado en la opcion inicialmente escogida)" << endl
         << "\t4)Set de datos inversamente ordenado(el contrario de lo inicialmente escogido)" << endl
         << endl;

    if (Order == 1)
    {

        cout << "Llenando vectores del area : Tablero de puntajes" << endl
             << endl;

        semiRandomVector(tableOfScoresSemiRandom, range1); //Set de datos aleatorios
        fullRandomVector(tableOfScoresFullRandom, range1); //Set de datos aleatorios duplicados
        ascendingVector(tableOfScoresOrder, range1);      //Set de datos ordenados
        descendingVector(tableOfScoresDisorder, range1);  //Set de datos inversamente ordenados

        cout << "Llenando vectores del area : Determinacion de camino entre aldeas" << endl
             << endl;

        semiRandomVector(villagesRoadsSemiRandom, range2); //Set de datos aleatorios
        fullRandomVector(villagesRoadsFullRandom, range2); //Set de datos aleatorios duplicados
        ascendingVector(villagesRoadsOrder, range2);      //Set de datos ordenados
        descendingVector(villagesRoadsDisorder, range2);  //Set de datos inversamente ordenados

        cout << "Llenando vectores del area : Dibujo o renderizado de objetos" << endl
             << endl;

        semiRandomVector(drawingSemiRandom, range3); //Set de datos aleatorios
        fullRandomVector(drawingFullRandom, range3); //Set de datos aleatorios duplicados
        ascendingVector(drawingOrder, range3);      //Set de datos ordenados
        descendingVector(drawingDisorder, range3);  //Set de datos inversamente ordenados

        cout << "Todos los vectores han sido llenados correctamente!!" << endl
             << endl;

        cout << "Ahora vamos a poner a prueba los vectores en los siguientes algoritmos: " << endl
             << endl;
        cout << "1)Bubble sort" << endl
             << "2)Heap sort" << endl
             << "3)Quick sort" << endl
             << "4)Merge sort" << endl
             << "5)Selection sort" << endl
             << "6)Insertion sort" << endl
             << "7)Shell sort" << endl;

        

	}
    return 0;
}

