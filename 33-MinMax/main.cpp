#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define EPS 1e-9
#define MOD (int)1e9+7
#define INF (int)1e9

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx, mn, start = 1;
    if (n & 1) mx = mn = a[0];
    else {
        start = 2;
        mx = max(a[1], a[0]);
        mn = min(a[1], a[0]);
    }
    // compare pairs of input, then compare the greater with the max, and the smaller with th min
    // maximum 3*floor(n/2) comparisons instead of 2n-2 if they were compared one-to-one
    for (int i = start; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i + 1]);
        } else {
            mx = max(mx, a[i + 1]);
            mn = min(mn, a[i]);
        }
    }
    cout << mn << " " << mx;
}