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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll x, even_sum = 0, odd_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x & 1) odd_sum += x;
            else even_sum += x;
        }
        (even_sum > odd_sum ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
