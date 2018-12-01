#include "bits/stdc++.h"
using namespace std;

#define SIZE 100008

int BITree[SIZE];

int getSum(int index) {
    int sum = 0;
    index = index + 1;
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index, int val) {
    index = index + 1;

    while (index <= n) {
        BITree[index] += val;
        index += index & (-index);
    }
}


int main() {
    int n;
    int q;
    cin >> n >> q;
    int k, x, y;
    int curr;
    for (int t = 0; t < n; t++) {
        cin >> curr;
        updateBIT(100005, t, curr);
    }
    for (int i = 0; i < q; i++) {
        cin >> k >> x >> y;
        if (k == 0) {
            updateBIT(100005, x - 1, y);
        } else {
            int sum = getSum(y - 1) - getSum(x - 2);
            int ans = sum % 3 == 0 ? 1 : 0;
            cout << ans << endl;
        }

    }
    return 0;
}

