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
        cin >> n;

        int a = 2, b = 3, c;
        cout << a << " " << b << " ";
        for (int i = 0; i < n - 2; i++) {
            c = a + b;

            int num = b + 1;
            while (3 * num % c == 0) num++;
            cout << num << " ";

            a = b;
            b = num;
        }
        cout << "\n";
    }

    return 0;
}
