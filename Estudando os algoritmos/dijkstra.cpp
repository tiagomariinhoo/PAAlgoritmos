#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 11000
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
int n,m;
vector < ii > adj[MAX];
int dist[MAX];

void dijk(int v){
    dist[v] = 0;
    priority_queue<ii , vector<ii> , greater<ii> > pq;
    pq.push(mp(dist[v],v));

    int u;
    while(!pq.empty()){
        u = pq.top().second;
        pq.pop();
            for(ii p : adj[u]){
                if(dist[p.S] > dist[u] + p.F){
                    dist[p.S] = dist[u] + p.F;
                    pq.push(mp(dist[p.S],p.F));
                }
            }
    }
}

int main (){
    cin >> n >> m;
    for(int i=0;i<=n;i++) dist[i] = INF;

    for(int i=0;i<m;i++){
        int a,b,c;
            cin >> a >> b >> c;
                adj[a].pb(mp(c,b));
                adj[b].pb(mp(c,a));
    }

    dijk(1);

    for(int i=1;i<=n;i++){
        cout << dist[i] << endl;
    }

    return 0;
}