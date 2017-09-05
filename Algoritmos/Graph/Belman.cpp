bool ans = false;
for(int i = 1; i <=n; i++)dist[i] = INF;
dist[1] = 0;
for(int i = 1; i <=n; i++){
	for(int k = 1; k <=n; k++){
		if(dist[k] == INF)continue;
		for(auto f : adj[k]){
			if(dist[f.first] > dist[k] + f.second){
				dist[f.first] = dist[k] + f.second;
				if(i == n)ans = true;// negative cycle
			}
		}
	}
}