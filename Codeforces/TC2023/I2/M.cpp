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

    str a, b, r_a;
    cin >> a;
    r_a = a;
    reverse(r_a.begin(), r_a.end());
    cout << a + r_a << "\n";

    return 0;
}
