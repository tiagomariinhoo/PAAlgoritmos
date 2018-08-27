#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n, q;
vi vec[100001];
int vis[100001];
int ans[1000001];
int prox[100001];
vector<pair<int, int> > guarda[100001];
int can[100001];

void dfs(int x){
	vis[x] = 1, can[x] = 1;
	for(auto i : guarda[x]){
		if(can[i.F]) ans[i.S] = 1;
	}


	for(auto i : vec[x]){
		if(!vis[i]){
			dfs(i);
		}
	}
	can[x] = 0;
}

int main(){
	cin >> n >> q;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(a == -1){
		prox[i] = a;
		} else {
		vec[i].pb(a);
		vec[a].pb(i);
		}
	}

	for(int i=0;i<q;i++){
		int a, b;
		cin >> a >> b;
		guarda[a].pb({b, i});
	}

	for(int i=0;i<n;i++){
		if(prox[i] == -1) dfs(i);
	}

	for(int i=0;i<q;i++){
		if(ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
