#include "bits/stdc++.h"

using namespace std;

#define MAX (2 << 26 + 1)

int arr[512345];
int ans[MAX];
set<int> vs;


int dfs(int s) {
    int res = 0;
    for (int i = 0; i < 26; i++) {
        int curr = 1 << i;
        if ((s & curr) == 0) {
            curr += s;
            if (vs.find(curr) != vs.end()) {
                int curr_ANS = dfs(curr);
                ans[curr] = curr_ANS;
                res = max(res, curr_ANS);
            }
        }
    }
    return res + 1;
}


int main() {
    int n;
    cin >> n;
    string s;
    for (int n_i = 0; n_i < n; n_i++) {
        cin >> s;
        int curr_mask = 0;
        for (int i = 0; i < s.length(); i++) {
            int cc = (s[i] - 'a');
            curr_mask += (1 << cc);
            arr[n_i] = curr_mask;
        }
        vs.insert(curr_mask);
    }

    int A = -1;
    for (int k = 0; k < n; k++) {
        if (ans[arr[k]] == 0) {
            ans[arr[k]] = dfs(arr[k]);
        }
        A = max(A, ans[arr[k]]);
    }
    cout << A << endl;
    return 0;
}
