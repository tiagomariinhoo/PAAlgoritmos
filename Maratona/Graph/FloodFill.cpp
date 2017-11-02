#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 10000001
#define MIN -2000000
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ sol.cpp -std=c++11 -o sol.exe && sol.exe < in.txt

int n;
int vis[MAX];
vi vec[MAX];

dfs(int v){
	vis[v] = 1;
	for(int i=0;i<vec[v].size();i++)
		if(vis[vec[v][i]]==-1) dfs(vec[v][i]);
}

bfs(int v){
	queue<int> fila;
	fila.push(v);
	vis[v] = 1;
	while(!fila.empty()){
		v = fila.front();
		cout << "V : " << v << endl;
		fila.pop();
		for(int i=0;i<vec[v].size();i++){
			cout << vec[v][i] << endl;
			if(vis[vec[v][i]]==-1) fila.push(vec[v][i]), vis[vec[v][i]]=1;
		}
	}
}

int main(){
	s(n);
		for(int i=0;i<n;i++){
			int a,b;
				ss(a,b);
				vec[b].pb(a);
		}
		for(int i=0;i<=n;i++) vis[i] = -1;

			bfs(0);

	return 0;
}

