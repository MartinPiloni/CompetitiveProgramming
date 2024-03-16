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

        map<int, int> l, r;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            l[x]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            r[x]++;
        }

        int l_k = 2 * k, r_k = 2 * k;
        vector<int> l_ans, r_ans;
        for (auto e : l) {
            if (l_k == 0) break;

            if (e.snd == 2) {
                l_ans.pb(e.fst);
                l_ans.pb(e.fst);
                l_k -= 2;
            }
        }

        for (auto e : r) {
            if (sz(l_ans) == sz(r_ans)) break;

            if (e.snd == 2) {
                r_ans.pb(e.fst);
                r_ans.pb(e.fst);
                r_k -= 2;
            }
        }

        for (auto e : l) {
            if (l_k == 0) break;

            if (e.snd == 1) {
                l_ans.pb(e.fst);
                r_ans.pb(e.fst);
                r_k--;
                l_k--;
            }
        }

        for (auto e : l_ans) {
            cout << e << " ";
        }
        cout << "\n";
        for (auto e : r_ans) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}
