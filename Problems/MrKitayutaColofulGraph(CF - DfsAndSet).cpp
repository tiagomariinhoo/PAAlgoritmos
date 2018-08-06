#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
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
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vector<ii> vec[101];
int vis[101];
map<ii, int> ans;

set< set<int> > auxx[101];
set<int> aux;

bool at = false;

void dfs(int x, int col){

	vis[x] = 1;
	for(int i=0;i<sz(vec[x]);i++){
		int a = vec[x][i].S;
		int c = vec[x][i].F;
			
		if(!vis[a] and c == col){
			aux.insert(x), aux.insert(a);
			dfs(a, c);
		}
	}
}

int check(int a, int b){
	int aa = 0;

	for(int i=1;i<=m;i++){
		for(auto j : auxx[i]){
			if(j.find(a) != j.end() and j.find(b) != j.end()){
				aa++;
				break;
			}
		}
	}

	return aa;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].pb({c,b});
		vec[b].pb({c,a});
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			memset(vis, 0, sizeof vis);
			dfs(j, i);
			if(sz(aux) != 0) auxx[i].insert(aux);
			aux.clear();
		}
	}

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int a,b;
		cin >> a >> b;
		cout << check(a,b) << endl;
	} 

	return 0;
}