#include <bits/stdc++.h>
using namespace std;

void __merge(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1 + 1], R[n2 + 1];

    for (int i = 1; i <= n1; i++)
        L[i] = a[l + i-1];
    for (int i = 1; i <= n2; i++)
        R[i] = a[mid + i];
    L[n1 + 1] = 1e9;
    R[n2 + 1] = 1e9;
    int i = 1, j = 1;
    for (int k = l; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        __merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    mergeSort(a, 1, n);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
