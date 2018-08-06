#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 101
#define INF 1e9
#define D cout << "DEBUG" << endl
int adjMatrix[MAX][MAX], max_flow, flow, src, sink;
vector<int> parent, adjList[MAX];

void augment(int v, int minEdge){
	if(v == src){
		flow = minEdge;
		return;
	} else if (parent[v] != -1){
		augment(parent[v], min(minEdge, adjMatrix[parent[v]][v]));
		adjMatrix[parent[v]][v] -= flow;
		adjMatrix[v][parent[v]] += flow;
	}
}

int maxflow(){
	max_flow = 0;
	while(1){
		flow = 0;
		bitset<MAX> vis;
		vis[src] = true;
		queue<int> q;
		q.push(src);
		parent.assign(MAX,-1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u==sink) break;
			for(int j=0;j<adjList[u].size();j++){
				int v = adjList[u][j];
				if(adjMatrix[u][v] > 0 && !vis[v]){
					vis[v] = true;
					q.push(v);
					parent[v] = u;
				}
			}
		}
		augment(sink, INF);
		if(flow==0) break;
		max_flow+=flow;
	}
	return max_flow;

}

int main (){
	int n,m;
		cin >> n >> m;
		memset(adjMatrix, 0, sizeof adjMatrix);
		for(int i=0;i<m;i++){
			int u, v, w;
			cin >> u >> v >> w;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
			adjMatrix[u][v] = w; //Fluxo entre esses dois vertices
		}
		src = 0;
		sink = 1;
		cout << "Max flow : " << maxflow();


	return 0;
}