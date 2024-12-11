#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()

using ll = long long;
using str = string;

const int INF = 1e9;
#define oper min
#define NEUT INF
struct STree {
    vector<int> st;
    int n;
    STree(int n) : st(4 * n + 5, 0), n(n) {}
    void upd(int k, int s, int e, int p) {
        if (s + 1 == e) {
            st[k] += 1;
            return;
        }
        int m = (s + e) / 2;
        if (p < m)
            upd(2 * k, s, m, p);
        else
            upd(2 * k + 1, m, e, p);
        st[k] = oper(st[2 * k], st[2 * k + 1]);
    }
    int query(int k, int s, int e, int a, int b) {
        if (s >= b || e <= a)
            return NEUT;
        if (s >= a && e <= b)
            return st[k];
        int m = (s + e) / 2;
        return oper(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
    }
    void upd(int p) { upd(1, 0, n, p); }
    int query(int a, int b) { return query(1, 0, n, a, b); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    STree s(n);

    int x, p_mine, mine;
    for (int i = 0; i < m; i++) {
        p_mine = s.query(0, n);
        cin >> x;
        x--;
        s.upd(x);
        mine = s.query(0, n);

        if (p_mine < mine)
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";

    return 0;
}
