#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n), b(n), c(n);
        fore(i, 0, n) cin >> a[i];
        fore(i, 0, n) cin >> b[i];
        fore(i, 0, n) cin >> c[i];

        int num = 0;
        fore(i, 0, n) {
            if ((a[i] & x) == a[i] && num != x) num |= a[i];
            else break;
        }
        fore(i, 0, n) {
            if ((b[i] & x) == b[i] && num != x) num |= b[i];
            else break;
        }
        fore(i, 0, n) {
            if ((c[i] & x) == c[i] && num != x) num |= c[i];
            else break;
        }

        (num == x ? cout << "Yes\n" : cout << "No\n");
    }

    return 0;
}

