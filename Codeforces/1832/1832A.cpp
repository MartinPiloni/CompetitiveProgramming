#include <bits/stdc++.h>
using namespace std;

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
        
        map<char, int> freq;
        for (int i = 0; i < (int) s.size(); i++) {
            freq[s[i]]++;
        }
        
        if ((int)s.size() % 2 == 0 && (int)freq.size() > 1) cout << "YES\n";
        else if ((int)s.size() % 2 == 1 && (int)freq.size() > 2) cout << "YES\n";
        else if ((int)s.size() % 2 == 1 && (int)freq.size() == 2 && freq[s[s.size() / 2]] > 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
