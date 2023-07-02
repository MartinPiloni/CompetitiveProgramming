#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))

using ll = long long;
using str = string;

const int MAXN = 1e5 + 10;
int p[MAXN];
int s[MAXN];

void make_set(int v) {
    p[v] = v;
    s[v] = 1;
}

int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (s[a] < s[b])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}

vector<pair<ll, pair<int, int>>> edges;
ll kruskal() {
    sort(ALL(edges));
    ll ans = 0;
    for (auto e : edges) {
        if (find_set(e.snd.fst) != find_set(e.snd.snd)) {
            ans += e.fst;
            union_sets(e.snd.fst, e.snd.snd);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    fore(i, 0, n) make_set(i);
    
    int x, y, c;
    fore(i, 0, m) {
        cin >> x >> y >> c;
        x--;  y--;
        edges.pb({c, {x, y}});
    }

    ll ans = kruskal();
    bool ok = true;
    fore(i, 1, n) {
        if (find_set(0) != find_set(i)) {
            ok = false;
            break;
        }
    }

    (ok ? cout << ans << "\n" : cout << "IMPOSSIBLE\n");
    return 0;
}
