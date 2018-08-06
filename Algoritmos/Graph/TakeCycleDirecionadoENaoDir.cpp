#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//ios_base::sync_with_stdio(false);
//g++ -std=c++11 sol.cpp -o sol.exe && sol.exe < in.txt > output.txt
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vi vec[501];
int p[501];
int vis[501];

// void dfs(int u){ Grafo Não direcionado
// 	vis[u] = 1;
// 	for(int i=0;i<sz(vec[u]);i++){
// 		int v = vec[u][i];
// 		if(!vis[v]){
// 			p[v] = u;
// 			dfs(v);
// 		} else if(vis[v] == 1){
// 			if(v != p[u]){
// 				cout << "----- Cycle -----" << endl;
// 				cout << u << " < - > " << v << endl;
// 				int k = u;
// 				while(p[k] != v){
// 					cout << p[k] << " - " << k << endl;
// 					k = p[k];
// 				} 
// 				cout << p[k] << " - " << k << endl;
// 				cout << "--- EndCycle ---" << endl;
// 			}
// 		}
// 	}
// 	vis[u] = 2;
// }

void dfs(int u){ //Grafo Direcionado
	vis[u] = 1;
	for(int i=0;i<sz(vec[u]);i++){
		int v = vec[u][i];
		if(!vis[v]){
			p[v] = u;
			dfs(v);
		} else if(vis[v]==1){
			if(u != p[v]){
				cout << "---- Cycle ----" << endl;
				cout << u << " <-> " << v << endl;
				int k = u;
				while(p[k] != v){
					cout << p[k] << " - " << k << endl;
					k = p[k];
				}
				cout << p[k] << " - " << k << endl;
				cout << "--- EndCycle ---" << endl;
			}
		}
	}
	vis[u] = 2;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		vec[a].pb(b);
		vec[b].pb(a);
	}
	memset(p, -1, sizeof p);

	for(int i=1;i<=n;i++) dfs(i);

	return 0;
}