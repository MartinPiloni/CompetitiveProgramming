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

    int b, a, x;
    cin >> b >> a >> x;

    if (x & 1 && a >= b) {
        for (int i = 0; i < a - (x + 1) / 2; i++) cout << "1";
        for (int i = 0; i < x + 1; i++) {
            if (i % 2 == 0) cout << "1";
            else cout << "0";
        }
        for (int i = 0; i < b - (x + 1) / 2; i++) cout << "0";
    } else if (x & 1 && a < b) {
        for (int i = 0; i < b - (x + 1) / 2; i++) cout << "0";
        for (int i = 0; i < x + 1; i++) {
            if (i % 2 == 0) cout << "0";
            else cout << "1";
        }
        for (int i = 0; i < a - (x + 1) / 2; i++) cout << "1";
    } else if (x % 2 == 0 && a >= b) {
        for (int i = 0; i < a - (x / 2); i++) cout << "1";
        for (int i = 0; i < b - (x / 2) + 1; i++) cout << "0";
        for (int i = 0; i < x - 1; i++) {
            if (i % 2 == 0) cout << "1";
            else cout << "0";
        }
    } else {
        for (int i = 0; i < b - (x / 2); i++) cout << "0";
        for (int i = 0; i < a - (x / 2) + 1; i++) cout << "1";
        for (int i = 0; i < x - 1; i++) {
            if (i % 2 == 0) cout << "0";
            else cout << "1";
        }
    }
    cout << "\n";

    return 0;
}

/*
1
1*- 10 -0*

2
1*- 10+1

3
1* - 1010 - 0*

4
1* - 10+101

5
1* - 101010 - 0*

6
1* - 10+10101
*/