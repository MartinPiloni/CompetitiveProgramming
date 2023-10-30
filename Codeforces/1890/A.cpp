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
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }
        if (sz(freq) > 2) cout << "NO\n";
        else if (sz(freq) == 1) cout << "YES\n";
        else {
            int f1 = freq.begin()->second;
            auto f2 = --freq.end();
            if (abs(f1 - f2->second) <= 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
