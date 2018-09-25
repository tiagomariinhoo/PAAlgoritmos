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
#define MAXN 201000

int x, y;
vector<ii> vec, vec2;
int n, m;
lli ans = 0;
int atual = 1;
lli tree[MAXN];
int maxi;

/*
  Fazer os casos no papel, a fórmula fica:
  sendo N horizontais e M retas verticais
  N + M + 1 + (N*M, que são intersecções de tipos diferentes)
  + (intersecções do mesmo tipo, que é dado pela contagem de inversões)
*/

void atualiza(lli x, lli v){
  for(;x<maxi;x+=(x&-x)) tree[x] += v;
}

lli sum(int x){
  lli s = 0;
  for(;x>0;x-=(x&-x)) s+=tree[x];
  return s;
}

void comprime(vector<ii> &aux){
  vi aux2;
  for(int i=0;i<sz(aux);i++) aux2.pb(aux[i].F), aux2.pb(aux[i].S);
  sort(aux2.begin(), aux2.end());
  
  for(int i=0;i<sz(aux);i++){
    aux[i].F = lower_bound(aux2.begin(), aux2.end(), aux[i].F) - aux2.begin() + 1;
    aux[i].S = lower_bound(aux2.begin(), aux2.end(), aux[i].S) - aux2.begin() + 1;
    maxi = max({maxi, aux[i].F, aux[i].S});
  }
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x >> y;

  cin >> n >> m;
  set<lli> aux;
  for(int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    vec.pb({a, b});
  }

  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    vec2.pb({a, b});
  }

  comprime(vec), comprime(vec2);
  sort(vec.begin(), vec.end());
  sort(vec2.begin(), vec2.end());
  lli ans = 0;

  lli inte = 0;  
  for(int i=sz(vec)-1;i>=0;i--){
    inte += sum(vec[i].S - 1);
    atualiza(vec[i].S, 1);
  }

  memset(tree, 0, sizeof tree);

  for(int i=sz(vec2)-1;i>=0;i--){
    inte += sum(vec2[i].S - 1);
    atualiza(vec2[i].S, 1);
  }

  lli n = sz(vec), m = sz(vec2);
  cout << n + m + 1 + (n*m) + inte << endl;

   return 0; 
} 