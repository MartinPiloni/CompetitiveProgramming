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
        str s;
        cin >> s;
        if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
