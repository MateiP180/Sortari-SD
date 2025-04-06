#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
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

void bucketSort(vector<long long>& arr, int n) 
{
    if (arr.empty()) return;
    int bucketCount = static_cast<int>(sqrt(arr.size()));
    double minVal = *min_element(arr.begin(), arr.end());
    double maxVal = *max_element(arr.begin(), arr.end());
    double range = maxVal - minVal;
    vector<vector<double>> buckets(bucketCount);
    for (double num : arr) 
    {
        int index = static_cast<int>((num - minVal) / range * (bucketCount - 1));
        buckets[index].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) 
    {
        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
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
    bucketSort(array, n);
    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}
