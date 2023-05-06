#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

map<int, int> prime_descomposition(int n) {
    map<int, int> primes;
    while (n % 2 == 0) {
        primes[2]++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }

    if (n > 1) primes[n]++;
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        if (n == m) {
            cout << "YES\n";
            continue;
        }
        if (n < m) {
            cout << "NO\n";
            continue;
        }

        map<int, int> n_factors = prime_descomposition(n);
        map<int, int> m_factors = prime_descomposition(m);
        bool eq = true;
        for (auto p : n_factors) {
            if (p.second != m_factors[p.first] && (p.first != 2 && p.first != 3)) {
                eq = false;
                break;
            }
        }

        for (auto p : m_factors) {
            if (p.second != n_factors[p.first] && (p.first != 2 && p.first != 3)) {
                eq = false;
                break;
            }
        }

        if (!eq) {
            cout << "NO\n";
            continue;
        }
        else if(n_factors[3] < m_factors[3] || n_factors[2] > m_factors[2]) cout << "NO\n";
        else if(n_factors[2] == m_factors[2]) cout << "YES\n";
        else if(m_factors[2] - n_factors[2] <= n_factors[3] - m_factors[3]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
