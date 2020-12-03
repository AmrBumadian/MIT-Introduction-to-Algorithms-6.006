#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define EPS 1e-9
#define MOD (int)1e9+7
#define INF (int)1e9
#define LINF (ll)1e18
#define pi 3.14
#define el "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

pair<ii, ll> maxCrossing(vll &a, int start, int mid, int end) { // find maximum subarray crossing through the midpoint
    ll leftSum = -LINF, rightSum = -LINF;
    ll sum = 0;
    int leftIdx, rightIdx;

    for (int i = mid; i >= start; --i) { // calculate sum for the left side
        sum += a[i];
        if (sum > leftSum) { // if sum > current sum reassign the answer
            leftSum = sum;
            leftIdx = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= end; ++i) { // calculate sum for the right side
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
            rightIdx = i;
        }
    }
    return {{leftIdx, rightIdx}, leftSum + rightSum}; // return the interval with its max sum
}

pair<ii, ll> maxSubarray(vll &a, int start, int end) { // find maximum sum contiguous subarray
    if (start == end) return {{start, end}, a[start]}; // contains 1 element return it
    int mid = (start + end) / 2;
    pair<ii, ll> left = maxSubarray(a, start, mid); // solve the left sub-problem recursively
    pair<ii, ll> right = maxSubarray(a, mid + 1, end); // solve the right sub-problem recursively
    pair<ii, ll> crossing = maxCrossing(a, start, mid, end); // find a combined solution

    if (left.s > right.s && left.s > crossing.s) { // if left has the greatest sum return it
        return left;
    } else if (right.s > left.s && right.s > crossing.s) { // if right has the greatest sum return it
        return right;
    } else return crossing; // crossing through the mid sub-array has the greatest contiguous sum
}


int main() {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
	// Theta(nlgn) running-time D&C Algorithm
    pair<ii, ll> ans = maxSubarray(a, 0, n - 1);

    // Faster linear-time Kadane's Algorithm
    ll sum = 0, mx = 0;
    int startIdx = 0, endIdx = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum > mx) { // max sum we reached
            mx = sum;
            endIdx = i;
        }
        if (sum < 0) { // if the sum drops below 0 it's always better to start from 0 instead of negative number
            sum = 0;
            startIdx = endIdx = i+1;
        }
    }
    cout << "Divide & Conquer Algorithm\n";
    cout << "[" << ans.f.f << "," << ans.f.s << "]\n";
    cout << "Max sum: " << ans.s << el;

    cout << "Kadane's Algorithm\n";
    cout << "[" << startIdx << "," << endIdx << "]\n";
    cout << "Max sum: " << mx << el;
}


