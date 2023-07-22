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



// Implementación de algoritmos de ordenamiento

// Bubble Sort
void bubbleSort() 
{
    // Implementa el algoritmo Bubble Sort
}

// Heap Sort
void heapSort() 
{
    // Implementa el algoritmo Heap Sort
}

// Quick Sort
void quickSort() 
{
    // Implementa el algoritmo Quick Sort
}

// Merge Sort
void mergeSort() 
{
    // Implementa el algoritmo Merge Sort
}

// Selection Sort
void selectionSort() 
{
    // Implementa el algoritmo Selection Sort
}

// Insertion Sort
void insertionSort() 
{
    // Implementa el algoritmo Insertion Sort
}

// Shell Sort
void shellSort() 
{
    // Implementa el algoritmo Shell Sort
}

int main() {
    
    int Option, Order, range1, range2, range3;
    
    cout << "Bienvenido a la carrera de algoritmos" << endl << endl;
    
    cout << "Ingresa la manera en la que deseas que estos algoritmos ordenen:" << endl <<"1)Ascendente " << endl << "2)Descendente"<<endl;
    cin >> Order;
    
    

    return 0;
}

