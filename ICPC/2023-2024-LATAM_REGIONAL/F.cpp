#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

const int MAXN = 1e6 + 10;
vector<ll> rep[MAXN];

bool is_palindrome(int b) {
    for (int i = 0; i < sz(rep[b]) / 2; i++) {
        if (rep[b][i] != rep[b][sz(rep[b]) - 1 - i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> ans;
    for (int i = 2; i <= min(n, (ll)1e6); i++) {
        ll n2 = n;
        while (n2 != 0) {
            rep[i].pb(n2 % i);
            n2 /= i;
        }

        if (is_palindrome(i)) ans.pb(i);
    }

    for (int i = 1; i <= 1e6; i++) {
        if ((n - i) % i == 0 && (n - i) / i > (ll)1e6) {
            ans.pb((n - i) / i);
        }
    }

    if (sz(ans) == 0) cout << "*\n";
    else {
        sort(all(ans));
        for (int i = 0; i < sz(ans); i++) {
            cout << ans[i] << " \n"[i == sz(ans) - 1];
        }
    }

    return 0;
}
