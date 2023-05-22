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
        int n;
        cin >> n;

        str s;
        cin >> s;

        set<string> r;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            str note = "";
            note += s[i];
            note += s[i + 1];
            if (r.insert(note).second) { 
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
