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

    ll n, m, d;
    cin >> n >> m >> d;
    
    set<ll> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
        s.insert(v[i]);
    }

    map<ll, ll> ans;
    ll curr = *s.begin(), cnt = 0;
    while (!s.empty()) {
        ans[curr] = cnt + 1;
        s.erase(curr); 

        auto a = s.upper_bound(curr + d);
        if (a == s.end()) {
            cnt++; 
            if(!s.empty()) curr = *s.begin();
        } else {
            curr = *a;
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < sz(v); i++) {
        cout << ans[v[i]] << " \n"[i == n - 1];
    }

    return 0;
}
