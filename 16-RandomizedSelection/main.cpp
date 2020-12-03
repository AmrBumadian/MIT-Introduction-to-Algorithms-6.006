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
int randomPartition(vector<T> &a, int s, int e) {
    srand(time(0)); // seed the generator
    int i = (rand() % (e - s + 1)) + s; // generate a random index between s and e
    swap(a[e], a[i]); // swap the element at i with the end of the subarray
    return partition(a, s, e); // partition and get a pivot for the next step
}

template<typename T>
T find_nTh_element(vector<T> &a, int s, int e, int i) {
    if (s == i) return a[s]; // base case, if there is only 1 element in the subarray return it
    int q = randomPartition(a, s, e); // random partition and get pivot
    int k = q - s + 1; // number of elements from start to pivot inclusive
    if (i == k) return a[q]; // the pivot is in its sorted position, so if true return it
    // else if the needed element order is less than the pivot's order, solve the left side recursively
    else if (i < k) return find_nTh_element(a, s, q - 1, i); 
    // else solve the right side recursively
    else return find_nTh_element(a, q + 1, e, i - k);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << find_nTh_element(a, 0, n - 1, x);
}
