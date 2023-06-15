#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funktion zum Vertauschen von zwei Elementen
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funktion zur Bestimmung des Pivotelements als das Element in der Mitte
int choosePivotMiddle(int arr[], int l, int r) {
    return arr[(l + r) / 2];
}

// Funktion zur Bestimmung des Pivotelements durch Zufall
int choosePivotRandom(int arr[], int l, int r) {
    int randomIndex = l + rand() % (r - l + 1);
    return arr[randomIndex];
}

// Funktion zur Bestimmung des Pivotelements als Median von a[l], a[(l+r)/2] und a[r]
int choosePivotMedian(int arr[], int l, int r) {
    int mid = (l + r) / 2;

    if (arr[l] > arr[mid])
        swap(arr[l], arr[mid]);

    if (arr[l] > arr[r])
        swap(arr[l], arr[r]);

    if (arr[mid] > arr[r])
        swap(arr[mid], arr[r]);

    return arr[mid];
}

// Funktion zum Aufteilen des Arrays und Rückgabe des Pivotindex
int partition(int arr[], int l, int r, int pivot) {
    while (l <= r) {
        while (arr[l] < pivot)
            l++;

        while (arr[r] > pivot)
            r--;

        if (l <= r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    return l;
}

// Hauptfunktion des Quicksort-Algorithmus
void quicksort(int arr[], int l, int r, int option) {
    if (l < r) {
        int pivot;

        switch (option) {
        case 1: // Pivotelement ist a[(l+r)/2]
            pivot = choosePivotMiddle(arr, l, r);
            break;
        case 2: // Aussuchen des Pivotelements mittels Random-Funktion
            pivot = choosePivotRandom(arr, l, r);
            break;
        case 3: // Aussuchen des Pivotelements als Median von a[l], a[(l+r)/2] und a[r]
            pivot = choosePivotMedian(arr, l, r);
            break;
        }

        int pivotIndex = partition(arr, l, r, pivot);

        quicksort(arr, l, pivotIndex - 1, option);
        quicksort(arr, pivotIndex, r, option);
    }
}

// Hilfsfunktion zum Ausgeben des Arrays
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hauptfunktion
int main() {
    srand(time(0)); // Seed für die Random-Funktion

    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    cout << "\nQuicksort (Pivotelement ist a[(l+r)/2]): ";
    quicksort(arr, 0, size - 1, 1);
    printArray(arr, size);

    cout << "\nQuicksort (Aussuchen des Pivotelements mittels Random-Funktion): ";
    quicksort(arr, 0, size - 1, 2);
    printArray(arr, size);

    cout << "\nQuicksort (Aussuchen des Pivotelements als Median von a[l], a[(l+r)/2] und a[r]): ";
    quicksort(arr, 0, size - 1, 3);
    printArray(arr, size);

    return 0;
}