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

    int cnt = 1, ans = 1;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            ans = max(cnt, ans);
            cnt = 1;
        }
    }
    ans = max(cnt, ans);
    cout << ans << "\n";

    return 0;
}
