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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    bool can = true;
    if (a != d) can = false;
    if (c > 0 && a == 0) can = false;
    (can ? cout << "1\n" : cout << "0\n");

    return 0;
}
