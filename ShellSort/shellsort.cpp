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


void shellSort(vector<long long>& v, long long n)
{
    for(Int interval = n/2; interval > 0; interval /= 2)
        for(Int i = interval; i<n; i++)
        {
            Int temp = v[i];
            Int j;
            for (j = i; j >= interval && v[j - interval] > temp; j-=interval)
            {
                v[j] = v[j-interval];
            }
            v[j] = temp;
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
    shellSort(array, n);
    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}
