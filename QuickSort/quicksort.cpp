#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void ReadArray(std::vector<long long> &arr, size_t &n, char *input_file)
{
	ifstream in(input_file);
	in >> n;
	arr.resize(n);

	for (size_t i = 0; i < n; ++i) 
    {
		in >> arr[i];
	}

	in.close();
	return;
}

int medianOfThree(vector<long long>& arr, int low, int high) 
{
    int mid = low + (high - low) / 2;

    if (arr[mid] < arr[low])
        swap(arr[mid], arr[low]);
    if (arr[high] < arr[low])
        swap(arr[high], arr[low]);
    if (arr[high] < arr[mid])
        swap(arr[high], arr[mid]);

    swap(arr[mid], arr[high - 1]);
    return arr[high - 1]; 
}

int partition(vector<long long>& arr, int low, int high) 
{
    int pivot = medianOfThree(arr, low, high);
    int i = low;
    int j = high - 1;
    int pasi = 0, pasj = 1;
    while (i < j) 
    {
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
            swap(pasi, pasj);
        }
        i += pasi;
        j -= pasj;
    }
    return i;
}

void quickSort(vector<long long>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    } 
}


void printArray(const vector<long long>& arr) 
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main(int argc, char *argv[]) 
{
    size_t n;
	vector<long long> array;
    ReadArray(array, n, argv[1]);
    cout << "Original array:\n";
    printArray(array);
    quickSort(array, 0, n - 1);
    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}
