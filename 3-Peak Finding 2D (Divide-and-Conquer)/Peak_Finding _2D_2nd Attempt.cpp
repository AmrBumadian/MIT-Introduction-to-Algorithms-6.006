#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mx 0
#define mn 1e9
#define v(dt) vector<dt>
const int N = 1e5;
ll n, m;

int findMax(int **a, int rows, int mid, int &max) {
    int max_index = 0;
    for (int i = 0; i < rows; i++) {
        if (a[i][mid] > max) {
            max = a[i][mid];
            max_index = i;
        }
    }
    return max_index;
}


ll greedyAscent(int **a, int rows, int columns, int mid) {

    int max = 0;
    int max_index = findMax(a, rows, mid, max);
    if ((mid==0 or max >= a[max_index][mid - 1]) and (mid== columns-1 or max >= a[max_index][mid + 1]))
        return max;
    else if (max < a[max_index][mid - 1])
        return greedyAscent(a, rows, columns, mid - ceil((double) mid / 2));
    else
        return greedyAscent(a, rows, columns, mid + ceil((double) mid / 2));
}

int main() {
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    ll res = greedyAscent(a, n, m, m / 2);
    cout << res;
    return 0;
}