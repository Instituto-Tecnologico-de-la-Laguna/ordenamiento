/*
 *  Algoritmos disponibles:
 *    1. Burbuja  (Bubble Sort)
 *    2. QuickSort
 *    3. HeapSort
 * ============================================================
 */
 
#include <iostream>
#include <iomanip>
#include <string.h>
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
    int n;
 
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
                memcpy(temp, original, sizeof(original));
                mostrarArreglo(temp, TAM);
                n = sizeof(original) / sizeof(original[0]);
                heapSort(temp, n);
                cout << "    Despues: "; 
                mostrarArreglo(temp, TAM);
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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función que asegura la propiedad de max-heap en un subárbol con raíz en 'i'
// n: tamaño del montículo, arr: arreglo
void heapify(int arr[], int n, int i) {
    int largest = i;       // Inicializamos el más grande como la raíz
    int left = 2 * i + 1;  // Hijo izquierdo (0-indexado)
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo existe y es mayor que la raíz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si el hijo derecho existe y es mayor que el más grande actual
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el más grande no es la raíz, intercambiamos y seguimos heapificando
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursión para ajustar el subárbol afectado
    }
}

// Ordenamiento por montículos
void heapSort(int arr[], int n) {
    // Paso 1: Construir el max-heap (reordenar el arreglo)
    // El último nodo no hoja está en (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Paso 2: Extraer elementos uno a uno del montículo
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual (máximo) al final
        swap(&arr[0], &arr[i]);

        // Reducir el tamaño del montículo y re-heapificar la raíz
        heapify(arr, i, 0);
    }
}