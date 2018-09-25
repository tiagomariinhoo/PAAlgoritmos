#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
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

#define MAXN 100001

/*
	Dado o nivel de riqueza, beleza e a doação
	Pegar um conjunto de pessoas que maximize a quantidade de doação
	E duas pessoas só podem estar no mesmo conjunto se:
	Supondo a,b e a2,b2 das duas pessoas (riqueza e beleza)
	Então a<a2 e b<b2
	Ou a==a2 e b==b2

	A solução é ordenar, fazendo
	1 1 30
	1 2 50
	2 1 50
	2 2 30, por exemplo
	E usar o 'b' dando update no indice
	Processa todos com a == 1, e faz a query(1, b-1), soma com o atual
	e dá update na posição B (caso seja maior)

*/

vector<pair<ii, lli> > vec, vec2;
set<lli> aa, bb;
map<lli, vector<pair<lli, lli> > > qt;
map<lli, int> comp;
int n;
lli ans = 0;
lli tree[4*MAXN];


lli query(int l, int r, int node = 1, int start = 1, int end = n){
	if(start > r or end < l) return 0;
	if(start >= l and end <= r) return tree[node];

	int mid = (start + end) >> 1;
	lli p1 = query(l, r, 2*node, start, mid);
	lli p2 = query(l, r, 2*node+1, mid+1, end);

	return max(p1, p2);
}	

void update(int idx, lli val, int node = 1, int start = 1, int end = n){
	if(start == end) tree[node] = val;
	else{
		int mid = (start + end) >> 1;
		if(start <= idx and idx <= mid) update(idx, val, 2*node, start, mid);
		else update(idx, val, 2*node+1, mid+1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
  	lli a, b, c;
  	cin >> a >> b >> c;
  	vec2.pb({{a,b}, c});
  	aa.insert(a);
  	bb.insert(b);
  }

  sort(vec2.begin(), vec2.end());

  int xx = 1;
  for(auto i : bb) comp[i] = xx++;

  for(int i=0;i<sz(vec2);i++) vec2[i].F.S = comp[vec2[i].F.S]; //Comprimindo coordenadas

  for(int i=0;i<sz(vec2);i++){
  	lli xx = vec2[i].F.F, yy = vec2[i].F.S, sum = vec2[i].S;
  	int iii = i+1;
  	while(vec2[iii].F.F == vec2[i].F.F and vec2[iii].F.S == vec2[i].F.S) sum += vec2[iii].S, iii++;
  	i = iii-1;
  	vec.pb({{xx, yy}, sum});
  }


  for(int i=0;i<sz(vec);i++)
  	qt[vec[i].F.F].pb({vec[i].F.S, vec[i].S});

  for(int i=0;i<sz(vec);i++){
  	if(vec[i].F.F != *aa.begin()) break;
  	update(vec[i].F.S, vec[i].S);
  }

  for(auto i : qt){
  	if(i.F == *aa.begin()) continue;
  	vector< pair<lli , lli> > aux;
  	for(auto j : i.S){
  		lli pos = j.F, sum = j.S;
  		aux.pb({pos, sum + query(1, pos-1)});
  	}

  	for(int j=0;j<sz(aux);j++){
  		int pos = aux[j].F;
  		lli atual = query(pos, pos);
  		if(atual < aux[j].S) update(pos, aux[j].S);
  	}
  }

  cout << query(1, n) << endl;

   return 0; 
} 