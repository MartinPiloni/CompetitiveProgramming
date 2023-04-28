#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

vector<vector<int>> g;
vector<int> color;

bool bfs(int v) {
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int n = q.front(); q.pop();
        for (auto i : g[n]) {
            if (color[i] == 0) {
                q.push(i);
                color[i] = (color[n] == 1 ? 2 : 1);
            } else if (color[n] == color[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            ans = bfs(i);
        }

        if (!ans) break;
    } 

    if (!ans) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
