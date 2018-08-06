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
int grau[501];
vector<ii> cic;
int pai[501];
int vis[501];

void dfs(int u){
	if(sz(cic)) return ;
	vis[u] = 1;
	for(int i=0;i<sz(vec[u]);i++){
		int v = vec[u][i];
		if(sz(cic)) return ;
		if(!vis[v]) pai[v] = u, dfs(v);
		if(vis[v] == 1){
			int k = u;
			if(u != pai[v]){
				cic.pb({u,v});
				while(v != pai[k]){
					cic.pb({pai[k], k});
					k = pai[k];
				}
				cic.pb({pai[k], k});
				return ;
			}
		}
	}
	vis[u] = 2;
}

bool check(int a, int b){
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

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		vec[a].pb(b);
		grau[b]++;
	}

	memset(pai, -1, sizeof pai);

	for(int i=1;i<=n;i++){
		dfs(i);
		if(sz(cic)) break;
	}

	if(!sz(cic)){
		cout << "YES" << endl;
		return 0;
	} else {
		for(int i=0;i<sz(cic);i++){
			if(check(cic[i].F, cic[i].S)){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}