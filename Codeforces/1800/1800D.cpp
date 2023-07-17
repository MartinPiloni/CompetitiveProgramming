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
        str s;
        cin >> n >> s;
        int ans = 1;
        for (int i = 2; i < n; i++) {
            if (s[i] != s[i - 2]) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
