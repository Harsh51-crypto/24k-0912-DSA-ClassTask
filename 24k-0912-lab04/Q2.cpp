#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && (++comparisons && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j = i;
            while (j >= gap && (++comparisons && arr[j - gap] > temp)) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n = 20;
    int arr[100];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100 + 1;

    cout << "Original Array:" << endl;
    display(arr, n);

    int temp[100], comparisons;

    copy(arr, arr + n, temp);
    comparisons = 0;
    bubbleSort(temp, n, comparisons);
    cout << "Bubble Sort: "; display(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copy(arr, arr + n, temp);
    comparisons = 0;
    insertionSort(temp, n, comparisons);
    cout << "Insertion Sort: "; display(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copy(arr, arr + n, temp);
    comparisons = 0;
    selectionSort(temp, n, comparisons);
    cout << "Selection Sort: "; display(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    copy(arr, arr + n, temp);
    comparisons = 0;
    shellSort(temp, n, comparisons);
    cout << "Shell Sort: "; display(temp, n);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
