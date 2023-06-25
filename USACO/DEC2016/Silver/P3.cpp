#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MAXN = 210;
vector<int> g[MAXN];
bool vis[MAXN];
int cnt;

void dfs(int v) {
    vis[v] = true;

    for (int n : g[v]) {
        if (!vis[n]) {
            cnt++;
            dfs(n);
        }
    }

    return;
}

int main() {
    setIO("moocast");
    int n;
    cin >> n;

    vector<int> x(n), y(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
        cin >> p[i];
    }

    int dist_square = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist_square = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
            if (dist_square <= p[i] * p[i]) {
                g[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        cnt = 1;
        dfs(i);
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}
