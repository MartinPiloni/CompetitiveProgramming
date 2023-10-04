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

    int x; cin >> x;
    int x_c = x, d;
    bool f = false;
    while (x_c != 0) {
        d = x_c % 10; 
        x_c /= 10;
        if (d == 7) f = true;
    }

    if (!f && x % 7 != 0) cout << "0\n";
    else if (!f && x % 7 == 0) cout << "1\n";
    else if (f && x % 7 != 0) cout << "2\n";
    else if (f && x % 7 == 0) cout << "3\n";

    return 0;
}
