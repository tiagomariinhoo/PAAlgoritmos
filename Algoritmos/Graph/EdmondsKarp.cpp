/* Edmonds Karp Max flow 
	Time complexity O(VE^2)
	não esquecer de adicionar os back edges na lista de adjascencias 
*/
int res[MAX][MAX], mf, flow, src, sink;
vector<int> p, adj[MAX];
void augment(int v, int minEdge) {
	if(v == src) flow = minEdge;
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= flow;
		res[v][p[v]] += flow;
	}
}
int maxflow(){
	mf = 0;
	while(1){
		flow = 0;
		bitset<MAX> vis; vis[src] = true;
		queue<int>q; q.push(src);
		p.assign(MAX, -1);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == sink) break;
			for(int j = 0; j < adj[u].size(); j++){
				int v = adj[u][j];
				if(res[u][v] > 0 && !vis[v]){
					vis[v] = true, q.push(v), p[v] = u;
				}
			}
		}
		augment(sink, INF);
		if(flow == 0)break;
		mf+=flow;
	}
	return mf;
}
