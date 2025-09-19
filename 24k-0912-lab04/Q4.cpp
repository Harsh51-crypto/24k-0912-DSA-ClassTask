#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);
    if (index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found" << endl;
    return 0;
}
