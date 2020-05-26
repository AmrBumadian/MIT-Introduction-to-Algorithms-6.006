#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mx 0
#define mn 1e9
#define v(dt) vector<dt>
const int N = 1e5;
ll n, m;

ll greedyAscent(int **a, int i, int j) {
    if (i > 0 and a[i][j] < a[i - 1][j])
        return greedyAscent(a, i - 1, j);

    else if (i < n - 1 and a[i][j] < a[i + 1][j])
        return greedyAscent(a, i + 1, j);

    else if (j > 0 and a[i][j] < a[i][j - 1])
        return greedyAscent(a, i, j - 1);

    else if (j < m - 1 and a[i][j] < a[i][j + 1])
        return greedyAscent(a, i, j + 1);

    else
        return a[i][j];
}

int main() {
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    ll res =greedyAscent(a, 0, 0);
    cout << res;
    return 0;
}