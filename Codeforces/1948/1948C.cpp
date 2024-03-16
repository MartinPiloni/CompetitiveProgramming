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
        vector<str> g(2);
        for (int i = 0; i < 2; i++) cin >> g[i];

        pair<int, int> cur_pos = {0, 0};
        
        bool ok = false;
        while (1) {
            if (g[cur_pos.fst][cur_pos.snd + 1] == '>') {
                cur_pos.snd += 2;
                if ((cur_pos.fst == 0 && cur_pos.snd == n - 1) || (cur_pos.fst == 1 && cur_pos.snd >= n - 1)) {
                    ok = true;
                    break;
                }
            } else if (g[cur_pos.fst][cur_pos.snd + 1] == '<') {
                if (g[!cur_pos.fst][cur_pos.snd] == '<') {
                    break;
                } else {
                    cur_pos.fst = !cur_pos.fst;
                    cur_pos.snd += 1;
                    if ((cur_pos.fst == 0 && cur_pos.snd == n - 1) || (cur_pos.fst == 1 && cur_pos.snd >= n - 1)) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        (ok ? cout << "YES\n" : cout << "NO\n");
    }

    return 0;
}
