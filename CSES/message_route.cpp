#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<int> dist(n);
    vector<int> pushed(n);
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : g[v]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[v] + 1;
            pushed[u] = v;
            q.push(u);
        }
    }

    if(!visited[n - 1]) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n - 1] + 1 << "\n";
        
        vector<int> ans(dist[n - 1] + 1);
        int v = n - 1;
        for (int i = dist[n - 1]; i >= 0; i--) {
            ans[i] = v + 1;
            v = pushed[v];
        }

        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }

    return 0;
}
