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

    int n, k, l;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> k >> l;

    ll ans = 0;
    vector<pair<ll, int>> v(k);
    for (int i = 0; i < k; i++) {
        v[i] = {-b[i], i};
        ans += a[i];
    }
    sort(all(v));

    vector<bool> used(n), erased(n), p(n);
    priority_queue<pair<ll, int>> pq, gq;
    for (int i = 0; i < l; i++) {
        ans += v[i].fst * -1;
        used[v[i].snd] = 1;
        gq.push({v[i].fst, v[i].snd});
    }

    for (int i = 0; i < k; i++) {
        if (!used[i]) pq.push({b[i], i});
    }

    if (l == n) {cout << ans << "\n"; return 0;}
    ll sum = ans;
    for (int i = 0; i < k; i++) {
        sum -= a[k - 1 - i];
        sum += a[n - i - 1];
        
        erased[k - 1 - i] = true;
        if (!erased[n - i - 1] || (erased[n - i - 1] && p[n - i - 1])) {
            pq.push({b[n - i - 1], n - i - 1});
        }
        erased[n - i - 1] = false;

        while (erased[pq.top().snd]) {p[pq.top().snd] = true; pq.pop();}
        while (!used[gq.top().snd]) gq.pop();
        if (used[k - 1 - i]) {
            p[k - 1 - i] = true;
            sum -= b[k - 1 - i];
            sum += pq.top().fst;
            used[k - 1 - i] = false;
            used[pq.top().snd] = true;
            gq.push({pq.top().fst * -1, pq.top().snd});
            pq.pop();
        } else if (pq.top().fst > gq.top().fst * -1) {
            sum -= gq.top().fst * -1;
            sum += pq.top().fst;
            used[gq.top().snd] = false;
            used[pq.top().snd] = true;
            gq.push({pq.top().fst * -1, pq.top().snd});
            pq.push({gq.top().fst * -1, gq.top().snd});
            pq.pop();
            gq.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";

    return 0;
}
