void dfs(int u){
    vstd[u] = 1;
    for(int i = 0; i <sz(adj[u]); i++){
        int v = adj[u][i].fi;
        if(!vstd[v]){
            p[v] = u;
            dfs(v);
        }
        else if(vstd[v] == 1){
            if(v != p[u]){
                printf("------Cycle-----\n");
                printf("%d -> %d\n", u, v);
                int k = u;
                while(p[k] != v){
                    printf("%d -> %d\n", p[k], k);
                    k = p[k];
                }
                printf("%d -> %d\n", p[k], k);
                printf("-----EndCycle----\n");
            }
        }
    }
    vstd[u] = 2;
}