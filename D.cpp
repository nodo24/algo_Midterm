#include "bits/stdc++.h"

using namespace std;

#define ll long long


int main() {
    int n;
    cin >> n;
    ll s, k;
    cin >> s >> k;
    if (s == k) {
        cout << "NO";
        return 0;
    }

    ll arr[n + 5];
    ll curr_s = s;
    set<ll> my_set;

    for (int i = n; i > 0; i--) {
        if (i == n) {
            arr[i] = curr_s;
            my_set.insert(curr_s - k);
            continue;
        }
        ll ans = -1;
        for (ll j = curr_s - 1; j > 0; j--) {
            if (my_set.find(j) == my_set.end()) {
                ans = j;
                break;
            }
        }
        if (ans == -1) {
            cout << "NO";
            return 0;
        }
        curr_s = ans;
        arr[i] = ans;
        my_set.insert(ans - k);
    }
    arr[0] = 0;
    for (int i = n; i > 0; i--) {
        cout << arr[i] - arr[i - 1] << endl;
    }
    return 0;
}
