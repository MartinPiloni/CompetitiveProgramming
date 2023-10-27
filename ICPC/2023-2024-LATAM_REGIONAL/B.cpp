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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> freq;

    int x;
    for (int i = 0; i < 3 * n; i++) {
        cin >> x;
        freq[x]++;
    }

    bool f = false;
    for (auto e : freq) {
        if (e.snd % 3 != 0) f = true;
    }
    (f ? cout << "Y\n" : cout << "N\n");

    return 0;
}