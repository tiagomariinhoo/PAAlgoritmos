int dfsCnt;
int low[MAX], p[MAX], d[MAX], child[MAX];
vector<int>adj[MAX];
int vstd[MAX];
int root;
void dfs(int v){ // first start root and d[root] = 0/ (child/vstd) = 0 / p = -1
	vstd[v] = 1;
	low[v] = d[v];
	for(auto u : adj[v]){
		if(!vstd[u]){
			child[v]++;
			p[u] = v;
			d[u] = d[v]+1;
			dfs(u);
			low[v] = min(low[v], low[u]);
			if(low[u] > d[v]){
				printf("%d - - %d (cut edge) \n", v, u);
			}
			if(low[u] >= d[v] && (v != root || child[v] > 1)){
				printf("%d - > cut vertex\n", v);
			}
		}
		else if(u != p[v]){
			low[v] = min(low[v], d[u]);
		}
	}
	vstd[v] = 2;
}
