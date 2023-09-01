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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {cin >> v[i]; s.insert(v[i]);}
    for (auto it = s.begin(); it != s.end(); it++) {
        while (*s.lower_bound(*it - k) < *it) {
            s.erase(s.lower_bound(*it - k));
        }
    }
    cout << sz(s) << "\n";

    return 0;
}
