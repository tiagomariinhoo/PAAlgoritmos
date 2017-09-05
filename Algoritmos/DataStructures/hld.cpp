#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
const int maxlg = 17;
int topch[maxn], sgtpos[maxn], idch[maxn], subsz[maxn], curch, par[maxn];
int dep[maxn];
int sgt[4 * maxn], a[maxn], next[maxn];
int pos, n;
vector<pair<int, int> > edges;
vector<int>adj[maxn], costs[maxn];
int left(int p){return (p << 1); }
int right(int p){return (p << 1) + 1;}
void build(int id = 1, int lf = 0, int rg = n){
	if(lf == rg)sgt[id] = a[lf]; // change
	else{
		int md = (lf + rg)>>1;
		build(left(id), lf, md);
		build(right(id), md + 1, rg);
		sgt[id] = max(sgt[left(id)],sgt[right(id)]); // change
	}
}
void update(int idx, int val, int lf = 0, int rg = n, int id = 1){
	if(lf == rg){ // change
		a[idx] = sgt[id] = val;
	}
	else{
		int md = (lf + rg) >> 1;
		if(lf <= idx && idx <= md)update(idx, val, lf, md, left(id));
		else update(idx, val, md+1, rg, right(id));
		sgt[id] = max(sgt[left(id)],sgt[right(id)]); // change
	}
}
int query(int esq, int dir, int lf = 0, int rg = n, int id = 1){
	if(dir < lf || rg < esq)return 0;
	if(esq <= lf && rg <= dir)return sgt[id];
	int md = (lf + rg)>>1;
	int l = query(esq, dir, lf, md, left(id));
	int r = query(esq, dir, md + 1, rg, right(id));
	return max(l, r); // change
}
void dfs(int v, int p, int h = 0){ // dfs(root, root)
	dep[v] = h, subsz[v] = 1;
	for(int i = 0; i < sz(adj[v]); i++)if(adj[v][i] != p){
		par[adj[v][i]] = v;
		dfs(adj[v][i], v, h + 1);
		subsz[v] += subsz[adj[v][i]];
	}
}
void hld(int cur, int cst = -1, int prev = -1){
	if(topch[curch] == -1)topch[curch] = cur;
	idch[cur] = curch, sgtpos[cur] = pos, a[pos++] = cst;
	int hvy = -1, ncost;
	rep(i, 0, sz(adj[cur]))if(adj[cur][i] != prev){
		if(hvy == -1 || subsz[hvy] < subsz[adj[cur][i]]){
			hvy = adj[cur][i];
			ncost = costs[cur][i];
		}
	}
	if(hvy != -1)hld(hvy,ncost,cur);
	rep(i, 0, sz(adj[cur]))if(adj[cur][i] != prev && adj[cur][i] != hvy){
		curch++;
		hld(adj[cur][i], costs[cur][i], cur);// se o peso tiver no vertice cost[adj[cur][i]]
	}
}
int query_hld(int u, int v){
	int res = -1, k = -1;
	int topu, topv, chu, chv;
	chu = idch[u], chv = idch[v];
	while(chu != chv){
		topu = topch[chu];
		topv = topch[chv];
		if(dep[topu] < dep[topv])swap(u, v), swap(topu, topv), swap(chu, chv);
		res = max(res, query(sgtpos[topu], sgtpos[u])); // change
		u = par[topu];
		chu = idch[u];
	}
	if(u != v){// se os pesos estiverem no vertice remover esse if
		if(dep[u] > dep[v])swap(u, v);
		res = max(res, query(sgtpos[u]+1, sgtpos[v]));// se o peso estiver no vertice remover o "+1"
	}
	return res;
}
void initHld(){
	curch = pos = 1;
	repn(i, 1, n)topch[i] = -1;
}
