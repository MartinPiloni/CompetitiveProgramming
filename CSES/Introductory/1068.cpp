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
    cout << n << " ";

    while (n != 1) {
        if (n & 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        cout << n << " \n"[n == 1];
    }

    return 0;
}
