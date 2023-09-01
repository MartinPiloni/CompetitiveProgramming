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
        set<int> s;
        vector<bool> seen(n);
        int m = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i]; 
            s.insert(v[i]); 
            m = max(m, v[i]);
            if(v[i] < n) seen[v[i]] = true;
        }

        int mex = n + 1;
        vector<int> mexs;
        for (int i = 0; i < n; i++) {
            if(!seen[i]) {
                mexs.pb(i); 
                break;
            }
        }

        if (sz(mexs) == 0) {
            cout << (ll)sz(s) + k << "\n"; 
            continue;
        } else mex = mexs[0];

        bool f = true;
        int j = 1, ops = 0;
        while (ops < k && f) {
            f = s.insert((m + mex + 1) / 2).second;
            if (s.find(mex) != s.end()) {
                mex = mexs[j]; 
                j++;
            }
            ops++;
        }
        cout << sz(s) << "\n";
    }

    return 0;
}
