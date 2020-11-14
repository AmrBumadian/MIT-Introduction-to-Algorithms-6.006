#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}
string t, p;
vi b;  //reset table

void preprocess() {  //preprocess the back table
    int m = p.length();
    int i = 1, j = 0;
    b[0] = -1;
    while (i < m) {
        if (j == 0 && p[i] != p[j]) j = b[j];  //different, reset j using b
        ++i, ++j;  //if same, advance both pointers
        b[i] = j;  //set the reset element at i to j (the index of the last unmatched char)
    }
}

void kmp() {  //same as preprocessing but comparing p[j] with t[i] instead
    int n = t.length(), m = p.length();
    int i = 0, j = 0;
    while (i < n) {
        if (j == 0 && t[i] != p[j]) j = b[j];  //different, reset j using b
        ++i, ++j;  //if same advance both pointers
        if (j == m) {
            cout << "There is occurrence starting at: " << i - j << "\n";
            j = b[j];   //reset j using b to the index we shall start comparison from
        }
    }
}

int main() {
    getline(cin, t);
    getline(cin, p);
    b.resize(p.length() + 1);
    preprocess();
    kmp();
}
