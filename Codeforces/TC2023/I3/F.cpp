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

    int cnt_a = 0, cnt_b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cnt_a++;
        else if (s[i] == 'b') cnt_b++;

        if(cnt_a == cnt_b + 2) {
            s[i] = 'b';
            ans++;
            cnt_a--;
            cnt_b++;
        } else if (cnt_b == cnt_a + 2) {
            s[i] = 'a';
            ans++;
            cnt_b--;
            cnt_a++;
        }
    }

    cout << ans << "\n";
    cout << s << "\n";

    return 0;
}
