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

    vector<str> in_num = {"11", "1001", "100001", "10000001", "1000000001", "100000000001"};
    vector<str> e_num = {"99", "9999", "999999", "99999999", "9999999999"};

    int k, p;
    cin >> k >> p;
    
    str curr = in_num[0];
    ll ans = 0, j = 0, n = sz(curr);
    for (int i = 0; i < k; i++) {
        ans = (ans % p + stoll(curr) % p) % p;

        if (curr == e_num[j]) {
            j++;
            curr = in_num[j];
            n = sz(curr);
        } else if (curr[n/2] == '9') {
            curr[n / 2] = '0';
            curr[n / 2 - 1] = '0';
            
            int l = 1;
            while (curr[n / 2 + l] == '9') {
                curr[n / 2 + l] = '0';
                curr[n / 2 - 1 - l] = '0';
                l++;
            }

            curr[n / 2 + l] += 1;
            curr[n / 2 - 1 - l] += 1;
        } else {
            curr[n/2] += 1;
            curr[n/2 - 1] += 1;
        }
    }

    cout << ans % p << "\n";
    return 0;
}
