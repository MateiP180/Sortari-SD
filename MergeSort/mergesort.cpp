#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    int n;
    cin>>n;
    vector <long long> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    MergeSort(v,0,n-1);
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}