#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e5 + 10;
vector<int> g[MAXN];
pair<int, int> io[MAXN];
int cnt;

void dfs(int x) {
    io[x].fst = cnt;
    cnt++;
    for (auto e : g[x]) {
        dfs(e);
    }
    io[x].snd = cnt;
    cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, x, y;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) g[x].pb(i);
        else g[n].pb(i);
    }

    cnt = 0;
    dfs(n);
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (x == y || (io[y].fst < io[x].fst && io[x].snd < io[y].snd)) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}
