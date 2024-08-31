#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

// Input
const int MAXN = 1e5;
ll in[MAXN];
int n;
int x;

// Verify all wrong cases
int readAns(ifstream &fin){
    str s;
    fin >> s;
    if (s == "*") return -2; // Solution doesn't exists 

    vector<int> v(n);
    v[0] = stoi(s);
    for (int i = 1; i < n; i++) fin >> v[i];

    for (int i = 1; i < n; i++) {
      if (v[i] + v[i - 1] == x) return -1; // Sum of two adjacent elements is x;
    }

    return 0; // Correct answer
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input_file", ifstream::in);
    ifstream ans("myAnswer", ifstream::in);
    ifstream cor("correctAnswer", ifstream::in);

    /// Read input
    fin >> n;
    fin >> x;
    vector<ll> in(n);
    for (int i = 0; i < n; i++) fin >> in[i];

    // Read my answer
    int myAnswer = readAns(ans);

    // Read brute force answer 
    int correctAnswer = readAns(cor);

    // Check my answer to brute force answer
    if (myAnswer == -2 && correctAnswer == 0) {
      cout << "WA Si se puede pero digo que no se puede\n";
      return -1;
    } else if (myAnswer == 0 && correctAnswer == -2) {
      cout << "WA No se puede pero digo que si se puede\n";
      return -1;
    } else if (myAnswer == -1) {
      cout << "WA Suma de dos elementos adyacentes es igual a X";
      return -1;
    }

    return 0;
}

