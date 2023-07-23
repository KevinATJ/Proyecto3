#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;


// Función que genera el rango de las carreras en general, permitiendo cambiar dentro del main las variables min y max dependiendo del tipo de carrera 
int generateRandomRaceRange(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

//Función que llena un arreglo de manera ascendente
void ascendingArray(int arr[], int size)
{
	int i;
	
	for (i = 0; i < size; i++) 
	{
        arr[i] = i + 1;
    }
}

//Función que llena un arreglo de manera descendente
void descendingArray(int arr[], int size)
{
	int i;
	int num = size;
	
    for (i = 0; i < size; i++)
	{
        arr[i] = num--;
    }
}


//Función que llena un arreglo de manera completamente aleatoria
void fullRandomArray(int arr[], int size)
{	
	srand(time(NULL)); 

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % (size + 1);
    }
		
}

//Función que llena un arreglo de manera semi aleatoria(es decir lo llena de manera aleatoria pero sin números duplicados)
void semiRandomArray(int arr[], int size)
{
	srand(time(NULL)); 
    int i, allNumbers[size], index;
    
    for (i = 0; i < size; i++) 
	{
        allNumbers[i] = i + 1;
    }

    for (i = 0; i < size; i++) 
	{
        index = rand() % (size - i); 
        arr[i] = allNumbers[index]; 
        allNumbers[index] = allNumbers[size - i - 1];
    }
		
}

//------------------------------algoritmos de ordenamiento------------------------------//


//Bubble Sort: 
/*
Este recorre el arreglo comparando elementos vecinos y los intercambia si están en el orden incorrecto.En cada pasada, 
el elemento más grande (ascendente) o más pequeño (descendente) se mueve  hacia su posición final. 
*/

