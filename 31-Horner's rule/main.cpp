#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define EPS 1e-9
#define MOD (int)1e9+7
#define INF (int)1e9
#define pi 3.14
#define el "\n"

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
    for (int i = 0; i < n; ++i) cin >> a[i]; // coefficients of the function a[0] is the leading coefficient
    int x; // sub with x
    cin >> x;
    ll y = 0;
    for (int i = 0; i < n; ++i) { // Horner's rule
        y = a[i] + x * y;
    }
    cout << y << el;
}
/* eg: x^3 + 2x^2 + 3x -4 => x(x(x + 2) + 3) - 4
 * therefore, instead of calculating each term independently then sum the terms,
 * starting from the term with the least degree we multiply the current answer 
 * by x again and add the coefficient to the answer so that each coefficient is implicitly
 * multiplied by x (the degree of its term) times.
*/
