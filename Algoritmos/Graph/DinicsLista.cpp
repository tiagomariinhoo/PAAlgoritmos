const int INF = 1e9+10;
struct edge{
	int v1, v2, cap, flow;
	edge(int _v1, int _v2, int _cap, int _flow) : v1(_v1), v2(_v2), cap(_cap), flow(_flow) {}
};
vector<edge> ed;
vector<int> adj[N];
int dist[N], que[N], nxt[N];
int src, sink, cntE;
int n;
void add_edge(int u, int v, int cap){ // antes de adicionar qualquer aresta lembrar de zerar o contador(cntE)
	adj[u].push_back(cntE++);
	adj[v].push_back(cntE++);
	ed.push_back(edge(u, v, cap, 0));
	ed.push_back(edge(v, u, 0, 0));
}
int bfs(){
	memset(dist, -1, sizeof dist);
	dist[src] = 0;
	int head = 0, tail = 0;
	que[tail++] = src;
	while(head < tail && dist[sink] == -1){
		int v = que[head++];
		for(int i = 0; i < (int)adj[v].size(); i++){
			int id = adj[v][i];
			int to = ed[id].v2;
			if(dist[to]  == -1 && ed[id].flow < ed[id].cap){
				que[tail++] = to;
				dist[to] = dist[v] + 1;
			}
		}
	}
	return dist[sink] != -1;
}
int dfs(int v, int flow) {
	if(!flow || v == sink)return flow;
	while(nxt[v] < (int)adj[v].size()) {
		int id = adj[v][nxt[v]];
		int to = ed[id].v2;
		if(dist[to] != dist[v] + 1){
			++nxt[v];
			continue;
		}
		int curFlow = dfs(to, min(flow, ed[id].cap - ed[id].flow));
		if(curFlow) {
			ed[id].flow += curFlow;
			ed[id^1].flow -= curFlow;
			return curFlow;
		}
		++nxt[v];
	}
	return 0;
}
int dinic() {
	int flow = 0;
	while(true){
		if(!bfs())break; // nao encontrou caminho ate o destino
		memset(nxt, 0, sizeof nxt);
		while(int curFlow = dfs(src, INF))flow+=curFlow;	
	}
	return flow;
}
void startFlow(int tam){
	for(int i = 0; i < tam; i++)adj[i].clear();
	ed.clear();
	cntE = 0;
}

