#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;


bool is_binary(int x) {
    bool ans = true;
    
    auto s = to_string(x);
    for (int i = 0; i < sz(s); i++) {
        if (s[i] > '1') {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> binary_decimals;
    for (int i = 2; i <= 32; i++) {
        int x = i;
        
        str binary_rep = "";
        while (x != 0) {
            binary_rep += to_string(x % 2);
            x /= 2;
        }

        reverse(all(binary_rep));
        binary_decimals.pb(stoi(binary_rep));
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (is_binary(n)) {
            cout << "YES\n";
            continue;
        }

        for (int i = 0; i < sz(binary_decimals); i++) {
            while (n % binary_decimals[i] == 0) n /= binary_decimals[i];
        }

        if (n == 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
