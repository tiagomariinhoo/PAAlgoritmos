// LCA pre-pro O(n log(n)) // query O (log(n))
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
const int maxlg = 20;
int par[maxn][maxlg], dep[maxn], tin[maxn], tout[maxn];
vector<int>adj[maxn];
int timer; // start 0
void dfs(int v, int p, int h = 0){ // dfs(root, root)
	tin[v] = ++timer;
	dep[v] = h;
	par[v][0] = p;
	rep(i, 1, maxlg)par[v][i] = par[par[v][i-1]][i-1];
	rep(i, 0, sz(adj[v]))if(adj[v][i] != p)dfs(adj[v][i], v, h+1);
	tout[v] = timer;
}
bool upper(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u, int v){
	if(upper(u, v))return u;
	if(upper(v, u))return v;
	per(i, 0, maxlg)
		if(!upper(par[u][i], v))u = par[u][i];
	return par[u][0];
}
int main(){
	timer  = 0;
	return 0;
}
