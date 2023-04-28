#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 1e5 + 10;
vector<int> g[MAX_N];
vector<int> visited(MAX_N);
vector<int> component(MAX_N);

void dfs(int v, int c) {
    if (visited[v]) return;

    visited[v] = 1;
    component[v] = c;
    for (auto i : g[v]) {
        dfs(i, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int c = 0;
    vector<int> routes;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            c++;
            routes.push_back(i + 1);
            dfs(i, c);
        }
    } 

    cout << c - 1 << "\n";
    if (c > 0) {
        for (int i = 0; i < (int) routes.size() - 1; i++) {
            cout << routes[i] << " " << routes[i + 1] << "\n";
        }
    }

    return 0;
}
