#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

ll sum_of_digits(ll x) {
    ll ans = 0;
    while (x != 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> ps(2e5 + 10);
    for (int i = 1; i < 2e5 + 10; i++) {
        ps[i] = ps[i - 1] + sum_of_digits(i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ps[n] << "\n";
    }

    return 0;
}
