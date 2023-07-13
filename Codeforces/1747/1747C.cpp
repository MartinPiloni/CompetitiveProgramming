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
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int m = 2e9;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m = min(m, v[i]);
        }

        if (m == v[0]) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
