#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

const int MAX_N = 1.5e7 + 5;
ll spf[MAX_N];

void sieve() {
    for (ll i = 2; i < MAX_N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (ll j = i * i; j < MAX_N; j += i) {
                spf[j] = i;
            }
        }
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    
    bool eq = true;
    ll g = v[0];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        g = gcd(g, v[i]);
        if (i != 0 && v[i] != v[i - 1]) eq = false;
    }

    if (eq) {
        cout << "-1\n";
        return 0;
    }

    sieve();

    set<pair<int, int>> g_fact;
    pair<int, int> p;
    if (g == 1) g_fact.insert({1, 1});
    
    p = {spf[g], 0};
    while (g > 1) {
        ll c = spf[g];
        if (c == p.first) p.second++;
        else p = {spf[g], 1};
        g_fact.insert(p);
        g /= spf[g];
    }

    map<pair<int, int>, int> p_occ;
    for (auto e : v) {
        if (e == 1) p_occ[{1, 1}]++;

        p = {spf[e], 0};
        while (e > 1) {
            ll c = spf[e];
            if (c == p.first) p.second++;
            else p = {spf[e], 1};
            p_occ[p]++;
            e /= spf[e];
        }
    }

    int m = 1e9;
    for (auto e : p_occ) {
        if (g_fact.count(e.first) == 0) {
            m = min(m, n - e.second);
        }
    }

    cout << m << "\n";
    return 0;
}
