
#include "bits/stdc++.h"

using namespace std;


vector<int> graph[11234];

int dfs(int s, set<int> &visited) {
    visited.insert(s);
    int res = 0;
    int len = graph[s].size();
    for (int i = 0; i < len; i++) {
        int c = graph[s][i];
        if (visited.find(c) == visited.end()) {
            res += dfs(c, visited);
        }
    }
    return res + 1;
}



int main() {
    int tt, n, m;
    int u, v;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        cin >> n >> m;
        int arr[n + 5];
        for (int i = 0; i <= n; i++) {
            arr[i] = -1;
        }
        for (int i = 0; i < m; i++) {
            cin >> v >> u;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (arr[i] != -1) {
                cout << arr[i] << " ";
                continue;
            }
            set<int> visited;
            int v_n = dfs(i, visited);
            set<int>::iterator it;
            for (it = visited.begin(); it != visited.end(); ++it) {
                arr[*it] = v_n - 1;
            }
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= n; i++) {
            graph[i].clear();
        }

    }
    return 0;
}
