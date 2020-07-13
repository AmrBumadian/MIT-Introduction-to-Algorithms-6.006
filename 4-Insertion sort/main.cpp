#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];

    int j=0;
    int temp;
    for (int i=1; i<n; i++)
    {
        temp = v[i];
        j=i-1;
        while(j>=0 and v[j]>temp)
        {
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = temp;
    }

    for (int i=0; i<n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
