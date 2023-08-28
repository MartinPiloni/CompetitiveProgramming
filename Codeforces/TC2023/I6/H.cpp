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

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    long double sum = .0, ans = .0;
    for (int i = 0; i < n; i++) {
        sum = .0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            if (j - i >= k - 1) {
                ans = max(ans, sum / (j - i + 1));
            }
        }
    }
    cout << setprecision(15) << ans << "\n";

    return 0;
}
