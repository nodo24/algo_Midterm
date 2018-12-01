#include "bits/stdc++.h"

using namespace std;


int d[112345][30];
int B[30];
string a, b;
int len_a, len_b;

int check(int i) {
    int err = 0;
    for (int j = 0; j < 26; j++) {
        int curr = d[i][j] - d[i - len_b][j];
        if (curr != B[j]) {
            err = 1;
        }
    }
    return err;
}

int main() {
    cin >> a >> b;
    len_b = b.length();
    len_a = a.length();
    if (len_a < len_b) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < len_b; i++) {
        B[b[i] - 'a']++;
    }

    for (int i = 0; i < len_a; i++) {
        d[i + 1][a[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            d[i + 2][j] = d[i + 1][j];
        }
    }
    int index = len_b;
    while (true) {
        if (index > len_a) {
            break;
        }
        if (check(index) == 0) {
            cout << "YES";
            return 0;
        }
        ++index;
    }
    cout << "NO";
    return 0;
}
