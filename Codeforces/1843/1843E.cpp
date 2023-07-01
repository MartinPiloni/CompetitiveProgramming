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

#define sz(x) int((x).size())

const int MAXN = 1e5 + 10;
int a[MAXN];
vector<pair<int, int>> segment;
int n, m;

bool can(int p) {
    vector<int> ps(n + 1);
    ps[0] = 0;
    fore(i, 1, n + 1) {
        if (a[i] != 0 && a[i] <= p) ps[i] = ps[i - 1] + 1;
        else ps[i] = ps[i - 1];
    }

    for (auto s : segment) {
        if ((s.second - s.first + 1) / 2 < ps[s.second] - ps[s.first - 1]) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        int x, y;
        fore(i, 0, m) {
            cin >> x >> y;
            segment.pb({x, y});
        }

        int q, c;
        cin >> q;
        
        fore(i, 0, q) {
            cin >> c;
            a[c] = i + 1;
        }

        int l = 1, r = q, mid;
        bool ok = false;
        while (l <= r) {
            mid = (l + r) / 2;

            if (can(mid)) {
                ok = true;
                r = mid - 1;
            } else l = mid + 1;
        }


        (ok ? cout << r + 1 << "\n" : cout << "-1\n");

        segment.clear();
        mset(a, 0);
    }

    return 0;
}
