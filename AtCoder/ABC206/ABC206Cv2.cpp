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

    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      freq[v[i]]++;
    }

    ll ans = 0;
    ll nums = n;
    for (int i = 0; i < n; i++) {
      ans += nums - freq[v[i]];
      nums--;
      freq[v[i]]--;
    }
    cout << ans << "\n";

    return 0;
}
