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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long double, int>> v(n);
    long double x, y;
    fore(i, 0, n) {
        cin >> x >> y;
        v[i] = {-x / (x + y), i + 1};
    }
    sort(ALL(v));
    fore(i, 0, n) cout << v[i].snd << " \n"[i == n - 1];

    return 0;
}
