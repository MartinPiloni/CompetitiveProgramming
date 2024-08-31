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

    str s;
    cin >> s;
    map<char, int> freq;
    for (int i = 0; i < sz(s); i++) {
      freq[s[i]]++;
    }
    cout << min({freq['T'], freq['P'], freq['A'] + freq['U']}) << "\n";

    return 0;
}
