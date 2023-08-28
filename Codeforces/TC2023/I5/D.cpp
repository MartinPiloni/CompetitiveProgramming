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

    str s; cin >> s;
    ll ans = 0, cnt = 0, cnt2 = 0;
    char curr = 'a', curr2 = 'a';
    for (int i = 0; i < sz(s); i++) {
        cnt = 0; cnt2 = 0;
        while (curr != s[i]) {
            if (curr == 'z') {cnt++; curr = 'a';}
            else {cnt++; curr++;}
        }
        
        while (curr2 != s[i]) {
            if (curr2 == 'a') {cnt2++; curr2 = 'z';}
            else {cnt2++; curr2--;}
        }

        ans += min(cnt, cnt2);
    }

    cout << ans << "\n";
    return 0;
}
