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
    int sum = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        if (abs(s_occ[c] - t_occ[c]) != 0 && a.find(c) == a.end()) {
            sum = (int)1e9;
            break;
        }
        sum += abs(s_occ[c] - t_occ[c]);
    }

    if (sum <= (s_occ['@'] + t_occ['@'])) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
