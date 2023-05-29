#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAX_N = 2e5 + 5;
vector<pair<int, int>> g[MAX_N];
vector<bool> vis(MAX_N);
int ans; 

void dfs(pair<int, int> v, int cnt, int t) {
    if (vis[v.first]) return;
    vis[v.first] = true;

    if (v.second < t) cnt++;
    for (auto n : g[v.first]) {
        dfs(n, cnt, v.second);
    }

    ans = max(ans, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            g[i].clear();
            vis[i] = false;
        }

        int x, y;
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            x--; y--;
            g[x].push_back(make_pair(y, i + 1));
            g[y].push_back(make_pair(x, i + 1));
        }

        ans = 0;
        dfs({0, 0}, 1, 0);
        
        cout << ans << "\n";
    }

    return 0;
}
