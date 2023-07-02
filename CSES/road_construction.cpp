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

const int MAXN = 2e5 + 10;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    fore(i, 0, n) make_set(i);

    int cnt = n, max_sz = 1, x, y;
    fore(i, 0, m) {
        cin >> x >> y;
        x--; y--;
        if (find_set(x) != find_set(y)) {
            cnt--;
            union_sets(x, y);
            int rep = find_set(x);
            if (s[rep] > max_sz) max_sz = s[rep];
        }
        cout << cnt << " " << max_sz << "\n";
    }

    return 0;
}
