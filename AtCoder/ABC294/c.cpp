#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N), b(M), c(N + M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        c[i] = a[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> b[i];
        c[N + i] = b[i];
    }

    sort(c.begin(), c.end());
    map<int, int> pos;
    for (int i = 0; i < N + M; i++) {
        pos[c[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << pos[a[i]] << " \n"[i == N-1];
    }

    for (int i = 0; i < M; i++) {
        cout << pos[b[i]] << " \n"[i == M-1];
    }

    return 0;
}
