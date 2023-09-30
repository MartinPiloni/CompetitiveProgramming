#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

#define oper(a, b) a&b
const int K = 20;
int st[K][1<<K]; int n;  // K such that 2^K>n
void st_init(vector<int> &a) {
	for (int i = 0; i < n; i++) st[0][i]=a[i];
	for (int k = 1; k < K; k++) {
	    for (int i = 0; i < n-(1<<k)+1; i++) st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
}

int st_query(int s, int e) {
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int bs(int x, int k) {
    int l = x, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (x == m || st_query(x, m) >= k) l = m + 1;
        else r = m - 1;
    }
    return l - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        st_init(v);
        int q; cin >> q;
        while (q--) {
            int l, k; cin >> l >> k;
            l--;
            if (v[l] < k) cout << "-1" << " \n"[q == 0];
            else cout << bs(l, k) << " \n"[q == 0];
        }
    }

    return 0;
}