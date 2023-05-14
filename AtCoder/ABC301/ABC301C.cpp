#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str s, t;
    cin >> s >> t;

    map<char, int> s_occ, t_occ;
    for (int i = 0; i < (int)s.size(); i++) {
        s_occ[s[i]]++;
        t_occ[t[i]]++;
    }

    set<char> a = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    bool ok = true;
    for(char c = 'a'; c <= 'z' && ok; c++) {
        if (s_occ[c] < t_occ[c] && a.find(c) != a.end()) {
            s_occ['@'] -= t_occ[c] - s_occ[c];
            s_occ[c] += t_occ[c] - s_occ[c];
        } else if (s_occ[c] < t_occ[c] && a.find(c) == a.end()) {
            ok = false;
        }

        if (s_occ['@'] < 0) ok = false;
    }
    
    for(char c = 'a'; c <= 'z' && ok; c++) {
        if (t_occ[c] < s_occ[c] && a.find(c) != a.end()) {
            t_occ['@'] -= s_occ[c] - t_occ[c];
            t_occ[c] += s_occ[c] - t_occ[c];
        } else if (t_occ[c] < s_occ[c] && a.find(c) == a.end()) {
            ok = false;
        }

        if (t_occ['@'] < 0) ok = false;
    }

    cout << (ok ? "Yes\n" : "No\n");

    return 0;
}
