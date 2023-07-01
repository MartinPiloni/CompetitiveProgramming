#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 3e3 + 10;
vector<int> g[MAXN];
bool vis[MAXN];
ll s_n, t_n;

bool valid(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
    return (((r1 - r2) * (r1 - r2) <= (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) && 
            (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r1 + r2) * (r1 + r2)));
}

bool dfs(ll v) {
    bool ans = false;

    vis[v] = true;
    if (v == t_n) ans = true;

    for (auto w : g[v]) {
        if (!vis[w]) {
            ans |= dfs(w);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s_x, s_y, t_x, t_y;
    cin >> n >> s_x >> s_y >> t_x >> t_y;

    ll x, y, r;
    vector<tuple<ll, ll, ll>> circles(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        circles[i] = {x, y, r};
    }

    s_n = -1; t_n = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll x1, y1, r1, x2, y2, r2;
            tie(x1, y1, r1) = circles[i];
            tie(x2, y2, r2) = circles[j];

            if (s_n == -1) {
                if ((s_x - x1) * (s_x - x1) + (s_y - y1) * (s_y - y1) == r1 * r1) {
                    s_n = i;
                } else if ((s_x - x2) * (s_x - x2) + (s_y - y2) * (s_y - y2) == r2 * r2) {
                    s_n = j;
                }
            }

            if (t_n == -1) {
                if ((t_x - x1) * (t_x - x1) + (t_y - y1) * (t_y - y1) == r1 * r1) {
                    t_n = i;
                } else if ((t_x - x2) * (t_x - x2) + (t_y - y2) * (t_y - y2) == r2 * r2) {
                    t_n = j;
                }
            }

            if(valid(x1, y1, r1, x2, y2, r2)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    bool f = dfs(s_n);
    (f ? cout << "Yes\n" : cout << "No\n");
    return 0;
}
