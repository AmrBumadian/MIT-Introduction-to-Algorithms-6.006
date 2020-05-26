#include <bits/stdc++.h>
using namespace std;
int partition (vector<int> &a,int s, int e)
{
    int x = a[e];
    int i = s-1;
    for (int j=s; j<e;++j)
    {
        if (a[j]<=x)
        {
            ++i;
            swap(a[i],a[j]);
        }
    }
    ++i;
    swap(a[i],a[e]);
    return i;
}
void quickSort(vector<int> &a, int s, int e)
{
    if (s<e)
    {
        int r = partition(a,s,e);
        quickSort (a,s,r-1);
        quickSort (a,r+1,e);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n);
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
