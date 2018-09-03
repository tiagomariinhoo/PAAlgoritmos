#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXL 20
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 200001

int n,m,k;
set<int> vec[MAXN];
vector<ii> q;
int vis[MAXN];
int grau[MAXN];
int ans[MAXN];
set<ii> aux;
map<ii, int> vis2;

void tira(int x){
	if(vis[x]) return ;
	vis[x] = 1;
	for(auto i : vec[x]){
		aux.erase({grau[i], i});
		grau[i]--;
		aux.insert({grau[i], i});
	}
}

void check(){
	while(!aux.empty()){
		ii v = *aux.begin();
		if(v.F >= k) break;
		aux.erase(aux.begin());
		tira(v.S);
	}
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  for(int i=0;i<m;i++){
  	int a, b;
  	cin >> a >> b;
  	q.pb({a, b});
  	vec[a].insert(b);
  	vec[b].insert(a);
  	grau[a]++, grau[b]++;
  }

  for(int i=1;i<=n;i++){
  	aux.insert({grau[i], i});
  }
  check();
  for(int i=m;i>=1;i--){
  	ans[i] = sz(aux);

  	int x = q[i-1].F, y = q[i-1].S;	
  	
  	if(!vis[x] and !vis[y]){
  		vec[x].erase(y);
  		vec[y].erase(x);

  		aux.erase({grau[x], x});
  		grau[x]--;
  		aux.insert({grau[x], x});;
  		
  		aux.erase({grau[y], y});
  		grau[y]--;
  		aux.insert({grau[y], y});
  	}

  	check();
  }

  for(int i=1;i<=m;i++) cout << ans[i] << endl;

  return 0;
}