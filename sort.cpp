#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// ======================= Insertion Sort =======================
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ======================= Merge Sort =======================
void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < L.size())
        arr[k++] = L[i++];
    while (j < R.size())
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ======================= Quick Sort =======================
int partitionFunc(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partitionFunc(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// ======================= Utility Function =======================
vector<int> generateRandomArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    return arr;
}

void printResult(string name, string id, string algo, int n, long long time)
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Algorithm: " << algo << endl;
    cout << "Input Size: " << n << endl;
    cout << "Execution Time: " << time << " microseconds" << endl;
    cout << "-----------------------------\n";
}

// ======================= Main Function =======================
int main()
{
    srand(time(0));

    string name = "Tanjimul Hasan Toha";
    string id = "C243016";

    vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (int n : sizes)
    {
        cout << "\n========== Input Size: " << n << " ==========\n";

        vector<int> original = generateRandomArray(n);

        // -------- Insertion Sort --------
        vector<int> arr1 = original;
        auto start = high_resolution_clock::now();
        insertionSort(arr1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        printResult(name, id, "Insertion Sort", n, duration.count());

        // -------- Merge Sort --------
        vector<int> arr2 = original;
        start = high_resolution_clock::now();
        mergeSort(arr2, 0, n - 1);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        printResult(name, id, "Merge Sort", n, duration.count());

        // -------- Quick Sort --------
        vector<int> arr3 = original;
        start = high_resolution_clock::now();
        quickSort(arr3, 0, n - 1);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        printResult(name, id, "Quick Sort", n, duration.count());
    }

    return 0;
}