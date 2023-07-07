#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> v(n + 1);
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            v[i] = v[i - 1] ^ x;
        }

        vector<bool> s(256);
        s[0] = true;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 256; j++) {
                if (s[j]) {
                    ans = max(ans, v[i] ^ j);
                }
            }

            s[v[i]] = true;
        }

        cout << ans << "\n";
    }
    return 0;
}
