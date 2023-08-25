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
        cin >> n;

        int x;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x % 2 == 0) s.insert(-x);
        }
        
        int ans = 0;
        while(!s.empty()) {
            ans++;
            auto it = s.begin();
            x = *it / -2;
            if (x % 2 == 0) s.insert(-x);
            s.erase(it);
        }

        cout << ans << "\n";
    }

    return 0;
}
