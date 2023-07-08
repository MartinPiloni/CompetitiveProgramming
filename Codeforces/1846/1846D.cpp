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

    int t;
    cin >> t;
    while (t--) {
        int n;
        long double b, h;
        cin >> n >> b >> h;

        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(all(v));

        long double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (b * h) / 2;
        }

        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1] - v[i] < h) {
                long double dist = v[i + 1] - v[i];
                long double sm_h = h - dist;
                long double sm_b = sm_h * b / h; 
                
                ans -= sm_b * sm_h / 2;
            }
        }

        cout << fixed << setprecision(15) << ans << "\n";
    }

    return 0;
}
