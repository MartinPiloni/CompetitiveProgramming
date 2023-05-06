#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int smallest_prime_factor(int n) {
    if (n % 2 == 0) return 2;

    int ans = n;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            ans = i;
            break;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        if (n == 1 || m == 1) {
            cout << "YES\n";
            continue;
        } 

        if (n <= m) {
            cout << "NO\n";
            continue;
        }            

        if (smallest_prime_factor(n) > m) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
