#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mx 0
#define mn 1e9
#define v(dt) vector<dt>
const int N = 1e5;
ll n;

ll findPeak(ll arr[], ll s, ll e) {

    ll mid = s + (e - s) / 2;
    if ((arr[mid] >= arr[mid - 1] or mid == 0) and (arr[mid] >= arr[mid + 1] or mid == n - 1)) {
        return mid;
    } else if (arr[mid] < arr[mid - 1]) {
        e = mid - 1;
        return findPeak(arr, s, mid - 1);
    } else {
        return findPeak(arr, mid + 1, e);
    }

}
ll findPeakUtil(ll arr[], ll low, ll high)
{
    ll mid = low + (high - low)/2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakUtil(arr, low, (mid - 1));
    else return findPeakUtil(arr, (mid + 1), high);
}

int main() {

    ll res = 0, res2 = 0;
    while (true)
    {
        int n = rand() % (int)1e5;
        ll arr[n];
        for (int i = 0; i < n; i++) {
             arr[i] = rand() % (ll)1e9;
        }
        res = findPeak(arr, 0, n - 1);
        res2 = findPeakUtil(arr, 0, n - 1);

        if (res!=res2)
        {
            break;
        }

    }

    cout <<res<<" "<<res2;
    return 0;
}