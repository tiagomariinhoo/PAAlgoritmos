#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
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
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 200010
#define MAXL 20

/*
  Dada uma lista de vertices e os valores dele
  O peso da aresta é dado por ai + ay (valor do vertice)

  Depois dá arestas especiais entre os vértices
  Achar a MST

  Basta pegar o vértice de menor custo, ligar a todos os outros
  E rodar o kruskal

*/

int n, m;
vector<pair<lli,lli>> value;
int pai[MAXN];
int peso[MAXN];

vector<ii> vec[MAXN]; 

vector< pair<lli, ii > > edges;

int search(int x){
	if(pai[x] == x) return x;
	return pai[x] = search(pai[x]);
}

void join(int a, int b){
	a = search(pai[a]);
	b = search(pai[b]);

	if(a == b) return ;

	if(peso[a] < peso[b]){
		pai[a] = b;
	} else if(peso[a] > peso[b]){
		pai[b] = a;
	} else {
		pai[a] = b;
		peso[b]++;
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=1;i<=n;i++){
  	lli a;
  	cin >> a;
  	value.pb({a, i});
  }

  sort(value.begin(), value.end());

  for(int i=1;i<sz(value);i++){
  	edges.pb({value[0].F + value[i].F, {value[0].S, value[i].S}});
  }

  for(int i=0;i<m;i++){
  	lli a, b, c;
  	cin >> a >> b >> c;
  	edges.pb({c, {a, b}});
  }

  sort(edges.begin(), edges.end());

  lli ans = 0;
  for(int i=0;i<=n;i++) pai[i] = i;

  for(int i=0;i<sz(edges);i++){
  	if(search(edges[i].S.F) != search(edges[i].S.S)){
  		join(edges[i].S.F, edges[i].S.S);
  		ans += edges[i].F;
  	}
  }

  cout << ans << endl;

  return 0;
}  