#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) (int) (x).size()

vector<int> find_primes(int n) {
    vector<int> primes;

    while (n % 2 == 0) {
        n /= 2;
        primes.push_back(2);
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            primes.push_back(i);
        }
    }

    if (n > 2) {
        primes.push_back(n);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> primes = find_primes(n);
        map<int, int> freq;

        int min_exp = 1e9;
        for (int i = 0; i < (int) size(primes); i++) {
            freq[primes[i]]++;
            min_exp = min(min_exp, freq[primes[i]]);
        }

        vector<int> a, p;
        int b;
        while(!freq.empty()) {
            b = 1;
            for (auto it = freq.begin(); it != freq.end();) {
                bool must_delete = false;
                b *= it->first;

                if (it->second - min_exp <= 0) {
                    must_delete = true;
                } else {
                    it->second -= min_exp;
                }

                if (must_delete) {
                    freq.erase(it++);
                } else {
                    ++it;
                }
            }

            a.push_back(b);
            p.push_back(min_exp);

            min_exp = 1e9;
            for (auto it = freq.begin(); it != freq.end(); it++) {
                min_exp = min(min_exp, it->second);
            }
        }

        int ans = 0;
        for (int i = 0; i < (int) size(a); i++) {
            ans +=	a[i] * p[i];
        }

        cout << ans << "\n";
    }

    return 0;
}
