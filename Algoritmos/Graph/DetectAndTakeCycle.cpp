void dfs(int u){ // memset pai -1
	// if(sz(cic)) return ;
	vis[u] = 1;
	for(int i=0;i<sz(vec[u]);i++){
		int v = vec[u][i];
		// if(sz(cic)) return ;
		if(!vis[v]) pai[v] = u, dfs(v);
		if(vis[v] == 1){
			int k = u;
			if(u != pai[v]){
			cout << "--- Cycle ---" << endl;
				cout << u << " -- " << v << endl;
				cic.pb({u,v});
				while(v != pai[k]){
					cic.pb({pai[k], k});
					cout << pai[k] << " - " << k << endl;
					k = pai[k];
				}
				cout << pai[k] << " - " << k << endl;
				cic.pb({pai[k], k});
				// return ;
			}
		}
	}
	vis[u] = 2;
}

bool TopologicalSort(int a, int b){ //If aa != n tem ciclo
	int gg[501];
	queue<int> q;
	for(int i=1;i<=n;i++) gg[i] = grau[i];
	for(int i=1;i<=n;i++){
		if(i == b) gg[i]--;
		if(!gg[i]) q.push(i);
	}
	int aa = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<sz(vec[u]);i++){
			int v = vec[u][i];
			if(a != u or v != b){
				gg[v]--;
				if(!gg[v]) q.push(v);
			}
		}
		aa++;
	}
	if(aa == n) return true;
	return false;
}