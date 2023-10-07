#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;

#define oper max
#define NEUT 0
struct STree { 
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
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
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        v[i] = {x, -y};    
    }
    sort(all(v));

    STree st(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        st.upd(v[i].snd * -1, st.query(0, v[i].snd * -1) + 1);
        ans = max(ans, st.query(v[i].snd * -1, v[i].snd * -1 + 1));
    }
    cout << ans << "\n";

    return 0;
}
