#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
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
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
vi vec[100001];
map<ii, int> vis2;
int vis[100001];
set<ii> ans;

void dfs(int x, bool at, int pai){
	vis[x] = 1;
	for(int i=0;i<sz(vec[x]);i++){
		int u = vec[x][i];
		if(!vis[u]){
			if(sz(vec[u]) >= 3){
				if(at == true){
					cout << "No" << endl;
					exit(0);
				}
				dfs(u, true, pai);
			} else {
				if(sz(vec[u]) == 1){
					int a = pai, b = u;
					if(a > b) swap(a,b);
					ans.insert({a,b});
				} else {
					dfs(u, at, pai);
				} 
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin >> a >> b;
		vec[a].pb(b);
		vec[b].pb(a);
	}
	int pos = 1, qt = sz(vec[1]);
	for(int i=1;i<=n;i++){
		if(sz(vec[i]) > qt){
			qt = sz(vec[i]);
			pos = i;
		}
	}

	dfs(pos, true, pos);

	cout << "Yes" << endl;
	cout << sz(ans) << endl;
	for(auto i : ans) cout << i.F << " " << i.S << endl;

	return 0;
}