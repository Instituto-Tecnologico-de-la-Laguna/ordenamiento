/*
 *  Algoritmos disponibles:
 *    1. Burbuja  (Bubble Sort)
 *    2. QuickSort
 *    3. HeapSort
 * ============================================================
 */
 
#include <iostream>
#include <iomanip>
using namespace std;
 
// ============================================================
//  CONSTANTES
// ============================================================
const int TAM = 10;
 
// ============================================================
//  PROTOTIPO DE FUNCIONES
// ============================================================
void mostrarArreglo(int arr[], int n);
void copiarArreglo(int origen[], int destino[], int n);
 
void BurbujaDsc(int arr[], int n);
void quickSortAsc(int arr[], int izq, int der);
void heapSort(int arr[], int n);
 
// Auxiliares internas de QuickSort y HeapSort
void heapify(int arr[], int n, int i);          // <-- completar
 
// ============================================================
//  ARREGLO ORIGINAL (fijo, no se modifica)
// ============================================================
int original[TAM] = {45, 12, 78, 3, 56, 89, 23, 67, 34, 9};

int destino[TAM];  // <-- arreglo de trabajo para cada ordenamiento
 
// ============================================================
//  MAIN
// ============================================================
int main() {
    int opcion;
    int temp[TAM];   // copia de trabajo para cada ordenamiento
 
    do {
        cout << "\n========================================" << endl;
        cout << "   ORDENAMIENTO DE ARREGLOS (COMPLETO, LOS 3 METODOS FUNCIONAN)    " << endl;
        cout << "========================================" << endl;
        //cout << " Arreglo original:" << endl;
        //cout << " ";
        //mostrarArreglo(original, TAM);
        cout << "----------------------------------------" << endl;
        cout << "  1. Burbuja  (Bubble Sort)"              << endl;
        cout << "  2. QuickSort"                           << endl;
        cout << "  3. HeapSort"                            << endl;
        cout << "  0. Salir"                               << endl;
        cout << "----------------------------------------" << endl;
        cout << " Elige una opcion: ";
        cin  >> opcion;
 
        cout << endl;
 
        switch (opcion) {
            case 1:
                cout << ">>> Burbuja (Bubble Sort)" << endl;
                cout << "    Antes : "; 
                mostrarArreglo(original, TAM);
                copiarArreglo(original, destino, TAM);
                cout << "    Datos Ordenados: "<<endl; 
                BurbujaDsc(destino, TAM);
                mostrarArreglo(destino, TAM);
                cout << "    ARREGLO ORIGINAL"<<endl;
                mostrarArreglo(original, TAM);
                break;
 
            case 2:
                cout << ">>> QuickSort" << endl;
                cout << "    Antes : ";  
                mostrarArreglo(original, TAM);
                copiarArreglo(original, destino, TAM);
                
                cout << "    Datos Ordenados: "; 
                quickSortAsc(destino, 0, TAM - 1);
                mostrarArreglo(destino, TAM);
                cout << "    ARREGLO ORIGINAL"<<endl;
                mostrarArreglo(original, TAM);
                break;
 
            case 3:
                cout << ">>> HeapSort" << endl;
                cout << "    Antes : ";  
                mostrarArreglo(original, TAM);
                copiarArreglo(original, destino, TAM);

                cout << "    Datos Ordenados: "; 
                heapSort(destino, TAM);
                mostrarArreglo(destino, TAM);
                cout << "    ARREGLO ORIGINAL"<<endl;
                mostrarArreglo(original, TAM);
                break;
 
            case 0:
                cout << " Saliendo del programa. Hasta luego!" << endl;
                break;
 
            default:
                cout << " Opcion invalida. Intenta de nuevo." << endl;
        }
 
    } while (opcion != 0);
 
    return 0;
}


// Muestra el arreglo en una línea
void mostrarArreglo(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << arr[i];
        if (i < n - 1) cout << ",";
    }
    cout << " ]" << endl;
}

void copiarArreglo(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}
void BurbujaDsc(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
      for (int j = n - 1; i < j; j--)
      {
            if (arr[j - 1] > arr[j])
            {
                int aux = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = aux;
            }
       }
            
}

void quickSortAsc(int arr[], int izq,int der)
    {
        int i,j,pivote,aux;
        
        i = izq;
        j = der;
        pivote = arr[(izq+der)/2] ;
        do
        {
            //this.comp++;
            while(arr[i] < pivote && i < der)
                i++;
            //comp++;
            while(arr[j] > pivote && j > izq)
                j--;
            
            if(i <= j)
            {
                aux = arr[i];
                arr[i] = arr[j] ;
                arr[j] = aux;
                i++;
                j--;
                
            }
        }while (i <= j);
        if(izq < j)
            quickSortAsc(arr,izq,j);
        if(i < der)
            quickSortAsc(arr,i,der);
}


// Transforma un subárbol con raíz en el índice 'i' en un montículo máximo (Max-Heap)
void heapify(int arr[], int n, int i) {
    int largest = i;       // Inicializar el más grande como la raíz
    int left = 2 * i + 1;  // Hijo izquierdo
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Si el hijo derecho es más grande que el más grande hasta ahora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Si el más grande no es la raíz, se intercambian
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // Recursión para asegurar que el subárbol afectado también sea un montículo
        heapify(arr, n, largest);
    }
}

// Función principal para ordenar usando Heapsort
void heapSort(int arr[], int n) {
    // Construir el montículo (reordenar el arreglo)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos uno a uno del montículo
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual al final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Llamar a heapify en el montículo reducido
        heapify(arr, i, 0);
    }
}
