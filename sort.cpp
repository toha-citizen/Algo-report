#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Random array generator
vector<int> generateRandom(int n) {
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    return arr;
}

// Main function
int main() {
    srand(time(0));

    vector<int> sizes = {10, 100, 1000, 10000, 100000};

    string name = "Tanjimul Hassan Toha";
    string id = "C243016";

    for(int n : sizes) {
        cout << "\n=============================\n";
        cout << "Input Size: " << n << endl;

        vector<int> original = generateRandom(n);

        // 🔸 Insertion Sort
        vector<int> arr1 = original;
        auto start1 = high_resolution_clock::now();
        insertionSort(arr1);
        auto end1 = high_resolution_clock::now();
        auto time1 = duration_cast<microseconds>(end1 - start1);

        cout << "\nName: " << name
             << "\nID: " << id
             << "\nAlgorithm: Insertion Sort"
             << "\nExecution Time: " << time1.count() << " microseconds\n";

        // Merge Sort
        vector<int> arr2 = original;
        auto start2 = high_resolution_clock::now();
        mergeSort(arr2, 0, n - 1);
        auto end2 = high_resolution_clock::now();
        auto time2 = duration_cast<microseconds>(end2 - start2);

        cout << "\nName: " << name
             << "\nID: " << id
             << "\nAlgorithm: Merge Sort"
             << "\nExecution Time: " << time2.count() << " microseconds\n";

        // Quick Sort
        vector<int> arr3 = original;
        auto start3 = high_resolution_clock::now();
        quickSort(arr3, 0, n - 1);
        auto end3 = high_resolution_clock::now();
        auto time3 = duration_cast<microseconds>(end3 - start3);

        cout << "\nName: " << name
             << "\nID: " << id
             << "\nAlgorithm: Quick Sort"
             << "\nExecution Time: " << time3.count() << " microseconds\n";
    }

    return 0;
}
