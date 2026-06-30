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
int ordenado[TAM]; 
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
                mostrarArreglo(original, TAM);
                cout << "    Despues: ";
                for (int i = 0; i < TAM; i++){
                    ordenado[i] = original[i];
                };
                burbuja(ordenado,TAM);
                mostrarArreglo(ordenado, TAM); 
                break;

            case 2:
                cout << ">>> QuickSort" << endl;
                cout << "    Antes : ";  
                mostrarArreglo(original, TAM);                
                cout << "    Despues: ";
                for (int i = 0; i < TAM; i++){
                    ordenado[i] = original[i];
                };
                quickSort(ordenado, 0, TAM-1);
                mostrarArreglo(ordenado, TAM);  
                break;
 
            case 3:
                cout << ">>> HeapSort" << endl;
                cout << "    Antes : ";  
                mostrarArreglo(original, TAM);               
                cout << "    Despues: "; 
                for (int i = 0; i < TAM; i++){
                    ordenado[i] = original[i];
                };
                heapSort(ordenado, TAM);
                mostrarArreglo(ordenado, TAM);  
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

// Ordenamiento burbuja
void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Banderas para optimizar: si no hay intercambios, el arreglo ya está ordenado
        bool Intercambio = false; 
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambio de elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                Intercambio = true;
            }
        }
        
        if (!Intercambio) {
            break;
        }
    }    
}

// Ordenamiento quickSort
int particionar(int arr[], int inicio, int fin) {
    int pivote = arr[fin];
    int i = (inicio - 1);

    for (int j = inicio; j <= fin - 1; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fin]);
    return (i + 1);
}

void quickSort(int arr[], int izq, int der){
    if (izq < der) {
        int pi = particionar(arr, izq, der);
        quickSort(arr, izq, pi - 1);
        quickSort(arr, pi + 1, der);
    }
}

// Ordenamiento heapSort
void mantenerHeap(int arr[], int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && arr[izq] > arr[mayor])
        mayor = izq;

    if (der < n && arr[der] > arr[mayor])
        mayor = der;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        mantenerHeap(arr, n, mayor);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        mantenerHeap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        mantenerHeap(arr, i, 0);
    }
}
