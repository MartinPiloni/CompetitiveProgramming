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
        cin >> n >> k;

        vector<int> v(n);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == k) ok = true;
        }

        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
