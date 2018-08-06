#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int adjMatrix[MAXN][MAXN], max_flow, flow, src, sink;
vi parent, adjList[MAXN];
int n,m;

void augment(int v, int minEdge){
	if(v == src){
		flow = minEdge;
	} else if(parent[v] != -1){
		augment(parent[v], min(minEdge, adjMatrix[parent[v]][v]));
		adjMatrix[parent[v]][v] -= flow;
		adjMatrix[v][parent[v]] += flow;
	}
}

int maxFlow(){
	max_flow = 0;
	while(1){
		flow = 0;
		bitset<MAXN> vis;
		vis[src] = true;
		queue<int> q;
		q.push(src);
		parent.assign(MAXN, -1);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == sink) break;
			for(int j=0;j<sz(adjList[u]);j++){
				int v = adjList[u][j];

				if(adjMatrix[u][v] > 0 and !vis[v]){
					vis[v] = true;
					q.push(v);
					parent[v] = u;
				}
			}
		}
		augment(sink, INF);
		if(flow == 0) break;
		max_flow += flow;
	}
	return max_flow;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		adjList[a].pb(b);
		adjList[b].pb(a);
		adjMatrix[a][b] = c;
		adjMatrix[b][a] = c;
	}

	src = 1, sink = n;
	cout << maxFlow() << endl;

	return 0;
}
