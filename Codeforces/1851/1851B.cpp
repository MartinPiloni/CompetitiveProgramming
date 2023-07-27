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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<bool> b(n);
        for (int i = 0; i < n; i++) b[i] = v[i] % 2;
        sort(all(v));
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (v[i] % 2 != b[i]) {ans = false; break;}
        }
        (ans ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
