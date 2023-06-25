#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 25;
bool vis[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    for (auto n : g[v]) {
        if (!vis[n]) {
            vis[n] = true;
            dfs(n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int a, b, s_a, s_b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> s_a >> s_b;
        a--; b--;
        if (s_a > s_b) {
            g[a].push_back(b);
        } else {
            g[b].push_back(a);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        dfs(i);
        if (vis[i]) {
            cnt++;
        }

        for (int j = 0; j < n; j++) {
            vis[j] = false;
        }
    }

    cout << cnt << "\n";
    return 0;
}
