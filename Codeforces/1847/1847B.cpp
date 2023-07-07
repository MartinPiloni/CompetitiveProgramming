#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
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
        cin >> n;
        vector<int> v(n);
        int min_sum = 0;
        fore(i, 0, n) {
            cin >> v[i];
            if (i == 0) min_sum = v[i];
            else min_sum &= v[i];
        }

        int cnt = 0;
        int sum = -1;
        if (min_sum > 0) cnt = 1;
        else {
            fore(i, 0, n) {
                if (sum == -1) sum = v[i];
                else sum &= v[i];

                if(sum == min_sum) {
                    sum = -1;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