void bubbleSortAscendant(int arr[], int size) 
{
	int i, j, temp;
	
    for (i = 0; i < size - 1; i++) 
	{
        for (j = 0; j < size - i - 1; j++)
		{
            if (arr[j] > arr[j + 1]) 
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(int arr[], int size) 
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Heap Sort:
/*
En este se construye un heap(montículo) ascendente o descendente a partir del arreglo y luego se extraen los elementos uno a uno para obtener el 
arreglo ordenado de manera ascendente o descendente.
*/

void heapifyAscendant(int arr[], int size, int i)
{
	int right = (2*i) +2;
	int left = (2*i) +1;
	int max = i;
	int temp;
    
    if (left < size && arr[left] > arr[max]) 
	{
        max = left;
    }

    if (right < size && arr[right] > arr[max]) 
	{
        max = right;
    }

    if (max != i) 
	{
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        heapifyAscendant(arr, size, max);
    }
	
}

void heapSortAscendant(int arr[], int size) 
{
    int i, temp;
    
    for (i = size / 2 - 1; i >= 0; i--) 
	{
        heapifyAscendant(arr, size, i);
    }
    
    for (int i = size - 1; i > 0; i--) 
	{
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyAscendant(arr, i, 0);
    }
}

void heapifyDescending(int arr[], int size, int i)
{
    int right = (2*i) +2;
    int left = (2*i) +1;
    int min = i;
    int temp;

    if (left < size && arr[left] < arr[min])
    {
        min = left;
    }

    if (right < size && arr[right] < arr[min])
    {
        min = right;
    }

    if (min != i)
    {
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        heapifyDescending(arr, size, min);
    }
}

void heapSortDescending(int arr[], int size) 
{
	int i, temp;
    
    for (int i = size / 2 - 1; i >= 0; i--) 
	{
        heapifyDescending(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) 
	{
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyDescending(arr, i, 0);
    }
}



// Quick Sort:
/*
Este selecciona un elemento (pivote) y reorganiza los elementos en dos grupos, uno con valores menores que el pivote y otro con valores mayores. 
Luego, se aplica el mismo proceso a cada grupo(el dicho anteriormente) hasta que el arreglo esté completamente ordenado, ya sea en orden ascendente o descendente.
*/

int pivotPartitionAscendant(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quickSortAscendant(int arr[], int low, int high) 
{
	int pivotIndex;
	
    if (low < high) 
    {
        pivotIndex = pivotPartitionAscendant(arr, low, high);

        quickSortAscendant(arr, low, pivotIndex - 1);
        quickSortAscendant(arr, pivotIndex + 1, high);
    }
}

int pivotPartitionDescending(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++) 
    {
        if (arr[j] > pivot) 
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quickSortDescending(int arr[], int low, int high) 
{
    int pivotIndex;

    if (low < high) 
    {
        pivotIndex = pivotPartitionDescending(arr, low, high);

        quickSortDescending(arr, low, pivotIndex - 1);
        quickSortDescending(arr, pivotIndex + 1, high);
    }
}

// Merge Sort:
/*
Este divide repetidamente el arreglo en dos mitades, ordena cada mitad usando recursividad, 
y luego combina las dos mitades ordenadas para obtener el arreglo completo, ya sea en orden ascendente o descendente
*/

void combineArraysAscendant(int arr[], int left, int mid, int right) 
{
	int i, j, k;
	
	int RArrSize = right - mid;
	int RightArr[RArrSize];
	
    int LArrSize = mid - left + 1;
    int LeftArr[LArrSize];
    
    for (i = 0; i < LArrSize; i++) 
    {
        LeftArr[i] = arr[left + i];
    }
    for (j = 0; j < RArrSize; j++) 
    {
        RightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < LArrSize && j < RArrSize) 
    {
        if (LeftArr[i] <= RightArr[j]) 
        {
            arr[k] = LeftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < LArrSize) 
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < RArrSize) 
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSortAscendant(int arr[], int left, int right) 
{
    if (left < right) 
	{
        int mid = left + (right - left) / 2;

        mergeSortAscendant(arr, left, mid);
        mergeSortAscendant(arr, mid + 1, right);

        combineArraysAscendant(arr, left, mid, right);
    }
}

void combineArraysDescending(int arr[], int left, int mid, int right) 
{
    int i, j, k;

    int RArrSize = right - mid;
    int RightArr[RArrSize];

    int LArrSize = mid - left + 1;
    int LeftArr[LArrSize];

    for (i = 0; i < LArrSize; i++) 
	{
        LeftArr[i] = arr[left + i];
    }
    for (j = 0; j < RArrSize; j++) 
	{
        RightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < LArrSize && j < RArrSize) 
	{
        if (LeftArr[i] >= RightArr[j])
		{
            arr[k] = LeftArr[i];
            i++;
        } else {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < LArrSize) 
	{
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < RArrSize) 
	{
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSortDescending(int arr[], int left, int right) 
{
    if (left < right)
	{
        int mid = left + (right - left) / 2;

        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);

        combineArraysDescending(arr, left, mid, right);
    }
}

// Selection Sort:
/*
Este encuentra(selecciona) repetidamente el elemento mínimo (o máximo, dependiendo del orden) del arreglo y lo coloca en su posición correcta. 
Luego se repite este proceso para el resto de los elementos hasta obtener el arreglo completamente ordenado.
*/

void selectionSort(int arr[], int size) 
{
	int i, j, minIndex, temp;
	
    for (i = 0; i < size - 1; i++) 
	{
        minIndex = i;
        for (j = i + 1; j < size; j++) 
		{
            if (arr[j] < arr[minIndex]) 
			{
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void selectionSortDescending(int arr[], int size) 
{
    int i, j, maxIndex, temp;
    
    for (i = 0; i < size - 1; i++) 
    {
        maxIndex = i;
        for (j = i + 1; j < size; j++) 
        {
            if (arr[j] > arr[maxIndex]) 
            {
                maxIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

// Insertion Sort:
/*
Este construye una parte ordenada del arreglo al insertar cada elemento en su posición correcta dentro de esa sección ordenada. 
Luego se repite este proceso para todos los elementos hasta obtener el arreglo completamente ordenado.
*/
void insertionSortAscendant(int arr[], int size) 
{
	int i, j, current;
	
    for (i = 1; i < size; i++) 
	{
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current) 
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void insertionSortDescending(int arr[], int size) 
{
    int i, j, current;

    for (i = 1; i < size; i++) 
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < current) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// Shell Sort:
/*
Este utiliza una secuencia de intervalos para comparar y mover elementos hacia su posición final. 
A medida que los intervalos disminuyen, el arreglo se va ordenando en pequeños grupos hasta obtener un arreglo completamente ordenado.
*/

void shellSortAscendant(int arr[], int size) 
{
	int i, j, gap, temp;
	
    for (gap = size / 2; gap > 0; gap /= 2) 
	{
        for (i = gap; i < size; i++) 
		{
            temp = arr[i];
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
			{
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSortDescending(int arr[], int size) 
{
    int i, j, gap, temp;
    
    for (gap = size / 2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < size; i++) 
        {
            temp = arr[i];
            
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}



int main() {
    
    int Option, Order, range1, range2, range3;
    
    cout << "Bienvenido a la carrera de algoritmos" << endl << endl;
    
    cout << "Ingresa la manera en la que deseas que estos algoritmos ordenen:" << endl <<"1)Ascendente " << endl << "2)Descendente"<<endl;
    cin >> Order;
    

    return 0;
}

