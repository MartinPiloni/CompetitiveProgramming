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

    str s;
    cin >> s;
    int n = sz(s);


    ll ans = (int(s[0]) % 4 == 0);
    for (int i = 1; i < n; i++) {
        if ((s[i - 1] - '0') % 2 == 0 && (s[i] - '0') % 4 == 0) ans += i + 1;
        else if ((s[i - 1] - '0') & 1 && (s[i] == '2' || s[i] == '6')) ans += i; 
        else if ((s[i] - '0') % 4 == 0) ans++;
    }
    cout << ans << "\n";

    return 0;
}
