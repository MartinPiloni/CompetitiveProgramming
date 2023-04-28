#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

map<int, int> primes;

void prime_desc(int p) {
    while (p % 2 == 0) {
        p /= 2;
        primes[2]++; 
    }

    for (int i = 3; i <= sqrt(p); i += 2) {
        while (p % i == 0) {
            p /= i;
            primes[i]++;
        }
    }

    if (p > 1) primes[p]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int in;
        for (int i = 0; i < n; i++) {
            cin >> in;
            prime_desc(in);
        }

        int ans = 0;
        for (auto it = primes.begin(); it != primes.end();) {
            if (it->second % 2 == 0) {
                ans += it->second / 2;
                primes.erase(it++);
            } else {
                ans += it->second / 2;
                it->second = 1; 
                it++;
            }
        } 

        ans += (int) primes.size() / 3;
        cout << ans << "\n";

        primes.clear();
    }

    return 0;
}
