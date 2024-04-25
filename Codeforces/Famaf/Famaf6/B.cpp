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
        int a, b, n;
        cin >> a >> b >> n;

        if (n % 3 == 0) cout << a << "\n";
        else if (n % 3 == 1) cout << b << "\n";
        else cout << (a ^ b) << "\n";
    }

    return 0;
}
