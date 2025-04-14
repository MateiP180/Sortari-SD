#include <iostream>
#include <fstream>
#include <vector>
typedef unsigned long long Int;
using namespace std;


void ReadArray(vector<long long> &arr, size_t &n, char *input_file)
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

void heapify(vector<Int>& v, long long n, Int i)
{
    Int Max= i;
    Int st = 2*i + 1;
    Int dr = 2*i + 2;
    if(st < n && v[st] > v[Max])
        Max = st;

    if(dr < n && v[dr] > v[Max])
        Max = dr;

    if(Max != i)
    {
        swap(v[i], v[Max]);
        heapify(v, n, Max);
    }
}

void heapSort(vector<Int>& v, long long n)
{
    for(long long i = n/2 - 1; i>=0; i--)
        heapify(v, n, i);

    for(long long i = n - 1; i>=0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void printArray(const vector<long long>& arr)
{
    for (double x : arr)
        cout << x << " ";
    cout << endl;
}


int main(int argc, char *argv[])
{
	size_t n;
	vector<long long> array;
    ReadArray(array, n, argv[1]);
    printArray(array);
    heapSort(array, n);
    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}
