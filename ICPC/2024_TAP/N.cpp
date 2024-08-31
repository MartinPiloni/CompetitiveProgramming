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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    ll ans = 0;
    ll a = v[n - 1], b, c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        b = v[i]; 
        c = v[j]; 
        ans = max(ans, a*a+b*b+c*c-a*b-a*c-b*c);
      }
    }
    cout << ans << "\n";

    return 0;
}
