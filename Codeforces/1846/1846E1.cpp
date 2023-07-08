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

    vector<bool> ans(1e6 + 10);
    for (int i = 2; i < 1e3; i++) {
        int j = i * i, s = 1 + i + i*i;
        while(s < 1e6) {
            ans[s] = true;
            j *= i;
            s += j;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        (ans[n] ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
