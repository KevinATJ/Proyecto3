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
    
    int Option, Order;
    
    cout << "Bienvenido a la carrera de algoritmos" << endl << endl;
    
    cout << "Ingresa la manera en la que deseas que estos algoritmos ordenen:" << endl <<"1)Ascendente " << endl << "2)Descendente"<<endl;
    cin >> Order;
    
    

    return 0;
}

