#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

str in;
vector<bool> oper(vector<bool>& a, vector<bool>& b) {
    vector<bool> res(26);
    for (int i = 0; i < 26; i++) res[i] = a[i] || b[i];
    return res;
}

#define NEUT vector<bool>(26); 
struct STree { 
	vector<vector<bool>> st;int n;
	STree(int n): st(4*n+5, vector<bool>(26)), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k][in[p] - 'a'] = 0; st[k][v] = 1; return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	vector<bool> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
        vector<bool> s1 = query(2*k,s,m,a,b);
        vector<bool> s2 = query(2*k+1,m,e,a,b);
		return oper(s1, s2);
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	vector<bool> query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> in;
    int q; cin >> q;
    STree st(sz(in));
    for (int i = 0; i < sz(in); i++) st.upd(i, in[i] - 'a');
    while (q--) {
        int t; 
        cin >> t;
        if (t == 1) {
            int p; char c;
            cin >> p >> c;
            p--;
            st.upd(p, c - 'a');
            in[p] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l--;

            int cnt = 0;
            auto ans = st.query(l, r);
            for (int i = 0; i < 26; i++) cnt += ans[i];
            cout << cnt << "\n";
        }
    }

    return 0;
}
