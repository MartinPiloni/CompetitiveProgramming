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
        for (int i = 0; i < n; i++) cin >> v[i];

        int cnt = 0, c = v[0], ind = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == c) cnt++;
            if (cnt == k) {ind = i; break;}
        }

        if (ind == -1) {cout << "NO\n"; continue;}
        else if (v[0] == v[n - 1]) {cout << "YES\n"; continue;}

        bool ans = false;
        cnt = 0, c = v[n - 1];
        for (int i = ind; i < n; i++) {
            if (v[i] == c) cnt++;
            if (cnt == k) {ans = true; break;}
        }

        (ans ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
