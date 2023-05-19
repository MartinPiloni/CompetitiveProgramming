#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

const int MAX_N = 3000;
int n;
double dp[MAX_N][MAX_N];
double prob[MAX_N];

double f(int x, int y) {
    if (x == n) return 1;

    double &r = dp[x][y];
    if (r != -1.0) return r;
    
    r = 0;
    r += f(x + 1, y) * prob[x];
    if (y < n / 2) {
        r += f(x + 1, y + 1) * (1 - prob[x]);
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1.0;
        }
    }

    cout.precision(9);
    cout << f(0, 0) << "\n";

    return 0;
}
