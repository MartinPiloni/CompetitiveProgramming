#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

#define oper min
#define NEUT 1e9
struct STree { 
	vector<int> st;int n;
	STree(int n): st(4*n+5,0), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    STree row(n), col(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        
        int a, b, c, d;
        if (t == 1) {
            cin >> a >> b;
            a--; b--;
            row.upd(a, row.query(a, a + 1) + 1);
            col.upd(b, col.query(b, b + 1) + 1);
        } else if (t == 2) {
            cin >> a >> b;
            a--; b--;
            row.upd(a, row.query(a, a + 1) - 1);
            col.upd(b, col.query(b, b + 1) - 1);
        } else {
            cin >> a >> b >> c >> d;
            a--; b--; c; d;
            if (row.query(a, c) > 0 || col.query(b, d) > 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}
