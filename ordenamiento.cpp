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
 
void burbuja(int arr[], int n);
void quickSort(int arr[], int izq, int der);
void heapSort(int arr[], int n);
 
// Auxiliares internas de QuickSort y HeapSort
void heapify(int arr[], int n, int i);          // <-- completar
 
// ============================================================
//  ARREGLO ORIGINAL (fijo, no se modifica)
// ============================================================
int original[TAM] = {45, 12, 78, 3, 56, 89, 23, 67, 34, 9};
 
// ============================================================
//  MAIN
// ============================================================
int main() {
    int opcion;
    int temp[TAM];   // copia de trabajo para cada ordenamiento
 
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU DE ORDENAMIENTO DE ARREGLOS    " << endl;
        cout << "========================================" << endl;
        cout << " Arreglo original:" << endl;
        cout << " ";
        mostrarArreglo(original, TAM);
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
      
                cout << "    Despues: "; 
                break;
 
            case 2:
                cout << ">>> QuickSort" << endl;
                cout << "    Antes : ";  
                
                cout << "    Despues: "; 
                break;
 
            case 3:
                cout << ">>> HeapSort" << endl;
                cout << "    Antes : ";  
               
                cout << "    Despues: "; 
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

void quickSort(int arr[], int izq, int der)
{
    int i = izq;
    int j = der;
    int pivote = arr[(izq + der) / 2];
    int aux;

    while (i <= j)
    {
        while (arr[i] < pivote)
            i++;

        while (arr[j] > pivote)
            j--;

        if (i <= j)
        {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;

            i++;
            j--;
        }
    }

    if (izq < j)
        quickSort(arr, izq, j);

    if (i < der)
        quickSort(arr, i, der);
}

