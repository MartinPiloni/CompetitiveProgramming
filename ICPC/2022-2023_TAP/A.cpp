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
    str s;
    cin >> n >> s;

    bool f = false;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!f && s[i] == 'a') {f = true; cnt++;}
        else if (f && s[i] == 'a') cnt++;
        else if (f && s[i] != 'a') {
            if (cnt > 1) ans += cnt;
            f = false; 
            cnt = 0;
        }
    }
    if (cnt > 1) ans += cnt;
    cout << ans << "\n";

    return 0;
}
