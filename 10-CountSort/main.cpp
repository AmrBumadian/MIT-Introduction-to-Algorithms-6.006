#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &input, int k) {
    int n = input.size();
    vector<int> sorted(n), count(k + 1);

    for (int i = 0; i < n; ++i) { // count each element frequency
        ++count[input[i]];
    }
    for (int i = 1; i <= k; ++i) { // cumulative sum for the frequencies so we get the proper index for each element
        count[i] += count[i - 1];
    }
    // get the index of each element and put it in its sorted position
    // starting from the end so the sorting is stable, if two elements are equal, which appeared last stays last
    for (int i = n - 1; i >= 0; --i) { 
        sorted[--count[input[i]]] = input[i];
//         equivalent to the first line
//        output[Count[input[i]] - 1] = input[i];
//        --Count[input[i]];
    }
    input = sorted;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    countSort(a, mx);
    
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
