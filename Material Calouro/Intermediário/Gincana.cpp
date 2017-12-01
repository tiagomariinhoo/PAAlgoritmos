#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF (1<<30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//Gincana DFS
// https://www.thehuxley.com/problem/160
int n,m;
vi adj[5000];
int vis[5000];
int solve(int x){
	if(!vis[x]) vis[x] = 1;
	for(int i=0;i<adj[x].size();i++)
		if(!vis[adj[x][i]]) solve(adj[x][i]);
	
}

int main(){
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		 adj[b].pb(a);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0) solve(i), ans++;
	}
	cout << ans << endl;

	return 0;
}