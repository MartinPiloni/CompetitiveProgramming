#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAXN = 110;
int p[MAXN][MAXN];
int s[MAXN][MAXN];

void make_set(int v, int c) {
    p[c][v] = v;
    s[c][v] = 1;
}

int find_set(int v, int c) {
    if (v == p[c][v])
        return v;
    return p[c][v] = find_set(p[c][v], c);
}

void union_sets(int a, int b, int c) {
    a = find_set(a, c);
    b = find_set(b, c);
    if (a != b) {
        if (s[a][c] < s[b][c])
            swap(a, b);
        p[c][b] = a;
        s[c][a] += s[c][b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            make_set(i, j);
        }
    }

    int x, y, c;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        c--;
        union_sets(x, y, c);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += find_set(x, j) == find_set(y, j);
        }

        cout << cnt << "\n";
    }

    return 0;
}
