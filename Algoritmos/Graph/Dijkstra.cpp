int dist[MAX];
vector<ii>adj[MAX];
void dijk(int v){
    dist[v] = 0;
    int u;
    priority_queue< ii, vector< pair<int, int> > , greater<ii> >pq;
    pq.push(mk(dist[v], v));
    while(!pq.empty()){
        u = pq.top().se;
        pq.pop();
        for(ii p: adj[u])
            if(dist[p.fi] > dist[u] + p.se){
                dist[p.fi] = dist[u] + p.se;
                pq.push(mk(dist[p.fi], p.fi));
            }
    }
}
