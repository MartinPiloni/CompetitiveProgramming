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
        vector<str> g(3);
        for (int i = 0; i < 3; i++) cin >> g[i];

        for (int i = 0; i < 3; i++) {
            set<char> s;
            for (int j = 0; j < 3; j++) {
                s.insert(g[i][j]);
            }

            if (s.count('?')) {
                if (s.count('A') == 0) cout << "A" << "\n";
                else if (s.count('B') == 0) cout << "B" << "\n";
                if (s.count('C') == 0) cout << "C" << "\n";
            }
        }
    }

    return 0;
}
