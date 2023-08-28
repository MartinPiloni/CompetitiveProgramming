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

        if(sz(s) < 2 || s[0] == 'B' || s[sz(s) - 1] != 'B') {cout << "NO\n"; continue;}

        bool can = true;
        int cnt_a = 0, cnt_b = 0;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'A') cnt_a++;
            else cnt_b++;

            can = (cnt_a >= cnt_b);
            if (!can) break;
        }
        (can ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
