#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 2e5 + 10;
ll p[MAXN];
ll s[MAXN];

void make_set(ll v) {
    p[v] = v;
    s[v] = 1;
}

ll find_set(ll v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

bool union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (s[a] < s[b])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> c(n);
    ll min_i = 1e18, min_c = 1e18;
    for (int i = 0; i < n; i++) {
        make_set(i);
        cin >> c[i];
        
        if (c[i] < min_c) {
            min_c = c[i];
            min_i = i;
        }
    }

    vector<pair<ll, pair<ll, ll>>> edges;
    ll x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        x--; y--;
        edges.push_back({w, {x, y}});
    }

    for (int i = 0; i < n; i++) {
        if (i == min_i) continue; 
        edges.push_back({c[i] + c[min_i], {min_i, i}});
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    for (int i = 0; i < sz(edges); i++) {
        x = edges[i].second.first;
        y = edges[i].second.second;
        if (union_sets(x, y)) ans += edges[i].first;
    }

    cout << ans << "\n"; 
    return 0;
}
