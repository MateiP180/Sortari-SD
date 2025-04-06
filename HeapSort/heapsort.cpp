#include <iostream>
#include <vector>
typedef unsigned long long Int;
using namespace std;

void heap(vector<Int>& v, Int n, Int i)
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
        heap(v, n, Max);
    }
}

void heapSort(vector<Int>& v, Int n)
{
    for(Int i = n/2 - 1; i>=0; i--)
        heap(v, n, i);

    for(Int i = n - 1; i>=0; i--)
    {
        swap(v[0], v[i]);
        heap(v, i, 0);
    }
}


int main()
{
    int n;
    cin>>n;
    vector<Int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    heapSort(v,n);
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}