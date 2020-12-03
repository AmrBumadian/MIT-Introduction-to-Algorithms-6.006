#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &input, int exp) {
    int n = input.size();
    vector<int> sorted(n), count(10);

    for (int i = 0; i < n; ++i) { // count each element frequency
        ++count[(input[i] / exp) % 10];
    }
    for (int i = 1; i < 10; ++i) { // cumulative sum for the frequencies so we get the proper index for each element
        count[i] += count[i - 1];
    }
    // get the index of each element and put it in its sorted position
    // starting from the end so the sorting is stable, if two elements are equal, which appeared last stays last
    for (int i = n - 1; i >= 0; --i) {
        sorted[--count[(input[i] / exp) % 10]] = input[i];
//         equivalent to the first line
//         output[count[(input[i] / exp) % 10] - 1] = input[i];
//        --count[(input[i] / exp) % 10];
    }
    input = sorted;
}

void radixSort(vector<int> &input, int range) {
    // count sort the numbers according to each digit from the least significant to the most
    // exp is multiplied by 10 each iteration so that input[i]/exp
    // last digit is the current digit to sort according to it, %10 to extract the last digit
    for (int exp = 1; range / exp > 0; exp *= 10) {
        countSort(input, exp);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    radixSort(a, mx);
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
