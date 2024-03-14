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
        int a, b, l;
        cin >> a >> b >> l;
        
        set<int> k_values;
        for (int i = 0; i < 20; i++) {
            int x = l;
            for (int j = 0; j < i; j++) {
                if (x % a == 0) x /= a;
            }

            for (int j = 0; j < 20; j++) {
                k_values.insert(x);
                if (x % b == 0) x /= b;
            }
        }
        cout << sz(k_values) << "\n";
    }

    return 0;
}
