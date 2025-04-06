#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(const vector<int>& arr)
{
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) 
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) 
    {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) 
{
    int max_val = getMax(arr);
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

void printArray(const vector<int>& arr) 
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() 
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array:\n";
    printArray(arr);
    radixSort(arr);
    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}
