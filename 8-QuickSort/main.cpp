#include <bits/stdc++.h>

using namespace std;

// loop through the array when and element <= the pivot is encountered put it in the partition before i
// if it is > the pivot ignore it it will be swapped with an element <= the pivot in next steps
// at the end put the pivot in its right position. The array is now partitioned around the pivot
// where all elements before it are <= to it and all elements after it are > it.
template<typename T>
int partition(vector<T> &a, int s, int e) {
    T x = a[e]; // the pivot
    int i = s - 1;
    for (int j = s; j < e; ++j) {
        if (a[j] <= x) { // if the current element <= to the pivot
            ++i; // increment i to point to the next available position
            swap(a[i], a[j]); // swap the current element with the one at i, self swap can happen.
        }
    }
    ++i; // increment i to point to the pivot sorted position
    swap(a[i], a[e]); // get the pivot in position i
    return i;
}

template<typename T>
void quickSort(vector<T> &a, int s, int e) {
    if (s < e) { // if the subarray to be sorted has size greater than 1
        int r = partition(a, s, e); // get a pivot
        // the pivot is in its sorted position, hence, not included
        quickSort(a, s, r - 1); // sort the pivot left side
        quickSort(a, r + 1, e); // sort the pivot right side
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
