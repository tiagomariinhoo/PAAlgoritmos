#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
#define mset0(x) memset(x, 0, sizeof x)
#define mset1(x) memset(x, -1, sizeof x)
int dfs_l[MAX];
int dfs_n[MAX];
int vstd[MAX];
vector<int>S;
vector<int> adj[MAX];
int dfsCount, numSCC;

void dfs(int at){
	dfs_n[at] = dfs_l[at] = dfsCount++;
	S.push_back(at);
	vstd[at]  = 1;

	for(int i = 0; i<adj[at].size(); i++){
		int to = adj[at][i];
		if(dfs_n[to] == -1){
			dfs(to);
		}
		if(vstd[to]){
			dfs_l[at] = min(dfs_l[at], dfs_l[to]);
		}
	}

	if(dfs_l[at] == dfs_n[at]){ // this is a root(start) of an SCC
		printf("SSC %d:", ++numSCC);
		while(true){
			int v = S.back();
			S.pop_back();
			vstd[v] = 0;
			printf(" %d", v);
			if(at == v)break;
		}
		printf("\n");

	}
}
int main(){

	int N, M, to;
	scanf("%d", &N);
	for(int i = 0; i<N; i++){
		scanf("%d", &M);
		adj[i].clear();
		for(int j = 0; j<M; j++){
			scanf("%d", &to);
			adj[i].push_back(to);
		}
	}
	mset0(dfs_l);
	mset1(dfs_n);
	mset0(vstd);
	dfsCount = numSCC = 0;
	S.clear();


	for(int i = 0; i<N; i++){
		if(dfs_n[i] == -1){
			dfs(i);
		}
	}

	return 0;
}