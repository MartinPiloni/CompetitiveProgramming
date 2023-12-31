#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()

using ll = long long;
using str = string;


// MAXN: max number of nodes or 2 * max number of variables (2SAT)
const int MAXN = 2e5 + 10;

bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	for(int i = 0; i < n; i++)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addor(int a, int b){g[neg(a)].pb(b);g[neg(b)].pb(a);}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	for(int i = 0; i < nvar; i++)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _n, _m;
    cin >> _n >> _m;
    vector<int> state(_n);
    vector<vector<int>> door(_n);
    for (int i = 0; i < _n; i++) cin >> state[i];
    
    int c;
    for (int i = 0; i < _m; i++) {
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            x--;
            door[x].pb(i);
        } 
    }

    for (int i = 0; i < _n; i++) {
        if (state[i] == 0) {
            addor(neg(door[i][0]), neg(door[i][1]));
            addor(door[i][0], door[i][1]);
        } else {
            addor(door[i][0], neg(door[i][1]));
            addor(neg(door[i][0]), door[i][1]);
        }
    }
    (satisf(_m) ? cout << "YES\n" : cout << "NO\n");

    return 0;
}
