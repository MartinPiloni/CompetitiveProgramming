#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

#define sz(x) int((x).size())

void setIO(string name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if ((int) name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("mixmilk");

    vector<pair<ll, ll>> bucket(3);
    ll c, m;
    for (int i = 0; i < 3; i++) {
        cin >> c >> m;
        bucket[i] = {c, m};
    }

    for (int i = 0; i < 100; i++) {
        ll capacity_left = bucket[(i + 1) % 3].first - bucket[(i + 1) % 3].second;
        ll milk = bucket[i % 3].second;
        if (milk >= capacity_left) {
            bucket[(i + 1) % 3].second = bucket[(i + 1) % 3].first;
            bucket[i % 3].second -= capacity_left;
        } else {
            bucket[(i + 1) % 3].second += milk;
            bucket[i % 3].second = 0;
        }
    }

    for (int i = 0; i < 3; i++) { 
        cout << bucket[i].second << "\n";
    }

    return 0;
}
