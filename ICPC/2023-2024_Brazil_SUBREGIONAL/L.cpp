#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s;
    int k;
    cin >> s >> k;

    vector<vector<char>> v(k);
    for (int i = 0; i < sz(s); i++) {
        v[i % k].pb(s[i]);
    }

    for (int i = 0; i < k; i++) {
        sort(all(v[i % k]));
    }

    for (int i = 0; i < sz(s); i++) {
        cout << v[i % k][i / k];
    }
    cout << "\n";

    return 0;
}
