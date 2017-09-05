#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const int INF = 1e9+10;
struct edge{
	int v1, v2, cap, flow;
	edge(int _v1, int _v2, int _cap, int _flow) : v1(_v1), v2(_v2), cap(_cap), flow(_flow) {}
};
vector<edge> ed;
vector<int> adj[N];
int dist[N], que[N], nxt[N], vstd[N];
int src, sink, cntE;
int group[N];
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
void minCut(int u){ /* todos as arestas que ligarem um vertice que foi visitado com um vertice 
	não visitado fazem parte do min cut*/
	vstd[u] = 1;
	for(int i = 0; i < (int)adj[u].size(); i++){
		int v = adj[u][i];
		int to = ed[v].v2;
		if(vstd[to])continue;
		if(ed[v].cap - ed[v].flow == 0)continue;
		else minCut(to);
	}
}
int main(){
	int m;
	src = 0;
	sink = 1;
	int u, v, cap;
	while(scanf("%d %d", &n, &m), n + m){
		startFlow(n);
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &cap);
			u--;v--;
			add_edge(u, v, cap);
			add_edge(v, u, cap);
		}
		dinic();
		memset(vstd, 0, sizeof vstd);
		memset(group, 0, sizeof group);
		minCut(src);
		for(int i = 0; i < (int)ed.size(); i+=4){ // lembrar que para cada edge adicionado tem o edge de volta
			u = ed[i].v1;
			v = ed[i].v2;
			if(vstd[u] != vstd[v])printf("%d %d\n",u + 1, v + 1);
		}
		printf("\n");
	}

	return 0;
}
