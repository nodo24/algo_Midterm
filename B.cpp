#include "bits/stdc++.h"

using namespace std;


int d[112345][30];
int B[30];
string a, b;

int main() {
    cin >> a >> b;
    int len_b = b.length();
    int len_a = a.length();
    if (len_a < len_b) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < len_b; i++) {
        B[b[i] - 'a']++;
    }

    for (int i = 0; i < len_a; i++) {
        d[i+1][a[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            d[i + 2][j] = d[i+1][j];
        }
    }

    for (int i = len_b; i <= len_a; i++) {
        int err = 0;
        for (int j = 0; j < 26; j++) {
            int curr = d[i][j] - d[i - len_b][j];
            if (curr != B[j]) {
                err = 1;
            }
        }
        if (err == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
