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
        map<int, int> freq;
        int x;
        for (int i = 0; i < 3; i++) {
            cin >> x;
            freq[x]++;
        }
        for (auto e : freq) {
            if (e.snd == 1) cout << e.fst << "\n";
        }
    }

    return 0;
}
