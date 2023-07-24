#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <stack>

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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int pivotPartitionAscendant(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSortAscendant(vector<int> &vec, int low, int high)
{
    stack<pair<int, int>> st;
    st.push(make_pair(low, high));

    while (!st.empty())
    {
        low = st.top().first;
        high = st.top().second;
        st.pop();

        if (low < high)
        {
            int pivotIndex = pivotPartitionAscendant(vec, low, high);

            st.push(make_pair(low, pivotIndex - 1));
            st.push(make_pair(pivotIndex + 1, high));
        }
    }
}
int pivotPartitionDescending(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (vec[j] > pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSortDescending(vector<int> &vec, int low, int high)
{
    stack<pair<int, int>> st;
    st.push(make_pair(low, high));

    while (!st.empty())
    {
        low = st.top().first;
        high = st.top().second;
        st.pop();

        if (low < high)
        {
            int pivotIndex = pivotPartitionDescending(vec, low, high);

            st.push(make_pair(low, pivotIndex - 1));
            st.push(make_pair(pivotIndex + 1, high));
        }
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
    int i;

    for (i = 1; i < vec.size(); i++)
    {
    	
        int current = vec[i];
        int j = i - 1;
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

//Esta funcion permite encontrar el menor tiempo en las carreras, para luego anunicar a su ganador mediante la igualación del valor minimo con todos los demás tiempos
double findMinTime(string name1, string name2, string name3, string name4, string name5, string name6, string name7,double time1, double time2, double time3, double time4, double time5, double time6, double time7) 
{
    
	vector<double> times = {time1, time2, time3, time4, time5, time6, time7};
    double minValue = times[0];

    for (double time : times) 
	{
        if (time < minValue) 
		{
            minValue = time;
        }
    }
    cout << endl;

    cout << "El ganador es ";

    if (time1 == minValue) 
	{
        cout << name1;
    } 
	else if (time2 == minValue) 
	{
        cout << name2;
    } 
	else if (time3 == minValue) 
	{
        cout << name3;
    } 
	else if (time4 == minValue) 
	{
        cout << name4;
    } 
	else if (time5 == minValue) 
	{
        cout << name5;
    } 
	else if (time6 == minValue) 
	{
        cout << name6;
    } 
	else if (time7 == minValue) 
	{
        cout << name7;
    } 
	else 
	{
        cout << "N/A";
    }
    cout << " con " << minValue << " segundos" << endl;

    return minValue;
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
    
    system("pause");
    cout << endl;

    cout << "Estas son las areas sobre las cuales estaran basadas las distintas carreras:" << endl<< endl;
    cout << "\tA)Tablero de puntajes: esta tendra de 90000 a 100000 datos" << endl
         << "\tB)Determinacion de camino entre aldeas: esta tendra de 50000 a 70000 datos" << endl
         << "\tC)Dibujo o renderizado de objetos: Esta tendra de 500 a 1000 datos repartidos en 15 categorias(1500 datos maximos)" << endl;

    cout << "Ahora comenzara el sorteo de elementos para cada categoria" << endl<< endl;

    range1 = generateRandomRaceRange(90000, 100000);
    cout << "A)Tablero de puntajes: " << range1 << " datos" << endl<< endl;

    range2 = generateRandomRaceRange(50000, 70000);
    cout << "B)Determinacion de camino entre aldeas: " << range2 << " datos" << endl<< endl;

    vector<int> categoryRanges = generateCategoryRanges(15, 500, 1000);

    for (int range : categoryRanges)
    {
        range3 += range;
    }

    cout << "C)Dibujo o renderizado de objetos: " << range3 << " datos" << endl<< endl;
    
	
	system("pause");
    cout << endl;
    
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
        
        //creando copias        
        vector<int> tableOfScoresSemiRandomCopy1 = tableOfScoresSemiRandom; // Copia para Bubble Sort
		vector<int> tableOfScoresSemiRandomCopy2 = tableOfScoresSemiRandom; // Copia para Heap Sort
		vector<int> tableOfScoresSemiRandomCopy3 = tableOfScoresSemiRandom; // Copia para Quick Sort
		vector<int> tableOfScoresSemiRandomCopy4 = tableOfScoresSemiRandom; // Copia para Merge sort
		vector<int> tableOfScoresSemiRandomCopy5 = tableOfScoresSemiRandom; // Copia para Selection Sort
		vector<int> tableOfScoresSemiRandomCopy6 = tableOfScoresSemiRandom; // Copia para Insertion Sort
		vector<int> tableOfScoresSemiRandomCopy7 = tableOfScoresSemiRandom; // Copia para Shell Sort
		
		vector<int> tableOfScoresFullRandomCopy1 = tableOfScoresFullRandom; // Copia para Bubble Sort
		vector<int> tableOfScoresFullRandomCopy2 = tableOfScoresFullRandom; // Copia para Heap Sort
		vector<int> tableOfScoresFullRandomCopy3 = tableOfScoresFullRandom; // Copia para Quick Sort
		vector<int> tableOfScoresFullRandomCopy4 = tableOfScoresFullRandom; // Copia para Merge sort
		vector<int> tableOfScoresFullRandomCopy5 = tableOfScoresFullRandom; // Copia para Selection Sort
		vector<int> tableOfScoresFullRandomCopy6 = tableOfScoresFullRandom; // Copia para Insertion Sort
		vector<int> tableOfScoresFullRandomCopy7 = tableOfScoresFullRandom; // Copia para Shell Sort
		
		vector<int> tableOfScoresOrderCopy1 = tableOfScoresOrder; // Copia para Bubble Sort
		vector<int> tableOfScoresOrderCopy2 = tableOfScoresOrder; // Copia para Heap Sort
		vector<int> tableOfScoresOrderCopy3 = tableOfScoresOrder; // Copia para Quick Sort
		vector<int> tableOfScoresOrderCopy4 = tableOfScoresOrder; // Copia para Merge sort
		vector<int> tableOfScoresOrderCopy5 = tableOfScoresOrder; // Copia para Selection Sort
		vector<int> tableOfScoresOrderCopy6 = tableOfScoresOrder; // Copia para Insertion Sort
		vector<int> tableOfScoresOrderCopy7 = tableOfScoresOrder; // Copia para Shell Sort
		
		vector<int> tableOfScoresDisorderCopy1 = tableOfScoresDisorder; // Copia para Bubble Sort
		vector<int> tableOfScoresDisorderCopy2 = tableOfScoresDisorder; // Copia para Heap Sort
		vector<int> tableOfScoresDisorderCopy3 = tableOfScoresDisorder; // Copia para Quick Sort
		vector<int> tableOfScoresDisorderCopy4 = tableOfScoresDisorder; // Copia para Merge sort
		vector<int> tableOfScoresDisorderCopy5 = tableOfScoresDisorder; // Copia para Selection Sort
		vector<int> tableOfScoresDisorderCopy6 = tableOfScoresDisorder; // Copia para Insertion Sort
		vector<int> tableOfScoresDisorderCopy7 = tableOfScoresDisorder; // Copia para Shell Sort
		
		system("pause");
	    cout << endl;
		

        cout << "Llenando vectores del area : Determinacion de camino entre aldeas" << endl<< endl;

        semiRandomVector(villagesRoadsSemiRandom, range2); //Set de datos aleatorios
        fullRandomVector(villagesRoadsFullRandom, range2); //Set de datos aleatorios duplicados
        ascendingVector(villagesRoadsOrder, range2);      //Set de datos ordenados
        descendingVector(villagesRoadsDisorder, range2);  //Set de datos inversamente ordenados
        
        //creando copias        
        vector<int> villagesRoadsSemiRandomCopy1 = villagesRoadsSemiRandom; // Copia para Bubble Sort
		vector<int> villagesRoadsSemiRandomCopy2 = villagesRoadsSemiRandom; // Copia para Heap Sort
		vector<int> villagesRoadsSemiRandomCopy3 = villagesRoadsSemiRandom; // Copia para Quick Sort
		vector<int> villagesRoadsSemiRandomCopy4 = villagesRoadsSemiRandom; // Copia para Merge sort
		vector<int> villagesRoadsSemiRandomCopy5 = villagesRoadsSemiRandom; // Copia para Selection Sort
		vector<int> villagesRoadsSemiRandomCopy6 = villagesRoadsSemiRandom; // Copia para Insertion Sort
		vector<int> villagesRoadsSemiRandomCopy7 = villagesRoadsSemiRandom; // Copia para Shell Sort
		
		vector<int> villagesRoadsFullRandomCopy1 = villagesRoadsFullRandom; // Copia para Bubble Sort
		vector<int> villagesRoadsFullRandomCopy2 = villagesRoadsFullRandom; // Copia para Heap Sort
		vector<int> villagesRoadsFullRandomCopy3 = villagesRoadsFullRandom; // Copia para Quick Sort
		vector<int> villagesRoadsFullRandomCopy4 = villagesRoadsFullRandom; // Copia para Merge sort
		vector<int> villagesRoadsFullRandomCopy5 = villagesRoadsFullRandom; // Copia para Selection Sort
		vector<int> villagesRoadsFullRandomCopy6 = villagesRoadsFullRandom; // Copia para Insertion Sort
		vector<int> villagesRoadsFullRandomCopy7 = villagesRoadsFullRandom; // Copia para Shell Sort
		
		vector<int> villagesRoadsOrderCopy1 = villagesRoadsOrder; // Copia para Bubble Sort
		vector<int> villagesRoadsOrderCopy2 = villagesRoadsOrder; // Copia para Heap Sort
		vector<int> villagesRoadsOrderCopy3 = villagesRoadsOrder; // Copia para Quick Sort
		vector<int> villagesRoadsOrderCopy4 = villagesRoadsOrder; // Copia para Merge sort
		vector<int> villagesRoadsOrderCopy5 = villagesRoadsOrder; // Copia para Selection Sort
		vector<int> villagesRoadsOrderCopy6 = villagesRoadsOrder; // Copia para Insertion Sort
		vector<int> villagesRoadsOrderCopy7 = villagesRoadsOrder; // Copia para Shell Sort
		
		vector<int> villagesRoadsDisorderCopy1 = villagesRoadsDisorder; // Copia para Bubble Sort
		vector<int> villagesRoadsDisorderCopy2 = villagesRoadsDisorder; // Copia para Heap Sort
		vector<int> villagesRoadsDisorderCopy3 = villagesRoadsDisorder; // Copia para Quick Sort
		vector<int> villagesRoadsDisorderCopy4 = villagesRoadsDisorder; // Copia para Merge sort
		vector<int> villagesRoadsDisorderCopy5 = villagesRoadsDisorder; // Copia para Selection Sort
		vector<int> villagesRoadsDisorderCopy6 = villagesRoadsDisorder; // Copia para Insertion Sort
		vector<int> villagesRoadsDisorderCopy7 = villagesRoadsDisorder; // Copia para Shell Sort
        
		system("pause");
	    cout << endl;

        cout << "Llenando vectores del area : Dibujo o renderizado de objetos" << endl<< endl;

        semiRandomVector(drawingSemiRandom, range3); //Set de datos aleatorios
        fullRandomVector(drawingFullRandom, range3); //Set de datos aleatorios duplicados
        ascendingVector(drawingOrder, range3);      //Set de datos ordenados
        descendingVector(drawingDisorder, range3);  //Set de datos inversamente ordenados
        
        //creando copias        
        vector<int> drawingSemiRandomCopy1 = drawingSemiRandom; // Copia para Bubble Sort
		vector<int> drawingSemiRandomCopy2 = drawingSemiRandom; // Copia para Heap Sort
		vector<int> drawingSemiRandomCopy3 = drawingSemiRandom; // Copia para Quick Sort
		vector<int> drawingSemiRandomCopy4 = drawingSemiRandom; // Copia para Merge sort
		vector<int> drawingSemiRandomCopy5 = drawingSemiRandom; // Copia para Selection Sort
		vector<int> drawingSemiRandomCopy6 = drawingSemiRandom; // Copia para Insertion Sort
		vector<int> drawingSemiRandomCopy7 = drawingSemiRandom; // Copia para Shell Sort
		
		vector<int> drawingFullRandomCopy1 = drawingFullRandom; // Copia para Bubble Sort
		vector<int> drawingFullRandomCopy2 = drawingFullRandom; // Copia para Heap Sort
		vector<int> drawingFullRandomCopy3 = drawingFullRandom; // Copia para Quick Sort
		vector<int> drawingFullRandomCopy4 = drawingFullRandom; // Copia para Merge sort
		vector<int> drawingFullRandomCopy5 = drawingFullRandom; // Copia para Selection Sort
		vector<int> drawingFullRandomCopy6 = drawingFullRandom; // Copia para Insertion Sort
		vector<int> drawingFullRandomCopy7 = drawingFullRandom; // Copia para Shell Sort
		
		vector<int> drawingOrderCopy1 = drawingOrder; // Copia para Bubble Sort
		vector<int> drawingOrderCopy2 = drawingOrder; // Copia para Heap Sort
		vector<int> drawingOrderCopy3 = drawingOrder; // Copia para Quick Sort
		vector<int> drawingOrderCopy4 = drawingOrder; // Copia para Merge sort
		vector<int> drawingOrderCopy5 = drawingOrder; // Copia para Selection Sort
		vector<int> drawingOrderCopy6 = drawingOrder; // Copia para Insertion Sort
		vector<int> drawingOrderCopy7 = drawingOrder; // Copia para Shell Sort
		
		vector<int> drawingDisorderCopy1 = drawingDisorder; // Copia para Bubble Sort
		vector<int> drawingDisorderCopy2 = drawingDisorder; // Copia para Heap Sort
		vector<int> drawingDisorderCopy3 = drawingDisorder; // Copia para Quick Sort
		vector<int> drawingDisorderCopy4 = drawingDisorder; // Copia para Merge sort
		vector<int> drawingDisorderCopy5 = drawingDisorder; // Copia para Selection Sort
		vector<int> drawingDisorderCopy6 = drawingDisorder; // Copia para Insertion Sort
		vector<int> drawingDisorderCopy7 = drawingDisorder; // Copia para Shell Sort
		
		system("pause");
	    cout << endl;

        cout << "Todos los vectores han sido llenados correctamente!!" << endl<< endl;

        cout << "Ahora vamos a poner a prueba los vectores en los siguientes algoritmos: " << endl<< endl;
             
        cout << "\t1)Bubble sort" << endl
             << "\t2)Heap sort" << endl
             << "\t3)Quick sort" << endl
             << "\t4)Merge sort" << endl
             << "\t5)Selection sort" << endl
             << "\t6)Insertion sort" << endl
             << "\t7)Shell sort" << endl << endl;
             
        system("pause");
        cout << endl;
    	
    	cout << "QUE COMIENCEN LAS CARRERAS!!!" << endl << endl;
    	
    	cout << "\t\t\t1)Carreras por tablero" << endl << endl;
    	
    	cout << "A)Carrera por tablero : Modo aleatorio sin duplicados" << endl << endl;
    	
	    auto startTime1A = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresSemiRandomCopy1);
	    auto endTime1A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1A = endTime1A - startTime1A;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1A.count() << " segundos" << endl;
	    
	    auto startTime2A = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresSemiRandomCopy2);
	    auto endTime2A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2A = endTime2A - startTime2A;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2A.count() << " segundos" << endl;
	    
	    auto startTime3A = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresSemiRandomCopy3, 0, tableOfScoresSemiRandomCopy3.size() - 1);
		auto endTime3A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3A = endTime3A - startTime3A;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3A.count() << " segundos" << endl;
	    
	    auto startTime4A = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresSemiRandomCopy4, 0, tableOfScoresSemiRandomCopy4.size() - 1);
		auto endTime4A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4A = endTime4A - startTime4A;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4A.count() << " segundos" << endl;
	    
	    auto startTime5A = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresSemiRandomCopy5);
	    auto endTime5A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5A = endTime5A - startTime5A;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5A.count() << " segundos" << endl;
	    
	    auto startTime6A = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresSemiRandomCopy6);
	    auto endTime6A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6A = endTime6A - startTime6A;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6A.count() << " segundos" << endl;
	    
	    auto startTime7A = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresSemiRandomCopy7);
	    auto endTime7A = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7A = endTime7A - startTime7A;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7A.count() << " segundos" << endl;
	    
	    findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort",elapsedSeconds1A.count(), elapsedSeconds2A.count(), elapsedSeconds3A.count(), elapsedSeconds4A.count(), elapsedSeconds5A.count(), elapsedSeconds6A.count(), elapsedSeconds7A.count());

		
		cout << endl<<endl;
	    
	           	
    	cout << "B)Carrera por tablero : Modo aleatorio con posibilidad de  duplicados" << endl << endl;
    	
    	auto startTime1B = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresFullRandomCopy1);
	    auto endTime1B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1B = endTime1B - startTime1B;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1B.count() << " segundos" << endl;
	    
	    auto startTime2B = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresFullRandomCopy2);
	    auto endTime2B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2B = endTime2B - startTime2B;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2B.count() << " segundos" << endl;
	    
	    auto startTime3B = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresFullRandomCopy3, 0, tableOfScoresFullRandomCopy3.size() - 1);
		auto endTime3B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3B = endTime3B - startTime3B;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3B.count() << " segundos" << endl;
	    
	    auto startTime4B = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresFullRandomCopy4, 0, tableOfScoresFullRandomCopy4.size() - 1);
		auto endTime4B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4B = endTime4B - startTime4B;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4B.count() << " segundos" << endl;
	    
	    auto startTime5B = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresFullRandomCopy5);
	    auto endTime5B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5B = endTime5B - startTime5B;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5B.count() << " segundos" << endl;
	    
	    auto startTime6B = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresFullRandomCopy6);
	    auto endTime6B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6B = endTime6B - startTime6B;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6B.count() << " segundos" << endl;
	    
	    auto startTime7B = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresFullRandomCopy7);
	    auto endTime7B = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7B = endTime7B - startTime7B;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7B.count() << " segundos" << endl;
	    
	    findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1B.count(), elapsedSeconds2B.count(), elapsedSeconds3B.count(), elapsedSeconds4B.count(), elapsedSeconds5B.count(), elapsedSeconds6B.count(), elapsedSeconds7B.count());
    	
    	cout << endl<<endl;
    	
    	cout << "C)Carrera por tablero : Modo ordenado" << endl << endl;
    	
    	auto startTime1C = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresOrderCopy1);
	    auto endTime1C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1C = endTime1C - startTime1C;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1C.count() << " segundos" << endl;
	    
	    auto startTime2C = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresOrderCopy2);
	    auto endTime2C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2C = endTime2C - startTime2C;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2C.count() << " segundos" << endl;
	    
	    auto startTime3C = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresOrderCopy3, 0, tableOfScoresOrderCopy3.size() - 1);
		auto endTime3C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3C = endTime3C - startTime3C;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3C.count() << " segundos" << endl;
	    
	    auto startTime4C = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresOrderCopy4, 0, tableOfScoresOrderCopy4.size() - 1);
		auto endTime4C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4C = endTime4C - startTime4C;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4C.count() << " segundos" << endl;
	    
	    auto startTime5C = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresOrderCopy5);
	    auto endTime5C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5C = endTime5C - startTime5C;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5C.count() << " segundos" << endl;
	    
	    auto startTime6C = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresOrderCopy6);
	    auto endTime6C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6C = endTime6C - startTime6C;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6C.count() << " segundos" << endl;
	    
	    auto startTime7C = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresOrderCopy7);
	    auto endTime7C = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7C = endTime7C - startTime7C;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7C.count() << " segundos" << endl;
	    
	    findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1C.count(), elapsedSeconds2C.count(), elapsedSeconds3C.count(), elapsedSeconds4C.count(), elapsedSeconds5C.count(), elapsedSeconds6C.count(), elapsedSeconds7C.count());

    	
    	cout << endl<<endl;
    	
    	cout << "D)Carrera por tablero : Modo inversamente ordenado" << endl << endl;
    	
    	auto startTime1D = chrono::high_resolution_clock::now();
	    bubbleSortAscendant(tableOfScoresDisorderCopy1);
	    auto endTime1D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds1D = endTime1D - startTime1D;
	    cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1D.count() << " segundos" << endl;
	    
	    auto startTime2D = chrono::high_resolution_clock::now();
	    heapSortAscendant(tableOfScoresDisorderCopy2);
	    auto endTime2D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds2D = endTime2D - startTime2D;
	    cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2D.count() << " segundos" << endl;
	    
	    auto startTime3D = chrono::high_resolution_clock::now();
		quickSortAscendant(tableOfScoresDisorderCopy3, 0, tableOfScoresDisorderCopy3.size() - 1);
		auto endTime3D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3D = endTime3D - startTime3D;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3D.count() << " segundos" << endl;
	    
	    auto startTime4D = chrono::high_resolution_clock::now();
		mergeSortAscendant(tableOfScoresDisorderCopy4, 0, tableOfScoresDisorderCopy4.size() - 1);
		auto endTime4D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4D = endTime4D - startTime4D;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4D.count() << " segundos" << endl;
	    
	    auto startTime5D = chrono::high_resolution_clock::now();
	    selectionSort(tableOfScoresDisorderCopy5);
	    auto endTime5D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds5D = endTime5D - startTime5D;
	    cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5D.count() << " segundos" << endl;
	    
	    auto startTime6D = chrono::high_resolution_clock::now();
	    insertionSortAscendant(tableOfScoresDisorderCopy6);
	    auto endTime6D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds6D = endTime6D - startTime6D;
	    cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6D.count() << " segundos" << endl;
	    
	    auto startTime7D = chrono::high_resolution_clock::now();
	    shellSortAscendant(tableOfScoresDisorderCopy7);
	    auto endTime7D = chrono::high_resolution_clock::now();
	    chrono::duration<double> elapsedSeconds7D = endTime7D - startTime7D;
	    cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7D.count() << " segundos" << endl<<endl;
	    
	    findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1D.count(), elapsedSeconds2D.count(), elapsedSeconds3D.count(), elapsedSeconds4D.count(), elapsedSeconds5D.count(), elapsedSeconds6D.count(), elapsedSeconds7D.count());
         
		system("pause");
        cout << endl;
		     
        cout << "\t\t\t2)Carreras por caminos entre aldeas" << endl << endl;
        
        cout << "A)Carrera por caminos : Modo aleatorio sin duplicados" << endl << endl;
        
        auto startTime1E = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsSemiRandomCopy1);
		auto endTime1E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1E = endTime1E - startTime1E;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1E.count() << " segundos" << endl;
		
		auto startTime2E = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsSemiRandomCopy2);
		auto endTime2E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2E = endTime2E - startTime2E;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2E.count() << " segundos" << endl;
		
		auto startTime3E = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsSemiRandomCopy3, 0, villagesRoadsSemiRandomCopy3.size() - 1);
		auto endTime3E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3E = endTime3E - startTime3E;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4E = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsSemiRandomCopy4, 0, villagesRoadsSemiRandomCopy4.size() - 1);
		auto endTime4E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4E = endTime4E - startTime4E;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4E.count() << " segundos" << endl;
		
		auto startTime5E = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsSemiRandomCopy5);
		auto endTime5E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5E = endTime5E - startTime5E;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5E.count() << " segundos" << endl;
		
		auto startTime6E = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsSemiRandomCopy6);
		auto endTime6E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6E = endTime6E - startTime6E;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6E.count() << " segundos" << endl;
		
		auto startTime7E = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsSemiRandomCopy7);
		auto endTime7E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7E = endTime7E - startTime7E;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7E.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1E.count(), elapsedSeconds2E.count(), elapsedSeconds3E.count(), elapsedSeconds4E.count(), elapsedSeconds5E.count(), elapsedSeconds6E.count(), elapsedSeconds7E.count());
		
		cout << endl << endl;		
		cout << "B)Carrera por caminos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1F = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsFullRandomCopy1);
		auto endTime1F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1F = endTime1F - startTime1F;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1F.count() << " segundos" << endl;
		
		auto startTime2F = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsFullRandomCopy2);
		auto endTime2F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2F = endTime2F - startTime2F;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2F.count() << " segundos" << endl;
		
		auto startTime3F = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsFullRandomCopy3, 0, villagesRoadsFullRandomCopy3.size() - 1);
		auto endTime3F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3F = endTime3F - startTime3F;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4F = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsFullRandomCopy4, 0, villagesRoadsFullRandomCopy4.size() - 1);
		auto endTime4F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4F = endTime4F - startTime4F;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4F.count() << " segundos" << endl;
		
		auto startTime5F = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsFullRandomCopy5);
		auto endTime5F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5F = endTime5F - startTime5F;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5F.count() << " segundos" << endl;
		
		auto startTime6F = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsFullRandomCopy6);
		auto endTime6F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6F = endTime6F - startTime6F;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6F.count() << " segundos" << endl;
		
		auto startTime7F = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsFullRandomCopy7);
		auto endTime7F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7F = endTime7F - startTime7F;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7F.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1F.count(), elapsedSeconds2F.count(), elapsedSeconds3F.count(), elapsedSeconds4F.count(), elapsedSeconds5F.count(), elapsedSeconds6F.count(), elapsedSeconds7F.count());
		
		cout << endl << endl;
		cout << "C)Carrera por caminos : Modo ordenado" << endl << endl;
		
		auto startTime1G = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsOrderCopy1);
		auto endTime1G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1G = endTime1G - startTime1G;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1G.count() << " segundos" << endl;
		
		auto startTime2G = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsOrderCopy2);
		auto endTime2G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2G = endTime2G - startTime2G;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2G.count() << " segundos" << endl;
		
		auto startTime3G = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsOrderCopy3, 0, villagesRoadsOrderCopy3.size() - 1);
		auto endTime3G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3G = endTime3G - startTime3G;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3G.count() << " segundos" << endl;
		
		auto startTime4G = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsOrderCopy4, 0, villagesRoadsOrderCopy4.size() - 1);
		auto endTime4G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4G = endTime4G - startTime4G;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4G.count() << " segundos" << endl;
		
		auto startTime5G = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsOrderCopy5);
		auto endTime5G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5G = endTime5G - startTime5G;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5G.count() << " segundos" << endl;
		
		auto startTime6G = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsOrderCopy6);
		auto endTime6G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6G = endTime6G - startTime6G;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6G.count() << " segundos" << endl;
		
		auto startTime7G = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsOrderCopy7);
		auto endTime7G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7G = endTime7G - startTime7G;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7G.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1G.count(), elapsedSeconds2G.count(), elapsedSeconds3G.count(), elapsedSeconds4G.count(), elapsedSeconds5G.count(), elapsedSeconds6G.count(), elapsedSeconds7G.count());
		
		cout << endl << endl;
		cout << "D)Carrera por caminos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1H = chrono::high_resolution_clock::now();
		bubbleSortAscendant(villagesRoadsDisorderCopy1);
		auto endTime1H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1H = endTime1H - startTime1H;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1H.count() << " segundos" << endl;
		
		auto startTime2H = chrono::high_resolution_clock::now();
		heapSortAscendant(villagesRoadsDisorderCopy2);
		auto endTime2H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2H = endTime2H - startTime2H;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2H.count() << " segundos" << endl;
		
		auto startTime3H = chrono::high_resolution_clock::now();
		quickSortAscendant(villagesRoadsDisorderCopy3, 0, villagesRoadsDisorderCopy3.size() - 1);
		auto endTime3H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3H = endTime3H - startTime3H;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3H.count() << " segundos" << endl;
		
		auto startTime4H = chrono::high_resolution_clock::now();
		mergeSortAscendant(villagesRoadsDisorderCopy4, 0, villagesRoadsDisorderCopy4.size() - 1);
		auto endTime4H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4H = endTime4H - startTime4H;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4H.count() << " segundos" << endl;
		
		auto startTime5H = chrono::high_resolution_clock::now();
		selectionSort(villagesRoadsDisorderCopy5);
		auto endTime5H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5H = endTime5H - startTime5H;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5H.count() << " segundos" << endl;
		
		auto startTime6H = chrono::high_resolution_clock::now();
		insertionSortAscendant(villagesRoadsDisorderCopy6);
		auto endTime6H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6H = endTime6H - startTime6H;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6H.count() << " segundos" << endl;
		
		auto startTime7H = chrono::high_resolution_clock::now();
		shellSortAscendant(villagesRoadsDisorderCopy7);
		auto endTime7H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7H = endTime7H - startTime7H;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7H.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1H.count(), elapsedSeconds2H.count(), elapsedSeconds3H.count(), elapsedSeconds4H.count(), elapsedSeconds5H.count(), elapsedSeconds6H.count(), elapsedSeconds7H.count());
		
		cout << endl << endl;
		
		system("pause");
        cout << endl;
        
        cout << "\t\t\t3)Carreras por los dibujos" << endl << endl;
        
        cout << "A)Carrera por dibujos : Modo aleatorio sin duplicados" << endl << endl;
        
        auto startTime1I = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingSemiRandomCopy1);
		auto endTime1I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1I = endTime1I - startTime1I;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1I.count() << " segundos" << endl;
		
		auto startTime2I = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingSemiRandomCopy2);
		auto endTime2I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2I = endTime2I - startTime2I;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2I.count() << " segundos" << endl;
		
		auto startTime3I = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingSemiRandomCopy3, 0, drawingSemiRandomCopy3.size() - 1);
		auto endTime3I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3I = endTime3I - startTime3I;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3I.count() << " segundos" << endl;
		
		auto startTime4I = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingSemiRandomCopy4, 0, drawingSemiRandomCopy4.size() - 1);
		auto endTime4I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4I = endTime4I - startTime4I;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4I.count() << " segundos" << endl;
		
		auto startTime5I = chrono::high_resolution_clock::now();
		selectionSort(drawingSemiRandomCopy5);
		auto endTime5I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5I = endTime5I - startTime5I;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5I.count() << " segundos" << endl;
		
		auto startTime6I = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingSemiRandomCopy6);
		auto endTime6I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6I = endTime6I - startTime6I;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6I.count() << " segundos" << endl;
		
		auto startTime7I = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingSemiRandomCopy7);
		auto endTime7I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7I = endTime7I - startTime7I;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7I.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1I.count(), elapsedSeconds2I.count(), elapsedSeconds3I.count(), elapsedSeconds4I.count(), elapsedSeconds5I.count(), elapsedSeconds6I.count(), elapsedSeconds7I.count());
		
		cout << endl << endl;
		cout << "B)Carrera por dibujos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1J = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingFullRandomCopy1);
		auto endTime1J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1J = endTime1J - startTime1J;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1J.count() << " segundos" << endl;
		
		auto startTime2J = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingFullRandomCopy2);
		auto endTime2J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2J = endTime2J - startTime2J;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2J.count() << " segundos" << endl;
		
		auto startTime3J = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingFullRandomCopy3, 0, drawingFullRandomCopy3.size() - 1);
		auto endTime3J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3J = endTime3J - startTime3J;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3J.count() << " segundos" << endl;
		
		auto startTime4J = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingFullRandomCopy4, 0, drawingFullRandomCopy4.size() - 1);
		auto endTime4J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4J = endTime4J - startTime4J;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4J.count() << " segundos" << endl;
		
		auto startTime5J = chrono::high_resolution_clock::now();
		selectionSort(drawingFullRandomCopy5);
		auto endTime5J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5J = endTime5J - startTime5J;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5J.count() << " segundos" << endl;
		
		auto startTime6J = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingFullRandomCopy6);
		auto endTime6J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6J = endTime6J - startTime6J;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6J.count() << " segundos" << endl;
		
		auto startTime7J = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingFullRandomCopy7);
		auto endTime7J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7J = endTime7J - startTime7J;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7J.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1J.count(), elapsedSeconds2J.count(), elapsedSeconds3J.count(), elapsedSeconds4J.count(), elapsedSeconds5J.count(), elapsedSeconds6J.count(), elapsedSeconds7J.count());
		
		cout << endl << endl;
		cout << "C)Carrera por dibujos : Modo ordenado" << endl << endl;
		
		auto startTime1K = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingOrderCopy1);
		auto endTime1K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1K = endTime1K - startTime1K;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1K.count() << " segundos" << endl;
		
		auto startTime2K = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingOrderCopy2);
		auto endTime2K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2K = endTime2K - startTime2K;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2K.count() << " segundos" << endl;
		
		auto startTime3K = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingOrderCopy3, 0, drawingOrderCopy3.size() - 1);
		auto endTime3K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3K = endTime3K - startTime3K;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3K.count() << " segundos" << endl;
		
		auto startTime4K = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingOrderCopy4, 0, drawingOrderCopy4.size() - 1);
		auto endTime4K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4K = endTime4K - startTime4K;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4K.count() << " segundos" << endl;
		
		auto startTime5K = chrono::high_resolution_clock::now();
		selectionSort(drawingOrderCopy5);
		auto endTime5K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5K = endTime5K - startTime5K;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5K.count() << " segundos" << endl;
		
		auto startTime6K = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingOrderCopy6);
		auto endTime6K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6K = endTime6K - startTime6K;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6K.count() << " segundos" << endl;
		
		auto startTime7K = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingOrderCopy7);
		auto endTime7K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7K = endTime7K - startTime7K;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7K.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1K.count(), elapsedSeconds2K.count(), elapsedSeconds3K.count(), elapsedSeconds4K.count(), elapsedSeconds5K.count(), elapsedSeconds6K.count(), elapsedSeconds7K.count());
		
		cout << endl << endl;
		cout << "D)Carrera por dibujos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1L = chrono::high_resolution_clock::now();
		bubbleSortAscendant(drawingDisorderCopy1);
		auto endTime1L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1L = endTime1L - startTime1L;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1L.count() << " segundos" << endl;
		
		auto startTime2L = chrono::high_resolution_clock::now();
		heapSortAscendant(drawingDisorderCopy2);
		auto endTime2L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2L = endTime2L - startTime2L;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2L.count() << " segundos" << endl;
		
		auto startTime3L = chrono::high_resolution_clock::now();
		quickSortAscendant(drawingDisorderCopy3, 0, drawingDisorderCopy3.size() - 1);
		auto endTime3L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3L = endTime3L - startTime3L;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3L.count() << " segundos" << endl;
		
		auto startTime4L = chrono::high_resolution_clock::now();
		mergeSortAscendant(drawingDisorderCopy4, 0, drawingDisorderCopy4.size() - 1);
		auto endTime4L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4L = endTime4L - startTime4L;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4L.count() << " segundos" << endl;
		
		auto startTime5L = chrono::high_resolution_clock::now();
		selectionSort(drawingDisorderCopy5);
		auto endTime5L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5L = endTime5L - startTime5L;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5L.count() << " segundos" << endl;
		
		auto startTime6L = chrono::high_resolution_clock::now();
		insertionSortAscendant(drawingDisorderCopy6);
		auto endTime6L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6L = endTime6L - startTime6L;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6L.count() << " segundos" << endl;
		
		auto startTime7L = chrono::high_resolution_clock::now();
		shellSortAscendant(drawingDisorderCopy7);
		auto endTime7L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7L = endTime7L - startTime7L;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7L.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1L.count(), elapsedSeconds2L.count(), elapsedSeconds3L.count(), elapsedSeconds4L.count(), elapsedSeconds5L.count(), elapsedSeconds6L.count(), elapsedSeconds7L.count());   
	}
	
	else if(Order == 2)
	{
		cout << "Llenando vectores del area : Tablero de puntajes" << endl<< endl;

        semiRandomVector(tableOfScoresSemiRandom, range1); //Set de datos aleatorios
        fullRandomVector(tableOfScoresFullRandom, range1); //Set de datos aleatorios duplicados        
        descendingVector(tableOfScoresDisorder, range1);//Set de datos ordenados
        ascendingVector(tableOfScoresOrder, range1);   //Set de datos inversamente ordenados   
		
		//creando copias        
        vector<int> tableOfScoresSemiRandomCopy1 = tableOfScoresSemiRandom; // Copia para Bubble Sort
		vector<int> tableOfScoresSemiRandomCopy2 = tableOfScoresSemiRandom; // Copia para Heap Sort
		vector<int> tableOfScoresSemiRandomCopy3 = tableOfScoresSemiRandom; // Copia para Quick Sort
		vector<int> tableOfScoresSemiRandomCopy4 = tableOfScoresSemiRandom; // Copia para Merge sort
		vector<int> tableOfScoresSemiRandomCopy5 = tableOfScoresSemiRandom; // Copia para Selection Sort
		vector<int> tableOfScoresSemiRandomCopy6 = tableOfScoresSemiRandom; // Copia para Insertion Sort
		vector<int> tableOfScoresSemiRandomCopy7 = tableOfScoresSemiRandom; // Copia para Shell Sort
		
		vector<int> tableOfScoresFullRandomCopy1 = tableOfScoresFullRandom; // Copia para Bubble Sort
		vector<int> tableOfScoresFullRandomCopy2 = tableOfScoresFullRandom; // Copia para Heap Sort
		vector<int> tableOfScoresFullRandomCopy3 = tableOfScoresFullRandom; // Copia para Quick Sort
		vector<int> tableOfScoresFullRandomCopy4 = tableOfScoresFullRandom; // Copia para Merge sort
		vector<int> tableOfScoresFullRandomCopy5 = tableOfScoresFullRandom; // Copia para Selection Sort
		vector<int> tableOfScoresFullRandomCopy6 = tableOfScoresFullRandom; // Copia para Insertion Sort
		vector<int> tableOfScoresFullRandomCopy7 = tableOfScoresFullRandom; // Copia para Shell Sort
		
		vector<int> tableOfScoresDisorderCopy1 = tableOfScoresDisorder; // Copia para Bubble Sort
		vector<int> tableOfScoresDisorderCopy2 = tableOfScoresDisorder; // Copia para Heap Sort
		vector<int> tableOfScoresDisorderCopy3 = tableOfScoresDisorder; // Copia para Quick Sort
		vector<int> tableOfScoresDisorderCopy4 = tableOfScoresDisorder; // Copia para Merge sort
		vector<int> tableOfScoresDisorderCopy5 = tableOfScoresDisorder; // Copia para Selection Sort
		vector<int> tableOfScoresDisorderCopy6 = tableOfScoresDisorder; // Copia para Insertion Sort
		vector<int> tableOfScoresDisorderCopy7 = tableOfScoresDisorder; // Copia para Shell Sort  
		
		vector<int> tableOfScoresOrderCopy1 = tableOfScoresOrder; // Copia para Bubble Sort
		vector<int> tableOfScoresOrderCopy2 = tableOfScoresOrder; // Copia para Heap Sort
		vector<int> tableOfScoresOrderCopy3 = tableOfScoresOrder; // Copia para Quick Sort
		vector<int> tableOfScoresOrderCopy4 = tableOfScoresOrder; // Copia para Merge sort
		vector<int> tableOfScoresOrderCopy5 = tableOfScoresOrder; // Copia para Selection Sort
		vector<int> tableOfScoresOrderCopy6 = tableOfScoresOrder; // Copia para Insertion Sort
		vector<int> tableOfScoresOrderCopy7 = tableOfScoresOrder; // Copia para Shell Sort
		
		system("pause");
        cout << endl;
		
		

        cout << "Llenando vectores del area : Determinacion de camino entre aldeas" << endl<< endl;

        semiRandomVector(villagesRoadsSemiRandom, range2); //Set de datos aleatorios
        fullRandomVector(villagesRoadsFullRandom, range2); //Set de datos aleatorios duplicados       
        descendingVector(villagesRoadsDisorder, range2);//Set de datos ordenados
        ascendingVector(villagesRoadsOrder, range2);  //Set de datos inversamente ordenados 
		
		//creando copias        
        vector<int> villagesRoadsSemiRandomCopy1 = villagesRoadsSemiRandom; // Copia para Bubble Sort
		vector<int> villagesRoadsSemiRandomCopy2 = villagesRoadsSemiRandom; // Copia para Heap Sort
		vector<int> villagesRoadsSemiRandomCopy3 = villagesRoadsSemiRandom; // Copia para Quick Sort
		vector<int> villagesRoadsSemiRandomCopy4 = villagesRoadsSemiRandom; // Copia para Merge sort
		vector<int> villagesRoadsSemiRandomCopy5 = villagesRoadsSemiRandom; // Copia para Selection Sort
		vector<int> villagesRoadsSemiRandomCopy6 = villagesRoadsSemiRandom; // Copia para Insertion Sort
		vector<int> villagesRoadsSemiRandomCopy7 = villagesRoadsSemiRandom; // Copia para Shell Sort
		
		vector<int> villagesRoadsFullRandomCopy1 = villagesRoadsFullRandom; // Copia para Bubble Sort
		vector<int> villagesRoadsFullRandomCopy2 = villagesRoadsFullRandom; // Copia para Heap Sort
		vector<int> villagesRoadsFullRandomCopy3 = villagesRoadsFullRandom; // Copia para Quick Sort
		vector<int> villagesRoadsFullRandomCopy4 = villagesRoadsFullRandom; // Copia para Merge sort
		vector<int> villagesRoadsFullRandomCopy5 = villagesRoadsFullRandom; // Copia para Selection Sort
		vector<int> villagesRoadsFullRandomCopy6 = villagesRoadsFullRandom; // Copia para Insertion Sort
		vector<int> villagesRoadsFullRandomCopy7 = villagesRoadsFullRandom; // Copia para Shell Sort
		
		vector<int> villagesRoadsDisorderCopy1 = villagesRoadsDisorder; // Copia para Bubble Sort
		vector<int> villagesRoadsDisorderCopy2 = villagesRoadsDisorder; // Copia para Heap Sort
		vector<int> villagesRoadsDisorderCopy3 = villagesRoadsDisorder; // Copia para Quick Sort
		vector<int> villagesRoadsDisorderCopy4 = villagesRoadsDisorder; // Copia para Merge sort
		vector<int> villagesRoadsDisorderCopy5 = villagesRoadsDisorder; // Copia para Selection Sort
		vector<int> villagesRoadsDisorderCopy6 = villagesRoadsDisorder; // Copia para Insertion Sort
		vector<int> villagesRoadsDisorderCopy7 = villagesRoadsDisorder; // Copia para Shell Sort
		
		vector<int> villagesRoadsOrderCopy1 = villagesRoadsOrder; // Copia para Bubble Sort
		vector<int> villagesRoadsOrderCopy2 = villagesRoadsOrder; // Copia para Heap Sort
		vector<int> villagesRoadsOrderCopy3 = villagesRoadsOrder; // Copia para Quick Sort
		vector<int> villagesRoadsOrderCopy4 = villagesRoadsOrder; // Copia para Merge sort
		vector<int> villagesRoadsOrderCopy5 = villagesRoadsOrder; // Copia para Selection Sort
		vector<int> villagesRoadsOrderCopy6 = villagesRoadsOrder; // Copia para Insertion Sort
		vector<int> villagesRoadsOrderCopy7 = villagesRoadsOrder; // Copia para Shell Sort
		
		system("pause");
        cout << endl;
		
		     

        cout << "Llenando vectores del area : Dibujo o renderizado de objetos" << endl<< endl;

        semiRandomVector(drawingSemiRandom, range3); //Set de datos aleatorios
        fullRandomVector(drawingFullRandom, range3); //Set de datos aleatorios duplicados        
        descendingVector(drawingDisorder, range3);//Set de datos ordenados
        ascendingVector(drawingOrder, range3);  //Set de datos inversamente ordenados
        
        //creando copias        
        vector<int> drawingSemiRandomCopy1 = drawingSemiRandom; // Copia para Bubble Sort
		vector<int> drawingSemiRandomCopy2 = drawingSemiRandom; // Copia para Heap Sort
		vector<int> drawingSemiRandomCopy3 = drawingSemiRandom; // Copia para Quick Sort
		vector<int> drawingSemiRandomCopy4 = drawingSemiRandom; // Copia para Merge sort
		vector<int> drawingSemiRandomCopy5 = drawingSemiRandom; // Copia para Selection Sort
		vector<int> drawingSemiRandomCopy6 = drawingSemiRandom; // Copia para Insertion Sort
		vector<int> drawingSemiRandomCopy7 = drawingSemiRandom; // Copia para Shell Sort
		
		vector<int> drawingFullRandomCopy1 = drawingFullRandom; // Copia para Bubble Sort
		vector<int> drawingFullRandomCopy2 = drawingFullRandom; // Copia para Heap Sort
		vector<int> drawingFullRandomCopy3 = drawingFullRandom; // Copia para Quick Sort
		vector<int> drawingFullRandomCopy4 = drawingFullRandom; // Copia para Merge sort
		vector<int> drawingFullRandomCopy5 = drawingFullRandom; // Copia para Selection Sort
		vector<int> drawingFullRandomCopy6 = drawingFullRandom; // Copia para Insertion Sort
		vector<int> drawingFullRandomCopy7 = drawingFullRandom; // Copia para Shell Sort
		
		vector<int> drawingDisorderCopy1 = drawingDisorder; // Copia para Bubble Sort
		vector<int> drawingDisorderCopy2 = drawingDisorder; // Copia para Heap Sort
		vector<int> drawingDisorderCopy3 = drawingDisorder; // Copia para Quick Sort
		vector<int> drawingDisorderCopy4 = drawingDisorder; // Copia para Merge sort
		vector<int> drawingDisorderCopy5 = drawingDisorder; // Copia para Selection Sort
		vector<int> drawingDisorderCopy6 = drawingDisorder; // Copia para Insertion Sort
		vector<int> drawingDisorderCopy7 = drawingDisorder; // Copia para Shell Sort
		
		vector<int> drawingOrderCopy1 = drawingOrder; // Copia para Bubble Sort
		vector<int> drawingOrderCopy2 = drawingOrder; // Copia para Heap Sort
		vector<int> drawingOrderCopy3 = drawingOrder; // Copia para Quick Sort
		vector<int> drawingOrderCopy4 = drawingOrder; // Copia para Merge sort
		vector<int> drawingOrderCopy5 = drawingOrder; // Copia para Selection Sort
		vector<int> drawingOrderCopy6 = drawingOrder; // Copia para Insertion Sort
		vector<int> drawingOrderCopy7 = drawingOrder; // Copia para Shell Sort
		
		system("pause");
        cout << endl;
		
		

        cout << "Todos los vectores han sido llenados correctamente!!" << endl<< endl;

        cout << "Ahora vamos a poner a prueba los vectores en los siguientes algoritmos: " << endl<< endl;
             
        cout << "\t1)Bubble sort" << endl
             << "\t2)Heap sort" << endl
             << "\t3)Quick sort" << endl
             << "\t4)Merge sort" << endl
             << "\t5)Selection sort" << endl
             << "\t6)Insertion sort" << endl
             << "\t7)Shell sort" << endl << endl;
             
        system("pause");
        cout << endl;
    	
    	cout << "QUE COMIENCEN LAS CARRERAS!!!" << endl << endl;
    	
    	cout << "\t\t\t1)Carreras por tablero" << endl << endl;
    	
    	cout << "A)Carrera por tablero : Modo aleatorio sin duplicados" << endl << endl;

		auto startTime1A = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresSemiRandomCopy1);
		auto endTime1A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1A = endTime1A - startTime1A;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1A.count() << " segundos" << endl;
		
		auto startTime2A = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresSemiRandomCopy2);
		auto endTime2A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2A = endTime2A - startTime2A;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2A.count() << " segundos" << endl;
		
		auto startTime3A = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresSemiRandomCopy3, 0, tableOfScoresSemiRandomCopy3.size() - 1);
		auto endTime3A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3A = endTime3A - startTime3A;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3A.count() << " segundos" << endl;
		
		auto startTime4A = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresSemiRandomCopy4, 0, tableOfScoresSemiRandomCopy4.size() - 1);
		auto endTime4A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4A = endTime4A - startTime4A;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4A.count() << " segundos" << endl;
		
		auto startTime5A = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresSemiRandomCopy5);
		auto endTime5A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5A = endTime5A - startTime5A;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5A.count() << " segundos" << endl;
		
		auto startTime6A = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresSemiRandomCopy6);
		auto endTime6A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6A = endTime6A - startTime6A;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6A.count() << " segundos" << endl;
		
		auto startTime7A = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresSemiRandomCopy7);
		auto endTime7A = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7A = endTime7A - startTime7A;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7A.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort",elapsedSeconds1A.count(), elapsedSeconds2A.count(), elapsedSeconds3A.count(), elapsedSeconds4A.count(), elapsedSeconds5A.count(), elapsedSeconds6A.count(), elapsedSeconds7A.count());
		
		cout << endl<<endl;
		
		
		cout << "B)Carrera por tablero : Modo aleatorio con posibilidad de  duplicados" << endl << endl;
		
		auto startTime1B = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresFullRandomCopy1);
		auto endTime1B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1B = endTime1B - startTime1B;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1B.count() << " segundos" << endl;
		
		auto startTime2B = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresFullRandomCopy2);
		auto endTime2B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2B = endTime2B - startTime2B;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2B.count() << " segundos" << endl;
		
		auto startTime3B = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresFullRandomCopy3, 0, tableOfScoresFullRandomCopy3.size() - 1);
		auto endTime3B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3B = endTime3B - startTime3B;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3B.count() << " segundos" << endl;
		
		auto startTime4B = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresFullRandomCopy4, 0, tableOfScoresFullRandomCopy4.size() - 1);
		auto endTime4B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4B = endTime4B - startTime4B;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4B.count() << " segundos" << endl;
		
		auto startTime5B = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresFullRandomCopy5);
		auto endTime5B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5B = endTime5B - startTime5B;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5B.count() << " segundos" << endl;
		
		auto startTime6B = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresFullRandomCopy6);
		auto endTime6B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6B = endTime6B - startTime6B;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6B.count() << " segundos" << endl;
		
		auto startTime7B = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresFullRandomCopy7);
		auto endTime7B = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7B = endTime7B - startTime7B;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7B.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1B.count(), elapsedSeconds2B.count(), elapsedSeconds3B.count(), elapsedSeconds4B.count(), elapsedSeconds5B.count(), elapsedSeconds6B.count(), elapsedSeconds7B.count());
		
		cout << endl<<endl;
		
		
		cout << "C)Carrera por tablero : Modo ordenado" << endl << endl;
		
		auto startTime1D = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresDisorderCopy1);
		auto endTime1D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1D = endTime1D - startTime1D;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1D.count() << " segundos" << endl;
		
		auto startTime2D = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresDisorderCopy2);
		auto endTime2D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2D = endTime2D - startTime2D;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2D.count() << " segundos" << endl;
		
		auto startTime3D = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresDisorderCopy3, 0, tableOfScoresDisorderCopy3.size() - 1);
		auto endTime3D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3D = endTime3D - startTime3D;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3D.count() << " segundos" << endl;
		
		auto startTime4D = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresDisorderCopy4, 0, tableOfScoresDisorderCopy4.size() - 1);
		auto endTime4D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4D = endTime4D - startTime4D;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4D.count() << " segundos" << endl;
		
		auto startTime5D = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresDisorderCopy5);
		auto endTime5D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5D = endTime5D - startTime5D;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5D.count() << " segundos" << endl;
		
		auto startTime6D = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresDisorderCopy6);
		auto endTime6D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6D = endTime6D - startTime6D;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6D.count() << " segundos" << endl;
		
		auto startTime7D = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresDisorderCopy7);
		auto endTime7D = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7D = endTime7D - startTime7D;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7D.count() << " segundos" << endl << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1D.count(), elapsedSeconds2D.count(), elapsedSeconds3D.count(), elapsedSeconds4D.count(), elapsedSeconds5D.count(), elapsedSeconds6D.count(), elapsedSeconds7D.count());
		
		cout << endl << endl;
		
		cout << "D)Carrera por tablero : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1C = chrono::high_resolution_clock::now();
		bubbleSortDescending(tableOfScoresOrderCopy1);
		auto endTime1C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1C = endTime1C - startTime1C;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1C.count() << " segundos" << endl;
		
		auto startTime2C = chrono::high_resolution_clock::now();
		heapSortDescending(tableOfScoresOrderCopy2);
		auto endTime2C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2C = endTime2C - startTime2C;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2C.count() << " segundos" << endl;
		
		auto startTime3C = chrono::high_resolution_clock::now();
		quickSortDescending(tableOfScoresOrderCopy3, 0, tableOfScoresOrderCopy3.size() - 1);
		auto endTime3C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3C = endTime3C - startTime3C;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3C.count() << " segundos" << endl;
		
		auto startTime4C = chrono::high_resolution_clock::now();
		mergeSortDescending(tableOfScoresOrderCopy4, 0, tableOfScoresOrderCopy4.size() - 1);
		auto endTime4C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4C = endTime4C - startTime4C;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4C.count() << " segundos" << endl;
		
		auto startTime5C = chrono::high_resolution_clock::now();
		selectionSortDescending(tableOfScoresOrderCopy5);
		auto endTime5C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5C = endTime5C - startTime5C;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5C.count() << " segundos" << endl;
		
		auto startTime6C = chrono::high_resolution_clock::now();
		insertionSortDescending(tableOfScoresOrderCopy6);
		auto endTime6C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6C = endTime6C - startTime6C;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6C.count() << " segundos" << endl;
		
		auto startTime7C = chrono::high_resolution_clock::now();
		shellSortDescending(tableOfScoresOrderCopy7);
		auto endTime7C = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7C = endTime7C - startTime7C;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7C.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1C.count(), elapsedSeconds2C.count(), elapsedSeconds3C.count(), elapsedSeconds4C.count(), elapsedSeconds5C.count(), elapsedSeconds6C.count(), elapsedSeconds7C.count());
		
		cout << endl << endl;
		
		system("pause");
        cout << endl;
		
		cout << "\t\t\t2)Carreras por caminos entre aldeas" << endl << endl;

		cout << "A)Carrera por caminos : Modo aleatorio sin duplicados" << endl << endl;
		
		auto startTime1E = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsSemiRandomCopy1);
		auto endTime1E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1E = endTime1E - startTime1E;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1E.count() << " segundos" << endl;
		
		auto startTime2E = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsSemiRandomCopy2);
		auto endTime2E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2E = endTime2E - startTime2E;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2E.count() << " segundos" << endl;
		
		auto startTime3E = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsSemiRandomCopy3, 0, villagesRoadsSemiRandomCopy3.size() - 1);
		auto endTime3E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3E = endTime3E - startTime3E;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3E.count() << " segundos" << endl;
		
		auto startTime4E = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsSemiRandomCopy4, 0, villagesRoadsSemiRandomCopy4.size() - 1);
		auto endTime4E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4E = endTime4E - startTime4E;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4E.count() << " segundos" << endl;
		
		auto startTime5E = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsSemiRandomCopy5);
		auto endTime5E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5E = endTime5E - startTime5E;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5E.count() << " segundos" << endl;
		
		auto startTime6E = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsSemiRandomCopy6);
		auto endTime6E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6E = endTime6E - startTime6E;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6E.count() << " segundos" << endl;
		
		auto startTime7E = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsSemiRandomCopy7);
		auto endTime7E = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7E = endTime7E - startTime7E;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7E.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1E.count(), elapsedSeconds2E.count(), elapsedSeconds3E.count(), elapsedSeconds4E.count(), elapsedSeconds5E.count(), elapsedSeconds6E.count(), elapsedSeconds7E.count());
		
		cout << endl << endl;		
		cout << "B)Carrera por caminos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1F = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsFullRandomCopy1);
		auto endTime1F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1F = endTime1F - startTime1F;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1F.count() << " segundos" << endl;
		
		auto startTime2F = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsFullRandomCopy2);
		auto endTime2F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2F = endTime2F - startTime2F;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2F.count() << " segundos" << endl;
		
		auto startTime3F = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsFullRandomCopy3, 0, villagesRoadsFullRandomCopy3.size() - 1);
		auto endTime3F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3F = endTime3F - startTime3F;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3F.count() << " segundos" << endl;
		
		auto startTime4F = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsFullRandomCopy4, 0, villagesRoadsFullRandomCopy4.size() - 1);
		auto endTime4F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4F = endTime4F - startTime4F;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4F.count() << " segundos" << endl;
		
		auto startTime5F = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsFullRandomCopy5);
		auto endTime5F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5F = endTime5F - startTime5F;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5F.count() << " segundos" << endl;
		
		auto startTime6F = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsFullRandomCopy6);
		auto endTime6F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6F = endTime6F - startTime6F;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6F.count() << " segundos" << endl;
		
		auto startTime7F = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsFullRandomCopy7);
		auto endTime7F = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7F = endTime7F - startTime7F;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7F.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1F.count(), elapsedSeconds2F.count(), elapsedSeconds3F.count(), elapsedSeconds4F.count(), elapsedSeconds5F.count(), elapsedSeconds6F.count(), elapsedSeconds7F.count());
		
		cout << endl << endl;
		
		cout << "C)Carrera por caminos : Modo ordenado" << endl << endl;
		
		auto startTime1H = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsDisorderCopy1);
		auto endTime1H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1H = endTime1H - startTime1H;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1H.count() << " segundos" << endl;
		
		auto startTime2H = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsDisorderCopy2);
		auto endTime2H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2H = endTime2H - startTime2H;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2H.count() << " segundos" << endl;
		
		auto startTime3H = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsDisorderCopy3, 0, villagesRoadsDisorderCopy3.size() - 1);
		auto endTime3H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3H = endTime3H - startTime3H;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3H.count() << " segundos" << endl;
		
		auto startTime4H = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsDisorderCopy4, 0, villagesRoadsDisorderCopy4.size() - 1);
		auto endTime4H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4H = endTime4H - startTime4H;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4H.count() << " segundos" << endl;
		
		auto startTime5H = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsDisorderCopy5);
		auto endTime5H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5H = endTime5H - startTime5H;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5H.count() << " segundos" << endl;
		
		auto startTime6H = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsDisorderCopy6);
		auto endTime6H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6H = endTime6H - startTime6H;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6H.count() << " segundos" << endl;
		
		auto startTime7H = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsDisorderCopy7);
		auto endTime7H = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7H = endTime7H - startTime7H;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7H.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1H.count(), elapsedSeconds2H.count(), elapsedSeconds3H.count(), elapsedSeconds4H.count(), elapsedSeconds5H.count(), elapsedSeconds6H.count(), elapsedSeconds7H.count());
		
		cout << endl << endl;
		
		cout << "D)Carrera por caminos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1G = chrono::high_resolution_clock::now();
		bubbleSortDescending(villagesRoadsOrderCopy1);
		auto endTime1G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1G = endTime1G - startTime1G;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1G.count() << " segundos" << endl;
		
		auto startTime2G = chrono::high_resolution_clock::now();
		heapSortDescending(villagesRoadsOrderCopy2);
		auto endTime2G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2G = endTime2G - startTime2G;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2G.count() << " segundos" << endl;
		
		auto startTime3G = chrono::high_resolution_clock::now();
		quickSortDescending(villagesRoadsOrderCopy3, 0, villagesRoadsOrderCopy3.size() - 1);
		auto endTime3G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3G = endTime3G - startTime3G;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3G.count() << " segundos" << endl;
		
		auto startTime4G = chrono::high_resolution_clock::now();
		mergeSortDescending(villagesRoadsOrderCopy4, 0, villagesRoadsOrderCopy4.size() - 1);
		auto endTime4G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4G = endTime4G - startTime4G;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4G.count() << " segundos" << endl;
		
		auto startTime5G = chrono::high_resolution_clock::now();
		selectionSortDescending(villagesRoadsOrderCopy5);
		auto endTime5G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5G = endTime5G - startTime5G;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5G.count() << " segundos" << endl;
		
		auto startTime6G = chrono::high_resolution_clock::now();
		insertionSortDescending(villagesRoadsOrderCopy6);
		auto endTime6G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6G = endTime6G - startTime6G;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6G.count() << " segundos" << endl;
		
		auto startTime7G = chrono::high_resolution_clock::now();
		shellSortDescending(villagesRoadsOrderCopy7);
		auto endTime7G = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7G = endTime7G - startTime7G;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7G.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1G.count(), elapsedSeconds2G.count(), elapsedSeconds3G.count(), elapsedSeconds4G.count(), elapsedSeconds5G.count(), elapsedSeconds6G.count(), elapsedSeconds7G.count());
		
		
		cout << endl << endl;
		
		system("pause");
        cout << endl;
		      
        cout << "\t\t\t3)Carreras por los dibujos" << endl << endl;
        
		cout << "A)Carrera por dibujos : Modo aleatorio sin duplicados" << endl << endl;
		
		auto startTime1I = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingSemiRandomCopy1);
		auto endTime1I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1I = endTime1I - startTime1I;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1I.count() << " segundos" << endl;
		
		auto startTime2I = chrono::high_resolution_clock::now();
		heapSortDescending(drawingSemiRandomCopy2);
		auto endTime2I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2I = endTime2I - startTime2I;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2I.count() << " segundos" << endl;
		
		auto startTime3I = chrono::high_resolution_clock::now();
		quickSortDescending(drawingSemiRandomCopy3, 0, drawingSemiRandomCopy3.size() - 1);
		auto endTime3I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3I = endTime3I - startTime3I;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3I.count() << " segundos" << endl;
		
		auto startTime4I = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingSemiRandomCopy4, 0, drawingSemiRandomCopy4.size() - 1);
		auto endTime4I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4I = endTime4I - startTime4I;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4I.count() << " segundos" << endl;
		
		auto startTime5I = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingSemiRandomCopy5);
		auto endTime5I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5I = endTime5I - startTime5I;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5I.count() << " segundos" << endl;
		
		auto startTime6I = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingSemiRandomCopy6);
		auto endTime6I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6I = endTime6I - startTime6I;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6I.count() << " segundos" << endl;
		
		auto startTime7I = chrono::high_resolution_clock::now();
		shellSortDescending(drawingSemiRandomCopy7);
		auto endTime7I = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7I = endTime7I - startTime7I;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7I.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1I.count(), elapsedSeconds2I.count(), elapsedSeconds3I.count(), elapsedSeconds4I.count(), elapsedSeconds5I.count(), elapsedSeconds6I.count(), elapsedSeconds7I.count());
		
		cout << endl << endl;
		cout << "B)Carrera por dibujos : Modo aleatorio con posibilidad de duplicados" << endl << endl;
		
		auto startTime1J = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingFullRandomCopy1);
		auto endTime1J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1J = endTime1J - startTime1J;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1J.count() << " segundos" << endl;
		
		auto startTime2J = chrono::high_resolution_clock::now();
		heapSortDescending(drawingFullRandomCopy2);
		auto endTime2J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2J = endTime2J - startTime2J;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2J.count() << " segundos" << endl;
		
		auto startTime3J = chrono::high_resolution_clock::now();
		quickSortDescending(drawingFullRandomCopy3, 0, drawingFullRandomCopy3.size() - 1);
		auto endTime3J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3J = endTime3J - startTime3J;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3J.count() << " segundos" << endl;
		
		auto startTime4J = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingFullRandomCopy4, 0, drawingFullRandomCopy4.size() - 1);
		auto endTime4J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4J = endTime4J - startTime4J;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4J.count() << " segundos" << endl;
		
		auto startTime5J = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingFullRandomCopy5);
		auto endTime5J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5J = endTime5J - startTime5J;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5J.count() << " segundos" << endl;
		
		auto startTime6J = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingFullRandomCopy6);
		auto endTime6J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6J = endTime6J - startTime6J;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6J.count() << " segundos" << endl;
		
		auto startTime7J = chrono::high_resolution_clock::now();
		shellSortDescending(drawingFullRandomCopy7);
		auto endTime7J = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7J = endTime7J - startTime7J;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7J.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1J.count(), elapsedSeconds2J.count(), elapsedSeconds3J.count(), elapsedSeconds4J.count(), elapsedSeconds5J.count(), elapsedSeconds6J.count(), elapsedSeconds7J.count());
		
		cout << endl << endl;
		cout << "C)Carrera por dibujos : Modo ordenado" << endl << endl;
		
		auto startTime1L = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingDisorderCopy1);
		auto endTime1L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1L = endTime1L - startTime1L;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1L.count() << " segundos" << endl;
		
		auto startTime2L = chrono::high_resolution_clock::now();
		heapSortDescending(drawingDisorderCopy2);
		auto endTime2L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2L = endTime2L - startTime2L;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2L.count() << " segundos" << endl;
		
		auto startTime3L = chrono::high_resolution_clock::now();
		quickSortDescending(drawingDisorderCopy3, 0, drawingDisorderCopy3.size() - 1);
		auto endTime3L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3L = endTime3L - startTime3L;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3L.count() << " segundos" << endl;
		
		auto startTime4L = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingDisorderCopy4, 0, drawingDisorderCopy4.size() - 1);
		auto endTime4L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4L = endTime4L - startTime4L;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4L.count() << " segundos" << endl;
		
		auto startTime5L = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingDisorderCopy5);
		auto endTime5L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5L = endTime5L - startTime5L;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5L.count() << " segundos" << endl;
		
		auto startTime6L = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingDisorderCopy6);
		auto endTime6L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6L = endTime6L - startTime6L;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6L.count() << " segundos" << endl;
		
		auto startTime7L = chrono::high_resolution_clock::now();
		shellSortDescending(drawingDisorderCopy7);
		auto endTime7L = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7L = endTime7L - startTime7L;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7L.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1L.count(), elapsedSeconds2L.count(), elapsedSeconds3L.count(), elapsedSeconds4L.count(), elapsedSeconds5L.count(), elapsedSeconds6L.count(), elapsedSeconds7L.count());
		
		cout << endl << endl;
		cout << "D)Carrera por dibujos : Modo inversamente ordenado" << endl << endl;
		
		auto startTime1K = chrono::high_resolution_clock::now();
		bubbleSortDescending(drawingOrderCopy1);
		auto endTime1K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds1K = endTime1K - startTime1K;
		cout << "Bubble sort - Tiempo transcurrido: " << elapsedSeconds1K.count() << " segundos" << endl;
		
		auto startTime2K = chrono::high_resolution_clock::now();
		heapSortDescending(drawingOrderCopy2);
		auto endTime2K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds2K = endTime2K - startTime2K;
		cout << "Heap sort - Tiempo transcurrido: " << elapsedSeconds2K.count() << " segundos" << endl;
		
		auto startTime3K = chrono::high_resolution_clock::now();
		quickSortDescending(drawingOrderCopy3, 0, drawingOrderCopy3.size() - 1);
		auto endTime3K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds3K = endTime3K - startTime3K;
		cout << "Quick sort - Tiempo transcurrido: " << elapsedSeconds3K.count() << " segundos" << endl;
		
		auto startTime4K = chrono::high_resolution_clock::now();
		mergeSortDescending(drawingOrderCopy4, 0, drawingOrderCopy4.size() - 1);
		auto endTime4K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds4K = endTime4K - startTime4K;
		cout << "Merge sort - Tiempo transcurrido: " << elapsedSeconds4K.count() << " segundos" << endl;
		
		auto startTime5K = chrono::high_resolution_clock::now();
		selectionSortDescending(drawingOrderCopy5);
		auto endTime5K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds5K = endTime5K - startTime5K;
		cout << "Selection sort - Tiempo transcurrido: " << elapsedSeconds5K.count() << " segundos" << endl;
		
		auto startTime6K = chrono::high_resolution_clock::now();
		insertionSortDescending(drawingOrderCopy6);
		auto endTime6K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds6K = endTime6K - startTime6K;
		cout << "Insertion sort - Tiempo transcurrido: " << elapsedSeconds6K.count() << " segundos" << endl;
		
		auto startTime7K = chrono::high_resolution_clock::now();
		shellSortDescending(drawingOrderCopy7);
		auto endTime7K = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsedSeconds7K = endTime7K - startTime7K;
		cout << "Shell sort - Tiempo transcurrido: " << elapsedSeconds7K.count() << " segundos" << endl;
		
		findMinTime("Bubble sort", "Heap sort", "Quick sort", "Merge sort", "Selection sort", "Insertion sort", "Shell sort", elapsedSeconds1K.count(), elapsedSeconds2K.count(), elapsedSeconds3K.count(), elapsedSeconds4K.count(), elapsedSeconds5K.count(), elapsedSeconds6K.count(), elapsedSeconds7K.count());
		
		cout << endl << endl;
		
	}
		
    return 0;
}

