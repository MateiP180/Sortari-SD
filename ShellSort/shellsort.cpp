#include <iostream>
#include <fstream>
#include <vector>
typedef unsigned long long Int;
using namespace std;

void shellSort(vector<long long>& v, Int n)
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

int main()
{
    int n;
    cin>>n;
    vector <long long> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    shellSort(v, n);
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}