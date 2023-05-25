#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 4e4 + 5;
const int P = 500;
const int MOD = 1e9 + 7;
int dp[P][MAX_N];
vector<int> pal;

vector<int> palindromes(int n) {
    vector<int> p;
    for (int i = 1; i < n; i++) {
        vector<int> v;
        int x = i;
        while (x != 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        auto rev = v;
        reverse(rev.begin(), rev.end());
        if (v == rev) p.push_back(i);
    }

    return p;
}

int f(int p, int c) {
    if (c == 0) return 1;
    if (p == (int)pal.size()) return 0;
    
    int &r = dp[p][c];
    if (r != -1) return r;

    r = f(p + 1, c); 
    if (c - pal[p] >= 0) {
        r = (r + f(p, c - pal[p])) % MOD;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof dp);
    pal = palindromes((int)4e4);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << f(0, n) << "\n";
    }

    return 0;
}
