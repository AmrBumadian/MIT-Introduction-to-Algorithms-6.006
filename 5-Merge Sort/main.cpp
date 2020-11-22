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
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

int inversionCount = 0;

void merge(vi &a, int p, int q, int r) { // merge the two sorted partitions back to A
    int n1 = q - p + 1;
    int n2 = r - q;
    vi left(n1), right(n2);
    for (int i = 0; i < n1; ++i) { // copy the left part, offset p
        left[i] = a[p + i];
    }
    for (int i = 0; i < n2; ++i) { // copy the right part, offset q+1
        right[i] = a[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    for (; k <= r && (i < n1 && j < n2); ++k) {
        // compare between the two least elements in left and right and put them back in sorted order
        if (left[i] <= right[j]) {
            a[k] = left[i];
            ++i; // advance pointer to the next element in left
        } else {
            // since right[j] is smaller than left[i], it makes an inversion with all elements left[i..n1]
            inversionCount += (n1 - i);
            a[k] = right[j];
            ++j; // advance pointer to the next element in right
        }
    }
    if (i < n1) { // if left wasn't fully copied
        while (k <= r) { // copy the rest of left back to A
            a[k] = left[i];
            ++i, ++k;
        }
    } else {
        while (k <= r) { // copy the rest of right back to A
            a[k] = right[j];
            ++j, ++k;
        }
    }
}

void mergeSort(vi &arr, int p, int r) {
    if (p < r) { // if the array has more than 1 element
        int q = (p + r) / 2; // partitioning around q
        mergeSort(arr, p, q); // sort the left partition
        mergeSort(arr, q + 1, r); // sort the right partition
        merge(arr, p, q, r); // merge the two partitions
    }
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << el;
    cout << inversionCount;
}
