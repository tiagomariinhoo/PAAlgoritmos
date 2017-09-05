vector<int>adj[MAX];
int vstd[MAX];
int q[MAX];
bool dfs(int u){ // return true if is bipartite
    bool bic = true;
    for(int x : adj[u]){
        if(!vstd[x]){
            vstd[x] = (vstd[u] == 1) ? 2 : 1;
            bic &= dfs(x);
        }else if(vstd[x] == vstd[u])return false;
    }
    return bic;
}
