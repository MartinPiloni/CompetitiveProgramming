#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define dbg(x) cerr << #x << ": " << (x) << endl

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s;
    cin >> s;
    sort(all(s));
    vector<str> ans;
    do {
      ans.pb(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << sz(ans) << "\n";
    for (auto e : ans) cout << e << "\n";

    return 0;
}
