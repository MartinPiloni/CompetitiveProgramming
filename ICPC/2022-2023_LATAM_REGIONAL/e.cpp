#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, e;
    cin >> n >> k >> e;

    multiset<int> s;
    s.insert(e);
    s.insert(k);
    s.insert(n - (k + e));

    if (s.count(1) == 3 || s.count(4) == 3) {
        cout << "2\n";
    } else if (s.count(2) == 3 || s.count(3) == 3){
        cout << "3\n";
    } else if (s.count(1) == 2) {
        cout << "1\n";
    } else if (s.count(2) == 2) {
        auto it = s.upper_bound(2);
        if (it != s.end() || s.find(0) != s.end()) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    } else if (s.count(3) == 2) {
        auto it = s.lower_bound(3);
        if (it != s.begin()) {
            it--;
            cout << *it << "\n";
        } else {
            cout << "0\n";
        }
    } else if (s.count(4) == 2) {
        auto it = s.lower_bound(4);
        if (it != s.begin()) {
            it--;
            cout << *it % 2 << "\n";
        } else {
            cout << "0\n";
        }
    } else {
        cout << "0\n";
    }

    return 0;
}
