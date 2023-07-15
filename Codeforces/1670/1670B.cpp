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
        int n, k;
        str s;
        cin >> n >> s >> k;
        set<char> c;
        char in;
        for (int i = 0; i < k; i++) {cin >> in; c.insert(in);}

        int cnt = 0, ans = 0;
        for (int i = 0; i < sz(s); i++) {
            if (!c.count(s[i])) cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        cout << ans << "\n";
    }
    

    return 0;
}
