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
        str s;
        cin >> s;

        vector<int> pos[26];
        int n = sz(s);
        for (int i = 0; i < n; i++) pos[s[i] - 'a'].pb(i + 1);
        
        int cost = 0, len = 0;
        if (s[0] <= s[n - 1]) {
            cost = s[n - 1] - s[0];
            for (char c = s[0]; c <= s[n - 1]; c++) len += sz(pos[c - 'a']);
            cout << cost << " " << len << "\n";
            for (char c = s[0]; c <= s[n - 1]; c++) {
                for (auto e : pos[c - 'a']) cout << e << " ";
            }
            cout << "\n";
        } else if (s[0] > s[n - 1]) {
            cost = s[0] - s[n - 1];
            for (char c = s[0]; c >= s[n - 1]; c--) len += sz(pos[c - 'a']);
            cout << cost << " " << len << "\n";
            for (char c = s[0]; c >= s[n - 1]; c--) {
                for (auto e : pos[c - 'a']) cout << e << " ";
            }
            cout << "\n";
        }     
    }

    return 0;
}
