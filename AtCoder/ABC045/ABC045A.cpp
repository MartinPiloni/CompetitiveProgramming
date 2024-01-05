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

    int a, b, h;
    cin >> a >> b >> h;
    if (a > b) swap(a, b);
    cout << a * h + (b - a) * h / 2 << "\n";
    return 0;
}
