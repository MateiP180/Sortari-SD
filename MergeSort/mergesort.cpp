#include <iostream>
#include <vector>
#include <iostream>
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

void Interclasare(vector<long long>& v, unsigned long long st, unsigned long long mij, unsigned long long dr)
{
    unsigned long long k = 0;
    vector<long long> c(dr - st + 1);

    unsigned long long i=st, j=mij+1;

    while( i <= mij && j <= dr)
        if(v[i] < v[j])
           c[k++] = v[i++];
        else
           c[k++] = v[j++];

    while(i<=mij)
        c[k++] = v[i++];

    while(j<=dr)
        c[k++] = v[j++];

    j = 0;
    for(i = st; i<=dr; i++)
        v[i] = c[j++];



}
void MergeSort(vector<long long>& v, unsigned long long st, unsigned long long dr)
{
    if(st < dr)
    {
        unsigned long long mij = (st + dr) / 2;
        MergeSort(v, st, mij);
        MergeSort(v, mij+1, dr);

        Interclasare(v, st, mij, dr);
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
    MergeSort(array, n);
    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}
