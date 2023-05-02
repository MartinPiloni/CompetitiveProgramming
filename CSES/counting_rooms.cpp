#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;


const int MAX_N = 1000;
vector<int> g[MAX_N * MAX_N];
vector<bool> vis(MAX_N * MAX_N, 1);

void dfs(int node) {
    if (vis[node]) return;

    vis[node] = 1;
    for(auto u : g[node]) {
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') vis[i * m + j] = 0;

            if (j != 0 && v[i][j] == '.' && v[i][j - 1] == '.') {
                g[i * m + j].push_back(i * m + j - 1);
                g[i * m + j - 1].push_back(i * m + j);
            }
            
            if (i != 0 && v[i][j] == '.' && v[i - 1][j] == '.') {
                g[i * m + j].push_back((i - 1) * m + j);
                g[(i - 1) * m + j].push_back(i * m + j);
            }
        }
    }
    
    int components = 0;
    for (int i = 0; i < MAX_N * MAX_N; i++) {
        if (!vis[i]) {
            components++;
            dfs(i);
        }
    }

    cout << components << "\n";
    return 0;
}
